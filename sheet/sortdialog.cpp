#include "sortdialog.h"
#include "spreadsheet.h"
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
    //setColunmRange('A','Z');
}

sortDialog::~sortDialog()
{

}


void sortDialog::setColunmRange(QChar first, QChar last)
{
    QStringList list;
    QChar temp=first;
    while(temp<=last){
        list<<temp;
        temp=temp.unicode()+1;
    }
    primaryColumnCombo->insertItems(1, list);
    secondaryColumnCombo->insertItems(1,list);
    tertiaryColumnCombo->insertItems(1,list);
}

void sortDialog::setSpreadSheet(spreadSheet *sp){
    QList<QTableWidgetSelectionRange> range=sp->selectedRanges();
    if(!range.isEmpty()){
        QListIterator<QTableWidgetSelectionRange> i(range);
        QTableWidgetSelectionRange temp=i.peekNext();
        int minLeft=temp.leftColumn();
        int maxRight=temp.rightColumn();
        while(i.hasNext()){
            temp=i.next();
            if(minLeft>temp.leftColumn())
                minLeft=temp.leftColumn();
            if(maxRight<temp.rightColumn())
                maxRight=temp.rightColumn();
        }
        setColunmRange(minLeft+'A',maxRight+'A');
    }
    else{
        setColunmRange('A','Z');
    }
}
