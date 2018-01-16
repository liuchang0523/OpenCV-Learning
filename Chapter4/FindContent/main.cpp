#include <opencv2/opencv.hpp>
#include "../Histogram1D/Histogram1D.hpp"
#include "../Histogram1D/ColorHistogram.hpp"
#include "ContentFinder.hpp"

int main()
{
#if 0
	cv::Mat image = cv::imread("beach.jpg");
	cv::Mat imageROI;

	imageROI = image(cv::Rect(360, 55, 40, 50));//包含云的区域

	cv::rectangle(image, cv::Rect(360, 55, 40, 50), cv::Scalar(0, 0, 255));

	Histogram1D h;
	cv::MatND hist = h.getHistogram(imageROI);

	cv::normalize(hist, hist, 1.0);

	cv::Mat back_project_image = h.getBackProjectImage(image, hist);
#endif

#if 0
	ColorHistogram hc;
	//读取彩图
	cv::Mat color = cv::imread("beach.jpg");
	//蓝天区域
	cv::Mat imageROI = color(cv::Rect(0, 0, 165, 75));
	cv::rectangle(color, cv::Rect(0, 0, 165, 75), cv::Scalar(0, 0, 255));
	cv::MatND hist = hc.getHistogram(imageROI); // has some problem
	ContentFinder finder;
	finder.setHistogram(hist);
	finder.setThreshold(0.05f);
	int channels[3];
	channels[0] = 0;//三个通道
	channels[1] = 1;
	channels[2] = 2;
	cv::Mat result = finder.find(color, 0, 255, channels, 3);
#endif


	//读取参考图像
	cv::Mat image = cv::imread("baboon1.jpg");
	//狒狒脸部的ROI 
	cv::Mat imageROI = image(cv::Rect(110, 260, 35, 40));
	//获取色调通道的直方图
	int minSat = 65;
	ColorHistogram hc;
	cv::MatND colorhist = hc.getHueHistogram(imageROI, minSat);

	ContentFinder finder;
	finder.setHistogram(colorhist);

	image = cv::imread("baboon4.jpg");
	//显示图像
	cv::imshow("Image 2", image);
	cv::Mat hsv;
	//转换到HSV空间
	cv::cvtColor(image, hsv, CV_BGR2HSV);
	//分割图像
	std::vector<cv::Mat> v;
	cv::split(hsv, v);
	//识别低饱和度的像素
	cv::threshold(v[1], v[1], minSat, 255, CV_THRESH_BINARY);

	//获取直方图的反投影
	cv::Mat result;
	int channels[3];
	channels[0] = 0;//三个通道
	channels[1] = 1;
	channels[2] = 2;
	result = finder.find(hsv, 0.0f, 180.0f, channels, 1);

	//去除低饱和度的像素
	cv::bitwise_and(result, v[1], result);

	cv::Rect rect(110, 260, 35, 40);
	cv::rectangle(image, rect, cv::Scalar(0, 0, 255));
	cv::TermCriteria ceiteria(cv::TermCriteria::MAX_ITER, 10, 0.001);
	int n = cv::meanShift(result, rect, ceiteria);
	cv::rectangle(image, rect, cv::Scalar(255, 0, 0));


	return 0;
}
