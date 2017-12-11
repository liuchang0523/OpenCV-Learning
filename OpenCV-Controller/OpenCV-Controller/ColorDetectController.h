#pragma once
#include "include/ColorDetector.h"
class ColorDetectController
{
public:
	ColorDetectController();
	~ColorDetectController();
	//����ɫ�ʾ�����ֵ
	void setColorDistanceThreshold(int distance);
	//��ȡɫ�ʾ�����ֵ
	int getColorDistanceThreshold()const;
	//����Ҫ����ɫ��
	void setTargetColor(unsigned char red,
		unsigned char green, unsigned char blue);
	//��ȡ�������ɫ
	void getTargetColor(unsigned char &red,
		unsigned char &green, unsigned char &blue)const;
	//��������ͼ��ͨ���ļ���ȡ
	bool setInputImage(std::string filename);
	//���ص�ǰ������ͼ��
	const cv::Mat getInputImage() const;
	//��ʼ����ͼ��
	void process();
	//��ȡ���һ�δ���Ľ��
	const cv::Mat getLastResult() const;
private:
	//�㷨��
	ColorDetector * cdetect;
	cv::Mat image;//�������ͼ��
	cv::Mat result;//���
	
};

