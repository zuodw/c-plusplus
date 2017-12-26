#include "common.h"

void sharpen2D(Mat& img, Mat& result)
{
	//构造核
	Mat kernel(3, 3, CV_32F, Scalar(0));

	//对核元素进行赋值
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;

	//对图像进行滤波
	filter2D(img, result, img.depth(), kernel);
}