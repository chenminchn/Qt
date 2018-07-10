#pragma once

#include "basewidget.h"
#include <QLineEdit>
#include <QPalette>

class middleWidget : public baseWidget
{
	Q_OBJECT

public:
	middleWidget(QWidget *parent);
	QSize sizeHint() const;
	void initWidget();
	~middleWidget();

	QLineEdit *display;
};
