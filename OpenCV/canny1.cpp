#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/imgcodecs.hpp>


using namespace cv;
using namespace std;

Mat img;

int main()

{
	setlocale(LC_ALL, "Russian");
	char filename[80]; //��������
	cout << "������� ��� �����, � ������� ������ ������ ��������� � ������� Enter" << endl;
	cin.getline(filename, 80);
	cout << "������ ����";
	cout << filename << endl;

	Mat img = imread(filename, 1);

	namedWindow("�������� �����������", WINDOW_AUTOSIZE);
	imshow("�������� �����������", img);

	waitKey(0);
	return 0;
}