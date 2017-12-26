#include "common.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


int threshval = 5;
void on_threshold_track_bar(int, void*);


void threshold_test()
{
	namedWindow("threshold_test");
	createTrackbar("threshold", "threshold_test", &threshval, 100, on_threshold_track_bar);
	on_threshold_track_bar(threshval, NULL);
	waitKey();
}

void on_threshold_track_bar(int, void*)
{
	Mat img = imread(DOTA_IMG_PATH, CV_LOAD_IMAGE_GRAYSCALE);
	if (img.empty())
	{
		cout << "read image failed!" << endl;
		return;
	}
	//全局二值化
	Mat global_img;
	threshold(img, global_img, threshval, 255, CV_THRESH_BINARY_INV);
	imshow("threshold_test", global_img);
}	