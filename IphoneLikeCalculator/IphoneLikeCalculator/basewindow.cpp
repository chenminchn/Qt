#include "basewindow.h"
#include <QMouseEvent>

baseWindow::baseWindow(QWidget *parent)
	: QWidget(parent)
{
	m_pressed = true;
}

baseWindow::~baseWindow()
{
}

void baseWindow::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		m_pressed = true;
		m_pos = event->pos();
	}
}

void baseWindow::mouseMoveEvent(QMouseEvent * event)
{
	if (m_pressed)
		move(event->pos() - m_pos + pos());
}

void baseWindow::mouseReleaseEvent(QMouseEvent * event)
{
	Q_UNUSED(event);
	m_pressed = false;


}