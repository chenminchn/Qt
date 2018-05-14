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
private slots:
    void on_textChanged(const QString& str);
};

#endif // GOTOCELLDIALOG_H
