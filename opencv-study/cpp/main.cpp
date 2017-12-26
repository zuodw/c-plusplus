#include "common.h"

#include "ColorDetector.h"
#include "Histogram1D.h"


int main()
{
	/*
	ColorDetector cdetect;

	Mat img_dota = imread(DOTA_IMG_PATH);

	if (!img_dota.data)
		return 0;

	cdetect.setTargetColor(130, 190, 230);

	imshow("result", cdetect.process(img_dota));
	*/

	/* 读取输入图像，灰度图 */
	Mat image_hist = imread(STAR_IMG_PATH, 0);
	/* Histogram对象 */
	Histogram1D h;
	/* 计算直方图 */
	MatND histo = h.getHistogram(image_hist);

	for (int i = 0; i < 256; i++)
	{
		cout << "Value" << i << "=" << histo.at<float>(i) << endl;
	}

	Mat hist_image = h.getHistogramImage(image_hist);


	imshow("test", hist_image);


	waitKey();
	return 0;

}