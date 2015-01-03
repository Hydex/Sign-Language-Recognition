﻿// fourier transform main function 
#include "stdafx.h"
#include "fourier.h"



using namespace cv;

fourier::fourier(){
	//nothing to do
}


void fourier::readimg(string path){
	img_path = path;
	img = imread(path, CV_LOAD_IMAGE_COLOR);
	img_gray = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
	resize(img,img,cv::Size(img.cols/2,img.rows/2));
	resize(img_gray,img_gray,cv::Size(img_gray.cols/2,img_gray.rows/2));
	//imshow("",img);
	waitKey(0);
	if(img.empty())
		return ;

}

void fourier::RGBtoYCbCr(IplImage *img)
{
	CvScalar scalarImg;
	double cb, cr, y;
	for( int i = 0; i < img->height; i++ )
		for( int j = 0; j < img->width; j++ )
		{
			scalarImg = cvGet2D(img, i, j);   //從影像中取RGB值
			y =  (16 + scalarImg.val[2]*0.257 + scalarImg.val[1]*0.504 + scalarImg.val[0]*0.098);
			cb = (128 - scalarImg.val[2]*0.148 - scalarImg.val[1]*0.291 + scalarImg.val[0]*0.439);
			cr = (128 + scalarImg.val[2]*0.439 - scalarImg.val[1]*0.368 - scalarImg.val[0]*0.071);      
			cvSet2D(img, i, j, cvScalar( y, cr, cb));  //以YCbCr方式畫img
		}
}

void fourier::Skin_Color_Detection(IplImage *img)
{
	//================
	int avg_cb = 120;  //YCbCr顏色空間膚色cb的平均值
	int avg_cr = 155;  //YCbCr顏色空間膚色cr的平均值
	int skinRange = 22;  //YCbCr顏色空間膚色的範圍
	//================

	CvScalar scalarImg;
	double cb, cr;
	for( int i = 0; i < img->height; i++ )
	{
		for( int j = 0; j < img->width; j++ )
		{
			scalarImg = cvGet2D(img, i, j);
			cr = scalarImg.val[1];
			cb = scalarImg.val[2];
			if((cb > avg_cb-skinRange && cb < avg_cb+skinRange) && (cr > avg_cr-skinRange && cr < avg_cr+skinRange))
				cvSet2D(img, i, j, cvScalar( 255, 255, 255));
			else
				cvSet2D(img, i, j, cvScalar( 0, 0, 0));
		}
	}
}

void fourier::boundary(){
	Mat kernel = cv::Mat::ones(3, 3, CV_8U);
	Mat eroded;
	erode(img_gray, eroded, kernel);
	img_gray = img_gray - eroded;

	IplImage *tmp, *YCbCr_img;

	CvSeq* contour = 0;
	tmp = cvCloneImage(&(IplImage)img);
	YCbCr_img = cvCreateImage(cvGetSize(tmp), tmp->depth, tmp->nChannels);

	//========RGB2YCrCb==========
	cvCopy(tmp, YCbCr_img, NULL);
	RGBtoYCbCr(YCbCr_img);
	//==========================

	//==========skin color detection=========
	Skin_Color_Detection(YCbCr_img);

	img = Mat(YCbCr_img,0);


	//===========YCbCr轉灰階=============
	cvtColor(img,img_gray,CV_RGB2GRAY);


	//cvCvtColor( YCbCr_img, gray_img, CV_RGB2GRAY );
	//===========Find Contours & Draw=============
	
	Canny( img_gray, img_gray, 10, 10*2, 3 );
	/// Find contours
	findContours( img_gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	
	/// Draw contours
	Mat drawing = Mat::zeros( img_gray.size(), CV_8UC3 );

	vector<cv::Point> insertContours;
	for(unsigned int i = 0 ;i < contours.size();i++) {
		for (unsigned int j = 0; j < contours[i].size(); j++) {
			insertContours.push_back(contours[i][j]);
		}
	}
	contours_one.push_back(insertContours);

	cvReleaseImage(&YCbCr_img);
	cvReleaseImage(&tmp);
	//cvClearSeq(contour);
	//cvClearSeq(cont);
	//cvClearSeq(mcont);

	return;
}
void fourier::fourier_descriptor()
{
	vector<complex<float>> z (contours_one[0].size());
	//FD = vector<double>(128);
	vector<Point> p (contours_one[0].size());
	//point to complex
	for(unsigned int i = 0 ; i < contours_one[0].size() ; i++)
	{
		z[i]=complex<float>((float)contours_one[0][i].x,(float)contours_one[0][i].y);
	}
	contours_one_p.push_back(z);

	//dft
	dft(z,z);
	//cut 128 
	
	for(int i = 0 ; i < 64 ; i ++)
	{
		FD.push_back(z[i].real());
	}
	for(unsigned int i = z.size()-64 ; i < z.size() ; i ++)
	{
		FD.push_back(z[i].real());
	}
	

	/*
	dft(z,z,CV_DXT_INV_SCALE);
	//complex to point
	for(int i = 0 ; i < contours_one[0].size() ; i++)
	{
		p[i].x=z[i].real();
		p[i].y=z[i].imag();
	}
	vector<vector<Point> > contours_one_new;
	contours_one_new.push_back(p);

	//draw
	RNG rng(12345);
	Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		drawContours( img_gray, contours_one_new,0, color, 2, 8, hierarchy, 0, Point() );
	imshow("",img_gray);
	waitKey(0);


	system("pause");
	*/
	
}

void fourier::normalize()
{
	float min = 0, max = 0;
	float offset, d;

	// *****************7Hu Moments*****************
	for (unsigned int i = 0; i < FD.size(); ++i) {
		if (min > FD[i]) {
			min = FD[i];
		}
		if (max < FD[i]) {
			max = FD[i];
		}
	}

	offset = -min;

	for (unsigned int i = 0; i < FD.size(); ++i) {
		FD[i] += offset;
	}
	
	d = max - min;

	for (unsigned int i = 0; i < FD.size(); ++i) {
		FD[i] /= d;
	}
	// *****************End*****************
}

vector<float> fourier::get_vector()
{
	return FD;
}

void fourier::clear_vector()
{
	FD.clear();
	contours.clear();
	contours_one_p.clear();
	contours_one.clear();
	inverse_contours.clear();
	hierarchy.clear();
}

void fourier::image_process (Mat in_image)
{
	img = in_image;
	
	clear_vector();
	cvtColor(img,img_gray,CV_RGB2GRAY);
	//boundary of binary image , find contour
	boundary();

	//fourier 
	fourier_descriptor();
	normalize();
	//write transform to txt
	char filename[]="fourier.txt";
    FILE * fp = fopen(filename, "a ");//開啟檔案
    if(!fp){//如果開啟檔案失敗，fp為0；成功，fp為非0
        cout<<"Fail to open file: "<<filename<<endl;
    }
    cout<<"File Descriptor: "<<fp<<endl;
	for(int i = 0 ; i < FD.size() ; i++)
	{
		fprintf (fp, "%f ", FD[i] );
	}
	fprintf (fp, "\n");

	fclose (fp);
}

