#include "AwesomeVector.h"

int main(){
	
	AwesomeVector<string>TMPE;
	
	string tmp = "";
	do{
		cin >> tmp;
		TMPE.push_back(tmp);
	}while(tmp != "-1");
	
	TMPE.print();
	TMPE.erase(TMPE.sizeOf()-1);
	
	cout << '\n';
	TMPE.print();
	
	return 0;
}