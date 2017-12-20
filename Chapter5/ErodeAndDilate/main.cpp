#include <opencv2/opencv.hpp>

int main()
{
	//读入图像
	cv::Mat image = cv::imread("binary.bmp");
	imshow("Source Image", image);
	//腐蚀图像
	cv::Mat eroded; //目标图像

	cv::Mat element(3, 3, CV_8U, cv::Scalar(1));

	cv::erode(image, eroded, cv::Mat());
	//显示腐蚀后的图像
	cv::imshow("Eroded Image", eroded);
	cv::waitKey();
	//////////////////////////////////////////////////////////////////////////
	//膨胀图像
	cv::Mat dilated; //目标图像
	cv::dilate(image, dilated, cv::Mat());
	//显示膨胀后的图像
	cv::imshow("Dilated Image", dilated);
	cv::waitKey();
}