#include "ColorDetector.h"



ColorDetector::ColorDetector():minDist(100)
{
	//初始化默认参数
	target[0] = target[1] = target[2] = 0;
}


ColorDetector::~ColorDetector()
{
}

int ColorDetector::getDistance(const cv::Vec3b& color) const
{
	return abs(color[0] - target[0]) +
		abs(color[1] - target[1]) +
		abs(color[2] - target[2]);
}

cv::Mat ColorDetector::process(const cv::Mat &image)
{
	//按需重新分配二值图像
	//与输入图像的尺寸相同，但是只有一个通道
	result.create(image.rows, image.cols, CV_8U);
	//得到迭代器
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	//对于每个像素
	for (;it!=itend;it++,itout++)
	{
		//处理每个像素------------------
		//计算离目标颜色的距离
		if (getDistance(*it)<minDist)
		{
			*itout = 255;
		}
		else
		{
			*itout = 0;
		}
		//结束像素处理------------------
	} 
	return result;
}

void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0)
	{
		distance = 0;
	}
	minDist = distance;
}

int ColorDetector::getColorDistanceThreshold() const
{
	return minDist;
}

void ColorDetector::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	//BGR顺序
	target[2] = red;
	target[1] = green;
	target[0] = blue;
}

void ColorDetector::setTargetColor(cv::Vec3b color)
{
	target = color;
}

cv::Vec3b ColorDetector::getTargetColor() const
{
	return target;
}
