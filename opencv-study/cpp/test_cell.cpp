#include "common.h"


/** Function Headers */

/** Global Variables */

Mat rgbImage, hsvImage;

void test_cell()
{
	namedWindow("RGB");
	namedWindow("HSV");
	namedWindow("HSV_1");

	rgbImage = imread(AAA_IMG_PATH);
	imshow("RGB", rgbImage);
	cvtColor(rgbImage, hsvImage, CV_BGR2HSV);
	imshow("HSV", hsvImage);

	bool isHMatch = false, isSMatch = false, isVMatch = false;

	for (int y = 0; y < rgbImage.rows; y++)
	{
		for (int x = 0; x < rgbImage.cols; x++)
		{
			isHMatch = hsvImage.at<Vec3b>(y, x)[0] > 35 && hsvImage.at<Vec3b>(y, x)[0] < 75;
			isSMatch = hsvImage.at<Vec3b>(y, x)[1] > 43 && hsvImage.at<Vec3b>(y, x)[1] < 255;
			isVMatch = hsvImage.at<Vec3b>(y, x)[2] > 46 && hsvImage.at<Vec3b>(y, x)[2] < 255;
			if (!isHMatch || !isSMatch || !isVMatch)
			{
				hsvImage.at<Vec3b>(y, x)[0] = 0;
				hsvImage.at<Vec3b>(y, x)[1] = 0;
				hsvImage.at<Vec3b>(y, x)[2] = 0;
			}
		}
	}
	//cvtColor(hsvImage, rgbImage, CV_HSV2BGR);
	imshow("HSV_1", hsvImage);

	Mat dstImage;
	addWeighted(rgbImage, 0.5, hsvImage, 0.5, 0, dstImage);
	imshow("aaa", dstImage);
	


	waitKey();

}
