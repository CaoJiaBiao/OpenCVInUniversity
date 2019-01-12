#include"highgui.h"
int main2() {
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	CvCapture *capture = cvCreateFileCapture("F:\\迅雷下载\\飞越疯人院BD双语双字[电影天堂www.dy2018.com].mkv");


	IplImage * frame;
	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(30);
		if (c == 27)break;

	}
	
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
	return 0;
}