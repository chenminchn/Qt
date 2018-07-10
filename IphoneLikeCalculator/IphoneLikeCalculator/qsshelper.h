#pragma once
#include <QFile>
#include <QString>
#include <QApplication>

class QSSHelper
{
public:
	static void setStyle(const QString& fileName)
	{
		QFile qssFile(fileName);
		if (!qssFile.open(QFile::ReadOnly))
			return;
		qApp->setStyleSheet(qssFile.readAll());
	}
};
