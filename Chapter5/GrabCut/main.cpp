#include <opencv2/opencv.hpp>

int main()
{
	//��ͼ��
	cv::Mat image = cv::imread("group.jpg");
	//����ǰ������İ�Χ��
	cv::Rect rectangle(10, 100, 380, 180);
	cv::Mat result; //�ָ���ֿ��ܵ�ֵ��
	cv::Mat bgModel, fgModel; //ģ�ͣ����ڲ�ʹ�ã�
	//GrabCut�ָ�
	cv::grabCut(image, //����ͼ��
		result,//�ָ���
		rectangle,//����ǰ������ľ���
		bgModel, fgModel,//ģ��
		5,//��������
		cv::GC_INIT_WITH_RECT);//ʹ�þ��ν��г�ʼ��
	//�õ�����Ϊǰ��������
	cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
	//�������ͼ��
	cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
	image.copyTo(foreground, result);//�����Ʊ�������

// 	ʹ�ð�λ��˶Ե�1��λ
// 		result = result & 1;//ǰ��ʱΪ1


	return 0;
}