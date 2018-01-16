
//2018/01/16  by LCCCCC

#ifndef ImageComparator_h__
#define ImageComparator_h__

#include <opencv2/opencv.hpp>

#include "../Histogram1D/ColorHistogram.hpp"

class ImageComparator
{
public:
	ImageComparator();
	~ImageComparator();
	//减色因子
	//比较的将是减色后的图像
	//色彩空间中的每个维度都将按照该变量进行减色
	void setColorReduction(int factor) {
		div = factor;
	}
	int getColorReduction() {
		return div;
	}

	void setReferenceImage(const cv::Mat &image) {
		reference = hist.colorReduce(image, div);
		refH = hist.getHistogram(reference);
	}

	double compare(const cv::Mat &image) {
		input = hist.colorReduce(image, div);
		inputH = hist.getHistogram(input);
		return cv::compareHist(refH, inputH, CV_COMP_INTERSECT);
	}


private:
	cv::Mat reference;
	cv::Mat input;
	cv::MatND refH;
	cv::MatND inputH;
	ColorHistogram hist;
	int div;
};

ImageComparator::ImageComparator() :div(32)
{
}

ImageComparator::~ImageComparator()
{
}




#endif // ImageComparator_h__
