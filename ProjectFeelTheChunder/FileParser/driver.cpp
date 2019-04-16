#include "parse.h"
#include <iostream>
using namespace std;

int main(){
	parse file1;
	file1.set_file("shapes.txt");
	
	file1.parseInput(1);
	
	cout << "Successful!\n";
	
	return 0;
}