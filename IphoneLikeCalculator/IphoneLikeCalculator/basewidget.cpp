#include "basewidget.h"
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>

baseWidget::baseWidget(QWidget *parent)
	: QWidget(parent)
{
	setMouseTracking(true);
}

baseWidget::~baseWidget()
{
}

void baseWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


