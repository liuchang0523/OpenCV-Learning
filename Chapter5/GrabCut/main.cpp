#include <opencv2/opencv.hpp>

int main()
{
	//打开图像
	cv::Mat image = cv::imread("group.jpg");
	//定义前景物体的包围盒
	cv::Rect rectangle(10, 100, 380, 180);
	cv::Mat result; //分割（四种可能的值）
	cv::Mat bgModel, fgModel; //模型（供内部使用）
	//GrabCut分割
	cv::grabCut(image, //输入图像
		result,//分割结果
		rectangle,//包含前景物体的矩形
		bgModel, fgModel,//模型
		5,//迭代次数
		cv::GC_INIT_WITH_RECT);//使用矩形进行初始化
	//得到可能为前景的像素
	cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
	//生成输出图像
	cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
	image.copyTo(foreground, result);//不复制背景像素

// 	使用按位与核对第1个位
// 		result = result & 1;//前景时为1


	return 0;
}