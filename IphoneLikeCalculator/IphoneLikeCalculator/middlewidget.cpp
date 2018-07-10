#include "middlewidget.h"
#include <QHBoxLayout>
//#include <QPushButton>
#include <QFont>

middleWidget::middleWidget(QWidget *parent)
	: baseWidget(parent)
{
	setMouseTracking(true);
	setStyleSheet("middleWidget{background: black;}");
	setFixedSize(1136, 150);
	initWidget();
};

QSize middleWidget::sizeHint() const
{
	return QSize(1136,100);
}

void middleWidget::initWidget()
{
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	display = new QLineEdit(this);
	display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	display->setStyleSheet("QLineEdit{border: none; background-color: black; color: white;}");
	/*QPalette palette;
	palette.setColor(QPalette::Background, Qt::black);
	display->setPalette(palette);*/
	display->setFont(QFont("Microsoft YaHei", 60, QFont::Bold));
	display->setAlignment(Qt::AlignBottom | Qt::AlignRight);
	mainLayout->addWidget(display);

	setLayout(mainLayout);
	adjustSize();
}

middleWidget::~middleWidget()
{
}
