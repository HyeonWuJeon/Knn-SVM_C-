
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Training.h"
#include "result.h"
//knn�����Ű��
using namespace cv;
using namespace cv::ml;
using namespace std;

//Test::Test(Mat img_float, Mat img_flatten, Mat img_resize, string path) : Training(img_float, img_flatten, img_resize, path) {}
Ptr<KNearest> Test::bring_knn(Ptr<KNearest> train_data) {
	Ptr<KNearest> knn = train_data;
	return knn;
}
void Test::result(Mat result) {
	if ((result.at<float>(0, 0) == 0)) {
		cout << "���� �Դϴ�" << endl;
	}
	else if ((result.at<float>(0, 0) == 1)) {
		cout << "���� �Դϴ�" << endl;
	}

	else if ((result.at<float>(0, 0) == 2)) {
		cout << "���̸� �Դϴ�" << endl;
	}

	else if ((result.at<float>(0, 0) == 3)) {
		cout << "���� �Դϴ�" << endl;
	}


};