
#include "opencv2/opencv.hpp"
#include <iostream>
#include "result.h"

using namespace cv;
using namespace cv::ml;
using namespace std;

//last Return Complete Training  Knn

Ptr<KNearest> result::bring_knn(Ptr<KNearest> train_data) {
	Ptr<KNearest> knn = train_data;
	return knn;
} 


//SHOW
void result::print(Mat result) {
	if ((result.at<float>(0, 0) == 0)) {
		cout << "hyeon" << endl;
	}
	else if ((result.at<float>(0, 0) == 1)) {
		cout <<"Ss" << endl;
	}

	else if ((result.at<float>(0, 0) == 2)) {
		cout << "Irene" << endl;
	}

	else if ((result.at<float>(0, 0) == 3)) {
		cout << "Joy" << endl;
	}

	else if ((result.at<float>(0, 0) == 4)) {
		cout << "Wendy" << endl;
	}


};