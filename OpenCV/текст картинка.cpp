#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include "Source.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

Mat img;

int main()

{
	int height = 520;

	int width = 840;

	Mat img(height, width, CV_8UC3);

	Point textOrg(100, img.rows / 2);
	Point textOrg1(500, img.rows / 2);


	int fontFace = FONT_HERSHEY_COMPLEX;

	double fontScale = 3;

	Scalar color(0, 0, 205);

	putText(img, "aboba", textOrg, fontFace, fontScale, color);
	putText(img, "bibibob", textOrg1, fontFace, fontScale, color);

	namedWindow("Hello World", (0));
	imshow("Hello World", img);

	waitKey(0);

	return 0;
}
