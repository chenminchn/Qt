#pragma once

#include <QtWidgets/QDialog>
#include "ui_calculatecodenum.h"
#include <QMap>
#include <QString>
#include <QVector>

class QStringList;

class calculateCodeNum : public QDialog
{
	Q_OBJECT

public:
	calculateCodeNum(QWidget *parent = Q_NULLPTR);

private slots:
	void calculate();

private:
	QStringList DirectoryOf();
	void filesPath();
	void showResult();


	Ui::calculateCodeNumClass ui;
	QMap<QString, QVector<int> > map;
};
