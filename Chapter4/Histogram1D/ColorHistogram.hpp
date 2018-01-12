#pragma once
#include <opencv2/opencv.hpp>
class ColorHistogram
{
public:
	ColorHistogram() {
		//准备彩色直方图参数
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;//BGR的颜色范围
		hranges[1] = 255.0;
		ranges[0] = ranges[1] = ranges[2] = hranges;//所有通道拥有相同的范围
		channels[0] = 0;//三个通道
		channels[1] = 1;
		channels[2] = 2;
	}

	cv::MatND getHistogram(const cv::Mat &image) {
		cv::MatND hist;
		//计算直方图
		cv::calcHist(&image,
			1,//仅计算一张图
			channels,//通道数量
			cv::Mat(),//不使用掩码图像
			hist,//返回的直方图
			3,//这是三维直方图
			histSize,//项的数量
			ranges);//像素值的范围
		return hist;
	}

	cv::SparseMat getSparseHistogram(const cv::Mat &image) {
		cv::SparseMat hist(3, histSize, CV_32F);
		//计算直方图
		cv::calcHist(&image,
			1,//仅计算一张图
			channels,//通道数量
			cv::Mat(),//不使用掩码图像
			hist,//返回的直方图
			3,//这是三维直方图
			histSize,//项的数量
			ranges);//像素值的范围
		return hist;
	}
protected:
private:
	int histSize[3];
	float hranges[2];
	const float *ranges[3];
	int channels[3];
};
