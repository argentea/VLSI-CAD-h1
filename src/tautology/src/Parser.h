#pragma once
#include<istream>
#include<fstream>
#include<sstream>
#include"Tautolopylib.h"
using namespace std;
namespace Parser {
	vector<vector<tautology::Value>> TautologyParser(char* fileName);
};
