#include <opencv2/opencv.hpp>
#include "../Histogram1D/Histogram1D.hpp"

int main()
{
	cv::Mat image = cv::imread("beach.jpg");
	cv::Mat imageROI;
	imageROI = image(cv::Rect(360, 55, 40, 50));//包含云的区域

	cv::rectangle(image, cv::Rect(360, 55, 40, 50), cv::Scalar(0, 0, 255));

	Histogram1D h;
	cv::MatND hist = h.getHistogram(imageROI);

	cv::normalize(hist, hist, 1.0);

	return 0;
}
