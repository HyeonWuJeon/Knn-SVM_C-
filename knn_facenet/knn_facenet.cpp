#define _CRT_SECURE_NO_WARNINGS
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Readdata.h"
#include "Training.h"
#include "result.h"
#include "knn_train.h"
#include "Imageoutput.h"
#include"npy.hpp"

//Main function
using namespace cv;
using namespace cv::ml;
using namespace std;

Ptr<KNearest> train_knn();
void on_k_changed(int, void*);
int k_value = 1;
void trainAndDisplay();

int main()
{
	Mat img_float, img_flatten, img_resize, train_images, train_labels;
	string path_test = "C:/Users/tkawn/Desktop/test/irene2.jpg"; //Test file

	string path_train[30] = { "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting0.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting1.jpg",
			"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting2.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting3.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting4.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting5.jpg",
		"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting6.jpg", "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting7.jpg",
			"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting8.jpg",  "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting9.jpg",
		 "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting10.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting11.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting12.jpg",
		"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting13.jpg",
		 "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting14.jpg",  "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting15.jpg",
		 "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting16.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting17.jpg",
		"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting18.jpg", "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting19.jpg",
	 "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting20.jpg",  "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting21.jpg",
	 "H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting22.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting23.jpg",
		"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting24.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting25.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting26.jpg",
	"H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting27.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting28.jpg","H:/workspace/cplusplus_opencv/Casecadenet/dataset/Image/setting29.jpg" };


	//ml::Training
	//////////////////////////////////////////////////////////////////////////////////////
	knn_train Knn(train_images, train_labels, path_train); //Training file handling  class  Mat filename = filepath
	vector<Mat>train_a; //Training File Read vector
	Knn.data(train_a); // reference Vector, function format : "Void" (&v)
	Mat train_last; 
	train_last.push_back(Knn.train_img(train_a)); //Return Training complete : Data
	Mat train_label_a;
	train_label_a.push_back(Knn.train_label()); // Return Training complete : Label
	Ptr<KNearest> knn = Knn.knn_t(train_last, train_label_a); //Knn Training completed!!! 
	////////////////////////////////////////////////////////////////////////////////////
	
	
	//ml::Test
	///////////////////////////////////////////////////////////////////////////////////
	Image_output output(path_test); //Bring test File class

	result test(img_float, img_flatten, img_resize, path_test); //TestFile handling.
	//result test();
	Mat src = output.src(); //Bring Testfile in the Mat format. Mat filename = filepath

	// Harr-classifier
	CascadeClassifier classifier("H:/workspace/cplusplus_opencv/Casecadenet/dataset/haarcascade_frontalface_default.xml"); 
	if (classifier.empty()) {
		cerr << "XML load failed!" << endl;

	}
	//If Test file is not Face Region  execute this line
	vector<Rect> faces;
	classifier.detectMultiScale(src, faces);
	Mat D; 
	for (Rect rc : faces) {
		//rectangle(src, rc, Scalar(255, 0, 255), 2);
		D = src(rc); //Face 
		//imshow("src", D);

	}
	Training last(img_float,img_flatten,img_resize);  //Test - traing class
	Mat r_img_flatten = last.training(D); //Testfile Training completed!
	


	
	Mat result(0, 0, CV_32F);
	knn->findNearest(r_img_flatten, k_value, result); 
	test.print(result); // Show !! Who u r?

	namedWindow("src", 0);
;
	imshow("src", D);
	createTrackbar("k", "src", &k_value, 5, on_k_changed);

	waitKey(0);

	return 0;

}



void on_k_changed(int, void*)
{
	if (k_value < 1) k_value = 1;
	trainAndDisplay();
}


void trainAndDisplay() { 
	cout << "Change kvalue value : " << k_value << endl;
	main();
}

