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
	char filename[80]; //картинка
	cout << "Введите имя файла, в который хотите внести изменения и нажмите Enter" << endl;
	cin.getline(filename, 80);
	cout << "Открыт файл";
	cout << filename << endl;

	Mat img = imread(filename, 1);

	namedWindow("Исходное изображение", WINDOW_AUTOSIZE);
	imshow("Исходное изображение", img);

	waitKey(0);
	return 0;
}