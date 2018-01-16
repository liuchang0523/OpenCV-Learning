#pragma once

#include <opencv2/opencv.hpp>

class ContentFinder
{
public:
	ContentFinder();
	~ContentFinder();

	//获取阈值
	float getThreshold() const { return threshold; }
	//设置直方图的阈值[0,1]
	void setThreshold(float val) { threshold = val; }
	//设置参考直方图
	void setHistogram(cv::MatND val) {
		histogram = val;
		cv::normalize(histogram, histogram, 1.0);
	}

	cv::Mat find(const cv::Mat &image) {
		cv::Mat result;
		hranges[0] = 0.0;
		hranges[1] = 255.0;
		channels[0] = 0;
		channels[1] = 1;
		channels[2] = 2;

		cv::calcBackProject(&image, 1, channels, histogram, result, ranges, 255);

		if (threshold > 0.0)
		{
			cv::threshold(result, result, 255 * threshold, 255, CV_THRESH_BINARY);
		}
		return result;
	}


	cv::Mat find(const cv::Mat &image,
		float minValue, float maxValue,
		int *channels, int dim) {
		cv::Mat result;
		hranges[0] = minValue;
		hranges[1] = maxValue;
		for (int i = 0; i < dim; ++i)
		{
			this->channels[i] = channels[i];
		}
		cv::calcBackProject(&image, 1,//输入图像
			channels,//所用通道的列表
			histogram,//直方图
			result,//反投影的结果
			ranges,//值域
			255);//缩放因子
		if (threshold > 0.0)
		{
			cv::threshold(result, result, 255 * threshold, 255,
				CV_THRESH_BINARY);
		}

		return result;
	}


private:
	float hranges[2];
	const float *ranges[3];
	int channels[3];
	float threshold;
	cv::MatND histogram;
};

ContentFinder::ContentFinder()
{
	setThreshold(-1.0f);
	ranges[0] = hranges;
	ranges[1] = hranges;
	ranges[2] = hranges;
}

ContentFinder::~ContentFinder()
{
}
