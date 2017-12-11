#include "MVC.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MVC w;
	w.show();
	return a.exec();
}
