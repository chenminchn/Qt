#pragma once

#include "mybutton.h"
#include <QMenu>

class QLabel;
class QPushButton;
class QLineEdit;



class SwitchPageButton : public MyButton
{
	Q_OBJECT

public:
	explicit SwitchPageButton(QWidget *parent = 0);
	SwitchPageButton(const QString& str, QWidget *parent = 0);
	~SwitchPageButton();
	void setIconPath(const QString& str1, const QString &str2);
	void setIconPath(const QString& str1, const QString &str2, const QString& str3, const QString &str4);

	const QString getImage(int n);
	void setBtnIcon(const QString &str);

	QPushButton *m_btnIcon;

signals:

protected:
	void enterEvent(QEvent *e);
public slots:
	void restoreAppearance();
private slots:

private:
	
	QString m_imgPath3;
	QString m_imgPath4;


	BaseWidget *parentWidget;
};

class TitleList :public BaseWidget
{
	Q_OBJECT
public:
	explicit TitleList(const QString& str,QWidget *parent = 0);
	~TitleList();

	QPushButton *m_btnCreateSongList;
	QPushButton *m_btnFolding;

	bool isFolding;

signals:
	void sig_createList();
	void sig_foldingLists();

public slots:


private slots:
	void changeBorderImg();


private:
	
};

class QMenu;

class SongListButton :public MyButton
{
	Q_OBJECT
public:
	explicit SongListButton(QWidget *parent);
	~SongListButton();
signals:
public slots:
	/*void restoreAppearance();*/
private slots:

protected:
	void mouseReleaseEvent(QMouseEvent *event);
	
private:
	QMenu m_menu;

	void init();
	void initMenu();
};

class SwitchBtnwithPlayBtn : public SwitchPageButton
{
	Q_OBJECT

public:
	SwitchBtnwithPlayBtn(const QString &str, QWidget *parent);
	~SwitchBtnwithPlayBtn();
protected:
	void enterEvent(QEvent *e);
	void leaveEvent(QEvent *e);
	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *e);
};
