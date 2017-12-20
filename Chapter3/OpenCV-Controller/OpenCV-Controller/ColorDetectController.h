#pragma once
#include "include/ColorDetector.h"
class ColorDetectController
{
public:
	ColorDetectController();
	~ColorDetectController();
	//设置色彩距离阈值
	void setColorDistanceThreshold(int distance);
	//获取色彩距离阈值
	int getColorDistanceThreshold()const;
	//设置要检测的色彩
	void setTargetColor(unsigned char red,
		unsigned char green, unsigned char blue);
	//获取需检测的颜色
	void getTargetColor(unsigned char &red,
		unsigned char &green, unsigned char &blue)const;
	//设置输入图像，通过文件读取
	bool setInputImage(std::string filename);
	//返回当前的输入图像
	const cv::Mat getInputImage() const;
	//开始处理图像
	void process();
	//获取最近一次处理的结果
	const cv::Mat getLastResult() const;
private:
	//算法类
	ColorDetector * cdetect;
	cv::Mat image;//被处理的图像
	cv::Mat result;//结果
	
};

