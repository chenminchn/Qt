#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QObject>
#include <QDialog>

#include "ui_gotocelldialog.h"

class goToCellDialog : public QDialog, public Ui::goToCellDialog
{
    Q_OBJECT
public:
    goToCellDialog(QWidget *parent=0);
};

#endif // GOTOCELLDIALOG_H
