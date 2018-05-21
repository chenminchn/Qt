#include "gotocelldialog.h"
#include <QRegExpValidator>
#include <QRegExp>
#include <QString>
#include <QPushButton>

goToCellDialog::goToCellDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    QRegExp rx(QString("[A-Za-z][1-9][0-9]{0,2}"));
    QRegExpValidator *validator=new QRegExpValidator(rx, this);
    lineEdit->setValidator(validator);

    //connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_textChanged(QString))); zidonglianjie,zhelibuxuyaoshoudonglianjie
    //connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
    //connect(cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
}

void goToCellDialog::on_lineEdit_textChanged(const QString& str)
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
