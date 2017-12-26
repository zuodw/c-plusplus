#include "ColorDetector.h"



ColorDetector::ColorDetector():minDist(100)
{
	target[0] = target[1] = target[2] = 0;
}


ColorDetector::~ColorDetector()
{
}

Mat ColorDetector::process(const Mat& img)
{
	result.create(img.cols, img.rows, CV_8U);

	Mat_<Vec3b>::const_iterator it = img.begin<Vec3b>();
	Mat_<Vec3b>::const_iterator itend = img.end<Vec3b>();
	Mat_<uchar>::iterator itout = result.begin<uchar>();

	for (; it != itend; ++it, ++itout)
	{
		if (getDistance(*it) < minDist)
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
	}
	return result;
}

void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0)
		distance = 0;
	minDist = distance;
}

int ColorDetector::getDistance(const Vec3b& color) const
{
	return abs(color[0] - target[0]) + abs(color[1] - target[1]) + abs(color[2] - target[2]);
}

int ColorDetector::getColorDistanceThreshold() const
{
	return minDist;
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	target[0] = blue;
	target[1] = green;
	target[2] = red;	
}

void ColorDetector::setTargetColor(Vec3b color)
{
	target = color;
}

Vec3b ColorDetector::getTargetColor() const
{
	return target;
}