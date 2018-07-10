#pragma once

#include "basewidget.h"
#include <QPushButton>
#include "mypushbutton.h"

class bottomWidget : public baseWidget
{
	Q_OBJECT

public:
	bottomWidget(QWidget *parent);
	void initWidget();
	QSize sizeHint() const;
	~bottomWidget();

	MyPushButton *m_btnLeftBracket;
	MyPushButton *m_btnRightBracket;
	MyPushButton *m_btnMemClear;
	MyPushButton *m_btnMemPlus;
	MyPushButton *m_btnMemMinus;
	MyPushButton *m_btnMemRecall;

	MyPushButton *m_btnsecond;
	MyPushButton *m_btnsquare;
	MyPushButton *m_btncube;
	MyPushButton *m_btnpower;
	MyPushButton *m_btnex;
	MyPushButton *m_btntenX;

	MyPushButton *m_btnoneX;
	MyPushButton *m_btnsquareRoot;
	MyPushButton *m_btnthreeRoot;
	MyPushButton *m_btnyRoot;
	MyPushButton *m_btnln;
	MyPushButton *m_btnlogTen;

	MyPushButton *m_btnxFactorial;
	MyPushButton *m_btnsin;
	MyPushButton *m_btncos;
	MyPushButton *m_btntan;
	MyPushButton *m_btne;
	MyPushButton *m_btnEE;

	MyPushButton *m_btnRad;
	MyPushButton *m_btnsinh;
	MyPushButton *m_btncosh;
	MyPushButton *m_btntanh;
	MyPushButton *m_btnPi;
	MyPushButton *m_btnRand;

	MyPushButton *m_btnC;
	MyPushButton *m_btnplusminus;
	MyPushButton *m_btnpercent;
	MyPushButton *m_btndivide;
	MyPushButton *m_btntimes;
	MyPushButton *m_btnminus;
	MyPushButton *m_btnplus;
	MyPushButton *m_btnequal;
	MyPushButton *m_btnpoint;

	MyPushButton *m_btnNum[10];

public slots:

	
};
