#ifndef TRAINING_H
#define TRAINING_H
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;


class Training{
	Mat img_float, img_flatten, img_resize;
public:
	Training(Mat img_float, Mat img_flatten, Mat img_resize);
	Mat training(Mat D);
};

#endif


