#ifndef KNN_TRAIN_H
#define KNN_TRAIN_H
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Readdata.h"
using namespace cv;
using namespace cv::ml;
using namespace std;



class knn_train : public Readdata {
	Mat train_images, train_labels;
	Mat s[30]; 
	vector<Mat> result;
	vector<Mat>D;

public:
	knn_train(Mat train_images, Mat train_labels, string path[]) : Readdata(path) { this->train_images = train_images, this->train_labels = train_labels; }


	Mat train_img( vector<Mat> &v);
	
	Mat train_label();
	//Make Knn data, Return Knn
	Ptr<KNearest> knn_t(Mat train_images, Mat train_labels); 

};


#endif