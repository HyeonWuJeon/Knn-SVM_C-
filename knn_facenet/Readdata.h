#ifndef READDATA_H
#define READDATA_H
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
class Readdata {
	Mat setting[30];
public:
	Readdata(string srcfile[]);
	
	void data(vector<Mat>& v);
};

#endif