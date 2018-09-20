#pragma execution_character_set("utf-8")

#include "basewindow.h"
#include <QGridLayout>
#include <QPainter>
#include <QDebug>
#include <QtMath>
#include <QMouseEvent>


BaseWindow::BaseWindow(QWidget *parent)
    : QWidget(parent),m_mainwid(this)
{
	m_leftButtonPressed = false;
	margin = 5;

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    m_mainwid.setAutoFillBackground(true);
    QGridLayout *mainLayout=new QGridLayout;
    mainLayout->addWidget(&m_mainwid);
    mainLayout->setContentsMargins(9,9,9,9);
    setLayout(mainLayout);
}

void BaseWindow::paintEvent(QPaintEvent *event){
	QPainter painter(this);
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(9, 9, this->width() - 18, this->height() - 18);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(50, 50, 50, 50);
	int margin = 9;
	for (int i = 0; i < margin; i++) {
		QPainterPath painterPath;
		painterPath.addRect(margin - i, margin - i, width() - (margin - i) * 2, height() - (margin - i) * 2);
		color.setAlpha(150 - qSqrt(i) * 50);
		painter.setPen(color);
		painter.drawPath(painterPath);
	}

}
void BaseWindow::mousePressEvent(QMouseEvent * event)
{
	//拖拽
	/*if (event->button() == Qt::LeftButton) {
		m_curPos = event->pos();
		m_leftButtonPressed = true;
	}*/
	if (event->button() == Qt::LeftButton) {
		if (QRect(margin + 1, margin + 1, width() - (margin + 1) * 2, height() - (margin + 1) * 2).contains(event->pos())) {
			m_leftButtonPressed=true;
			m_curPos = event->pos();
		}
		else 
			m_pressBorder=true;
	}

	
}
void BaseWindow::mouseMoveEvent(QMouseEvent * event)
{
	//拖拽、移动
	if (m_leftButtonPressed&&dir==Middle){
		move(pos() + event->pos() - m_curPos);
	}
	//改变界面大小
	region(event);
	if (m_pressBorder) {
		switch (dir)
		{
		case TopLeft:
			setGeometry(QCursor::pos().x(), QCursor::pos().y(), pos().x() + width() - QCursor::pos().x(), pos().y() + height() - QCursor::pos().x());
			break;
		case Top:
			setGeometry(pos().x(), QCursor::pos().y(), width(), pos().y() + height() - QCursor::pos().y());
			break;
		case TopRight:
			setGeometry(pos().x(), QCursor::pos().y(), QCursor::pos().x() - pos().x(), pos().y() + height() - QCursor::pos().y());
			break;
		case Right:
			setGeometry(pos().x(), pos().y(), QCursor::pos().x() - pos().x(), height());
			break;
		case BottomRight:
			setGeometry(pos().x(), pos().y(), QCursor::pos().x() - pos().x(), QCursor::pos().y() - pos().y());
			break;
		case Bottom:
			setGeometry(pos().x(), pos().y(), width(), QCursor::pos().y() - pos().y());
			break;
		case BottomLeft:
			setGeometry(QCursor::pos().x(), pos().y(), pos().x() + width() - QCursor::pos().x(), pos().y() + height() - QCursor::pos().y());
			break;
		case Left:
			setGeometry(QCursor::pos().x(), pos().y(), pos().x() + width() - QCursor::pos().x(), height());
			break;
		default:
			break;
		}
	}
	/*if (dir == TopLeft&&m_leftButtonPressed) {
		setGeometry(QCursor::pos().x(), QCursor::pos().y(), pos().x() + width() - QCursor::pos().x(), pos().y() + height() - QCursor::pos().x());
	}
	else if (dir == Top&&m_leftButtonPressed) {
		setGeometry(pos().x(), QCursor::pos().y(), width(), pos().y() + height() - QCursor::pos().y());
	}
	else if (dir == TopRight&&m_leftButtonPressed) {
		setGeometry(pos().x(), QCursor::pos().y(), QCursor::pos().x() - pos().x(), pos().y() + height() - QCursor::pos().y());
	}
	else if (dir == Right&&m_leftButtonPressed) {
		 setGeometry(pos().x(), pos().y(), QCursor::pos().x() - pos().x(), height());
	}
	else if (dir == BottomRight&&m_leftButtonPressed) {
		setGeometry(pos().x(), pos().y(), QCursor::pos().x() - pos().x(), QCursor::pos().y() - pos().y());
	}
	else if (dir == Bottom&&m_leftButtonPressed) {
		setGeometry(pos().x(), pos().y(), width(), QCursor::pos().y() - pos().y());
	}
	else if (dir == BottomLeft&&m_leftButtonPressed) {
		setGeometry(QCursor::pos().x(), pos().y(), pos().x() + width() - QCursor::pos().x(), pos().y() + height() - QCursor::pos().y());
	}
	else if (dir == Left&&m_leftButtonPressed) {
		setGeometry(QCursor::pos().x(), pos().y(), pos().x() + width() - QCursor::pos().x(), height());
	}*/
}
void BaseWindow::mouseReleaseEvent(QMouseEvent * event)
{
	m_leftButtonPressed = false;
	m_pressBorder=false;
}

