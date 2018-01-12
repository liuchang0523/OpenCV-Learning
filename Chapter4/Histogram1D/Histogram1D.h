#pragma once
#include <opencv2/opencv.hpp>

class Histogram1D
{
public:
	Histogram1D() {
		//准备1D直方图的参数
		histSize[0] = 256;
		hranges[0] = 0.0;
		hranges[1] = 255.0;
		ranges[0] = hranges;
		channels[0] = 0;//默认情况，我们考察0号通道
	};
	//计算1D直方图
	cv::MatND getHistogram(const cv::Mat &image) {
		cv::MatND hist;
		//计算直方图
		cv::calcHist(&image,
			1,//计算单张图像的直方图
			channels,
			cv::Mat(),
			hist,
			1,
			histSize,
			ranges
		);
		return hist;
	}

	cv::Mat getHistogramImage(const cv::Mat &image)
	{
		//首先计算直方图
		cv::MatND hist = getHistogram(image);
		//cv::normalize(hist, hist, 1.0);
		//获取最大值和最小值
		double maxVal = 0;
		double minVal = 0;
		cv::minMaxLoc(hist, &minVal, &maxVal);
		//显示直方图的图像
		cv::Mat histImg(histSize[0], histSize[0], CV_8U, cv::Scalar(255));
		//设置最高点为nbins的90%
		int hpt = static_cast<int>(0.9*histSize[0]);
		//每个条目都绘制一条垂直线
		for (int h = 0; h < histSize[0]; h++)
		{
			float binVal = hist.at<float>(h);
			int intensity = static_cast<int>(binVal*hpt / maxVal);
			//两点之间绘制一条直线
			cv::line(histImg, cv::Point(h, histSize[0]),
				cv::Point(h, histSize[0] - intensity),
				cv::Scalar::all(0));
		}
		return histImg;
	}

	//使用查找表修改图像外观
	cv::Mat applyLookUp(const cv::Mat &image,//输入图像
		const cv::Mat &lookup) {
		//输出图像
		cv::Mat result;
		//应用查找表
		cv::LUT(image, lookup, result);
		return result;
	}

	//拉伸直方图，扩展对比度
	cv::Mat stretch(const cv::Mat &image, int min_value = 0) {
		//首先计算直方图
		cv::MatND hist = getHistogram(image);
		//寻找直方图的左端
		int imin = 0;
		for (; imin < histSize[0]; ++imin)
		{
			std::cout << hist.at<float>(imin) << std::endl;
			if (hist.at<float>(imin) > min_value)
			{
				break;
			}
		}
		//寻找直方图的右端
		int imax = histSize[0] - 1;
		for (; imax >= 0; --imax)
		{
			if (hist.at<float>(imax) > min_value)
			{
				break;
			}
		}
		//创建查找表
		int dim(256);
		cv::Mat lookup(1, &dim, CV_8U);
		//填充查找表
		for (int i = 0; i < 256; i++)
		{
			//确保数值位于imin与imax之间
			if (i < imin)
			{
				lookup.at<uchar>(i) = 0;
			}
			else if (i > imax)
			{
				lookup.at<uchar>(i) = 255;
			}
			else
			{
				lookup.at<uchar>(i) = static_cast<uchar>(
					255.0*(i - imin) / (imax - imin) + 0.5);
			}
		}
		//应用查找表
		cv::Mat result;
		result = applyLookUp(image, lookup);
		return result;
	}


	~Histogram1D() {};

private:
	int histSize[1]; //项的数目
	float hranges[2]; //像素的最小及最大值
	const float *ranges[1];
	int channels[1]; //仅用到一个通道
};
