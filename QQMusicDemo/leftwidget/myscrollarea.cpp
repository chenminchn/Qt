#include "myscrollarea.h"
#include <QScrollBar>

MyScrollArea::MyScrollArea(QWidget *parent)
	: QScrollArea(parent)
{
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFrameShadow(QFrame::Plain);
	setFrameShape(QFrame::NoFrame);//È¥µô±ß¿ò
	setStyleSheet("QScrollArea{background:transparent;}");
	setWidgetResizable(true);
	QScrollBar *scrollBar = verticalScrollBar();
	scrollBar->setStyleSheet(
		"QScrollBar{width:10px;background:transparent;padding-right:2px;}"
		"QScrollBar::handle{width: 8px;min-height: 20px;background: rgb(190, 190, 190);border-radius:4px;}"
		"QScrollBar::handle:hover{background: rgb(170, 170, 170);}"
		"QScrollBar::sub-line:vertical{width:0px;height:0px;}"
		"QScrollBar::add-line:vertical{width:0px;height:0px;}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background:transparent;}"
	);
}

MyScrollArea::~MyScrollArea()
{
}
