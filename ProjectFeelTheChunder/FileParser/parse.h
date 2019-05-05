#ifndef __PARSE_H__
#define __PARSE_H__
#include <fstream>
#include <QString>
#include <QDebug>
#include <QFile>
#include <iostream>
#include "shape.h"
#include "../containers/AwesomeVector.h"
using namespace std;

class parse{
	public:
		// Default constructor
                parse();
		
		// Non-default constructor
                parse(QString);

                ~parse(){inputFile.close();}
		
		// Sets (new) filename
                void set_file(QString);
		
		// Pretty obvious
                void parseInput(AwesomeVector<Shape*> &shapeMagazine);
		
		// NOT PART OF PARSER CLASS REMOVE BEFORE DEVELOPMENT:
		void print();
	private:
		// File IO Variables:
        QString ShapeFileName;
        QFile   inputFile;
		
		// Set Defaults:
		void setDefaults();
		
		// File Controller Stuffs:
		void openFile();	
		void closeFile();
		
        // QString Parser:
        void parseQString();
		
        // Vector for dimensions QString since it can theoretically be infinitely long:
        AwesomeVector<QString> shpdmnsns;
		
		// "save" input to Shape object:
        void storeInput(AwesomeVector<Shape*> &shapeMagazine);
		
		// Shape variables for inputing:
		int ShapeId;
        QString Dimensions;
        QString ShapeType;
        QString PenColor;
		int PenWidth;
        QString PenStyle;
        QString PenCapStyle;
        QString PenJoinStyle;
        QString BrushColor;
        QString BrushStyle;
        QString TextQString;
        QString TextColor;
        QString TextAlignment;
		int TextPointSize;
        QString TextFontFamily;
        QString TextFontStyle;
        QString TextFontWeight;
};

//-----------------------------------------------------------------------------------
//	Function Definitions
//-----------------------------------------------------------------------------------

const char DIVIDER = ' '; // Must be set as a char using ''. not "".

parse::parse() : inputFile(new QFile("shapes.txt")){
	setDefaults();
}
parse::parse(QString x) : inputFile(new QFile(x)){
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
    TextQString = "";
	TextColor = "";
	TextAlignment = "";
	TextPointSize = 0;
	TextFontFamily = "";
	TextFontStyle = "";
	TextFontWeight = "";
	// Clear the Vector object's data
	int q = shpdmnsns.sizeOf();
	if(q != 0){
		for(int i=0; i<q; i++){
			shpdmnsns.erase(0);
		}
	}
}
void parse::set_file(QString x){
// QString name setter
    //inputFile.set
}
void parse::openFile(){
    if(inputFile.exists())
        inputFile.open();
    else
        qDebug() << "cannot open input file";
}	
void parse::closeFile(){
	inputFile.close();
}
void parse::parseInput(AwesomeVector<Shape*> & shapeMagazine){
	openFile();
    QTextStream txtStream(&inputFile);

    QString tmp;
	int count = 0;
    do{
		count++;
		if(count > 5000){
            qDebug() << "Error!\n";
			break;
		}
		// Begin Parsing:
        txtStream >> tmp;
		if(tmp == "ShapeId:"){
            txtStream >> ShapeId;
		}else if(tmp == "ShapeType:"){
            txtStream >> ShapeType;
            txtStream.ignore(10000, '\n');
			// Gets the "ShapeDimensions" since it is dynamic
			// and can, for polyline/polygon, can be infinitely
			// long, we use Vectors.
			getline(inputFile,Dimensions);
            // Seperates QString "Dimensions" by "DIVIDER"
            parseQString();
            // Clears "Dimensions" QString.
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
        }else if(tmp == "TextQString:"){
            inputFile >> TextQString;
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
                        storeInput(shapeMagazine);	// Store the inputted shape data to the shape class.
			setDefaults();	// Reset evreything in parse class to defaults to eliminate cross-contamination. 
		}
	}while(tmp != "--END-FILE--");
	closeFile();
}
void parse::parseQString(){
// Seperates QString "Dimensions" by "DIVIDER"
    QString tmp = "";
	unsigned int i;
	for(i=0; i<Dimensions.size()+2; i++){
		if(Dimensions[i] == DIVIDER || Dimensions[i] == '\0' || Dimensions[i] == '\n'){
			if(tmp != ""){
				tmp.resize(tmp.size()-1);
				if(tmp != "ShapeDimensions" && tmp != "" && tmp != " " && tmp != "\0" && tmp != "\n"){
                    shpdmnsns.push_back(tmp);			// Create new QString in vector object shpdmnsns
				}
				tmp = "";
			}
		}else{
            tmp.insert(tmp.end(),Dimensions[i]);	// QString Manipulations
		}
	}
}
void parse::storeInput(AwesomeVector<Shape*> & shapeMagazine){
// Store the inputted shape data to the shape class.
    if(Shape::ShapeType == "Line"){
            shapeMagazine.push_back(new Line())
        }else if(Shape::ShapeType == "Polyline"){
qDebug() << "Storing Polyline\n";
        }else if(Shape::ShapeType == "Polygon"){
qDebug() << "Storing Polygon\n";
        }else if(Shape::ShapeType == "Rectangle"){
qDebug() << "Storing Rectangle\n";
        }else if(Shape::ShapeType == "Ellipse"){
qDebug() << "Storing Ellipse\n";
        }else if(Shape::ShapeType == "Text"){
qDebug() << "Storing Text\n";
	}
print();
}



// NOT PART OF PARSER CLASS REMOVE BEFORE DEVELOPMENT:

void parse::print(){
	if(ShapeId != 0){
        qDebug() << "ShapeId        : " << ShapeId << '\n';
	}
	if(shpdmnsns.sizeOf() > 0){
		shpdmnsns.print();
	}
	if(ShapeType != ""){
        qDebug() << "ShapeType      : " << ShapeType << '\n';
	}
	if(PenColor != ""){
        qDebug() << "PenColor       : " << PenColor << '\n';
	}
	if(PenWidth != 0){
        qDebug() << "PenWidth       : " << PenWidth << '\n';
	}
	if(PenStyle != ""){
        qDebug() << "PenStyle       : " << PenStyle << '\n';
	}
	if(PenCapStyle != ""){
        qDebug() << "PenCapStyle    : " << PenCapStyle << '\n';
	}
	if(PenJoinStyle != ""){
        qDebug() << "PenJoinStyle   : " << PenJoinStyle << '\n';
	}
	if(BrushColor != ""){
        qDebug() << "BrushColor     : " << BrushColor << '\n';
	}
	if(BrushStyle != ""){
        qDebug() << "BrushStyle     : " << BrushStyle << '\n';
	}
    if(TextQString != ""){
        qDebug() << "TextQString     : " << TextQString << '\n';
	}
	if(TextColor != ""){
        qDebug() << "TextColor      : " << TextColor << '\n';
	}
	if(TextAlignment != ""){
        qDebug() << "TextAlignment  : " << TextAlignment << '\n';
	}
	if(TextPointSize != 0){
        qDebug() << "TextPointSize  : " << TextPointSize << '\n';
	}
	if(TextFontFamily != ""){
        qDebug() << "TextFontFamily : " << TextFontFamily << '\n';
	}
	if(TextFontStyle != ""){
        qDebug() << "TextFontStyle  : " << TextFontStyle << '\n';
	}
	if(TextFontWeight != ""){
        qDebug() << "TextFontWeight : " << TextFontWeight << '\n';
	}
    qDebug() << '\n';
}

#endif
