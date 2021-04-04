#include "src/Tautolopylib.h"
#include "src/Parser.h"
using namespace tautology;
int main(int argc, char* argv[]){
	if(argc != 2) {
		cout << "Need 1 argument\n";
		return 0;
	}
	vector<vector<Value>> testData(Parser::TautologyParser(argv[1]));
	Checker testChecker(testData);
	cout << testChecker.run() << endl;
	return 0;
}