void BaseWindow::region(QMouseEvent * event)
{
	if (QRect(0, 0, margin, margin).contains(event->pos())) {
		dir = TopLeft;
		setCursor(Qt::SizeFDiagCursor);
		//return true;
	}
	else if (QRect(margin, 0, width() - margin * 2, margin).contains(event->pos())) {
		dir = Top;
		setCursor(Qt::SizeVerCursor);
		//return true;
	}
	else if (QRect(width() - margin, 0, margin, margin).contains(event->pos())) {
		dir = TopRight;
		setCursor(Qt::SizeBDiagCursor);
		//return true;
	}
	else if (QRect(width() - margin, margin, margin, height() - margin * 2).contains(event->pos())) {
		dir = Right;
		setCursor(Qt::SizeHorCursor);
		//return true;
	}
	else if (bool test = QRect(width() - margin, height() - margin, margin, margin).contains(event->pos())) {
		dir = BottomRight;
		setCursor(Qt::SizeFDiagCursor);
		//return true;
	}
	else if (QRect(margin, height() - margin, width() - margin * 2, margin).contains(event->pos())) {
		dir = Bottom;
		setCursor(Qt::SizeVerCursor);
		//return true;
	}
	else if (QRect(0, height() - margin, margin, margin).contains(event->pos())) {
		dir = BottomLeft;
		setCursor(Qt::SizeBDiagCursor);
		//return true;
	}
	else if (QRect(0, margin, margin, height() - margin * 2).contains(event->pos())) {
		dir = Left;
		setCursor(Qt::SizeHorCursor);
		//return true;
	}
	else if(QRect(margin+1,margin+1,width()-(margin+1)*2,height()- (margin + 1) * 2).contains(event->pos())){
		dir = Middle;
		setCursor(Qt::ArrowCursor);
	}
}

void BaseWindow::resize()
{
}







Widget::Widget(QWidget *parent):QWidget(parent)
{
	//setAttribute(Qt::WA_TranslucentBackground, true);
    bool test=m_curPix.load(":/images/background_1.png");
	//setStyleSheet("Widget{background:transparent;}");

}

void Widget::setSkin(const QString &skin){
    m_curPix.load(skin);
    m_curPixPath=skin;
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
	int test=m_curPix.width();
	if (m_curPix.width()) {
		double h = width()*(m_curPix.height()) / m_curPix.width();
		/*if (h < height()) {
			painter.drawPixmap(0, 0, width(), height(),
				m_curPix, 0, 0, m_curPix.height()*width() / height(), m_curPix.height());
			return;
		}
		else if (h > height()) {
			painter.drawPixmap(0, 0, width(), height(),
				m_curPix, 0, 0, m_curPix.width(), height()*m_curPix.width() / width());
		}
		else if (h == height()) {
			painter.drawPixmap(0, 0, width(), height(), m_curPix);
			return;
		}*/
		/*painter.drawPixmap(0, 0, m_curPix.width(), m_curPix.height(), m_curPix,0,0,m_curPix.width(),m_curPix.height());*/
	}
	else
		qDebug() << "载入图像出错";
}

//
//void BaseWindow::mousePressEvent(QMouseEvent * event)
//{	
//	//拖拽
//	if (event->button()==Qt::LeftButton) {
//		m_curPos = event->pos();
//		m_leftButtonPressed = true;
//	}
//	
//	region(event);
//}
//
//void BaseWindow::mouseMoveEvent(QMouseEvent * event)
//{
//	//拖拽
//	if (m_leftButtonPressed) {
//		move(pos() + event->pos() - m_curPos);
//	}
//	//改变界面大小
//	
//
//}
//
//void BaseWindow::region(QMouseEvent * event)
//{
//	int margin = 5;
//	if (QRect(margin, margin, width() - margin, height() - margin).contains(event->pos())) {
//		setCursor(Qt::ArrowCursor);
//	}
//	else if (QRect(0, 0, margin, margin).contains(event->pos())) {
//		dir = TopLeft;
//		setCursor(Qt::SizeFDiagCursor);
//	}
//	else if (QRect(margin, 0, width() - margin * 2, margin).contains(event->pos())) {
//		dir = Top;
//		setCursor(Qt::SizeVerCursor);
//	}
//	else if (QRect(width() - margin, 0, margin, margin).contains(event->pos())) {
//		dir = TopRight;
//		setCursor(Qt::SizeBDiagCursor);
//	}
//	else if (QRect(width() - margin, margin, margin, height() - margin * 2).contains(event->pos())) {
//		dir = Right;
//		setCursor(Qt::SizeHorCursor);
//	}
//	else if (bool test = QRect(width() - margin, height() - margin, margin, margin).contains(event->pos())) {
//		dir = BottomRight;
//		setCursor(Qt::SizeFDiagCursor);
//	}
//	else if (QRect(margin, height() - margin, width() - margin * 2, margin).contains(event->pos())) {
//		dir = Bottom;
//		setCursor(Qt::SizeVerCursor);
//	}
//	else if (QRect(0, height() - margin, margin, margin).contains(event->pos())) {
//		dir = BottomLeft;
//		setCursor(Qt::SizeBDiagCursor);
//	}
//	else if (QRect(0, margin, margin, height() - margin * 2).contains(event->pos())) {
//		dir = Left;
//		setCursor(Qt::SizeHorCursor);
//	}
//}
//
//void BaseWindow::mouseReleaseEvent(QMouseEvent * event)
//{
//	m_leftButtonPressed = false;
//}


