#include"Parser.h"
#include "Tautolopylib.h"
namespace Parser {
vector<vector<tautology::Value>> TautologyParser(char* fileName) {
	int varNum = 0;
	int size = 0;
	vector<vector<tautology::Value>> data;
	string line;
	stringstream sline;
	ifstream dataFile (fileName);
	if(dataFile.is_open()) {
		getline(dataFile, line);
		cout << line;
		sline << line;
		string tmp;
		bool findVarNum = false;
		while(!sline.eof()) {
			sline >> tmp;
			if(!findVarNum&&stringstream(tmp) >> varNum) {
				findVarNum = true;
				cout << varNum << endl;
			}
			if(findVarNum&&stringstream(tmp) >> size) {
				cout << size << endl;
				break;
			}
		}
		data.assign(size, vector<tautology::Value>(varNum));
		int indexi = 0;
		int tmpint = 0;
		while (getline(dataFile, line)) {
			sline << line;
			int indexj = 0;
			while (sline >> tmpint){
				if(tmpint == 1){
					data[indexi][indexj] = tautology::POSITIVE;
					continue;
				}
				if(tmpint == 10){
					data[indexi][indexj] = tautology::NAGETIVE;
					continue;
				}
				if(tmpint == 11){
					data[indexi][indexj] = tautology::NOTCARE;
					continue;
				}
				cerr << "Not expect value in (" << indexi << ", " << indexj << ")" << endl;
			}
		}
		dataFile.close();
	}
	else {
		cerr << "Can not open the file\n";
	}
	return data;
}
};
