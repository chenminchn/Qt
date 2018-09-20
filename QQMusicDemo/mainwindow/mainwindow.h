#ifndef WIDGET_H
#define WIDGET_H

#include "basewindow.h"
#include "leftwidget.h"
#include "mainwidget.h"
#include "topwidget.h"
#include "bottomwidget.h"

class MainWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);
private:
	TopWidget m_topwid;
	LeftWidget m_leftwid;
	MainWidget m_mainwid;
	BottomWidget m_bottomwid;

	void initLayout();
	void initConnection();
};

#endif // WIDGET_H
