#include <opencv2/opencv.hpp>

int main()
{
	//∂¡»ÎÕºœÒ
	cv::Mat image = cv::imread("binary.bmp");
	imshow("Source Image", image);
	cv::Mat element5(5, 5, CV_8U, cv::Scalar(1));
	cv::Mat closed;
	cv::morphologyEx(image, closed, cv::MORPH_CLOSE, element5);
	imshow("Closed Image", closed);
	cv::Mat opened;
	cv::morphologyEx(image, opened, cv::MORPH_OPEN, element5);
	imshow("Opened Image", opened);
	cv::Mat closedAndOpened;
	cv::morphologyEx(image, closedAndOpened, cv::MORPH_CLOSE, element5);
	cv::morphologyEx(closedAndOpened, closedAndOpened, cv::MORPH_OPEN, element5);
	imshow("Closed and Opened Image", closedAndOpened);
	cv::waitKey();
}