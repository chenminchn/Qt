#pragma execution_character_set("utf-8")

#include "switchpagebutton.h"
#include "leftdownwid.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QString>
#include <QColor>
#include <QPushButton>
#include <QEvent>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGridLayout>
#include "mycreatelistwid.h"
#include <QAction>
#include <QEvent>
#include <QPushButton>
#include <QPalette>
#include <QBrush>
//#include "customiconstyle.h"

SwitchPageButton::SwitchPageButton(QWidget *parent) :MyButton(parent)
{

}
SwitchPageButton::SwitchPageButton(const QString & str, QWidget * parent):MyButton(parent)
{
	parentWidget = qobject_cast<BaseWidget*>(parent);
	setFixedHeight(28);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	setStyleSheet(
		"BaseWidget{background:transparent;border-radius:3px;}"
		"BaseWidget:hover{background:#E7E9E9;}"
	);
	m_labelIcon = new QLabel(this);
	m_labelIcon->setFixedSize(20, 20);
	m_btnIcon = new QPushButton(this);
	m_btnIcon->setFixedSize(20, 20);
	m_btnIcon->setFlat(true);
	m_btnIcon->setCursor(Qt::PointingHandCursor);
	m_btnIcon->hide();

	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->addStretch();
	vLayout->addWidget(m_labelIcon);
	vLayout->addStretch();
	vLayout->setContentsMargins(0, 0, 0, 0);

	label_text = new QLabel(str, this);
	label_text->setStyleSheet(
		"QLabel{background:transparent;}"
	);

	connect(this, SIGNAL(clicked()), this, SLOT(changeAppearance()));

	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addLayout(vLayout);
	hLayout->addSpacing(5);
	hLayout->addWidget(label_text);
	hLayout->addStretch();
	hLayout->addWidget(m_btnIcon);
	hLayout->setContentsMargins(10, 0, 10, 0);

	setLayout(hLayout);

}

SwitchPageButton::~SwitchPageButton()
{

}

void SwitchPageButton::setIconPath(const QString& str1,const QString& str2)
{
	m_imgPath1 = str1;
	m_imgPath2 = str2;
}

void SwitchPageButton::setIconPath(const QString& str1, const QString &str2, const QString& str3, const QString &str4)
{
	m_imgPath1 = str1;
	m_imgPath2 = str2;
	m_imgPath3 = str3;
	m_imgPath4 = str4;
}

//点击时改变外观

void SwitchPageButton::restoreAppearance()
{
	setStyleSheet(
		"BaseWidget{background:transparent;border-radius:3px;}"
		"BaseWidget:hover{background:#E7E9E9;}"
	);
	setLabelIcon(m_imgPath1);
	label_text->setStyleSheet("QLabel{color:#5C5F5E;}");
}

const QString SwitchPageButton::getImage(int n)
{
	if (n > 0)
	{
		switch (n)
		{
		case 1:
			return m_imgPath1;
			break;
		case 2:
			return m_imgPath2;
			break;
		case 3:
			return m_imgPath3;
			break;
		case 4:
			return m_imgPath4;
			break;
		default:
			return QString();
			break;
		}
	}
	return QString();
}

void SwitchPageButton::setBtnIcon(const QString &str)
{
	QString tempstr = "QPushButton{border-image:url(" + str + ");}";
	m_btnIcon->setStyleSheet(tempstr);
}

void SwitchPageButton::enterEvent(QEvent *e)
{
	 
}

TitleList::TitleList(const QString& str,QWidget *parent) :BaseWidget(parent)
{
	isFolding = true;

	TitleListBtn *title = new TitleListBtn(str,this);
	m_btnCreateSongList = new QPushButton(this);
	m_btnCreateSongList->setCursor(Qt::PointingHandCursor);
	m_btnCreateSongList->setFlat(true);
	m_btnCreateSongList->setFixedSize(20, 20);
	m_btnCreateSongList->setStyleSheet("QPushButton{border-image:url(:/images/leftwidget/btn_createlist(1).png);}");
	m_btnCreateSongList->hide();
	m_btnFolding = new QPushButton(this);
	m_btnFolding->setCursor(Qt::PointingHandCursor);
	m_btnFolding->setFlat(true);
	m_btnFolding->setFixedSize(20, 20);
	if (!isFolding)
		m_btnFolding->setStyleSheet("QPushButton{border-image:url(:/images/leftwidget/btn_folding(1).png);}");
	else
		m_btnFolding->setStyleSheet("QPushButton{border-image:url(:/images/leftwidget/btn_folding(2).png);}");

	m_btnFolding->hide();
	connect(m_btnFolding, SIGNAL(clicked()), this, SLOT(changeBorderImg()));
	connect(title, SIGNAL(clicked()), this, SLOT(changeBorderImg()));
	connect(m_btnCreateSongList, SIGNAL(clicked()), this, SIGNAL(sig_createList()));

	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addWidget(title);
	hLayout->addStretch();
	hLayout->addWidget(m_btnCreateSongList);
	hLayout->addWidget(m_btnFolding);
	hLayout->setSpacing(0);
	hLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(hLayout);
}

