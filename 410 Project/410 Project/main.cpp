#include "utilities.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	 const char* test = "testdata.txt";
	 //Basic Testing
	loadData(test);
	sortData(CPU_TIME);
	saveData("outputFile.txt");
	sortData(START_TIME);
	saveData("outputFile2.txt");
	sortData(PROCESS_NUMBER);
	saveData("outputFile3.txt");

	//Failure Testing
	loadData("gofuckurmum.txt");


	return 0;
}