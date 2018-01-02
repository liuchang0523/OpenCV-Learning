#include "WatershedSegmenter.h"
using namespace cv;

int main()
{
	Mat image = imread("binary.bmp");
	Mat binary;
	//threshold(image, binary, 128, 255, cv::THRESH_BINARY);
	cvtColor(image, binary, CV_RGB2GRAY);
	//移除噪点与微小物体
	Mat fg;
	erode(binary, fg, cv::Mat(), cv::Point(-1, -1), 6);
	imshow("Foreground Image", fg);
	//识别不包含物体的像素
	Mat bg;
	dilate(binary, bg, cv::Mat(), cv::Point(-1, -1), 6);
	threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);
	//创建标记图像
	cv::Mat markers(binary.size(), CV_8UC1, cv::Scalar(0));
	markers = bg + fg;

	//创建分水岭分割对象
	WatershedSegmenter segmenter;
	//设置标记，并处进行处理
	segmenter.setMarkers(markers);
	segmenter.process(image);
	Mat result = segmenter.getSegmentation();
	Mat watershed_ = segmenter.getWatersheds();
	return 0;
}