#include "ColorDetectController.h"

int main()
{
	ColorDetectController::getInstance()->setInputImage("QQ.jpg");
	cv::imshow("Source", ColorDetectController::getInstance()->getInputImage());
	ColorDetectController::getInstance()->setTargetColor(102, 74, 50);
	ColorDetectController::getInstance()->process();
	cv::imshow("After", ColorDetectController::getInstance()->getLastResult());
	cv::waitKey();
	ColorDetectController::destory();
}