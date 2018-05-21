#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QObject>
#include "ui_sortdialog.h"
#include <QChar>

class sortDialog : public QDialog,public Ui::sortDialog
{
public:
    sortDialog(QWidget *parent=0);
    ~sortDialog();
    void setColunmRange(QChar first,QChar last);
private:

};

#endif // SORTDIALOG_H
