#include<iostream>
#include"src/aig/saig/saig.h"
using namespace std;
int main(){
	Aig_Man_t* aig = new(Aig_Man_t);
	aig = Saig_ManReadBlif("/home/kunpengjiang/vlsicad/hw/h1/benchmarks_updated/equivalence/int2float/1.blif");
	cout << "equivalence\n";
	cout << Saig_ManCiNum(aig);
	return 0;
}
