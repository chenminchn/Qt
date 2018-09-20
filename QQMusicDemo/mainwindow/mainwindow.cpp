#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainstackwidget0.h"
#include "mainstackwidget1.h"
#include "mainstackwidget2.h"
#include "mainstackwidget3.h"
#include "mainstackwidget4.h"
#include "mainstackwidget5.h"
#include "mainstackwidget6.h"
#include "mainstackwidget7.h"

MainWindow::MainWindow(QWidget *parent)
    :BaseWindow(parent)
	,m_topwid(this)
	,m_leftwid(this)
	,m_mainwid(this)
	,m_bottomwid(this)
{
    setMinimumSize(1010,600);
	BaseWindow::m_mainwid.setStyleSheet("Widget{background:rgb(255,255,255);}");
	initLayout();
	initConnection();
}

void MainWindow::initLayout() {
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addWidget(&m_topwid);
	vLayout->addWidget(&m_mainwid);

	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addWidget(&m_leftwid);
	hLayout->addLayout(vLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(hLayout);
	mainLayout->addWidget(&m_bottomwid);

	mainLayout->setSpacing(0);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	BaseWindow::m_mainwid.setLayout(mainLayout);
}

void MainWindow::initConnection()
{
	connect(&m_leftwid, SIGNAL(sig_switchPage(int)), &m_mainwid, SLOT(slot_switchPage(int)));
}
