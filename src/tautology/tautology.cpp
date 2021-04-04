#include "src/Tautolopylib.h"
#include "src/Parser.h"
using namespace tautology;
int main(){
	vector<vector<Value>> testData;
	testData.push_back({POSITIVE, POSITIVE, NOTCARE});
	testData.push_back({POSITIVE, NOTCARE, POSITIVE});
	testData.push_back({POSITIVE, NAGETIVE, NAGETIVE});
	testData.push_back({NAGETIVE, NOTCARE, NOTCARE});
	Checker testChecker(testData);
	cout << testChecker.run() << endl;
	return 0;
}
