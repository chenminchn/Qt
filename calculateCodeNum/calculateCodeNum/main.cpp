#include "calculatecodenum.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	calculateCodeNum w;
	w.show();
	return a.exec();
}
