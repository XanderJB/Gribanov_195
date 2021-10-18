#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace cv;
using namespace std;

int Main()
{
	//��������� ��� ������ ��� ��������
	setlocale(LC_ALL, "Russian");

	char filename[100]; //video
	cout << "������� ��� �����, ������� ������ �������, � ������� Enter" << endl;
	cin.getline(filename, 100);
	cout << "������ ���� ";
	cout << filename << endl;

	VideoCapture cap(filename);
	if (!cap.isOpened()) { cout << "������ �������� ����� "; return -1; }
	Mat im;
	for (;;)
	{
		Mat mat, frame;
		cap >> frame;
		mat = frame;
		if (mat.empty()) break;

		imshow("�������������", frame);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}
