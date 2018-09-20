#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QPixmap>

class Widget:public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent=0);
public slots:
    void setSkin(const QString& skin);
protected:
    void paintEvent(QPaintEvent *event);


private:
    QString m_curPixPath;
    QPixmap m_curPix;
    QPixmap m_skinPic;
    QPixmap m_netPic;


};

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = 0);
    Widget m_mainwid;	//实现更换皮肤

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	bool m_leftButtonPressed;
	bool m_pressBorder;
	QPoint m_curPos;
	enum Direction { Middle, TopLeft, Top, TopRight, Right, BottomRight, Bottom, BottomLeft, Left };
	Direction dir;
	int margin;


	void region(QMouseEvent *event);
	void resize();
};

#endif // BASEWINDOW_H
