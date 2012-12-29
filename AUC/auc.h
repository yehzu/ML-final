
// To use this, you have to create an EvalItem for each testing instance, containing the prediction(pCTR) and the real label. Then you can call function calcAuc() defined in this header to calculate AUC.
#ifndef EVALUATE_H
#define EVALUATE_H
#include<vector>
#include<algorithm>
using namespace std;

typedef struct EvalItem {
	double pCtr;
	int label;
	EvalItem() {}
	EvalItem(double a, int b, int c):pCtr(a), label(b) {}
	bool operator<(const struct EvalItem &a) const {
		return pCtr > a.pCtr;
	}
}EvalItem;


inline double calcAuc(vector<EvalItem> &a) {
	double tp = 0, fp = 0, area = 0;
	sort(a.begin(), a.end());
	for(vector<EvalItem>::iterator itr = a.begin(); itr != a.end(); ) {
		double t = 0, f = 0, p = itr->pCtr;
		for(; itr != a.end() && itr->pCtr == p; ++itr){
            if(itr->label==1)
                t += 1;
            else 
                f += 1;
        }
		if(f > 0) area += (tp+tp+t) * f * 0.5;
		tp += t;
		fp += f;
	}
	return (tp==0 || fp==0) ? 0 : (area / tp / fp);
}


#endif
