#include <opencv2/opencv.hpp>

int main()
{
	//����ͼ��
	cv::Mat image = cv::imread("binary.bmp");
	imshow("Source Image", image);
	//��ʴͼ��
	cv::Mat eroded; //Ŀ��ͼ��

	cv::Mat element(3, 3, CV_8U, cv::Scalar(1));

	cv::erode(image, eroded, cv::Mat());
	//��ʾ��ʴ���ͼ��
	cv::imshow("Eroded Image", eroded);
	cv::waitKey();
	//////////////////////////////////////////////////////////////////////////
	//����ͼ��
	cv::Mat dilated; //Ŀ��ͼ��
	cv::dilate(image, dilated, cv::Mat());
	//��ʾ���ͺ��ͼ��
	cv::imshow("Dilated Image", dilated);
	cv::waitKey();
}