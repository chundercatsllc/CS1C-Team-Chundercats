#ifndef __PARSE_H__
#define __PARSE_H__
#include <fstream>
#include <string>
#include <iostream>
#include "../containers/vectors.h"
using namespace std;

class parse{
	public:
		// Default constructor
		parse();
		
		// Non-default constructor
		parse(string);
		
		// Sets (new) filename
		void set_file(string);
		
		// Pretty obvious
		void parseInput(int REPLACE_WITH_SHAPE_CLASS);
		
		// NOT PART OF PARSER CLASS REMOVE BEFORE DEVELOPMENT:
		void print();
	private:
		// File IO Variables:
		string ShapeFileName;
		ifstream inputFile;
		
		// Set Defaults:
		void setDefaults();
		
		// File Controller Stuffs:
		void openFile();	
		void closeFile();
		
		// String Parser:
		void parseString();
		
		// Vector for dimensions string since it can theoretically be infinitely long:
		Vectors<string> shpdmnsns;
		
		// "save" input to Shape object:
		void storeInput(int REPLACE_WITH_SHAPE_CLASS);
		
		// Shape variables for inputing:
		int ShapeId;
		string Dimensions;
		string ShapeType;
		string PenColor;
		int PenWidth;
		string PenStyle;
		string PenCapStyle;
		string PenJoinStyle;
		string BrushColor;
		string BrushStyle;
		string TextString;
		string TextColor;
		string TextAlignment;
		int TextPointSize;
		string TextFontFamily;
		string TextFontStyle;
		string TextFontWeight;
};

#endif