#include"Tautolopylib.h"
namespace tautology {

CubeList::CubeList(vector<vector<Value>> data){
	if(TAUTOLOGYTEST)
		cout << "Tautology:: Init CubeList from data\n";
	for(auto cube: data) {
		matrix.push_back(cube);
	}
}

CubeList::CubeList(CubeList& pre, int variable, Value V){
	if(TAUTOLOGYTEST)
		cout << "Tautology:: Create new cublist from old, splitVar: "<< variable << ", value "<< V << "\n";
	for(auto preCube: pre.matrix){
		if(preCube[variable] == V){
			matrix.push_back(preCube);
			matrix.back()[variable] = NOTCARE;
		}else if(preCube[variable] == NOTCARE){
			matrix.push_back(preCube);
		}else {
			continue;
		}
	}
}

int CubeList::splitVariable() {
	if(TAUTOLOGYTEST)
		cout << "Tautology:: Find splitVariable\n";
	int varNum = matrix[0].size();
	vector<int> trueVar(varNum, 0);
	vector<int> complVar(varNum, 0);
	for(auto cube: matrix) {
		for(int i = 0; i < varNum; i++) {
			if(cube[i] == POSITIVE) {
				trueVar[i]++;
			}else if(cube[i] == NAGETIVE) {
				complVar[i]++;
			}
		}
	}
	int min = matrix.size();
	int max = 0;
	int minid = -1;
	for(int i = 0; i < varNum; i++) {
		if(trueVar[i]!=0&&complVar[i]!=0) {
			if(trueVar[i]+complVar[i] > max) {
				minid = i;
				min = abs(trueVar[i]-complVar[i]);
				max = trueVar[i]+complVar[i];
			}
			if(trueVar[i]+complVar[i] == max&&abs(trueVar[i]-complVar[i]) < min) {
				minid = i;
				min = abs(trueVar[i]-complVar[i]);
			}
		}
	}
	if(minid == -1) {
		cerr << "Tautology:: No split id found\n";
	}
	if(TAUTOLOGYTEST)
		cout << "Tautology:: Find splitVariable end\n";
	return minid;
}

bool CubeList::isUnate() {
	vector<Value> flag;
	flag.assign(matrix[0].size(), NOTCARE);
	int varNum = matrix[0].size();
	for(auto cube: matrix) {
		for(int i = 0; i < varNum; i++){
			if(cube[i] == NOTCARE){
				continue;
			}
			if(flag[i] == NOTCARE) {
				flag[i] = cube[i];
			}else if(flag[i] != cube[i]) {
				return false;
			}
		}
	}
	return true;
}

Rule CubeList::checkRule1(){
	bool flag = false;
	for(auto cube: matrix) {
		bool check = true;
		for(Value v: cube) {
			if(v != NOTCARE){
				check = false;
				break;
			}
		}
		if(check){
			flag = true;
			break;
		}
	}
	if(flag) {
		return TRUE;
	}else {
		return FALSE;
	}
}

Rule CubeList::checkRule3() {
	if(TAUTOLOGYTEST)
		cout << "Tautology:: checkRule3\n";
	int size = matrix[0].size();
	vector<bool> sigleP(size, false);
	vector<bool> sigleN(size, false);
	for(auto cube : matrix) {
		bool flag = false;
		int tmpid;
		for(int i = 0; i < size; ++i) {
			if(!flag && cube[i] != NOTCARE) {
				flag = true;
				tmpid = i;
			}
			if(flag && cube[i] != NOTCARE) {
				flag = false;
				break;
			}
		}
		if(flag){
			cube[tmpid] == POSITIVE? sigleP[tmpid] = true: sigleN[tmpid] = true;
		}
	}
	for(int i = 0; i < size; ++i) {
		if(sigleP[i] && sigleN[i]) {
			if(TAUTOLOGYTEST)
				cout << "Tautology:: checkRule3 end TRUE\n";
			return TRUE;
		}
	}
	if(TAUTOLOGYTEST)
		cout << "Tautology:: checkRule3 end NOTKNOW\n";
	return NOTKNOW;
}

void CubeList::printCubeList() {
	if(TAUTOLOGYTEST)
		cout << "print:: CubeList\n";
	cerr << "size: " << matrix.size() << " varNum: " << matrix[0].size() << endl;
	for(auto cube: matrix) {
		for(auto var: cube) {
			if(var == POSITIVE){
				cout << "T\t";
			}else if(var == NAGETIVE) {
				cout << "F\t";
			}else {
				cout << "N\t";
			}
		}
		cout << endl;
	}
}

void CubeList::printSATList() {
	int num = 0;
	int size = matrix.size();
	int varNum = matrix[0].size();
	string symbol("a");
	cout << "(";
	int j = 0;
	for(auto cube: matrix) {
		for(int i = 0; i < varNum; i++){
			if(cube[i] == POSITIVE){
				cout << symbol+to_string(i);
			}else if(cube[i] == NAGETIVE){
				cout << "!" << symbol+to_string(i);
			}else {
				cout << "T";
			}
			if(i != varNum-1) {
				cout << "^";
			}
		}
		if(j != size-1) {
			cout << ")||(";
		}
		j++;
	}
	cout << ")" << endl;
}

bool CubeList::tautology() {
	if(TAUTOLOGYTEST)
		printCubeList();
	if(isUnate()) {
		if(TAUTOLOGYTEST)
			cout << "Tautology:: isUnate\n";
		Rule r1 = checkRule1();
		if(r1 == TRUE) {
			if(TAUTOLOGYTEST)
				cout << "Tautology:: True\n";
			return true;
		}else if(r1 == FALSE){
			if(TAUTOLOGYTEST)
				cout << "Tautology:: False\n";
			return false;
		}
	}else if (checkRule3() == TRUE) {
		return true;
	}else if (checkRule3() == FALSE){
		return false;
	}else {
		splitVar = splitVariable();
		return CubeList(*this, splitVar, POSITIVE).tautology() && CubeList(*this, splitVar, NAGETIVE).tautology();
	}
	cerr << "Tautology:: not expect situation\n";
	return false;
}

};