TitleList::~TitleList()
{
	//举报4804238外挂群
}

void TitleList::changeBorderImg()
{
	isFolding = !isFolding;
	if (!isFolding)
		m_btnFolding->setStyleSheet("QPushButton{border-image:url(:/images/leftwidget/btn_folding(1).png);}");
	else
		m_btnFolding->setStyleSheet("QPushButton{border-image:url(:/images/leftwidget/btn_folding(2).png);}");
	emit sig_foldingLists();
}

SongListButton::SongListButton(QWidget *parent):MyButton(parent)
{
	m_imgPath1 = ":/images/leftwidget/btn_songlist(1).png";
	m_imgPath2 = ":/images/leftwidget/btn_songlist(2).png";
	init();
	initMenu();
}

SongListButton::~SongListButton()
{

}

void SongListButton::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
		m_menu.exec(QCursor::pos());
	MyButton::mouseReleaseEvent(event);
}

void SongListButton::init()
{
	setFixedHeight(28);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
	setStyleSheet(
		"BaseWidget{background:transparent;border-radius:3px;}"
		"BaseWidget:hover{background:#E7E9E9;}"
	);
	m_labelIcon = new QLabel(this);
	m_labelIcon->setFixedSize(28, 28);
	setLabelIcon(m_imgPath1);

	label_text = new QLabel(this);
	label_text->setText("新建歌单");
	QHBoxLayout *hLayout = new QHBoxLayout;
	hLayout->addWidget(m_labelIcon);
	hLayout->addWidget(label_text);
	hLayout->setContentsMargins(5, 0, 0, 0);
	setLayout(hLayout);

	connect(this, SIGNAL(clicked()), this, SLOT(changeAppearance()));
}

void SongListButton::initMenu()
{
	//CustomIconStyle *pStyle = new CustomIconStyle;
	//m_menu.setStyle(pStyle);
	m_menu.setStyleSheet(
		"QMenu{background-color:white;margin:10px 0px;}"
		"QMenu::item{background:transparent;padding:10px 40px 10px 40px;margin:0px 0px;font:13px;}"
		"QMenu::item:selected{background-color:#F1F1F1;}"
		"QMenu::separator{color:#F5F5F5;height:20px;margin:0px;}"
		"QMenu::icon{padding-left:15px;width:20px;height:20px;}"
	);

	QAction *act_play = new QAction("播放");
	act_play->setIcon(QIcon(":/images/leftwidget/btn_history(1).png"));
	QAction *act_delete = new QAction("删除");
	act_delete->setIcon(QIcon(":/images/leftwidget/btn_history(1).png"));
	QAction *act_reName = new QAction("重命名");

	QAction *act_importSongList = new QAction("导入外部歌单");
	QAction *act_syncAllSongList = new QAction("同步所有歌单");
	QAction *act_recoverSongList = new QAction("恢复歌单");
	
	m_menu.addAction(act_play);
	m_menu.addAction(act_delete);
	m_menu.addAction(act_reName);
	m_menu.addSeparator();
	m_menu.addAction(act_importSongList);
	m_menu.addAction(act_syncAllSongList);
	m_menu.addAction(act_recoverSongList);

	m_menu.setContentsMargins(0, 10, 0, 10);
}

SwitchBtnwithPlayBtn::SwitchBtnwithPlayBtn(const QString &str, QWidget *parent)
	: SwitchPageButton(str, parent)
{

}

SwitchBtnwithPlayBtn::~SwitchBtnwithPlayBtn()
{
}

void SwitchBtnwithPlayBtn::enterEvent(QEvent *e)
{
	QPalette pal = this->palette();
	QBrush brush = pal.background();
	QColor color = brush.color();
	if (color == QColor(49, 194, 124))
		setBtnIcon(getImage(4));
	else
		setBtnIcon(getImage(3));
	m_btnIcon->show();
}

void SwitchBtnwithPlayBtn::leaveEvent(QEvent *e)
{
	m_btnIcon->hide();
}

void SwitchBtnwithPlayBtn::paintEvent(QPaintEvent *e)
{
	BaseWidget::paintEvent(e);
}

void SwitchBtnwithPlayBtn::mousePressEvent(QMouseEvent *e)
{
	SwitchPageButton::mousePressEvent(e);
	setBtnIcon(getImage(4));
}



