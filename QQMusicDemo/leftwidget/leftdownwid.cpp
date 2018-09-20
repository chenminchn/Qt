#pragma execution_character_set("utf-8")

#include "leftdownwid.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFont>
#include "mybutton.h"
#include <QGridLayout>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QLabel>
#include "switchpagebutton.h"
#include <QVector>
#include "mycreatelistwid.h"


LeftDownWid::LeftDownWid(QWidget *parent)
	: MyScrollArea(parent),m_wid(this)
{
	m_pressedButton = nullptr;
	//setStyleSheet("BaseWidget{background:black;}");
	setMinimumWidth(200);
	setMaximumWidth(234);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	initWidget();	
}

BaseWidget * LeftDownWid::mWidget()
{
	return &m_wid;
}

LeftDownWid::~LeftDownWid()
{
}

void LeftDownWid::initWidget()
{
	m_wid.setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	QVBoxLayout *mainLayout = new QVBoxLayout;

	TitleList *m_btnOnlineMusic = new TitleList("在线音乐", this);
	SwitchPageButton *m_widMusicStudio = new SwitchPageButton("音乐馆", this);
	m_widMusicStudio->setIconPath(":/images/leftwidget/label_musicstudio(1).png", ":/images/leftwidget/label_musicstudio(2).png");
	m_widMusicStudio->setLabelIcon(m_widMusicStudio->getImage(1));

	SwitchPageButton *m_widMV = new SwitchPageButton("MV", this);
	m_widMV->setIconPath(":/images/leftwidget/btn_MV(1).png", ":/images/leftwidget/btn_MV(2).png");
	m_widMV->setLabelIcon(m_widMV->getImage(1));

	SwitchBtnwithPlayBtn *m_widPersonalRadio = new SwitchBtnwithPlayBtn("个性电台", this);
	m_widPersonalRadio->setIconPath(":/images/leftwidget/btn_personalradio(1).png", ":/images/leftwidget/btn_personalradio(2).png", ":/images/leftwidget/btn_personalradio(3).png", ":/images/leftwidget/btn_personalradio(4).png");
	m_widPersonalRadio->setLabelIcon(m_widPersonalRadio->getImage(1));

	SwitchPageButton *m_widSpecial = new SwitchPageButton("明日之子第二季", this);
	m_widSpecial->setIconPath(":/images/leftwidget/btn_special(1).png", ":/images/leftwidget/btn_special(2).png");
	m_widSpecial->setLabelIcon(m_widSpecial->getImage(1));

	TitleList *m_btnMyMusic = new TitleList("我的音乐", this);
	SwitchPageButton *m_widILike = new SwitchPageButton("我喜欢", this);
	m_widILike->setIconPath(":/images/leftwidget/btn_ilike(1).png", ":/images/leftwidget/btn_ilike(2).png");
	m_widILike->setLabelIcon(m_widILike->getImage(1));

	SwitchPageButton *m_widLocal = new SwitchPageButton("本地和下载", this);
	m_widLocal->setIconPath(":/images/leftwidget/btn_local(1).png", ":/images/leftwidget/btn_local(2).png");
	m_widLocal->setLabelIcon(m_widLocal->getImage(1));

	SwitchPageButton *m_widHistory = new SwitchPageButton("播放历史", this);
	m_widHistory->setIconPath(":/images/leftwidget/btn_history(1).png", ":/images/leftwidget/btn_history(2).png");
	m_widHistory->setLabelIcon(m_widHistory->getImage(1));

	SwitchPageButton *m_widTryList = new SwitchPageButton("试听列表", this);
	m_widTryList->setIconPath(":/images/leftwidget/btn_trylist(1).png", ":/images/leftwidget/btn_trylist(2).png");
	m_widTryList->setLabelIcon(m_widTryList->getImage(1));

	m_btnMyCreateList = new TitleList("我创建的歌单", this);
	m_btnMyCreateList->m_btnCreateSongList->show();
	m_btnMyCreateList->m_btnFolding->show();

	m_widMyCreateList = new MyCreateListWid(this);

	TitleList *m_btnMyCollectList = new TitleList("我收藏的歌单", this);
	m_btnMyCollectList->m_btnFolding->show();
	
	connect(m_widMusicStudio, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widMV, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widPersonalRadio, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widSpecial, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widILike, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widLocal, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widHistory, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	connect(m_widTryList, SIGNAL(clicked()), this, SLOT(setPressedButton()));
	
	connect(m_btnMyCreateList, SIGNAL(sig_createList()), m_widMyCreateList, SLOT(slot_createList()));
	connect(m_btnMyCreateList, SIGNAL(sig_foldingLists()), m_widMyCreateList, SLOT(slot_foldingLists()));
	
	mainLayout->addWidget(m_btnOnlineMusic);
	mainLayout->addWidget(m_widMusicStudio);
	mainLayout->addWidget(m_widMV);
	mainLayout->addWidget(m_widPersonalRadio);
	mainLayout->addWidget(m_widSpecial);
	mainLayout->addWidget(m_btnMyMusic);
	mainLayout->addWidget(m_widILike);
	mainLayout->addWidget(m_widLocal);
	mainLayout->addWidget(m_widHistory);
	mainLayout->addWidget(m_widTryList);
	mainLayout->addWidget(m_btnMyCreateList);
	mainLayout->addWidget(m_widMyCreateList);
	mainLayout->addWidget(m_btnMyCollectList);

	mainLayout->setSpacing(5);
	mainLayout->addStretch();
	mainLayout->setContentsMargins(20, 20, 10, 20);
	//mainLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
	m_wid.setLayout(mainLayout);
}

void LeftDownWid::setPressedButton()
{
	MyButton *button1 = qobject_cast<MyButton*>(sender());
	if (m_pressedButton == button1)
		return;
	MyButton *button2 = m_pressedButton;
	if (button2)
	{
		button2->restoreAppearance();
	}
	m_pressedButton = button1;
}

void LeftDownWid::initConnection()
{

}


