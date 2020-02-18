#ifndef TRAININH_H
#define TRAININH_H

#include"opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;

class Training {
	Mat src; // 테스트용 이미지
	string s; //이미지 경로
public:
	Training(string s, Mat src);
	void classifier(string s);
	void Image_read(Mat src,string s);

};
#endif // SVMTEST_H
