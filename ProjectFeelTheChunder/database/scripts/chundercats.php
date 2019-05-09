<?php

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