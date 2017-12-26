#include "common.h"

void blur_canny(void)
{
	Mat srcImg = imread(CELL_IMG_PATH);
	imshow("srcImg", srcImg);

	Mat dstImg, edge, grayImg;

	//创建与src同类型和同大小的矩阵
	dstImg.create(srcImg.size(), srcImg.type());

	//将原始图转化为灰度图
	cvtColor(srcImg, grayImg, COLOR_BGR2GRAY);

	//先使用3*3内核来降噪
	blur(grayImg, edge, Size(3, 3));

	//运行canny算子
	Canny(edge, edge, 3, 9, 3);

	imshow("边缘提取效果", edge);
}