#include "gotocelldialog.h"
#include <QRegExpValidator>
#include <QRegExp>
#include <QString>

goToCellDialog::goToCellDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    QRegExp rx=new QRegExp(QString("[A-Za-z][1-9][0-9]{0,2}"));
    QRegExpValidator *validator=new QRegExpValidator(rx, this);
    lineEdit->setValidator(validator);

    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_textChanged(QString)));
    connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
}

void goToCellDialog::on_textChanged(const QString& str)
{
    if(!str.isEmpty())
        okButton->setEnabled(true);
}
