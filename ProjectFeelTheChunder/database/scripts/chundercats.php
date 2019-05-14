<?php

	/* 
		-------Chundercats2Dmodeling server side scripts-------
		DISCLAIMER: while this code works, it is insecure. It gets the job done for this project,
		but this would be unacceptable in a production environment. This code could be succeptable to 
		sql injection, XSS attacks, etc. as the incomming request data does not get fully sanitized.
	*/

	function openConnection(){
		$servername = "178.128.15.169";
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
				$sql2 = "SELECT * FROM Poly_Dimensions;";
				$result2 = mysqli_query($conn,$sql);
				$responseTextPoly='';
				while($row = mysqli_fetch_array($result,MYSQLI_NUM)){
					if($row[0] != "Polyline" && $row[0] != "Polygon"){
						for($i=0;$i<sizeof($row);$i++){
							$text = $row[$i].=".";
							$responseText .= $text;
						}
						$responseText .= "|";
					}else{
						for($i=0;$i<sizeof($row);$i++){
							$text = $row[$i].=".";
							$responseTextPoly .= $text;
						}
						$responseTextPoly .= ":";
						while($row2 = mysqli_fetch_assoc($result2)){
							if($row[0] == $row2['shape_id']){
								$text = $row2['value'] .= ",";
								$responseTextPoly .= $text;
							}
						}
						$responseTextPoly .= "|";
						$responseText .= $responseTextPoly;
						$responseTextPoly = '';
					}
				}
			}

			if($_REQUEST['action'] == 'save_shape'){
				$sql = mysqli_prepare($conn,"INSERT INTO Shapes (shape_id,x1,x2,_a_,_b_,pen_color,pen_width,pen_style,pen_cap_style,pen_join_style,brush_color,brush_style,text_string,text_color,text_alignment,text_point_size,text_font_family,text_font_style,text_font_weight) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);");	
				mysqli_stmt_bind_param($sql,"iiiiisissssssssisss",$x1,$x2,$_a_,$_b_,$pen_color,$pen_width,$pen_style,$pen_cap_style,$pen_join_style,$brush_color,$brush_style,$text_string,$text_color,$text_alignment,$text_point_size,$text_font_family,$text_font_style,$text_font_weight);
				$shape_id = getShapeId($_REQUEST['shape']);
				$x1 = $x2 = $_a_ = $_b_ = $pen_color = $pen_width = $pen_style = $pen_cap_style = $pen_join_style = $brush_color = $brush_style = $text_string = $text_color = $text_alignment = $text_point_size = $text_font_family = $text_font_style = $text_font_weight = NULL;
				$dimensionsArray = $_REQUEST['dimensions'].split(",");
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
				mysqli_stmt_execute($sql);
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
						mysqli_query($conn,$sql2);
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
				$sql = "CALL user_login(".$_REQUEST['user_name'].",".$_REQUEST['password'].");";
				$result = mysqli_query($conn,$sql);
				while($row = mysqli_fetch_assoc($result)){
					$responseText = $row['user_type'];
				}
			}

			if($_REQUEST['action'] == 'create_user'){
				$sql = "CALL create_user(".$_REQUEST['user_name'].",".$_REQUEST['password'].",".$_REQUEST['type'].");";
				$result = mysqli_query($conn,$sql);
				while($row = mysqli_fetch_assoc($result)){
					$responseText = $row['message'];
				}
			}

			echo $responseText;

			mysqli_free_result($result);

			mysqli_close($conn);
		}

	}
?>