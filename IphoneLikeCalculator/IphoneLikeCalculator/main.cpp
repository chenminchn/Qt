#include "iphonelikecalculator.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include "qsshelper.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/*QFile qss("style.qss");
	if (!qss.open(QFile::ReadOnly))
		return -1;
	qApp->setStyleSheet(qss.readAll());*/
	QSSHelper::setStyle("style.qss");
	IphoneLikeCalculator w;
	w.show();
	return a.exec();
}
