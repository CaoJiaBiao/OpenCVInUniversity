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

//����ȫ�ֱ���
Mat g_srcImage;         //��������ͼ��
Mat g_dstImage;         //����Ŀ��ͼ��

const int g_nTrackbarMaxValue = 9;      //����켣�����ֵ
int g_nTrackbarValueM;                   //����켣����ʼֵ
int g_nTrackbarValueN;                   //����켣����ʼֵ
int g_nKernelValueM=1;                   //����kernel�ߴ�
int g_nKernelValueN=10;                  //����kernel�ߴ�

void on_kernelTrackbarM(int, void*);     //����ص�����
void on_kernelTrackbarN(int, void*);     //����ص�����

int main()
{
	g_srcImage = imread("C:\\Users\\JiaBiao\\Documents\\Visual Studio 2017\\Project2017\\OpenCvPic\\chrome1.png");

	//�ж�ͼ���Ƿ���سɹ�
	if (g_srcImage.empty())
	{
		cout << "ͼ�����ʧ��!" << endl;
		return -1;
	}
	else
		cout << "ͼ����سɹ�!" << endl << endl;

	namedWindow("ԭͼ��", WINDOW_AUTOSIZE);     //���崰����ʾ����
	imshow("ԭͼ��", g_srcImage);

	//g_nTrackbarValueM = 1;
	//g_nTrackbarValueN = 10;
	namedWindow("��ֵ�˲�", WINDOW_AUTOSIZE);   //�����˲���ͼ����ʾ��������

	//����켣�����ƺ����ֵ
	char kernelNameM[20];
	sprintf(kernelNameM, "M�ߴ� %d", g_nTrackbarMaxValue); 
	

	//�����켣��M "��ֵ�˲�"��ָ������
	createTrackbar(kernelNameM, "��ֵ�˲�", &g_nTrackbarValueM, g_nTrackbarMaxValue, on_kernelTrackbarM);
	on_kernelTrackbarM(g_nTrackbarValueM, 0);

	char kernelNameN[20];
	sprintf(kernelNameN, "N�ߴ� %d", g_nTrackbarMaxValue);
	createTrackbar(kernelNameN, "��ֵ�˲�", &g_nTrackbarValueN, g_nTrackbarMaxValue, on_kernelTrackbarN);
	
	on_kernelTrackbarN(g_nTrackbarValueN, 0);

	//���水ť
	//createButton("����", on_SaveButton_Clicked);
	//createButton()
	//cv::Mat frame = cv::Mat(200, 500, CV_8UC3);
	//cvui::button(frame, 110, 80, "Hello, world!");	
	waitKey(0);
	imwrite("�����ͼ��.png", g_dstImage);
	return 0;
}
void on_SaveButton_Clicked()
{

}
void on_kernelTrackbarM(int, void*)
{
	//��������ֵ���¼���kernel�ߴ�
	g_nKernelValueM = g_nTrackbarValueM * 2 + 1;

	//��ֵ�˲�����
	blur(g_srcImage, g_dstImage, Size(g_nKernelValueM, g_nKernelValueN));

	imshow("��ֵ�˲�", g_dstImage);
}
void on_kernelTrackbarN(int, void*)
{
	//��������ֵ���¼���kernel�ߴ�
	g_nKernelValueN = g_nTrackbarValueN * 2 + 1;

	//��ֵ�˲�����
	blur(g_srcImage, g_dstImage, Size(g_nKernelValueM, g_nKernelValueN));

	imshow("��ֵ�˲�", g_dstImage);
}