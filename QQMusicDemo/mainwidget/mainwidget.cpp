#include "mainwidget.h"
#include <QVBoxLayout>
#include <QStackedWidget>

MainWidget::MainWidget(QWidget *parent)
	:BaseWidget(parent),
	m_Swidget0(this),
	m_Swidget1(this),
	m_Swidget2(this),
	m_Swidget3(this),
	m_Swidget4(this),
	m_Swidget5(this),
	m_Swidget6(this),
	m_Swidget7(this)
{
	setMouseTracking(true);
	//setMinimumSize(792, 530);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
	setStyleSheet("BaseWidget{background:rgb(231,232,233);}");
	initLayout();
}

void MainWidget::initLayout()
{
	QVBoxLayout *vLayout = new QVBoxLayout;
	m_stackWid.addWidget(&m_Swidget0);
	m_stackWid.addWidget(&m_Swidget1);
	m_stackWid.addWidget(&m_Swidget2);
	m_stackWid.addWidget(&m_Swidget3);
	m_stackWid.addWidget(&m_Swidget4);
	m_stackWid.addWidget(&m_Swidget5);
	m_stackWid.addWidget(&m_Swidget6);
	m_stackWid.addWidget(&m_Swidget7);
	vLayout->addWidget(&m_stackWid);
	setLayout(vLayout);
}

void MainWidget::slot_switchPage(int index)
{
	m_stackWid.setCurrentIndex(index);
}



