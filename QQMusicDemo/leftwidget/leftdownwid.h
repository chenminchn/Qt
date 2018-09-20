#pragma once

#include "basewidget.h"
#include "myscrollarea.h"
#include "switchpagebutton.h"
#include <QVector>
#include "mycreatelistwid.h"

class QVBoxLayout;

class LeftDownWid : public MyScrollArea
{
	Q_OBJECT

public:
	enum ChangelessBtn { MusicRadio, MV, PerRadio, Tommorrow, ILike, Local, History, TryList };
	LeftDownWid(QWidget *parent);
	BaseWidget *mWidget();
	~LeftDownWid();
signals:
	void sig_switchPage(int);
public slots:
	void setPressedButton(/*SwitchPageButton *button*/);
private slots:
	

private:
	BaseWidget m_wid;
	MyButton *m_pressedButton;
	QVector<SongListButton*> m_myCreateList;
	QVector<SongListButton*> m_myCollectList;
	MyCreateListWid *m_widMyCreateList;
	TitleList *m_btnMyCreateList;

	void initWidget();
	void initConnection();
};
