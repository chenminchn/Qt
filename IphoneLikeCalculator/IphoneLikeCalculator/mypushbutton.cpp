#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent)
	: QPushButton(parent)
{
	//setFlat(true);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
	//setStyleSheet("QPushButton{padding: 20px;}");
	//setMaximumSize(100, 100);
}

MyPushButton::~MyPushButton()
{
}
