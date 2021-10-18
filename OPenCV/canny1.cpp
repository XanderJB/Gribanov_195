#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Source.h"


using namespace cv;
using namespace std;

Mat img;

int main()

{
	setlocale(LC_ALL, "Russian");
	char filename[80]; //���� � ������� ����� �����������
	cout << "������� ��� ����� � ������� Enter" << endl;
	cin.getline(filename, 80);
	cout << "������ ���� "; // ��������� ����������, ����� ����������� ��� �������
	cout << filename << endl;

	Mat img = imread(filename, 1);

	namedWindow("�������� �����������", WINDOW_AUTOSIZE); //�����������, ������� �� ��������� � ���������
	imshow("�������� �����������", img);

	Mat src_gray;
	Mat canny_output;

	cvtColor(img, src_gray, COLOR_RGB2GRAY); // ������� ����������� � ��
	imwrite("cvtColor.jpg", src_gray);  //���������� �� ����������� 
	blur(src_gray, src_gray, Size(2, 2)); // ������ �������� �����������
	imwrite("blur.jpg", src_gray); // ���������� ����������� � ��������� 

	double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU); //� ������� BINARY ��� ����� ����������� ���������� ���������(�������� ��� ��������� ����� - ������ � ����� => ������� � ������ ������ ���������� �����, � �������� ������)
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5; //�����, ������������ ����, ������� �� 2 � ��� ����� �������� ����� ����� ������� ��-�� �������, � ������ ������

	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3); // ������� ����������� ����� ������ Canny


	namedWindow("����� �����������", WINDOW_AUTOSIZE); //����� �� ����� ������������� �����������
	imshow("����� �����������", canny_output);
	imwrite("canny_output.jpg", canny_output); // �������� �����������, ������������� � ������� Canny
	
	Mat contour;
	RNG rng(12345); // rng ���������� ��������� ����� ��������
	vector<vector<Point>> contours;//���������� ��������� ��������
	vector<Vec4i>hierarchy;//���������� �������� � ������� �����������

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); // ����� � ���������� Canny (����� ��� �����)

	vector<Moments> mu(contours.size());  //����������� ������ ���� �� ����������� � ����, ��� ����� �������� ������
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false); // ���  �������� false ������� ����������� �������� ������
	}

	vector<Point2f> mc(contours.size()); //����������� ��������� ����� �������
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);// ��� �������� ����������, ��� ����� ����������� ����� � ���� �������� ������
	}

	for (int i = 0; i < contours.size(); i++) 
	{
		printf("������ � %d: ����� ���� - � = %.2f y = %.2f; ����� - %.2f\n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true)); // ����� � ������� ����� �������, ���������� ����� (����� ����) � ��� �����
	}

	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); // CV_8UC3 - 3-��������� �����������
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)); //�������, �������� � �������� rng, ����������� ������������ ������
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point()); //��������� �������� �����������
		circle(drawing, mc[i], 4, color, -1, 5, 0); // ��������� ����� �������
	}
	namedWindow("�������", WINDOW_AUTOSIZE);
	imshow("�������", drawing);

	waitKey(0);
	return 0;
}