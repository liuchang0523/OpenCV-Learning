#include "ColorDetector.h"

int main() {
	//1.����ͼ����Ķ���
	ColorDetector cdetect;
	//2.��ȡ����ͼ��
	cv::Mat image = cv::imread("QQ.jpg");
	if (!image.data)
	{
		return 0;
	}
	//3.�����������
	cdetect.setTargetColor(102, 74, 50);
	cv::namedWindow("result");
	//4.������ʾ���
	cv::imshow("result", cdetect.process(image));
	cv::waitKey();
	return 0;
}