#include <math.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stack>
using namespace cv;
using namespace std;
typedef struct Point2{
	int x;
	int y;
};
Point2 b;
int flag = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		b.x = y;
		b.y = x;
		std::cout << b.x << endl;
		std::cout << b.y << endl;
		flag = 1;
	}
}
int main()
{
	Mat var1 = imread("shapes.jpg", 1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC3, Scalar(0,0,0));
	stack <Point2> S;
	Point2 a;
	int i, j;
/*	b.x = 286;
	b.y = 388;
	i = b.x;
	j = b.y;*/
	//std::cout << i << endl;
	//std::cout << j<< endl;

	namedWindow("My Window", 1);
	setMouseCallback("My Window", CallBackFunc, NULL);
	imshow("My Window", var1);
	//b.x = 286;
	//b.y = 388;
	/*i = b.x;
	j = b.y;*/

	while (1)
	{
		if (flag == 1){
			i = b.x;
			j = b.y;
			flag = 0;
			S.push(b);
			var2.at<uchar>(i, j) = 255;
			var3.at<Vec3b>(i, j)[0] = 255;

			while (S.empty() == 0)
			{
				a = S.top();
				S.pop();
				if (a.x - 1 >= 0)
				{
					if (a.y - 1 >= 0)
					{
						if (var1.at<Vec3b>(a.x - 1, a.y - 1)[0] == 255 && var1.at<Vec3b>(a.x - 1, a.y - 1)[0] == 255 && var1.at<Vec3b>(a.x - 1, a.y - 1)[0] == 255 && var2.at<uchar>(a.x - 1, a.y - 1) == 0)
						{
							b.x = a.x - 1;
							b.y = a.y - 1;
							S.push(b);
							var2.at<uchar>(a.x - 1, a.y - 1) = 255;
							var3.at<Vec3b>(a.x - 1, a.y - 1)[0] = 255;
						}
					}
					if (var1.at<Vec3b>(a.x - 1, a.y)[0] == 255 && var1.at<Vec3b>(a.x - 1, a.y)[1] == 255 && var1.at<Vec3b>(a.x - 1, a.y)[2] == 255 && var2.at<uchar>(a.x - 1, a.y) == 0)
					{
						b.x = a.x - 1;
						b.y = a.y;
						S.push(b);
						var2.at<uchar>(a.x - 1, a.y) = 255;
						var3.at<Vec3b>(a.x - 1, a.y)[0] = 255;
					}
					if (a.y + 1 < var1.cols)
					{
						if (var1.at<Vec3b>(a.x - 1, a.y + 1)[0] == 255 && var1.at<Vec3b>(a.x - 1, a.y + 1)[1] == 255 && var1.at<Vec3b>(a.x - 1, a.y + 1)[2] == 255 && var2.at<uchar>(a.x - 1, a.y + 1) == 0)
						{
							b.x = a.x - 1;
							b.y = a.y + 1;
							S.push(b);
							var2.at<uchar>(a.x - 1, a.y + 1) = 255;
							var3.at<Vec3b>(a.x - 1, a.y + 1)[0] = 255;
						}
					}
				}
				if (a.x + 1 < var1.rows)
				{
					if (a.y - 1 >= 0)
					{
						if (var1.at<Vec3b>(a.x + 1, a.y - 1)[0] == 255 && var1.at<Vec3b>(a.x + 1, a.y - 1)[1] == 255 && var1.at<Vec3b>(a.x + 1, a.y - 1)[2] == 255 && var2.at<uchar>(a.x + 1, a.y - 1) == 0)
						{
							b.x = a.x + 1;
							b.y = a.y - 1;
							S.push(b);
							var2.at<uchar>(a.x + 1, a.y - 1) = 255;
							var3.at<Vec3b>(a.x + 1, a.y - 1)[0] = 255;
						}
					}
					if (var1.at<Vec3b>(a.x + 1, a.y)[0] == 255 && var1.at<Vec3b>(a.x + 1, a.y)[1] == 255 && var1.at<Vec3b>(a.x + 1, a.y)[2] == 255 && var2.at<uchar>(a.x + 1, a.y) == 0)
					{
						b.x = a.x + 1;
						b.y = a.y;
						S.push(b);
						var2.at<uchar>(a.x + 1, a.y) = 255;
						var3.at<Vec3b>(a.x + 1, a.y)[0] = 255;
					}
					if (a.y + 1 < var1.cols)
					{
						if (var1.at<Vec3b>(a.x + 1, a.y + 1)[0] == 255 && var1.at<Vec3b>(a.x + 1, a.y + 1)[1] == 255 && var1.at<Vec3b>(a.x + 1, a.y + 1)[2] == 255 && var2.at<uchar>(a.x + 1, a.y + 1) == 0)
						{
							b.x = a.x + 1;
							b.y = a.y + 1;
							S.push(b);
							var2.at<uchar>(a.x + 1, a.y + 1) = 255;
							var3.at<Vec3b>(a.x + 1, a.y + 1)[0] = 255;
						}
					}
				}
				if (a.y - 1 >= 0)
				{
					if (var1.at<Vec3b>(a.x, a.y - 1)[0] == 255 && var1.at<Vec3b>(a.x, a.y - 1)[1] == 255 && var1.at<Vec3b>(a.x, a.y - 1)[2] == 255 && var2.at<uchar>(a.x, a.y - 1) == 0)
					{
						b.x = a.x;
						b.y = a.y - 1;
						S.push(b);
						var2.at<uchar>(a.x, a.y - 1) = 255;
						var3.at<Vec3b>(a.x, a.y - 1)[0] = 255;
					}
				}
				if (a.y + 1 < var1.cols)
				{
					if (var1.at<Vec3b>(a.x, a.y + 1)[0] == 255 && var1.at<Vec3b>(a.x, a.y + 1)[1] == 255 && var1.at<Vec3b>(a.x, a.y + 1)[2] == 255 && var2.at<uchar>(a.x, a.y + 1) == 0)
					{
						b.x = a.x;
						b.y = a.y + 1;
						S.push(b);
						var2.at<uchar>(a.x, a.y + 1) = 255;
						var3.at<Vec3b>(a.x, a.y + 1)[0] = 255;
					}
				}
			}
		}
		imshow("window", var3);
		waitKey(10);
	}
	return(0);
}