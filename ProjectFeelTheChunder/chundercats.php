<?php

	/* 
		-------Chundercats2Dmodeling server side scripts-------
		DISCLAIMER: while this code works, it is insecure. It gets the job done for this project,
		but this would be unacceptable in a production environment. This code could be succeptable to 
		sql injection, XSS attacks, etc. as the incomming request data does not get fully sanitized.
	*/

	function openConnection(){
		$servername = "localhost";
		$username = "snarf";
		$password = "snarfsnarf";
		$db = "chundercats2Dmodeling";
		// Create connection
		$conn = mysqli_connect($servername, $username, $password, $db);
		// Check connection
		if (!$conn) {
		    die("Connection failed: " . mysqli_connect_error());
		}else{
			return $conn;
		}		
	}

	function getShapeId($shape){
		$id;
		switch($shape){
			case "Line":
				$id = 1;
			break;
			case "Polyline";
				$id = 2;
			break;
			case "Polygon";
				$id = 3;
			break;
			case "Rectangle";
				$id = 4;
			break;
			case "Square";
				$id = 5;
			break;
			case "Ellipse";
				$id = 6;
			break;
			case "Circle";
				$id = 7;
			break;
			case "Text";
				$id = 8;
			break;
		}
		return $id;
	}

	if($_SERVER['REQUEST_METHOD'] == 'GET'){

		if(isset($_REQUEST['action'])){
			$conn = openConnection();
			$responseText='';
			
			if($_REQUEST['action'] == 'get_shapes'){
				$sql = "CALL get_shapes";
				$result = mysqli_query($conn,$sql);
				mysqli_close($conn);
				$conn = openConnection();
				$sql2 = "SELECT * FROM Poly_Dimensions;";
				$result2 = mysqli_query($conn,$sql2);
				$responseTextPoly='';
				$polydimensions = array();
				while($row2 = mysqli_fetch_assoc($result2)){
					array_push($polydimensions,($row2['shape_id'].":".$row2['value'])); 
				}
				while($row = mysqli_fetch_array($result,MYSQLI_NUM)){
					if($row[0] != "Polyline" && $row[0] != "Polygon"){
						for($i=0;$i<sizeof($row);$i++){
							if($i == 3 || $i== 4 || $i==5){
								$text = $row[$i].=",";
							}else{
								$text = $row[$i].=".";
							}
							$responseText .= $text;
						}
						$responseText .= "|";
					}else{
						for($i=0;$i<sizeof($row);$i++){
							$text = $row[$i].=".";
							$responseTextPoly .= $text;
						}
						$responseTextPoly .= ":";
						for($j=0;$j<sizeof($polydimensions);$j++){
							$val = explode(":",$polydimensions[$j]);
							if($row[1] == $val[0]){
								$text = $val[1] .= ",";
								$responseTextPoly .= $text;
							}
						}
						$responseTextPoly = substr($responseTextPoly, 0, -1);
						$responseTextPoly .= "|";
						$responseText .= $responseTextPoly;
						$responseTextPoly = '';
					}
				}
				$responseText = substr($responseText, 0, -1);
				mysqli_free_result($result2);
			}

			if($_REQUEST['action'] == 'save_shape'){
				$sql = mysqli_prepare($conn,"INSERT INTO Shapes (shape_id,x1,x2,_a_,_b_,pen_color,pen_width,pen_style,pen_cap_style,pen_join_style,brush_color,brush_style,text_string,text_color,text_alignment,text_point_size,text_font_family,text_font_style,text_font_weight) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");	
				mysqli_stmt_bind_param($sql,"iiiiisissssssssisss",$shape_id,$x1,$x2,$_a_,$_b_,$pen_color,$pen_width,$pen_style,$pen_cap_style,$pen_join_style,$brush_color,$brush_style,$text_string,$text_color,$text_alignment,$text_point_size,$text_font_family,$text_font_style,$text_font_weight);
				$shape_id = getShapeId($_REQUEST['shape']);
				$x1 = $x2 = $_a_ = $_b_ = $pen_color = $pen_width = $pen_style = $pen_cap_style = $pen_join_style = $brush_color = $brush_style = $text_string = $text_color = $text_alignment = $text_point_size = $text_font_family = $text_font_style = $text_font_weight = NULL;
				$dimensionsArray = explode(",",$_REQUEST['dimensions']);
				$dimensionsArray = array_map('trim',$dimensionsArray);
				if($shape_id == 8){
					$text_string = $_REQUEST['text_string'];
					$text_color = $_REQUEST['text_color'];
					$text_alignment = $_REQUEST['text_alignment'];
					$text_point_size = $_REQUEST['text_point_size'];
					$text_font_family = $_REQUEST['text_font_family'];
					$text_font_style = $_REQUEST['text_font_style'];
					$text_font_weight = $_REQUEST['text_font_weight'];
				}else{
					$pen_color = $_REQUEST['pen_color'];
					$pen_width = $_REQUEST['pen_width'];
					$pen_style = $_REQUEST['pen_style'];
					$pen_cap_style = $_REQUEST['pen_cap_style'];
					$pen_join_style = $_REQUEST['pen_join_style'];
					if(isset($_REQUEST['brush_color'],$_REQUEST['brush_style'])){
						$brush_color = $_REQUEST['brush_color'];
						$brush_style = $_REQUEST['brush_style'];
					}
				}
				if($shape_id != 2 && $shape_id != 3){
					$x1 = $dimensionsArray[0];
					$x2 = $dimensionsArray[1];
					if(sizeof($dimensionsArray) > 2){
						$_a_ = $dimensionsArray[2];
					}
					if(sizeof($dimensionsArray) > 3){
						$_b_ = $dimensionsArray[3];
					}
				}
				$result = mysqli_stmt_execute($sql);
				$newShapeID = mysqli_insert_id($conn);
				if($newShapeID == 0){
					$responseText = "error";
				}else{
					$responseText = "success";
					if($shape_id == 2 || $shape_id == 3){
						$sql2 = "INSERT INTO Poly_Dimensions (shape_id,dimension,value) VALUES ('".$newShapeID."','x','".$dimensionsArray[0]."'),";
						for($i = 1;$i < (sizeof($dimensionsArray)-1);$i++){
							if(($i+1)%2 == 0){
								$sql2.="('".$newShapeID."','y','".$dimensionsArray[$i]."'),";
							}else{
								$sql2.="('".$newShapeID."','x','".$dimensionsArray[$i]."'),";
							}
						}
						$sql2.="('".$newShapeID."','y','".$dimensionsArray[sizeof($dimensionsArray)-1]."');";
						$result = mysqli_query($conn,$sql2);
					}
				}
			}

			if($_REQUEST['action'] == 'shape_type'){
				$sql = "SELECT shape FROM Shape_Type;";
				$result = mysqli_query($conn,$sql);
				while($row = mysqli_fetch_assoc($result)){
					$text = $row['shape'].=",";
					$responseText.= $text;
				}
			}

			if($_REQUEST['action'] == 'login'){
				$sql = "CALL user_login('".$_REQUEST['user_name']."','".$_REQUEST['password']."');";
				$result = mysqli_query($conn,$sql);
				while($row = mysqli_fetch_assoc($result)){
					$responseText = $row['user_type'];
				}
			}

			if($_REQUEST['action'] == 'create_user'){
				$sql = "CALL create_user('".$_REQUEST['user_name']."','".$_REQUEST['password']."','".$_REQUEST['type']."');";
				$result = mysqli_query($conn,$sql);
				while($row = mysqli_fetch_assoc($result)){
					$responseText = $row['message'];
				}
			}

			if($_REQUEST['action'] == 'delete_shape'){
				$sql = "DELETE FROM Shapes WHERE id = '".$_REQUEST['shape_id']."';";
				if(mysqli_query($conn,$sql)){
					$responseText = "success";
				}else{
					$responseText = "error";
				}
			}

			if($_REQUEST['action'] == 'testimonial'){
				$sql = "INSERT INTO Testimonials (name,testimonial) VALUES ('".$_REQUEST['name']."','".$_REQUEST['testimonial']."');";
				mysqli_query($conn,$sql);
				if(mysqli_insert_id($conn) != 0){
					$responseText = "success";
				}else{
					$responseText = "error";
				}
			}

			echo $responseText;

			if($_REQUEST['action'] != 'save_shape' && $_REQUEST['action'] != 'delete_shape' && $_REQUEST['action'] != 'testimonial'){
				mysqli_free_result($result);
			}

			mysqli_close($conn);
		}

	}
?>