#ifndef RESULT_H
#define RESULT_H
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Training.h"
//knn적용시키기
using namespace cv;
using namespace cv::ml;
using namespace std;

class result : public Training{
public:
	result(Mat img_float, Mat img_flatten, Mat img_resize, string path) : Training(img_float, img_flatten, img_resize, path) {}
	Ptr<KNearest> bring_knn(Ptr<KNearest> train_data);
	void result(Mat result);


};

#endif