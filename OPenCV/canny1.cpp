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
	char filename[80]; //ввод в консоль имени изображени€
	cout << "¬ведите им€ файла и нажмите Enter" << endl;
	cin.getline(filename, 80);
	cout << "ќткрыт файл "; // программа показывает, какое изображение она открыла
	cout << filename << endl;

	Mat img = imread(filename, 1);

	namedWindow("»сходное изображение", WINDOW_AUTOSIZE); //изображение, которое мы загрузили в программу
	imshow("»сходное изображение", img);

	Mat src_gray;
	Mat canny_output;

	cvtColor(img, src_gray, COLOR_RGB2GRAY); // перевод изображени€ в чб
	imwrite("cvtColor.jpg", src_gray);  //сохранение чб изображение 
	blur(src_gray, src_gray, Size(2, 2)); // размер размыти€ изображени€
	imwrite("blur.jpg", src_gray); // сохранение изображени€ с размытием 

	double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU); //с помощью BINARY все цвета изображени€ станов€тс€ бинарными(остаетс€ два начальных цвета - черный и белый => участок с четным числом становитс€ белым, с нечетным черным)
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5; //числа, обозначающие цвет, дел€тс€ на 2 и тем самым нечетные цвета стали черными из-за остатка, а четные белыми

	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3); // пропуск изображени€ через фильтр Canny


	namedWindow("—ерое изображение", WINDOW_AUTOSIZE); //вывод на экран обработанного изображени€
	imshow("—ерое изображение", canny_output);
	imwrite("canny_output.jpg", canny_output); // название изображени€, обработанного с помощью Canny
	
	Mat contour;
	RNG rng(12345); // rng генерирует случайное число контуров
	vector<vector<Point>> contours;//вычисление координат векторов
	vector<Vec4i>hierarchy;//вычисление векторов в пор€дке возрастани€

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); // св€зь с оператором Canny (вроде так пон€л)

	vector<Moments> mu(contours.size());  //определение темной зоны на изображении и зоны, где будет проведен вектор
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false); // при  значении false участок изображени€ остаетс€ черным
	}

	vector<Point2f> mc(contours.size()); //определение координат точки вектора
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);// тут задаютс€ координаты, где будет расположена точка и куда проведен вектор
	}

	for (int i = 0; i < contours.size(); i++) 
	{
		printf(" онтур є %d: центр масс - х = %.2f y = %.2f; длина - %.2f\n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true)); // вывод в консоль номер вектора, координаты точки (центр масс) и его длину
	}

	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); // CV_8UC3 - 3-канальное изображение
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)); //участки, попавшие в диапазон rng, окашиваютс€ определенным цветом
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point()); //рисование контуров изображени€
		circle(drawing, mc[i], 4, color, -1, 5, 0); // рисование точек вектора
	}
	namedWindow(" онтуры", WINDOW_AUTOSIZE);
	imshow(" онтуры", drawing);

	waitKey(0);
	return 0;
}