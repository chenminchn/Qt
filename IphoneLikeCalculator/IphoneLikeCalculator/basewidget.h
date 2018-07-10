#pragma once

#include <QObject>
#include <QWidget>

class baseWidget : public QWidget
{
	Q_OBJECT

public:
	baseWidget(QWidget *parent);
	~baseWidget();

protected:
	virtual void paintEvent(QPaintEvent *e);

private:
};
