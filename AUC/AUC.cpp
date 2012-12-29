#include <iostream>
#include <fstream>
#include "auc.h"
using namespace std;

int main(int argc, char* argv[]){
	if (argc < 2){
		cout << "No enough input" << endl;
		cout << "Usage:./AUC prediction data label" << endl;
	}

	
	ifstream labelFile, predFile;
	labelFile.open(argv[2]);
	predFile.open(argv[1]);

	double label;
	double pred;
	vector<EvalItem> input;

	while (!labelFile.eof()){
		labelFile >> label;
		predFile >> pred;
//		cout << "(pred, label) = (" << pred << ", " << label << ")" << endl; 
		EvalItem tmp(pred, label, 0);
		input.push_back(tmp);
	}

	double auc = calcAuc(input);
	cout << "The AUC is: " << auc << endl;
	return 0;
}
