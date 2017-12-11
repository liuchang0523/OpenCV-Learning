#include "MVC.h"

MVC::MVC(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void MVC::on_pushButtonOpen_clicked()
{
	m_filename = QFileDialog::getOpenFileName(this, QStringLiteral("打开文件"), ".", "Image Files(*.jpg *.png *.bmp)");
	if (m_filename.isEmpty())
	{
		return;
	}
	ColorDetectController::getInstance()->setInputImage(m_filename.toLocal8Bit().toStdString());
	ui.labelImg->setPixmap(QPixmap(m_filename));
}

void MVC::on_pushButtonColor_clicked()
{
	m_color = QColorDialog::getColor(m_color, this);
	if (m_color.isValid())
	{
		ColorDetectController::getInstance()->setTargetColor(m_color.red(), m_color.green(), m_color.blue());
	}
}

void MVC::on_pushButtonProcess_clicked()
{
	ColorDetectController::getInstance()->setColorDistanceThreshold(ui.verticalSlider->value());
	ColorDetectController::getInstance()->process();
	m_result = ColorDetectController::getInstance()->getLastResult();
	if (!m_result.empty())
	{
		ui.labelImg->setPixmap(QPixmap::fromImage(Mat2QImage(m_result)));
	}
}

void MVC::on_verticalSlider_valueChanged(int value)
{
	QString text = "<html><head/><body><p>Color</p><p align=\"justify\">Distance</p><p>Threshold:" + QString::number(value) + "</p></body></html>";
	ui.label->setText(text);
}

void MVC::on_pushButtonSrc_pressed()
{
	ui.labelImg->setPixmap(QPixmap(m_filename));
}

void MVC::on_pushButtonSrc_released()
{
	if (!m_result.empty())
	{
		ui.labelImg->setPixmap(QPixmap::fromImage(Mat2QImage(m_result)));
	}
}
