#include "parse.h"

const char DIVIDER = ' '; // Must be set as a char using ''. not "".

parse::parse(){
// Dafault Constructor
	ShapeFileName = '\0';
	setDefaults();
}
parse::parse(string x){
// Non-dafault Constructor
	ShapeFileName = x;
	setDefaults();
}
void parse::setDefaults(){
// Obvious? - YES
	ShapeId = 0;
	Dimensions = "";
	ShapeType = "";
	PenColor = "";
	PenWidth = 0;
	PenStyle = "";
	PenCapStyle = "";
	PenJoinStyle = "";
	BrushColor = "";
	BrushStyle = "";
	TextString = "";
	TextColor = "";
	TextAlignment = "";
	TextPointSize = 0;
	TextFontFamily = "";
	TextFontStyle = "";
	TextFontWeight = "";
	// Clear the Vector object's data
	int q = shpdmnsns.getSize();
	if(q != 0){
		for(int i=0; i<q; i++){
			shpdmnsns.erase(0, 0);
		}
	}
}
void parse::set_file(string x){
// String name setter
	ShapeFileName = x;
}
void parse::openFile(){
// Obvious? - YES
	inputFile.open(ShapeFileName);
}	
void parse::closeFile(){
// Obvious? - YES
	inputFile.close();
}
void parse::parseInput(int REPLACE_WITH_SHAPE_CLASS){
	openFile();
	string tmp;
	int count = 0;
	do{
		// Loop fail control
		count++;
		if(count > 5000){
			cout << "Error!\n";
			break;
		}
		// Begin Parsing:
		inputFile >> tmp;
		if(tmp == "ShapeId:"){
			inputFile >> ShapeId;
		}else if(tmp == "ShapeType:"){
			inputFile >> ShapeType;
			inputFile.ignore(10000, '\n');
			// Gets the "ShapeDimensions" since it is dynamic
			// and can, for polyline/polygon, can be infinitely
			// long, we use Vectors.
			getline(inputFile,Dimensions);
			// Seperates String "Dimensions" by "DIVIDER"
			parseString();
			// Clears "Dimensions" string.
			Dimensions = "";
		}else if(tmp == "PenColor:"){
			inputFile >> PenColor;
		}else if(tmp == "PenWidth:"){
			inputFile >> PenWidth;
		}else if(tmp == "PenStyle:"){
			inputFile >> PenStyle;
		}else if(tmp == "PenCapStyle:"){
			inputFile >> PenCapStyle;
		}else if(tmp == "PenJoinStyle:"){
			inputFile >> PenJoinStyle;
		}else if(tmp == "BrushColor:"){
			inputFile >> BrushColor;
		}else if(tmp == "BrushStyle:"){
			inputFile >> BrushStyle;
		}else if(tmp == "TextString:"){
			inputFile >> TextString;
		}else if(tmp == "TextColor:"){
			inputFile >> TextColor;
		}else if(tmp == "TextAlignment:"){
			inputFile >> TextAlignment;
		}else if(tmp == "TextPointSize:"){
			inputFile >> TextPointSize;
		}else if(tmp == "TextFontFamily:"){
			inputFile >> TextFontFamily;
		}else if(tmp == "TextFontStyle:"){
			inputFile >> TextFontStyle;
		}else if(tmp == "TextFontWeight:"){
			inputFile >> TextFontWeight;
		}else if(tmp == "--END-SHAPE--"){
			// After every shape:
			storeInput(REPLACE_WITH_SHAPE_CLASS);	// Store the inputted shape data to the shape class.
			setDefaults();	// Reset evreything in parse class to defaults to eliminate cross-contamination. 
		}
	}while(tmp != "--END-FILE--");
	closeFile();
}
void parse::parseString(){
// Seperates String "Dimensions" by "DIVIDER"
	string tmp = "";
	unsigned int i;
	for(i=0; i<Dimensions.size()+2; i++){
		if(Dimensions[i] == DIVIDER || Dimensions[i] == '\0' || Dimensions[i] == '\n'){
			if(tmp != ""){
				tmp.resize(tmp.size()-1);
				if(tmp != "ShapeDimensions" && tmp != "" && tmp != " " && tmp != "\0" && tmp != "\n"){
					shpdmnsns.push_back(tmp);			// Create new string in vector object shpdmnsns
				}
				tmp = "";
			}
		}else{
			tmp.insert(tmp.end(),Dimensions[i]);	// String Manipulations
		}
	}
}
void parse::storeInput(int REPLACE_WITH_SHAPE_CLASS){
// Store the inputted shape data to the shape class.
	if(ShapeType == "Line"){
		cout << "Storing Line\n";
	}else if(ShapeType == "Polyline"){
		cout << "Storing Polyline\n";
	}else if(ShapeType == "Polygon"){
		cout << "Storing Polygon\n";
	}else if(ShapeType == "Rectangle"){
		cout << "Storing Rectangle\n";
	}else if(ShapeType == "Square"){
		cout << "Storing Square\n";
	}else if(ShapeType == "Ellipse"){
		cout << "Storing Ellipse\n";
	}else if(ShapeType == "Circle"){
		cout << "Storing Circle\n";
	}else if(ShapeType == "Text"){
		cout << "Storing Text\n";
	}
print();
}



// NOT PART OF PARSER CLASS REMOVE BEFORE DEVELOPMENT:

void parse::print(){
	if(ShapeId != 0){
		cout << "ShapeId        : " << ShapeId << '\n';
	}
	if(shpdmnsns.getSize() > 0){
		shpdmnsns.print();
	}
	if(ShapeType != ""){
		cout << "ShapeType      : " << ShapeType << '\n';
	}
	if(PenColor != ""){
		cout << "PenColor       : " << PenColor << '\n';
	}
	if(PenWidth != 0){
		cout << "PenWidth       : " << PenWidth << '\n';
	}
	if(PenStyle != ""){
		cout << "PenStyle       : " << PenStyle << '\n';
	}
	if(PenCapStyle != ""){
		cout << "PenCapStyle    : " << PenCapStyle << '\n';
	}
	if(PenJoinStyle != ""){
		cout << "PenJoinStyle   : " << PenJoinStyle << '\n';
	}
	if(BrushColor != ""){
		cout << "BrushColor     : " << BrushColor << '\n';
	}
	if(BrushStyle != ""){
		cout << "BrushStyle     : " << BrushStyle << '\n';
	}
	if(TextString != ""){
		cout << "TextString     : " << TextString << '\n';
	}
	if(TextColor != ""){
		cout << "TextColor      : " << TextColor << '\n';
	}
	if(TextAlignment != ""){
		cout << "TextAlignment  : " << TextAlignment << '\n';
	}
	if(TextPointSize != 0){
		cout << "TextPointSize  : " << TextPointSize << '\n';
	}
	if(TextFontFamily != ""){
		cout << "TextFontFamily : " << TextFontFamily << '\n';
	}
	if(TextFontStyle != ""){
		cout << "TextFontStyle  : " << TextFontStyle << '\n';
	}
	if(TextFontWeight != ""){
		cout << "TextFontWeight : " << TextFontWeight << '\n';
	}
	cout << '\n';
}















