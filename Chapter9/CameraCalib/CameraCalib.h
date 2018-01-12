#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CameraCalib.h"
#include <opencv2/opencv.hpp>

class CameraCalib : public QMainWindow
{
	Q_OBJECT

public:
	CameraCalib(QWidget *parent = Q_NULLPTR);
	int AddChessboardPoints(const std::vector<std::string> &filelist, cv::Size &board_size);

private:
	Ui::CameraCalibClass ui;

	//输入点：
	//位于世界坐标的点
	std::vector<std::vector<cv::Point3f>> object_points;
	//像素坐标的点
	std::vector<std::vector<cv::Point2f>> image_points;
	//输出矩阵
	cv::Mat camera_matrix;
	cv::Mat dist_coeffs;
	//标定的方式
	int flag;
	//用于图像去畸变
	cv::Mat map_1, map_2;
	bool must_init_undistort;
};
