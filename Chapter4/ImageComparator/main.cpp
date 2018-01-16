#include "ImageComparator.hpp"


int main()
{
	cv::Mat image = cv::imread("beach.jpg");
	ImageComparator c;
	c.setReferenceImage(image);

	cv::Mat image2 = cv::imread("beach.jpg");
	double diff = c.compare(image2);

	return 0;
}
