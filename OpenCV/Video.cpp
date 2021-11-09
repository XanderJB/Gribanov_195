#include "opencv2/highgui/highgui.hpp"
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

void Video(string filename)
{
	VideoCapture cap(filename);
	if (!cap.isOpened()) { cout << "Ошибка открытия файла "; return -1; }
	Mat im;
	for (;;)
	{
		Mat mat, frame;
		cap >> frame;
		mat = frame;
		if (mat.empty()) break;

		imshow("Распознавание", frame);
		if (waitKey(30) >= 0) break;
	}	
}

int main()
{
	//установка рус локали для консоли
	setlocale(LC_ALL, "Russian");
	
	char filename[100]; //video
	cout << "Введите имя файла, который хотите открыть, и нажмите Enter" << endl;
	cin.getline(filename, 100);
	cout << "Открыт файл ";
	cout << filename << endl;
	Video(filename);
	
	return 0;
}
