#pragma once
#include "ColorDetector.h"
class ColorDetectController
{
	//访问单件实例
public:
	static ColorDetectController* getInstance()
	{
		//在首次调用是创建实例
		if (singleton == nullptr)
		{
			singleton = new ColorDetectController;
		}
		return singleton;
	}
	//释放单件的实例
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
	//单件指针
	static ColorDetectController *singleton;
	//私有构造函数
	ColorDetectController();
	//算法类
	ColorDetector * cdetect;
	cv::Mat image;//被处理的图像
	cv::Mat result;//结果
	
};

