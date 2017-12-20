#pragma once
#include "ColorDetector.h"
class ColorDetectController
{
	//���ʵ���ʵ��
public:
	static ColorDetectController* getInstance()
	{
		//���״ε����Ǵ���ʵ��
		if (singleton == nullptr)
		{
			singleton = new ColorDetectController;
		}
		return singleton;
	}
	//�ͷŵ�����ʵ��
	static void destory()
	{
		if (singleton != nullptr)
		{
			delete singleton;
			singleton = 0;
		}
	}
public:
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
	//����ָ��
	static ColorDetectController *singleton;
	//˽�й��캯��
	ColorDetectController();
	//�㷨��
	ColorDetector * cdetect;
	cv::Mat image;//�������ͼ��
	cv::Mat result;//���
	
};

