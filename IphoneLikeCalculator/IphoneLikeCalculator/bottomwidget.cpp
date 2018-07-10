#include "bottomwidget.h"
#include <QHBoxLayout>
//#include <QPushButton>
#include<QGridLayout>

bottomWidget::bottomWidget(QWidget *parent)
	: baseWidget(parent)
{
	setMouseTracking(true);
	setStyleSheet(
		"bottomWidget{background: black;}"
	);

	initWidget();
}

void bottomWidget::initWidget()
{
	QGridLayout *mainLayout = new QGridLayout(this);

	m_btnLeftBracket = new MyPushButton(this);
	m_btnRightBracket = new MyPushButton(this);
	m_btnMemClear = new MyPushButton(this);
	m_btnMemPlus = new MyPushButton(this); 
	m_btnMemMinus = new MyPushButton(this);
	m_btnMemRecall = new MyPushButton(this);
	m_btnsecond = new MyPushButton(this);
	m_btnsquare = new MyPushButton(this);
	m_btncube = new MyPushButton(this);
	m_btnpower = new MyPushButton(this);
	m_btnex = new MyPushButton(this);
	m_btntenX = new MyPushButton(this);
	m_btnoneX = new MyPushButton(this);
	m_btnsquareRoot = new MyPushButton(this);
	m_btnthreeRoot = new MyPushButton(this);
	m_btnyRoot = new MyPushButton(this);
	m_btnln = new MyPushButton(this);
	m_btnlogTen = new MyPushButton(this);
	m_btnxFactorial = new MyPushButton(this);
	m_btnsin = new MyPushButton(this);
	m_btncos = new MyPushButton(this);
	m_btntan = new MyPushButton(this);
	m_btne = new MyPushButton(this);
	m_btnEE = new MyPushButton(this);
	m_btnRad = new MyPushButton(this);
	for (int i = 0; i < 10; i++) {
		m_btnNum[i] = new MyPushButton(this);
	}
	m_btnsinh = new MyPushButton(this);
	m_btncosh = new MyPushButton(this);
	m_btntanh = new MyPushButton(this);
	m_btnPi = new MyPushButton(this);
	m_btnRand = new MyPushButton(this);
	m_btnC = new MyPushButton(this);
	m_btnplusminus = new MyPushButton(this);
	m_btnpercent = new MyPushButton(this);
	m_btndivide = new MyPushButton(this);
	m_btntimes = new MyPushButton(this);
	m_btnminus = new MyPushButton(this);
	m_btnplus = new MyPushButton(this);
	m_btnequal = new MyPushButton(this);
	m_btnpoint = new MyPushButton(this);

	m_btnLeftBracket->setObjectName("leftbracket");
	m_btnRightBracket->setObjectName("rightbracket");
	m_btnMemClear->setObjectName("memclear");
	m_btnMemPlus->setObjectName("mempuls");
	m_btnMemMinus->setObjectName("memminus");
	m_btnMemRecall->setObjectName("memrecall");
	m_btnsecond->setObjectName("second");
	m_btnsquare->setObjectName("square");
	m_btncube->setObjectName("cube");
	m_btnpower->setObjectName("power");
	m_btnex->setObjectName("ex");
	m_btntenX->setObjectName("tenx");
	m_btnoneX->setObjectName("onex");
	m_btnsquareRoot->setObjectName("squareroot");
	m_btnthreeRoot->setObjectName("threeroot");
	m_btnyRoot->setObjectName("yroot");
	m_btnln->setObjectName("ln");
	m_btnlogTen->setObjectName("logten");
	m_btnxFactorial->setObjectName("xfactorial");
	m_btnsin->setObjectName("sin");
	m_btncos->setObjectName("cos");
	m_btntan->setObjectName("tan");
	m_btne->setObjectName("e");
	m_btnEE->setObjectName("EE");
	m_btnRad->setObjectName("rad");
	m_btnsinh->setObjectName("sinh");
	m_btncosh->setObjectName("cosh");
	m_btntanh->setObjectName("tanh");
	m_btnPi->setObjectName("pi");
	m_btnRand->setObjectName("rand");
	m_btnC->setObjectName("ac");
	m_btnplusminus->setObjectName("plusminus");
	m_btnpercent->setObjectName("percent");
	m_btndivide->setObjectName("divide");
	m_btntimes->setObjectName("times");
	m_btnminus->setObjectName("minus");
	m_btnplus->setObjectName("plus");
	m_btnequal->setObjectName("equal");
	m_btnpoint->setObjectName("point");
	m_btnNum[0]->setObjectName("num0");
	m_btnNum[1]->setObjectName("num1");
	m_btnNum[2]->setObjectName("num2");
	m_btnNum[3]->setObjectName("num3");
	m_btnNum[4]->setObjectName("num4");
	m_btnNum[5]->setObjectName("num5");
	m_btnNum[6]->setObjectName("num6");
	m_btnNum[7]->setObjectName("num7");
	m_btnNum[8]->setObjectName("num8");
	m_btnNum[9]->setObjectName("num9");

	mainLayout->addWidget(m_btnLeftBracket, 0, 0, 1, 1);
	mainLayout->addWidget(m_btnRightBracket, 0, 1, 1, 1);
	mainLayout->addWidget(m_btnMemClear, 0, 2, 1, 1);
	mainLayout->addWidget(m_btnMemPlus, 0, 3, 1, 1);
	mainLayout->addWidget(m_btnMemMinus, 0, 4, 1, 1);
	mainLayout->addWidget(m_btnMemRecall, 0, 5, 1, 1);
	mainLayout->addWidget(m_btnC, 0, 6, 1, 1);
	mainLayout->addWidget(m_btnplusminus, 0, 7, 1, 1);
	mainLayout->addWidget(m_btnpercent, 0, 8, 1, 1);
	mainLayout->addWidget(m_btndivide, 0, 9, 1, 1);

	mainLayout->addWidget(m_btnsecond, 1, 0, 1, 1);
	mainLayout->addWidget(m_btnsquare, 1, 1, 1, 1);
	mainLayout->addWidget(m_btncube, 1, 2, 1, 1);
	mainLayout->addWidget(m_btnpower, 1, 3, 1, 1);
	mainLayout->addWidget(m_btnex, 1, 4, 1, 1);
	mainLayout->addWidget(m_btntenX, 1, 5, 1, 1);
	mainLayout->addWidget(m_btnNum[7], 1, 6, 1, 1);
	mainLayout->addWidget(m_btnNum[8], 1, 7, 1, 1);
	mainLayout->addWidget(m_btnNum[9], 1, 8, 1, 1);
	mainLayout->addWidget(m_btntimes, 1, 9, 1, 1);

	mainLayout->addWidget(m_btnoneX, 2, 0, 1, 1);
	mainLayout->addWidget(m_btnsquareRoot, 2, 1, 1, 1);
	mainLayout->addWidget(m_btnthreeRoot, 2, 2, 1, 1);
	mainLayout->addWidget(m_btnyRoot, 2, 3, 1, 1);
	mainLayout->addWidget(m_btnln, 2, 4, 1, 1);
	mainLayout->addWidget(m_btnlogTen, 2, 5, 1, 1);
	mainLayout->addWidget(m_btnNum[4], 2, 6, 1, 1);
	mainLayout->addWidget(m_btnNum[5], 2, 7, 1, 1);
	mainLayout->addWidget(m_btnNum[6], 2, 8, 1, 1);
	mainLayout->addWidget(m_btnminus, 2, 9, 1, 1);

	mainLayout->addWidget(m_btnxFactorial, 3, 0, 1, 1);
	mainLayout->addWidget(m_btnsin, 3, 1, 1, 1);
	mainLayout->addWidget(m_btncos, 3, 2, 1, 1);
	mainLayout->addWidget(m_btntan, 3, 3, 1, 1);
	mainLayout->addWidget(m_btne, 3, 4, 1, 1);
	mainLayout->addWidget(m_btnEE, 3, 5, 1, 1);
	mainLayout->addWidget(m_btnEE, 3, 5, 1, 1);
	mainLayout->addWidget(m_btnNum[1], 3, 6, 1, 1);
	mainLayout->addWidget(m_btnNum[2], 3, 7, 1, 1);
	mainLayout->addWidget(m_btnNum[3], 3,8, 1, 1);
	mainLayout->addWidget(m_btnplus, 3, 9, 1, 1);

	mainLayout->addWidget(m_btnRad, 4, 0, 1, 1);
	mainLayout->addWidget(m_btnsinh, 4, 1, 1, 1);
	mainLayout->addWidget(m_btncosh, 4, 2, 1, 1);
	mainLayout->addWidget(m_btntanh, 4, 3, 1, 1);
	mainLayout->addWidget(m_btnPi, 4, 4, 1, 1);
	mainLayout->addWidget(m_btnRand, 4, 5, 1, 1);
	mainLayout->addWidget(m_btnNum[0], 4, 6, 1, 2);
	mainLayout->addWidget(m_btnpoint, 4, 8, 1, 1);
	mainLayout->addWidget(m_btnequal, 4, 9, 1, 1);
	mainLayout->setSpacing(11);
	mainLayout->setContentsMargins(10, 10, 10, 10);
	setLayout(mainLayout);
}

QSize bottomWidget::sizeHint() const
{
	return QSize(1136,300);
}

bottomWidget::~bottomWidget()
{
}

