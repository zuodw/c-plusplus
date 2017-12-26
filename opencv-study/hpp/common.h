#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

#define CELL_IMG_PATH "C:/Users/zuodw/Desktop/picture/cell2.jpg"
#define CIRCLE_IMG_PATH "C:/Users/zuodw/Desktop/picture/circle.jpg"
#define TEST_IMG_PATH "C:/Users/zuodw/Desktop/picture/opencv_test.png"
#define COLOR_IMG_PATH "C:/Users/zuodw/Desktop/picture/color.png"
#define AAA_IMG_PATH "C:/Users/zuodw/Desktop/picture/111.jpg"
#define DOTA_IMG_PATH "C:/Users/zuodw/Desktop/picture/dota.png"
#define LOGO_IMG_PATH "C:/Users/zuodw/Desktop/picture/dota_logo.png"
#define STAR_IMG_PATH "C:/Users/zuodw/Desktop/picture/star.jpg"
#define MONSTER_IMG_PATH "C:/Users/zuodw/Desktop/picture/monster.jpg"



void circle(void);
void test_cell(void);
void threshold_test(void);
void blur_canny(void);
void colorReduce(Mat& img, int div=64);
void sharpen(Mat& img, Mat& result);
void sharpen2D(Mat& img, Mat& result);