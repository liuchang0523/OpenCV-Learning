#include "ColorDetector.h"

int main() {
	//1.创建图像处理的对象
	ColorDetector cdetect;
	//2.读取输入图像
	cv::Mat image = cv::imread("QQ.jpg");
	if (!image.data)
	{
		return 0;
	}
	//3.设置输入参数
	cdetect.setTargetColor(102, 74, 50);
	cv::namedWindow("result");
	//4.处理并显示结果
	cv::imshow("result", cdetect.process(image));
	cv::waitKey();
	return 0;
}