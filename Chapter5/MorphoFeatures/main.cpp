#include <opencv2/opencv.hpp>


int main()
{
	cv::Mat cross(5, 5, CV_8U, cv::Scalar(0));
	//创建十字形元素
	for (int i = 0;i < 5; i++)
	{
		cross.at<uchar>(2, i) = 1;
		cross.at<uchar>(i, 2) = 1;
	}
	cv::Mat diamond(5, 5, CV_8U, cv::Scalar(1));
	//创建菱形元素
	cross.at<uchar>(0, 0) = 0;
	cross.at<uchar>(0, 1) = 0;
	cross.at<uchar>(0, 3) = 0;
	cross.at<uchar>(0, 3) = 0;
	cross.at<uchar>(1, 0) = 0;
	cross.at<uchar>(1, 4) = 0;
	cross.at<uchar>(3, 0) = 0;
	cross.at<uchar>(3, 4) = 0;
	cross.at<uchar>(4, 0) = 0;
	cross.at<uchar>(4, 1) = 0;
	cross.at<uchar>(4, 3) = 0;
	cross.at<uchar>(4, 4) = 0;

	cv::Mat x(5, 5, CV_8U, cv::Scalar(0));
	//创建X形元素
	for (int i = 0; i < 5; i++)
	{
		x.at<uchar>(i, i) = 1;
		x.at<uchar>(4 - i, i) = 1;
	}
	cv::Mat square(5, 5, CV_8U, cv::Scalar(1));//创建方形元素

	cv::Mat image_src = cv::imread("square.bmp",0);
	cv::Mat step1,step2,step3,step4;
	cv::dilate(image_src, step1, cross);//十字形膨胀
	cv::imwrite("step1.bmp", step1);
	cv::erode(step1, step2, diamond);//菱形腐蚀
	cv::imwrite("step2.bmp", step2);
	cv::dilate(image_src, step3, x);//X形膨胀
	cv::imwrite("step3.bmp", step3);
	cv::erode(step3, step4, square);//方形腐蚀
	cv::imwrite("step4.bmp", step4);
}