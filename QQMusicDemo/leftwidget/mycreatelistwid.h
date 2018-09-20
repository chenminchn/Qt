#pragma once

#include "basewidget.h"

class QVBoxLayout;
class SongListButton;
class LeftDownWid;

class MyCreateListWid : public BaseWidget
{
	Q_OBJECT

public:
	explicit MyCreateListWid(QWidget *parent=0);
	~MyCreateListWid();

	//QVBoxLayout *vMyCreateLayout;
	LeftDownWid *pWid;
signals:
	
public slots:
	void slot_createList();
	void slot_foldingLists();
	void oneBtnClicked();

protected:


private:
	QVector<SongListButton*> m_myCreateList;
	SongListButton *m_myPressedBtn;
};
