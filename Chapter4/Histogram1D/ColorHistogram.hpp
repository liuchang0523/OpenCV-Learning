#pragma once
#include <opencv2/opencv.hpp>
class ColorHistogram
{
public:
	ColorHistogram() {
		//准备彩色直方图参数
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0;//BGR的颜色范围
		hranges[1] = 255.0;
		ranges[0] = hranges;//所有通道拥有相同的范围
		ranges[1] = hranges;
		ranges[2] = hranges;
		channels[0] = 0;//三个通道
		channels[1] = 1;
		channels[2] = 2;
	}

	cv::MatND getHistogram(const cv::Mat &image) {
		cv::MatND hist;
		//计算直方图
		cv::calcHist(&image,
			1,//仅计算一张图
			channels,//通道数量
			cv::Mat(),//不使用掩码图像
			hist,//返回的直方图
			3,//这是三维直方图
			histSize,//项的数量
			ranges);//像素值的范围
		return hist;
	}

	cv::SparseMat getSparseHistogram(const cv::Mat &image) {
		cv::SparseMat hist(3, histSize, CV_32F);
		//计算直方图
		cv::calcHist(&image,
			1,//仅计算一张图
			channels,//通道数量
			cv::Mat(),//不使用掩码图像
			hist,//返回的直方图
			3,//这是三维直方图
			histSize,//项的数量
			ranges);//像素值的范围
		return hist;
	}

	//使用掩码计算1D色调直方图
	//BGR图像需转换为HSV色彩空间
	//并去除低饱和度的像素
	cv::MatND getHueHistogram(const cv::Mat &image, int minSaturation = 0) {
		cv::MatND hist;
		//转换为HSV色彩空间
		cv::Mat hsv;
		cv::cvtColor(image, hsv, CV_BGR2HSV);
		//是否使用掩码
		cv::Mat mask;
		if (minSaturation > 0)
		{
			//分割三通道为三幅图像
			std::vector<cv::Mat> v;
			cv::split(hsv, v);
			//标出低饱和度的参数
			cv::threshold(v[1], mask, minSaturation, 255, CV_THRESH_BINARY);
		}
		//1D色调直方图的参数
		hranges[0] = 0.0;
		hranges[1] = 180;
		channels[0] = 0;//色彩通道
		//计算直方图
		cv::calcHist(&hsv, 1, channels, mask, hist, 1, histSize, ranges);
		return hist;
	}

	cv::Mat colorReduce(const cv::Mat &image, int div = 64) {

		int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0));
		// mask used to round the pixel value
		uchar mask = 0xFF << n; // e.g. for div=16, mask= 0xF0

		cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
		cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();

		// Set output image (always 1-channel)
		cv::Mat result(image.rows, image.cols, image.type());
		cv::Mat_<cv::Vec3b>::iterator itr = result.begin<cv::Vec3b>();

		for (; it != itend; ++it, ++itr) {

			(*itr)[0] = ((*it)[0] & mask) + div / 2;
			(*itr)[1] = ((*it)[1] & mask) + div / 2;
			(*itr)[2] = ((*it)[2] & mask) + div / 2;
		}

		return result;
	}

protected:
private:
	int histSize[3];
	float hranges[2];
	const float *ranges[3];
	int channels[3];
};
