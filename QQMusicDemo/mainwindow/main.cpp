#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	/*QFile qssFile(":/qss/myStyle.qss");
	if (!qssFile.open(QFile::ReadOnly)) {
		qDebug() << "can not open the qss file myStyle.qss";
		return -1;
	}
	QString test = qssFile.readAll();
	qDebug() << test;
	qApp->setStyleSheet(qssFile.readAll());
	qssFile.close();*/
    MainWindow w;
    w.show();

    return a.exec();
}
