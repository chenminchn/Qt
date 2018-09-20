#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include "basewidget.h"

class MyPushButton;

class QLineEdit;

class TopWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent=0);

private:
	void initWidget();
	void initSearchLineEdit();

	//MyPushButton *m_btnReturn;
	QLineEdit *m_lineEdit;
};

#endif // TOPWIDGET_H
