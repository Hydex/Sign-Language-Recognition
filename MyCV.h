#pragma once

#include <vector>
#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\features2d\features2d.hpp"
#include "opencv2\nonfree\features2d.hpp"
#include "opencv2\nonfree\nonfree.hpp"
#include "opencv2\ml\ml.hpp"
#include <opencv2/opencv.hpp>
#include "opencv\cv.h"

using namespace std;
using namespace cv;

class MyCV
{
public:
	MyCV();
	System::Drawing::Bitmap^ getBitmap();
	System::Drawing::Bitmap^ getOtherBitmap(cv::Mat cvImage);
	void RGBtoYCbCr(IplImage *img);
	void Skin_Color_Detection(IplImage *img);
	void HuMoment();
	void calHistogram(int histSize, const float* histRange);
	void detectSIFT();
	void readImage(std::string fileName);
	void readFrame(Mat frame);
	void img_preproc();
	void set_bg_frame();
	Mat getImage();
	vector<float> getHuVector();
	vector<float> getHistVector();
	vector<float> getSiftVector();
	void clear();

private:
	Mat cvImage;
	Mat skin;
	Mat first_frame;
	CvHuMoments HuMoments; 
	vector<float> huVector;
	vector<float> histVector;
	vector<float> siftVector;
};