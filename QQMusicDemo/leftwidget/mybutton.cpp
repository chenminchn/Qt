#include "mybutton.h"
#include <QLabel>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <QPainter>

MyButton::MyButton(QWidget *parent)
	: BaseWidget(parent)
{
}

MyButton::~MyButton()
{
}

void MyButton::changeAppearance()
{
	QPalette pal = this->palette();
	QBrush brush = pal.background();
	QColor color = brush.color();
	if (color != QColor(49, 194, 124))
	{
		setStyleSheet(
			"BaseWidget{background:rgb(49, 194, 124);border-radius:3px;}"
		);
		setLabelIcon(m_imgPath2);
		label_text->setStyleSheet("QLabel{color:white;}");
	}
}

void MyButton::restoreAppearance()
{
	setStyleSheet(
		"BaseWidget{background:transparent;border-radius:3px;}"
		"BaseWidget:hover{background:#E7E9E9;}"
	);
	setLabelIcon(m_imgPath1);
	label_text->setStyleSheet("QLabel{color:#5C5F5E;}");
}

void MyButton::setLabelIcon(const QString& imgPath)
{
	QString tempStr = "QLabel{border-image:url(" + imgPath + ");}";
	m_labelIcon->setStyleSheet(tempStr);
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		emit clicked();
}

MyPushButton::MyPushButton(QWidget *parent)
	: QPushButton(parent)
{
	setCursor(Qt::PointingHandCursor);
	setFlat(true);
	setCursor(Qt::PointingHandCursor);
	/*setStyleSheet(
	"QPushButton{background:transparent}"
	"QPushButton{border-image:url(:/images/topwidget/test.png);}"
	);*/

}

MyPushButton::~MyPushButton()
{
}

SongDetailButton::SongDetailButton(QWidget *parent) :QAbstractButton(parent)
{
	m_mouseHover = false;
	setMouseTracking(true);
	setFixedSize(69, 69);
}

SongDetailButton::~SongDetailButton()
{

}

void SongDetailButton::mouseMoveEvent(QMouseEvent *e)
{
	if (this->rect().contains(e->pos()))
		m_mouseHover = true;
}

void SongDetailButton::leaveEvent(QEvent *e)
{
	m_mouseHover = false;
}

void SongDetailButton::paintEvent(QPaintEvent *e)
{
	QPixmap pix(69, 69);
	pix.load(":/images/bottomwidget/btn_songdetail(1).png");
	QPainter p(this);
	p.drawPixmap(this->rect(), pix);

	if (m_mouseHover)
	{
		QPixmap pixmap(69, 69);
		pixmap.load(":/images/bottomwidget/btn_songdetail(2).png");
		p.setCompositionMode(QPainter::CompositionMode_SourceOver);
		p.drawPixmap(this->rect(), pixmap);
	}
}

TitleListBtn::TitleListBtn(const QString& str, QWidget *parent) :QPushButton(str, parent)
{
	setCursor(Qt::PointingHandCursor);
	setFont(QFont("Microsoft YaHei"));
	setFlat(true);
	setStyleSheet(
		"QPushButton{background:transparent;margin:0px 3px 3px 0px;text-align: left;}"
		"QPushButton::pressed{margin:0px 0px 0px 0px;}"
	);

}

TitleListBtn::~TitleListBtn()
{

}


