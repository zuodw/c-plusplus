#pragma once

#include "common.h"

class ColorDetector
{
public:
	ColorDetector();
	~ColorDetector();

	Mat process(const Mat& img);

	void setColorDistanceThreshold(int distance);

	int getColorDistanceThreshold() const;

	void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
	void setTargetColor(Vec3b color);

	Vec3b getTargetColor() const;



private:
	//最小可接受距离
	int minDist;
	//目标色
	Vec3b target;
	//结果图像
	Mat result;

	int getDistance(const Vec3b& color) const;
};

