#pragma once

#include "basewidget.h"
#include <QPushButton>
#include <QCloseEvent>

class topWidget : public baseWidget
{
	Q_OBJECT

public:
	topWidget(QWidget *parent);
	QSize sizeHint() const;
	void initLayout();
	~topWidget();

signals:
	void closeWindow();
	void miniWindow();


public slots:
	void miniBtnClicked();
	void closeBtnClicked();
	


protected:

	QPushButton *m_btnmini;
	QPushButton *m_btnclose;
	
	//void closeEvent(QCloseEvent *event);
};
