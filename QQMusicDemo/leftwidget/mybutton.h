#pragma once

#include "basewidget.h"
#include <QPushButton>

class QLabel;

class MyButton : public BaseWidget
{
	Q_OBJECT

public:
	explicit MyButton(QWidget *parent=0);
	~MyButton();
	void setLabelIcon(const QString& imgPath);

	QLabel *m_labelIcon;
signals:
	void clicked();
public slots:
	virtual void restoreAppearance();
	void changeAppearance();
protected:
	void mousePressEvent(QMouseEvent *event);

	QLabel *label_text;
	QString m_imgPath1;
	QString m_imgPath2;
};

class MyPushButton : public QPushButton
{
	Q_OBJECT

public:
	MyPushButton(QWidget *parent);
	~MyPushButton();
};

class SongDetailButton : public QAbstractButton
{
	Q_OBJECT
public:
	explicit SongDetailButton(QWidget *parent = 0);
	~SongDetailButton();
protected:
	void mouseMoveEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *e);
	void leaveEvent(QEvent *e);
private:
	bool m_mouseHover;
};

class TitleListBtn :public QPushButton
{
	Q_OBJECT
public:
	explicit TitleListBtn(const QString &str, QWidget *parent = 0);
	~TitleListBtn();
};

