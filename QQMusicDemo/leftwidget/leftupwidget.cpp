#include "leftupwidget.h"
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QVBoxLayout>
#include <QHBoxLayout>

LeftUpWidget::LeftUpWidget(QWidget *parent)
	: BaseWidget(parent)
{
	setFixedHeight(147);
	lb_head = new QLabel(this);
	QLabel *lb_profile = new QLabel(this);
	lb_profile->setAlignment(Qt::AlignCenter);
	lb_profile->setText("chenmin");
	
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addStretch();
	vLayout->addWidget(lb_head);
	vLayout->addSpacing(20);
	vLayout->addWidget(lb_profile);
	vLayout->addStretch();
	vLayout->setSpacing(0);
	vLayout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addStretch();
	hLayout->addLayout(vLayout);
	hLayout->addStretch();

	setLayout(hLayout); 
}

LeftUpWidget::~LeftUpWidget()
{
}

void LeftUpWidget::paintEvent(QPaintEvent * event)
{
	QPixmap photo(":/images/leftwidget/profilephoto.jpg");
	QPixmap pix(54, 54);
	pix.fill(Qt::transparent);
	QPainter painter(&pix);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	QPainterPath path;
	path.addEllipse(0, 0, 54, 54);
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, 54, 54, photo);
	lb_head->setPixmap(pix);
}
