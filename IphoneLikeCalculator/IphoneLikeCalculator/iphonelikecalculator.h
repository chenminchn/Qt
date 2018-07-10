#pragma once

#include "basewindow.h"
#include "topwidget.h"
#include "middlewidget.h"
#include "bottomwidget.h"

class IphoneLikeCalculator : public baseWindow
{
	Q_OBJECT

public:
	IphoneLikeCalculator(QWidget *parent = Q_NULLPTR);

public slots:
	void minimize();

private slots:
	void keysDown();

protected:

private:
	void initWidget();
	void initConnection();

	topWidget *topwid;
	middleWidget *middlewid;
	bottomWidget *bottomwid;
	
};
