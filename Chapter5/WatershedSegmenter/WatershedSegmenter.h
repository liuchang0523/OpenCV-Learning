#pragma once
#include <opencv2/opencv.hpp>
class WatershedSegmenter
{
public:
	WatershedSegmenter();
	~WatershedSegmenter();

	void setMarkers(const cv::Mat& markerImage) {
		//ת��Ϊ����ͼ��
		markerImage.convertTo(markers, CV_32S);
	}
	cv::Mat process(const cv::Mat& image) {
		//ʹ���㷨
		cv::watershed(image, markers);
		return markers;
	}

	//��ͼ�����ʽ���ؽ��
	cv::Mat getSegmentation() {
		cv::Mat tmp;
		//��ǩ����255�ķָ�һ�ɸ�ֵΪ255
		markers.convertTo(tmp, CV_8U);
		return tmp;
	}

	//��ͼ�����ʽ���ط�ˮ��
	cv::Mat getWatersheds() {
		cv::Mat tmp;
		//ת��ǰÿ�����ض�Ϊ255p+255
		markers.convertTo(tmp, CV_8U, 255, 255);
		return tmp;
	}

private:
	cv::Mat markers;
};

