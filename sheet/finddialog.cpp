#include "finddialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include "finddialog.h"


findDialog::findDialog(QWidget *parent):QDialog(parent)
{
    setWindowIcon(QIcon(":/images/magnifier.png"));
	setWindowTitle(tr("Find"));

    label=new QLabel(tr("Find &what:"),this);
	lineEdit=new QLineEdit(this);
	label->setBuddy(lineEdit);//QLabel专用

	caseCheckBox=new QCheckBox(tr("Match case"),this);
	backwardCheckBox=new QCheckBox(tr("Search backward"),this);

	findButton=new QPushButton(tr("&Find"),this);
	findButton->setEnabled(true);
	closeButton=new QPushButton(tr("Close"),this);

    QHBoxLayout *mainLayout=new QHBoxLayout(this);

	QHBoxLayout *topLeftLayout=new QHBoxLayout(this);
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *bottomLeftLayout=new QVBoxLayout(this);
	bottomLeftLayout->addWidget(caseCheckBox);
	bottomLeftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *leftLayout=new QVBoxLayout(this);
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addLayout(bottomLeftLayout);

	QVBoxLayout *rightLayout=new QVBoxLayout(this);
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);

	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());

    connect(lineEdit,SIGNAL(textChanged(const QString&)),this,SLOT(enableFindButton(const QString&)));//同一窗口中的不同部件可以相互发送信号
    connect(findButton,SIGNAL(clicked()),this,SLOT(findButtonClicked()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(closeButtonClicked()));

    //connect(this,SIGNAL(findPrevious(QString,Qt::CaseSensitivity)),parentWindow,SLOT(slot_findPrevious(QString,Qt::CaseSensitivity)));
    //connect(this,SIGNAL(findNext(QString,Qt::CaseSensitivity)),parentWindow,SLOT(slot_findNext(QString,Qt::CaseSensitivity)));
            //connect(this,SIGNAL(sig_findButtonClicked(const QString& text)),parentWindow,SLOT(slot_find(const QString& text)));
}

findDialog::~findDialog()
{

}

void findDialog::enableFindButton(const QString& str)
{
	findButton->setEnabled(!str.isEmpty());
}

void findDialog::findButtonClicked()
{
	currentText=lineEdit->text();
    Qt::CaseSensitivity cs=caseCheckBox->isChecked()?(Qt::CaseSensitive):(Qt::CaseInsensitive);
 	if(backwardCheckBox->isChecked())
 	{
        emit findPrevious(currentText,cs);
 	}
 	else
 	{
        emit findNext(currentText,cs);
 	}
}

void findDialog::closeButtonClicked()
{
	currentText=lineEdit->text();
    //to do
}
