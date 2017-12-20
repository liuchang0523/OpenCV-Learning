#pragma once
#include <opencv2/opencv.hpp>
class ColorDetector
{
public:
	ColorDetector();
	~ColorDetector();
	//������Ŀ����ɫ�ľ���
	int getDistance(const cv::Vec3b& color)const;
	cv::Mat process(const cv::Mat &image);
	//����ɫ�ʾ�����ֵ�� ��ֵ���������ģ�������Ϊ0
	void setColorDistanceThreshold(int distance);
	//��ȡɫ�ʾ�����ֵ
	int getColorDistanceThreshold() const;
	//�����������ɫ
	void setTargetColor(unsigned char red,
		unsigned char green,
		unsigned char blue
	);
	void setTargetColor(cv::Vec3b color);
	cv::Vec3b getTargetColor() const;

	cv::Mat getResult() const { return result; }
private:
	//��С�ɽ��ܾ���
	int minDist;
	//Ŀ��ɫ
	cv::Vec3b target;
	//���ͼ��
	cv::Mat result;

};

