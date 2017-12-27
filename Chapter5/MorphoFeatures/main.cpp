#include <opencv2/opencv.hpp>


int main()
{
	#if 1
cv::Mat cross(5, 5, CV_8U, cv::Scalar(0));
	//创建十字形元素
	for (int i = 0;i < 5; i++)
	{
		cross.at<uchar>(2, i) = 1;
		cross.at<uchar>(i, 2) = 1;
	}
	cv::Mat diamond(5, 5, CV_8U, cv::Scalar(1));
	//创建菱形元素
	diamond.at<uchar>(0, 0) = 0;
	diamond.at<uchar>(0, 1) = 0;
	diamond.at<uchar>(0, 3) = 0;
	diamond.at<uchar>(0, 4) = 0;
	diamond.at<uchar>(1, 0) = 0;
	diamond.at<uchar>(1, 4) = 0;
	diamond.at<uchar>(3, 0) = 0;
	diamond.at<uchar>(3, 4) = 0;
	diamond.at<uchar>(4, 0) = 0;
	diamond.at<uchar>(4, 1) = 0;
	diamond.at<uchar>(4, 3) = 0;
	diamond.at<uchar>(4, 4) = 0;

	cv::Mat x(5, 5, CV_8U, cv::Scalar(0));
	//创建X形元素
	for (int i = 0; i < 5; i++)
	{
		x.at<uchar>(i, i) = 1;
		x.at<uchar>(4 - i, i) = 1;
	}
	cv::Mat square(5, 5, CV_8U, cv::Scalar(1));//创建方形元素
#endif
#if 0
	cv::Mat cross(3, 3, CV_8U, cv::Scalar(0));
	//创建十字形元素
	for (int i = 0; i < 3; i++)
	{
		cross.at<uchar>(1, i) = 1;
		cross.at<uchar>(i, 1) = 1;
	}
	cv::Mat diamond(3, 3, CV_8U, cv::Scalar(1));
	//创建菱形元素
	diamond.at<uchar>(0, 0) = 0;
	diamond.at<uchar>(0, 2) = 0;
	diamond.at<uchar>(2, 0) = 0;
	diamond.at<uchar>(2, 2) = 0;

	cv::Mat x(3, 3, CV_8U, cv::Scalar(0));
	//创建X形元素
	for (int i = 0; i < 3; i++)
	{
		x.at<uchar>(i, i) = 1;
		x.at<uchar>(2 - i, i) = 1;
	}
	cv::Mat square(3, 3, CV_8U, cv::Scalar(1));//创建方形元素
#endif

	cv::Mat image_src = cv::imread("square.bmp",0);
	cv::Mat step1,step2,step3,step4;
	std::cout << cross << std::endl;
	cv::dilate(image_src, step1, cross);//十字形膨胀
	cv::imwrite("step1.bmp", step1);
	cv::morphologyEx(step1, step2, cv::MORPH_ERODE, diamond);
	//cv::erode(step1, step2, diamond);//菱形腐蚀
	std::cout << diamond << std::endl;
	cv::imwrite("step2.bmp", step2);
	cv::dilate(image_src, step3, x);//X形膨胀
	cv::imwrite("step1.bmp", step1);
	std::cout << x << std::endl;
	cv::imwrite("step3.bmp", step3);
	cv::erode(step3, step4, square);//方形腐蚀
	std::cout << square << std::endl;
	cv::imwrite("step4.bmp", step4);
}