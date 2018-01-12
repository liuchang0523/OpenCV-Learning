#include "CameraCalib.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CameraCalib w;
	w.show();
	return a.exec();
}
