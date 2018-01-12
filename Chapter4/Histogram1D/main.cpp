#include <QtCore/QCoreApplication>
#include "Histogram1D.hpp"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	cv::Mat image = cv::imread("test.bmp", 0);
	Histogram1D h;
	cv::MatND histo = h.getHistogram(image);
	//cv::normalize(histo, histo, 1.0);
	cv::Mat histImg = h.getHistogramImage(image);


	int dim(256);
	cv::Mat lut(1, &dim, CV_8U);
	for (int i = 0; i < 256; ++i)
	{
		lut.at<uchar>(i) = 255 - i;
	}
	cv::Mat negative = h.applyLookUp(image, lut);

	cv::Mat stretched = h.stretch(image, 800);

	cv::Mat hist_image_2 = h.getHistogramImage(stretched);
	cv::imwrite("stretched.bmp", stretched);

	return a.exec();
}
