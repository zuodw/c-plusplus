#include "common.h"

void colorReduce(Mat& img, int div)
{
	/* 行数 */
	int nl = img.rows;
	/* 每行的元素个数 */
	int nc = img.cols * img.channels();

	for (int j = 0; j < nl; j++)
	{
		/* 得到第j行的首地址 */
		uchar* data = img.ptr<uchar>(j);	/* Mat提供模板函数ptr，可以得到任意行的首地址 */
		for (int i = 0; i < nc; i++)
		{
			/* 处理每一个元素 */
			data[i] = data[i] / div * div + div / 2;
			/* 像素处理完成 */
		}/* 行处理完成 */
	}
}