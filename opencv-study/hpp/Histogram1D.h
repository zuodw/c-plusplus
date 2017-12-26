#pragma once

#include "common.h"

class Histogram1D
{
private:
	int histSize[1];//项的数量
	float hranges[2];//像素的最小及最大值
	const float* ranges[1];
	int channels[1];

public:
	Histogram1D();
	~Histogram1D();

	MatND getHistogram(const Mat &image);
	Mat getHistogramImage(const Mat &image);

};

