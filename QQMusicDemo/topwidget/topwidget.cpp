#pragma execution_character_set("utf-8")

#include "topwidget.h"
#include <QHBoxLayout>
#include "mybutton.h"
#include <QLineEdit>
#include <QLabel>

TopWidget::TopWidget(QWidget *parent)
    :BaseWidget(parent)
{
	//setMouseTracking(true);
	setFixedHeight(50);
	//setMinimumHeight(50);
	//setMinimumWidth(792);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setStyleSheet("BaseWidget{background:rgb(247,247,248);}");
	initWidget();
}

void TopWidget::initWidget()
{
	QHBoxLayout *mainLayout = new QHBoxLayout;

	/*********************************layout1***********************************/
	MyPushButton *m_btnReturn = new MyPushButton(this);
	m_btnReturn->setFixedSize(20, 20);
	m_btnReturn->setObjectName("return");
	m_btnReturn->setStyleSheet(
		"MyPushButton{border-image:url(:/images/topwidget/btn_return(1).png);}"
		"MyPushButton::hover{border-image:url(:/images/topwidget/btn_return(2).png);}"
		"MyPushButton::pressed{border-image:url(:/images/topwidget/btn_return(3).png);}"
	);

	MyPushButton *m_btnNext=new MyPushButton(this);
	m_btnNext->setFixedSize(20, 20);
	m_btnReturn->setObjectName("next");
	m_btnNext->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_next(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_next(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_next(3).png);}"
	);

	MyPushButton *m_btnRefresh = new MyPushButton(this);
	m_btnRefresh->setFixedSize(20, 20);
	m_btnRefresh->setObjectName("refresh");
	m_btnRefresh->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_refresh(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_refresh(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_refresh(3).png);}"
	);

	initSearchLineEdit();

	MyPushButton *songRecognition = new MyPushButton(this);
	songRecognition->setFixedSize(20, 20);
	songRecognition->setObjectName("recognition");
	songRecognition->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_musicRecg(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_musicRecg(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_musicRecg(3).png);}"
	);


	QHBoxLayout *hLayout1 = new QHBoxLayout;
	hLayout1->addWidget(m_btnReturn);
	hLayout1->addWidget(m_btnNext);
	hLayout1->addWidget(m_btnRefresh);
	hLayout1->addWidget(m_lineEdit);
	hLayout1->addWidget(songRecognition);
	hLayout1->setSpacing(10);

	/********************************layout2***********************************/
	MyPushButton *m_btnMsg = new MyPushButton(this);
	m_btnMsg->setFixedSize(25, 25);
	m_btnReturn->setObjectName("msg");
	m_btnMsg->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_msg(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_msg(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_msg(3).png);}"
	);

	MyPushButton *m_btnVIP = new MyPushButton(this);
	m_btnVIP->setFixedSize(20, 20);
	m_btnReturn->setObjectName("vip");
	m_btnVIP->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_VIP(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_VIP(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_VIP(3).png);}"
	);

	MyPushButton *m_btnSkin = new MyPushButton(this);
	m_btnSkin->setFixedSize(20, 20);
	m_btnReturn->setObjectName("skin");
	m_btnSkin->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_skin(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_skin(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_skin3).png);}"
	);

	MyPushButton *m_btnMainMenu = new MyPushButton(this);
	m_btnMainMenu->setFixedSize(20, 20);
	m_btnReturn->setObjectName("mainmenu");
	m_btnMainMenu->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_mainmenu(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_mainmenu(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_mainmenu(3).png);}"
	);

	MyPushButton *m_btnSimpleMode = new MyPushButton(this);
	m_btnSimpleMode->setFixedSize(20, 20);
	m_btnReturn->setObjectName("simplemode");
	m_btnSimpleMode->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_simplemode(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_simplemode(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_simplemode(3).png);}"
	);

	MyPushButton *m_btnMinimize = new MyPushButton(this);
	m_btnMinimize->setFixedSize(20, 20);
	m_btnReturn->setObjectName("minimize");
	m_btnMinimize->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_minmize(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_minmize(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_minmize(3).png);}"
	);

	MyPushButton *m_btnRestore = new MyPushButton(this);
	m_btnRestore->setFixedSize(20, 20);
	m_btnRestore->setObjectName("maxmize");
	m_btnRestore->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_restore(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_restore(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_restore(3).png);}"
	);

	MyPushButton *m_btnClose = new MyPushButton(this);
	m_btnClose->setFixedSize(20, 20);
	m_btnReturn->setObjectName("close");
	m_btnClose->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_close(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/btn_close(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/btn_close(3).png);}"
	);

	QHBoxLayout *hLayout2=new QHBoxLayout;
	hLayout2->addWidget(m_btnMsg);
	hLayout2->addWidget(m_btnVIP);
	hLayout2->addWidget(m_btnSkin);
	hLayout2->addWidget(m_btnMainMenu);
	hLayout2->addWidget(m_btnSimpleMode);
	hLayout2->addWidget(m_btnMinimize);
	hLayout2->addWidget(m_btnRestore);
	hLayout2->addWidget(m_btnClose);
	hLayout2->setSpacing(10);
	setContentsMargins(0, 0, 0, 0);

	mainLayout->addLayout(hLayout1);
	mainLayout->addSpacing(100);
	mainLayout->addSpacerItem(new QSpacerItem(20,50,QSizePolicy::Expanding));
	mainLayout->addLayout(hLayout2);
	setLayout(mainLayout);
}

void TopWidget::initSearchLineEdit()
{
	m_lineEdit = new QLineEdit(this);
	m_lineEdit->setFixedSize(200, 24);
	m_lineEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_lineEdit->setStyleSheet("QLineEdit{border-radius:12px;background:rgb(234,234,234,180);}");
	m_lineEdit->setContextMenuPolicy(Qt::NoContextMenu);

	QLabel *leftSearchIcon = new QLabel(m_lineEdit);
	leftSearchIcon->setFixedSize(16, 16);
	QPixmap pix(":/images/topwidget/label_leftsearch.png");
	leftSearchIcon->setPixmap(pix);
	/*MyPushButton *leftSerBtn = new MyPushButton(m_lineEdit);
	leftSerBtn->setFixedSize(16, 16);
	leftSerBtn->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/btn_search(1).png);}"
	);*/
	
	MyPushButton *rightSerBtn = new MyPushButton(m_lineEdit);
	rightSerBtn->setFixedSize(16, 16);
	rightSerBtn->setStyleSheet(
		"QPushButton{border-image:url(:/images/topwidget/label_rightsearch(1).png);}"
		"QPushButton::hover{border-image:url(:/images/topwidget/label_rightsearch(2).png);}"
		"QPushButton::pressed{border-image:url(:/images/topwidget/label_rightsearch(3).png);}"
	);

	m_lineEdit->setPlaceholderText(tr("ËÑË÷ÒôÀÖ¡¢MV¡¢¸èµ¥¡¢ÓÃ»§"));
	QMargins margins = m_lineEdit->textMargins();
	m_lineEdit->setTextMargins(margins.left() + 15, margins.top(), margins.right() + 15, margins.bottom());

	QHBoxLayout *pSearchLayout = new QHBoxLayout(this);
	//pSearchLayout->addWidget(leftSerBtn);
	pSearchLayout->addWidget(leftSearchIcon);
	pSearchLayout->addStretch();
	pSearchLayout->addWidget(rightSerBtn);
	pSearchLayout->setSpacing(0);
	pSearchLayout->setContentsMargins(0, 0, 15, 0);
	m_lineEdit->setLayout(pSearchLayout);
}
