#include "Readdata.h"



Readdata::Readdata(string srcfile[]) {
	for (int i = 0; i < 30; i++) {
		this->setting[i] = imread(srcfile[i]);//Read
	}
}


void Readdata::data(vector<Mat>& v) {
	for (int i = 0; i < 30; i++) {
		v.push_back(setting[i]);
	}
}
