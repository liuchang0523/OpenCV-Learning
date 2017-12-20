#include "ColorDetectController.h"

int main()
{
	ColorDetectController controller;
	controller.setInputImage("QQ.jpg");
	cv::imshow("Source", controller.getInputImage());
	controller.setTargetColor(102, 74, 50);
	controller.process();
	cv::imshow("After", controller.getLastResult());
	cv::waitKey();
}