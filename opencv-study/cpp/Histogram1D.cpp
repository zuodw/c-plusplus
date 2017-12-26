#include "Histogram1D.h"



Histogram1D::Histogram1D()
{
	histSize[0] = 256;
	hranges[0] = 0.0;
	hranges[1] = 255.0;
	ranges[0] = hranges;
	channels[0] = 0;
}


Histogram1D::~Histogram1D()
{
}

MatND Histogram1D::getHistogram(const Mat &image)
{
	MatND hist;
	//计算直方图
	calcHist(&image,
		1,				//计算单张图像的直方图
		channels,		//通道数量
		Mat(),			//不使用图像作为掩码
		hist,			//返回的直方图
		1,				//这是1D的直方图
		histSize,		//项的数量
		ranges			//像素值的范围
	);
	return hist;
}

Mat Histogram1D::getHistogramImage(const Mat &image)
{
	//首先计算直方图
	MatND hist = getHistogram(image);
	//获取最大值和最小值
	double maxVal = 0;
	double minVal = 0;
	minMaxLoc(hist, &minVal, &maxVal, 0, 0);
	//显示直方图的图像
	Mat histImage(histSize[0], histSize[0], CV_8U, Scalar(255));
	//设置最高点为nbins的90%
	int hpt = static_cast<int>(0.9 * histSize[0]);
	//每个条目都绘制一条垂直线
	for (int h = 0; h < histSize[0]; h++)
	{
		float binVal = hist.at<float>(h);
		int intensity = static_cast<int>(binVal * hpt / maxVal);
		//两点之间绘制一条直线
		line(histImage, Point(h, histSize[0]), Point(h, histSize[0] - intensity), Scalar::all(0));
	}
	return histImage;
}