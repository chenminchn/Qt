#pragma once

#include "basewidget.h"

class QLabel;

class LeftUpWidget : public BaseWidget
{
	Q_OBJECT

public:
	LeftUpWidget(QWidget *parent);
	~LeftUpWidget();
protected:
	void paintEvent(QPaintEvent *event);
private:
	QLabel *lb_head;
};
