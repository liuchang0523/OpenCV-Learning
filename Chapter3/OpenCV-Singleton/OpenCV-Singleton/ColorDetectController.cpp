#include "ColorDetectController.h"

ColorDetectController *ColorDetectController::singleton = 0;

ColorDetectController::ColorDetectController()
{
	//初始化工作
	cdetect = new ColorDetector();
}


ColorDetectController::~ColorDetectController()
{
	delete cdetect;
}

void ColorDetectController::setColorDistanceThreshold(int distance)
{
	cdetect->setColorDistanceThreshold(distance);
}

int ColorDetectController::getColorDistanceThreshold() const
{
	return cdetect->getColorDistanceThreshold();
}

void ColorDetectController::setTargetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	cdetect->setTargetColor(red, green, blue);
}

void ColorDetectController::getTargetColor(unsigned char &red, unsigned char &green, unsigned char &blue) const
{
	cv::Vec3b color = cdetect->getTargetColor();
	red = color[2];
	green = color[1];
	blue = color[0];
}

bool ColorDetectController::setInputImage(std::string filename)
{
	image = cv::imread(filename);
	if (!image.data)
	{
		return false;
	}
	else
	{
		return true;
	}
}

const cv::Mat ColorDetectController::getInputImage() const
{
	return image;
}

void ColorDetectController::process()
{
	result = cdetect->process(image);
}

const cv::Mat ColorDetectController::getLastResult() const
{
	return result;
}
