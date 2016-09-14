#include "utilities.h"
#include <string>
#include <fstream>
#include <iostream> 
#include <vector>
#include <sstream>
#include <algorithm>
 using namespace std;

 //Global Variables
 vector<process_stats> data;

 	//Comparitor for CPU time.
	bool cpuComp(const process_stats x, const process_stats y){
		return x.cpu_time < y.cpu_time;
	}

	//Comparitor for process number.
	bool cpuProcess(const process_stats x, const process_stats y){
		return x.process_number < y.process_number;
	}

	//Comparitor for start time.
	bool cpuStart(const process_stats x, const process_stats y){
		return x.start_time < y.start_time;
	}

 //Load Data
	int loadData(const char* filename){
		fstream myFile;
		string test;
		string token;
		process_stats lineData;

		try{
		myFile.open(filename);
			while(!myFile.eof()){
				getline(myFile, test);
				test.erase(test.find_last_not_of(" \n\r\t")+1);
				istringstream ss(test);

				vector<string> parsedString;

				while(getline(ss,token,CHAR_TO_SEARCH_FOR)){
					parsedString.push_back(token);
				}
				
				lineData.process_number = stoi(parsedString.at(0),NULL,10);
					
				lineData.start_time = stoi(parsedString.at(1),NULL,10);
					
				lineData.cpu_time = stoi(parsedString.at(2),NULL,10);

				data.push_back(lineData);
			}
		}
		catch(exception e){
			myFile.close();
			return COULD_NOT_OPEN_FILE;
		}
		return SUCCESS;
	}

//Save Data	
	int saveData(const char* filename){
		ofstream myFile;
		vector<process_stats>::iterator myIter = data.begin();

		try{
			myFile.open(filename);
			while(myIter != data.end()){
				myFile << (*myIter).process_number << ",";
				myFile << (*myIter).start_time << ",";
				myFile << (*myIter).cpu_time << "\n\r";
				myFile.flush();
				myIter++;
			}

			
		}
		catch(exception e){
			myFile.close();
			return COULD_NOT_OPEN_FILE;;
		}
		myFile.close();
		return 0;
	}

	//Sort Data
	void sortData(SORT_ORDER mySortOrder){
		if(mySortOrder == CPU_TIME){
			sort (data.begin(), data.end(), cpuComp);
		}
		else if(mySortOrder == PROCESS_NUMBER){
			sort (data.begin(), data.end(), cpuProcess);
		}
		else if(mySortOrder == START_TIME){
			sort (data.begin(), data.end(), cpuStart);
		}
	}

