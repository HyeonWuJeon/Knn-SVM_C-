
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Imageoutput.h"
#include "Training.h"
//Test
using namespace cv;
using namespace cv::ml;
using namespace std;



Training::Training(Mat img_float, Mat img_flatten, Mat img_resize){

	this->img_flatten = img_flatten, this->img_float = img_float, this->img_resize = img_resize;
}


Mat Training::training(Mat D) {

	resize(D, img_resize, Size(200, 200), 0, 0, INTER_AREA);
	img_resize.convertTo(img_float, CV_32F); 
	img_flatten = img_float.reshape(1, 1);
	return img_flatten;
}





