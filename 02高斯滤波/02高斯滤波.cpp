#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include "C:\\Users\\JiaBiao\\Documents\\Visual Studio 2017\\Project2017\\OpenCVCVGUI\\cvui-2.0.0\\cvui.h"

using namespace std;
using namespace cv;
void main() {
	Mat image = imread("C:\\Users\\JiaBiao\\Documents\\Visual Studio 2017\\Project2017\\OpenCvPic\\΢��ͼƬ_20180509173955.tif");
	//Mat salt_image;
	//image.copyTo(salt_image);

	Mat image1;
	GaussianBlur(image, image1, Size(3, 3), 1);

	imshow("ԭͼ", image);
	//imshow("�޽��λ�ͼ", salt_image);
	imshow("opencv�Դ��ĸ�˹�˲�", image1);
	waitKey();
}
