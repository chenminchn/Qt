#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = 0);

signals:

public slots:
};

#endif // BASEWINDOW_H