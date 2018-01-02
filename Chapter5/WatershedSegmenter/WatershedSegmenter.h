#pragma once
#include <opencv2/opencv.hpp>
class WatershedSegmenter
{
public:
	WatershedSegmenter();
	~WatershedSegmenter();

	void setMarkers(const cv::Mat& markerImage) {
		//转换为整数图像
		markerImage.convertTo(markers, CV_32S);
	}
	cv::Mat process(const cv::Mat& image) {
		//使用算法
		cv::watershed(image, markers);
		return markers;
	}

	//以图像的形式返回结果
	cv::Mat getSegmentation() {
		cv::Mat tmp;
		//标签高于255的分割一律赋值为255
		markers.convertTo(tmp, CV_8U);
		return tmp;
	}

	//以图像的形式返回分水岭
	cv::Mat getWatersheds() {
		cv::Mat tmp;
		//转换前每个像素都为255p+255
		markers.convertTo(tmp, CV_8U, 255, 255);
		return tmp;
	}

private:
	cv::Mat markers;
};

