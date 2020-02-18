#include "Imageoutput.h"
// After Reading Imagepath, Return <Mat class>image;  
Mat Image_output::src() {
	image = imread(path);
	if (image.empty()) {
		cerr << "image load failed!!" << endl;
	}
	return image;
}
