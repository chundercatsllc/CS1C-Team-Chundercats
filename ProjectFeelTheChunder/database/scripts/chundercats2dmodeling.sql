CREATE TABLE User_Type (
	id INT AUTO_INCREMENT NOT NULL PRIMARY KEY, #ID and PK
	user_type VARCHAR(255) NOT NULL
);

CREATE TABLE Users (
	id INT AUTO_INCREMENT NOT NULL PRIMARY KEY, #ID and PK
	user_type_id INT NOT NULL,					#foreign key
	user_name VARCHAR(255) NOT NULL,
	password VARCHAR(255) NOT NULL,
	FOREIGN KEY (user_type_id) REFERENCES User_Type(id) #user_type_id is id of specific user type in User_Type table
);

CREATE TABLE Shape_Type ( #contains the name of every shape
	id INT AUTO_INCREMENT NOT NULL PRIMARY KEY, #ID and PK
	shape VARCHAR(255) NOT NULL
);

CREATE TABLE Shapes ( #table contains all attributes for standard shapes and text. polyline and polygon dimensions are stored in the Poly_Dimensions table
	id INT AUTO_INCREMENT NOT NULL PRIMARY KEY, #ID and PK
	shape_id INT NOT NULL, #foreign key
	x1 INT,
	x2 INT,
	_a_ INT,
	_b_ INT,
	pen_color ENUM('white','black','red','green','blue','cyan','magenta','yellow','gray'),
	pen_width INT,
	pen_style ENUM('NoPen','SolidLine','DashLine','DotLine','DashDotLine','DashDotDotLine'),
	pen_cap_style ENUM('FlatCap','SquareCap','RoundCap'),
	pen_join_style ENUM('MiterJoin','BevelJoin','RoundJoin'),
	brush_color ENUM('white','black','red','green','blue','cyan','magenta','yellow','gray'),
	brush_style ENUM('SolidPattern','HorPattern','VerPattern','NoBrush'),
	text_string VARCHAR(255),
	text_color ENUM('white','black','red','green','blue','cyan','magenta','yellow','gray'),
	text_alignment ENUM('AlignLeft','AlignRight','AlignTop','AlignBottom','AlignCenter'),
	text_point_size INT,
	text_font_family VARCHAR(255),
	text_font_style ENUM('StyleNormal','StyleItalic','StyleOblique'),
	text_font_weight ENUM('Thin','Light','Normal','Bold'),
	FOREIGN KEY (shape_id) REFERENCES Shape_Type(id) #the shape id for each row is the id of a specific shape in Shape_Type table.
);

INSERT INTO Shapes (shape_id,x1,x2,_a_,_b_,pen_color,pen_width,pen_style,pen_cap_style,pen_join_style) VALUES ('1','20','90','100','20','blue','2','DashDotLine','FlatCap','MiterJoin');


CREATE TABLE Poly_Dimensions (
	id INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
	shape_id INT NOT NULL,
	dimension VARCHAR(255) NOT NULL,
	value INT NOT NULL,
	FOREIGN KEY (shape_id) REFERENCES Shapes(id)
);

INSERT INTO Shape_Type (shape) VALUES ('Line'),('Polyline'),('Polygon'),('Rectangle'),('Square'),('Ellipse'),('Cirlce'),('Text');

DELIMITER $$
CREATE PROCEDURE user_login(IN username VARCHAR(255), IN pass VARCHAR(255))
BEGIN
	SELECT IF(EXISTS(SELECT id FROM Users WHERE (user_name = username AND password = pass)),(SELECT user_type FROM User_Type WHERE id = (SELECT user_type_id FROM Users WHERE user_name = username)),'failed') AS user_type;
END $$
DELIMITER ;

DELIMITER $$
CREATE PROCEDURE create_user(IN username VARCHAR(255), IN pass VARCHAR(255), IN type VARCHAR(255))
BEGIN
	SELECT IF(EXISTS(SELECT id FROM Users WHERE (user_name = username)),1,0) INTO @exists;
	IF @exists < 1 THEN
		INSERT INTO Users (user_type_id, user_name, password) VALUES ((SELECT id FROM User_Type WHERE user_type = type), username, pass);
		SELECT 'success' AS message;
	ELSE
		SELECT 'exists' AS message;
	END IF;
END $$
DELIMITER ;

DELIMITER $$
CREATE PROCEDURE get_shapes()
BEGIN
	SELECT Shape_Type.shape,Shapes.* FROM Shape_Type INNER JOIN Shapes ON Shape_Type.id = Shapes.shape_id;
END $$
DELIMITER ;