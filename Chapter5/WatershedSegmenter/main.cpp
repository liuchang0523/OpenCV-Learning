#include "WatershedSegmenter.h"
using namespace cv;

int main()
{
	Mat image = imread("binary.bmp");
	Mat binary;
	//threshold(image, binary, 128, 255, cv::THRESH_BINARY);
	cvtColor(image, binary, CV_RGB2GRAY);
	//�Ƴ������΢С����
	Mat fg;
	erode(binary, fg, cv::Mat(), cv::Point(-1, -1), 6);
	imshow("Foreground Image", fg);
	//ʶ�𲻰������������
	Mat bg;
	dilate(binary, bg, cv::Mat(), cv::Point(-1, -1), 6);
	threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);
	//�������ͼ��
	cv::Mat markers(binary.size(), CV_8UC1, cv::Scalar(0));
	markers = bg + fg;

	//������ˮ��ָ����
	WatershedSegmenter segmenter;
	//���ñ�ǣ��������д���
	segmenter.setMarkers(markers);
	segmenter.process(image);
	Mat result = segmenter.getSegmentation();
	Mat watershed_ = segmenter.getWatersheds();
	return 0;
}