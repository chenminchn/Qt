#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "basewidget.h"
#include <QStackedWidget>

#include "mainstackwidget0.h"
#include "mainstackwidget1.h"
#include "mainstackwidget2.h"
#include "mainstackwidget3.h"
#include "mainstackwidget4.h"
#include "mainstackwidget5.h"
#include "mainstackwidget6.h"
#include "mainstackwidget7.h"

class MainWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent=0);
public slots:
	void slot_switchPage(int);
private:
	void initLayout();

	QStackedWidget m_stackWid;
	MainStackWidget0 m_Swidget0;
	MainStackWidget1 m_Swidget1;
	MainStackWidget2 m_Swidget2;
	MainStackWidget3 m_Swidget3;
	MainStackWidget4 m_Swidget4;
	MainStackWidget5 m_Swidget5;
	MainStackWidget6 m_Swidget6;
	MainStackWidget7 m_Swidget7;
};

#endif // MAINWIDGET_H
