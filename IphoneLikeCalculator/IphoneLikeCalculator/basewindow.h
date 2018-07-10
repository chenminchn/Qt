#pragma once

#include <QWidget>

class baseWindow : public QWidget
{
	Q_OBJECT

public:
	baseWindow(QWidget *parent);
	~baseWindow();

protected:
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	bool m_pressed;
private:

	QPoint m_pos;
};
