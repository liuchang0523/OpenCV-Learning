#include "CameraCalib.h"
#include <vector>
CameraCalib::CameraCalib(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	flag = 0;
	must_init_undistort = true;

}

int CameraCalib::AddChessboardPoints(const std::vector<std::string> &filelist, cv::Size &board_size)
{
	// 棋盘上的点的两种坐标
	std::vector<cv::Point2f> image_corners;
	std::vector<cv::Point3f> object_corners;
	// 3D场景中的点:
	// 在棋盘坐标系中初始化棋盘角点
	// 这些点位于(X,Y,Z) = (i,j,0)
	for (int i = 0; i < board_size.height; ++i)
		for (int j = 0; j < board_size.width; ++j)
			object_corners.push_back(cv::Point3f(i, j, 0.0f));
	//2D图像中的点:
	cv::Mat image;
}
