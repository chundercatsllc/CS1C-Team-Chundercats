1) git repo: https://github.com/chundercatsllc/CS1C-Team-Chundercats

2) included in tar - complete project zip
3) included in tar - class files

4) requirements met: 
	1. tesimonials: see testimonials.cpp/.h/.ui
	   called in MainWindow.cpp line 674 in slot for testimonial_button clicked. Displays window for testimonials
	2. contact us method: see contactus.cpp/.h/.ui
	   called in MainWindow.cpp line 681 in slot for thank_kanye_button clicked. Displays the contact us page with all our info and logo
	3. display all shapes in rendering window: see RenderArea.cpp/.h - called for every addition of a shape by admin
	   as well as upon readin the input file. called in RenderArea.cpp line 12-17 for a paintEvent. Paints all shapes in the vector
	4. read in shapes from a shape file - see RenderArea.cpp lines 209-696. Called in RenderArea.cpp line 9
	5. move shapes: will be implemented by final submission. shape move functions are written, just not connected to gui
	6. add/remove shapes: see RenderArea.cpp line 32-36 and mainwindow.cpp lines 399-568 and 586-631
	7. shape listing report: will be implemented by final submission. Online database queries will provide reports sorted by name, id, size, or area
	8. shape listing sorted by area: see above
	9: shape listing report by perimeter: see above
	10: data saved between executions: see dbconnection.cpp/.h as well as sql and php folders in scripts folder in tar file. all changes will be saed and retrieved from online database
	inheritance: see shapes.h - class Line inherits from Shape
	Composition: see MainWindow.h - window is composed of a Login object pointer - line 102
	Exception handlers: to be implemented
	Virtual functions: see draw, move, area, and perimeter in shape.h -> Shape class
	Overloaded operators: see AwesomeVector.h line 38 and Shape.h line 24
	templated class: see AwesomeVector.h - lines 75, 84, etc
	pointer member of class/copy constructor: see AwesomeVector.h - see lines 75 and 150
	overloaded equality and less than operators: to be written by Tuesday
	disable copy ops: to be implemented
	custom vector: see AwesomeVector.cpp/.h in containers folder. Implemented in RenderArea.cpp lines 4,15,16,21,34,etc as ShapeMagazine
	

5) agile documents: included in tar

6) doxygen: included in tar - doxygen comments in code will be transfered by tues (huge merge conflict on git...sigh)

7) valgrind: will submit on Tuesday

8) team contributions: will submit on Tuesday

EC: selection sort: close to finishing: will submit on Tuesday

EC: agile management: we used git->projects. Screenshots are in the artifacts folder

Database files with php and sql files included in separate folder in tar