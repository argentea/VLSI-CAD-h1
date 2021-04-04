#pragma once
#define TAUTOLOGYTEST 0

#include<vector>
#include<string>
#include<iostream>
#include<stdlib.h>

namespace tautology{
using namespace std;

/*! \enum Value
 *
 *  Detailed description
 */
enum Value { POSITIVE, NAGETIVE,  NOTCARE};
enum Rule { TRUE, FALSE, NOTKNOW};

class CubeList {
private:
	int splitVar;
	vector<int> variable;
	vector<vector<Value>> matrix;
	vector<int> trueVar;
	vector<int> complVar;
public:
	CubeList(){cerr << "Tautology:: CubeList constructed without data\n";};
	CubeList(CubeList& pre, int variable, Value V);
	CubeList(vector<vector<Value>> data);
	int splitVariable();
	bool isUnate();
	bool tautology();
	Rule checkRule1();
	Rule checkRule2();
	Rule checkRule3();
	void printCubeList();
	void printSATList();
};

class Checker {
private:
	CubeList list;
public:
	Checker();
	Checker(vector<vector<Value>> data):list(CubeList(data)) {};
	bool run() {
		list.printSATList();
		return list.tautology();
	};
};

};
