#include "iphonelikecalculator.h"
#include <QVBoxLayout>
//#include <qpushbutton.h>
#include "mypushbutton.h"

IphoneLikeCalculator::IphoneLikeCalculator(QWidget *parent)
	: baseWindow(parent)
{
	m_pressed = false;

	setWindowFlags(Qt::FramelessWindowHint);
	setMouseTracking(true);
	setFixedSize(1136, 640);
	//setAttribute(Qt::WA_DeleteOnClose);
	initWidget();
	initConnection();
}

//void IphoneLikeCalculator::closeEvent(QCloseEvent * event)
//{
//	event->ignore();
//}
//bool IphoneLikeCalculator::eventFilter(QObject * obj, QEvent * event)
//{
//	if (obj == topwid) {
//		if (event->type() == QEvent::Close) {
//			//QCloseEvent *closeEvent = static_cast<QCloseEvent*>(event);
//			event->accept();
//			return true;
//		}
//		else
//			return false;
//	}
//	return QWidget::eventFilter(obj, event);
//}
void IphoneLikeCalculator::minimize()
{
	showMinimized();

}

void IphoneLikeCalculator::initWidget()
{
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	topwid = new topWidget(this);
	middlewid = new middleWidget(this);
	bottomwid = new bottomWidget(this);

	connect(topwid, SIGNAL(miniWindow()), this, SLOT(minimize()));
	connect(topwid, SIGNAL(closeWindow()), this, SLOT(close()));

	mainLayout->addWidget(topwid);
	mainLayout->addWidget(middlewid);
	mainLayout->addWidget(bottomwid);
	mainLayout->setSpacing(0);
	mainLayout->setMargin(0);

	setLayout(mainLayout);
}

void IphoneLikeCalculator::initConnection()
{
	connect(bottomwid->m_btnLeftBracket, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnRightBracket, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnMemClear, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnMemPlus, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnMemMinus, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnMemRecall, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnsecond, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnsquare, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btncube, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnpower, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnex, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btntenX, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnoneX, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnsquareRoot, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnthreeRoot, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnyRoot, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnln, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnlogTen, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnxFactorial, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnsin, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btncos, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btntan, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btne, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnEE, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnRad, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnsinh, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btncosh, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btntanh, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnPi, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnRand, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnC, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnplusminus, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnpercent, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btndivide, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btntimes, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnminus, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnplus, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnequal, SIGNAL(clicked()), this, SLOT(keysDown()));
	connect(bottomwid->m_btnpoint, SIGNAL(clicked()), this, SLOT(keysDown()));
	for (int i = 0; i < 10; i++)
	{
		connect(bottomwid->m_btnNum[i], SIGNAL(clicked()), this, SLOT(keysDown()));
	}
}

void IphoneLikeCalculator::keysDown()
{
	MyPushButton *button = qobject_cast<MyPushButton*>(sender());
	middlewid->display->setText(button->objectName());
}
