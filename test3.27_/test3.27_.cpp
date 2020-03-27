// test3.27_.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;



	cap.open(0);

	while (1)
	{
		Mat frame;
		Mat dst_mB;
		Mat dst_blur;
		Mat dst_GB;
		Mat dst_sobelx;
		Mat dst_sobely;
		cap >> frame;
		bool rSucess = cap.read(frame);
		medianBlur(frame, dst_mB, 3);
		blur(frame, dst_blur, Size(3, 3));
		GaussianBlur(frame, dst_GB, Size(3, 3), 1, 0);
		Sobel(frame, dst_sobelx, CV_16SC1, 1, 0, 3);
		convertScaleAbs(dst_sobelx, dst_sobelx);
		Sobel(frame, dst_sobely, CV_16SC1, 0, 1, 3);
		convertScaleAbs(dst_sobely, dst_sobely);

		imshow("frame", frame);            //原图
		namedWindow("dst_mB", 0);
		imshow("dst_mB", dst_mB);			//中值滤波
		imshow("dst_blur", dst_blur);		//均值滤波
		imshow("dst_GB", dst_GB);		 //均值滤波-高斯
		imshow("dst_sobelx", dst_sobelx);		//边缘提取-x
		imshow("dst_sobely", dst_sobely);		//边缘提取-y

		waitKey(30);
	}
	return 0;
}

