

//Train 
//C++ npy file load = C:\Users\tkawn\Desktop\libnpy-master
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Readdata.h"
#include "knn_train.h"
using namespace cv;
using namespace cv::ml;
using namespace std;
Mat knn_train::train_img(vector<Mat>& images) { // Recive training File
	
	vector<Mat> D;
	for (int i = 0; i < 30; i++) {
		D.push_back(images.at(i));
		cout <<"src : " << D[i].size() << endl;
		/*
		CascadeClassifier classifier("H:/workspace/cplusplus_opencv/Casecadenet/dataset/haarcascade_frontalface_default.xml"); //Harr-Classifier
		if (classifier.empty()) {
			cerr << "XML load failed!" << endl;
		}
		*/
	}
	/* Save face region 
		vector<Rect> faces;
		classifier.detectMultiScale(src, faces);	
		for (Rect rc : faces) { 
			rectangle(src, rc, Scalar(255, 0, 255), 2); region BOX
			D.push_back(src(rc)); //Save Face region
			cout << D[i].size << endl;
		}
	}
	*/
	Mat s[30];
	for (int i = 0; i < 30; i++) {
		resize(D[i], s[i], Size(200, 200), 0, 0); //Regulization
		result.push_back(s[i]);// Input Vector
	}


		Mat roi[30], roi_float[30], roi_flatten[30];
		for (int j = 0; j < 30; j++) { 
			roi[j] = result.at(j);
			roi[j].convertTo(roi_float[j], CV_32F); // Change Float format
			roi_flatten[j] = roi_float[j].reshape(1, 1); // Save Row vector

			train_images.push_back(roi_flatten[j]); 


		}
	return train_images;

}

Mat knn_train::train_label() {
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 6; i++) 
		{
			train_labels.push_back(j % 6);
		}
	}

	return train_labels;
}

Ptr<KNearest> knn_train::knn_t(Mat train_images, Mat train_labels) {
	Ptr<KNearest> knn = KNearest::create();
	knn->train(train_images, ROW_SAMPLE, train_labels);

	return knn;
}
