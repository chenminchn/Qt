#include "basewidget.h"
#include <QPainter>
#include <QStyleOption>

BaseWidget::BaseWidget(QWidget *parent) : QWidget(parent)
{
	setMouseTracking(true);
	setStyleSheet("QWidget{background:transparent;}");
}

void BaseWidget::paintEvent(QPaintEvent *event) 
{
	QStyleOption opt;
	opt.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
