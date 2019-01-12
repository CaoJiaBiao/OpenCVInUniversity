#include"highgui.h"
int main() {
	IplImage * img = cvLoadImage("C:\\Users\\JiaBiao\\Documents\\Visual Studio 2017\\Project2017\\OpenCvPic\\timg.tif");
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
	return 0;
}