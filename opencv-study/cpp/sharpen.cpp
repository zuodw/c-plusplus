#include "common.h"

void sharpen(Mat& img, Mat& result)
{
	result.create(img.size(), img.type());

	for (int j = 1; j < img.rows - 1; j++)
	{
		const uchar* previous = img.ptr<const uchar>(j - 1);
		const uchar* current = img.ptr<const uchar>(j);
		const uchar* next = img.ptr<const uchar>(j + 1);

		uchar* output = result.ptr<uchar>(j);
		
		for (int i = 1; i < img.cols - 1; i++)
		{
			/* saturate_cast:–hŽ~”˜ˆìo */
			*output++ = saturate_cast<uchar>(5*current[i] - current[i - 1] - current[i + 1] -previous[i] - next[i]);
		}
	}

	result.row(0).setTo(Scalar(0));
	result.row(result.rows - 1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols - 1).setTo(Scalar(0));
}
