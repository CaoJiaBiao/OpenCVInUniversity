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

//定义全局变量
Mat g_srcImage;         //定义输入图像
Mat g_dstImage;         //定义目标图像

const int g_nTrackbarMaxValue = 9;      //定义轨迹条最大值
int g_nTrackbarValueM;                   //定义轨迹条初始值
int g_nTrackbarValueN;                   //定义轨迹条初始值
int g_nKernelValueM=1;                   //定义kernel尺寸
int g_nKernelValueN=10;                  //定义kernel尺寸

void on_kernelTrackbarM(int, void*);     //定义回调函数
void on_kernelTrackbarN(int, void*);     //定义回调函数

int main()
{
	g_srcImage = imread("C:\\Users\\JiaBiao\\Documents\\Visual Studio 2017\\Project2017\\OpenCvPic\\chrome1.png");

	//判断图像是否加载成功
	if (g_srcImage.empty())
	{
		cout << "图像加载失败!" << endl;
		return -1;
	}
	else
		cout << "图像加载成功!" << endl << endl;

	namedWindow("原图像", WINDOW_AUTOSIZE);     //定义窗口显示属性
	imshow("原图像", g_srcImage);

	//g_nTrackbarValueM = 1;
	//g_nTrackbarValueN = 10;
	namedWindow("均值滤波", WINDOW_AUTOSIZE);   //定义滤波后图像显示窗口属性

	//定义轨迹条名称和最大值
	char kernelNameM[20];
	sprintf(kernelNameM, "M尺寸 %d", g_nTrackbarMaxValue); 
	

	//创建轨迹条M "均值滤波"是指窗口名
	createTrackbar(kernelNameM, "均值滤波", &g_nTrackbarValueM, g_nTrackbarMaxValue, on_kernelTrackbarM);
	on_kernelTrackbarM(g_nTrackbarValueM, 0);

	char kernelNameN[20];
	sprintf(kernelNameN, "N尺寸 %d", g_nTrackbarMaxValue);
	createTrackbar(kernelNameN, "均值滤波", &g_nTrackbarValueN, g_nTrackbarMaxValue, on_kernelTrackbarN);
	
	on_kernelTrackbarN(g_nTrackbarValueN, 0);

	//保存按钮
	//createButton("保存", on_SaveButton_Clicked);
	//createButton()
	//cv::Mat frame = cv::Mat(200, 500, CV_8UC3);
	//cvui::button(frame, 110, 80, "Hello, world!");	
	waitKey(0);
	imwrite("保存的图像.png", g_dstImage);
	return 0;
}
void on_SaveButton_Clicked()
{

}
void on_kernelTrackbarM(int, void*)
{
	//根据输入值重新计算kernel尺寸
	g_nKernelValueM = g_nTrackbarValueM * 2 + 1;

	//均值滤波函数
	blur(g_srcImage, g_dstImage, Size(g_nKernelValueM, g_nKernelValueN));

	imshow("均值滤波", g_dstImage);
}
void on_kernelTrackbarN(int, void*)
{
	//根据输入值重新计算kernel尺寸
	g_nKernelValueN = g_nTrackbarValueN * 2 + 1;

	//均值滤波函数
	blur(g_srcImage, g_dstImage, Size(g_nKernelValueM, g_nKernelValueN));

	imshow("均值滤波", g_dstImage);
}