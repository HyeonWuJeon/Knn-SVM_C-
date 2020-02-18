#ifndef IMAGEOUTPUT_H
#define IMAGEOUTPUT_H
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;
class Image_output {
	string path;
	Mat image;
public:
	Image_output(string path) { this->path = path; }
	Mat src();
};
#endif