#include"Parser.h"
#include "Tautolopylib.h"
namespace Parser {
vector<vector<tautology::Value>> TautologyParser(char* fileName) {
	int varNum = 0;
	int size = 0;
	string line;
	stringstream sline;
	ifstream dataFile (fileName);
	if(dataFile.is_open()) {
		getline(dataFile, line);
		sline << line;
		string tmp;
		bool findVarNum = false;
		while(!sline.eof()) {
			sline >> tmp;
			if(!findVarNum&&stringstream(tmp) >> varNum) {
				findVarNum = true;
				if(TAUTOLOGYTEST) {
					cout << endl << varNum << endl;
				}
				continue;
			}
			if(findVarNum&&stringstream(tmp) >> size) {
				if(TAUTOLOGYTEST) {
					cout << size << endl;
				}
				break;
			}
		}
		vector<vector<tautology::Value>> data(size, vector<tautology::Value>(varNum));
		data[0][0] = tautology::NOTCARE;
		int indexi = 0;
		int tmpint = 0;
		while (getline(dataFile, line)) {
			if(TAUTOLOGYTEST) {
				cout << line << endl;
			}
			stringstream dline;
			dline << line;
			string tmp;
			int indexj = 0;
			while (!dline.eof()){
				dline >> tmp;
				if(stringstream(tmp) >> tmpint){
					if(TAUTOLOGYTEST) {
						cout << tmpint << " ";
					}
				}else {
					break;
				}
				if(tmpint == 1){
					data[indexi][indexj] = tautology::POSITIVE;
					indexj++;
					continue;
				}
				if(tmpint == 10){
					data[indexi][indexj] = tautology::NAGETIVE;
					indexj++;
					continue;
				}
				if(tmpint == 11){
					data[indexi][indexj] = tautology::NOTCARE;
					indexj++;
					continue;
				}
				cerr << "Not expect value in (" << indexi << ", " << indexj << ")  " << tmpint << endl;
				exit(1);
			}

			if(TAUTOLOGYTEST) {
				cout << endl;
			}
			indexi++;
		}
		dataFile.close();
		return data;
	}
	else {
		cerr << "Can not open the file\n";
		exit(1);
	}
}
};
