#pragma once

#include <QScrollArea>

class MyScrollArea : public QScrollArea
{
	Q_OBJECT

public:
	explicit MyScrollArea(QWidget *parent = 0);
	~MyScrollArea();
};
