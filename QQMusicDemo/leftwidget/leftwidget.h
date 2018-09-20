#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H
#include "basewidget.h"

class LeftWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent=0);

signals:
	void sig_switchPage(int);
};

#endif // LEFTWIDGET_H
