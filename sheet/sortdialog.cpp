#include "sortdialog.h"
#include <QLayout>
#include <QGroupBox>

sortDialog::sortDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    moreButton->setChecked(false);
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    primaryGroupBox_2->setVisible(false);
    primaryGroupBox_3->setVisible(false);

    primaryColumnCombo->setMinimumSize(secondaryColumnCombo->sizeHint());
    setColunmRange('A','Z');
}

sortDialog::~sortDialog()
{

}


void sortDialog::setColunmRange(QChar first, QChar last)
{

}
