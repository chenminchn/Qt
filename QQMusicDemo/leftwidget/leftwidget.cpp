#include "leftwidget.h"
#include "leftupwidget.h"
#include <QScrollArea>
#include "leftdownwid.h"
#include <QVBoxLayout>
#include "basewidget.h"


LeftWidget::LeftWidget(QWidget *parent):BaseWidget(parent)
{
	setMouseTracking(true);
	setMinimumWidth(200);
	setMaximumWidth(234);
	setMinimumHeight(530);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	setStyleSheet(
		"BaseWidget{background:rgb(239,240,240);}"
		"QWidget{color:rgb(73,73,73);}"		
	);
	LeftUpWidget *m_leftUpWid = new LeftUpWidget(this);
	LeftDownWid *m_leftDownScrollArea = new LeftDownWid(this);
	m_leftDownScrollArea->setWidget(m_leftDownScrollArea->mWidget());
	
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addWidget(m_leftUpWid);
	vLayout->addWidget(m_leftDownScrollArea);
	vLayout->setSpacing(0);
	vLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(vLayout);

	connect(m_leftDownScrollArea, SIGNAL(sig_switchPage(int)), this, SIGNAL(sig_switchPage(int)));
}
