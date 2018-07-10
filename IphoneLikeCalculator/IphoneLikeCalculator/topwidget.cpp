#include "topwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
//#include<QAbstractButton>
//#include<QIcon>
//#include "pushbutton.h"
#include <QSpacerItem>


topWidget::topWidget(QWidget *parent)
	: baseWidget(parent)
{
	setStyleSheet("topWidget{background: white;}");
	setMouseTracking(true);
	setFixedSize(1136, 26);

	initLayout();
}

QSize topWidget::sizeHint() const
{
	return QSize(1136,40);
}

void topWidget::initLayout()
{
	QHBoxLayout *hLayout = new QHBoxLayout(this);

	m_btnmini = new QPushButton(this);
	m_btnclose = new QPushButton(this);

	m_btnmini->setFlat(true);
	m_btnclose->setFlat(true);

	m_btnmini->setFixedSize(26, 26);
	m_btnclose->setFixedSize(26, 26);
	m_btnmini->setStyleSheet(
		"QPushButton{border: none; border-image: url(:/images/min.png);}"
		"QPushButton::hover{border: none; border-image: url(:/images/min_hover.png);}"
		"QPushButton::pressed{border: none; border-image: url(:/images/min_click.png);}"
	);
	m_btnclose->setStyleSheet(
		"QPushButton{border: none; border-image: url(:/images/close.png)}"
		"QPushButton::hover{border: none; border-image: url(:/images/close_hover.png);}"
		"QPushButton::pressed{border: none; border-image: url(:/images/close_click.png);}"
	);
	connect(m_btnmini, SIGNAL(clicked()), this, SLOT(miniBtnClicked()));
	connect(m_btnclose, SIGNAL(clicked()), this, SLOT(closeBtnClicked()));
	
	hLayout->addSpacerItem(new QSpacerItem(1100, 26, QSizePolicy::Maximum, QSizePolicy::Fixed));
	hLayout->addWidget(m_btnmini);
	hLayout->addWidget(m_btnclose);
	hLayout->setSpacing(0);
	hLayout->setContentsMargins(0, 0, 0, 0);

	setLayout(hLayout);
}

topWidget::~topWidget()
{
}

void topWidget::closeBtnClicked() 
{
	emit closeWindow();
}

void topWidget::miniBtnClicked()
{
	emit miniWindow();
}





