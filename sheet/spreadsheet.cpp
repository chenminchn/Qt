#include "spreadsheet.h"
#include <QStringList>
#include <QChar>
#include <qtablewidget.h>


spreadSheet::spreadSheet(QWidget *parent):QTableWidget(parent)
{
    /*setColumnCount(26);
    setRowCount(1000);
    QStringList header;
    QChar ch='A';
    QChar last='Z';
    while(ch.unicode()<last.unicode()+1)
        {
        header<<ch;
        ch=ch.unicode()+1;
    }
    setHorizontalHeaderLabels(header);*/
	connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));
}

void spreadSheet::somethingChanged() {
	//�ęn���޸�
	emit modified();
}
spreadSheet::~spreadSheet()
{

}

bool spreadSheet::readFile(const QString& fileName){
	return true;
}

bool spreadSheet::writeFile(const QString& fileName){
	return true;
}

QString& spreadSheet::currentLocation()
{
    return m_currentLocation;
}

QString& spreadSheet::currentFormula()
{
    return m_currentFormula;
}
bool spreadSheet::showGrid()
{
	return m_showgrid;
}

void spreadSheet::slot_setShowGrid(bool flag)
{
	m_showgrid=flag;
	//to do
}

void spreadSheet::slot_cut()
{

}

void spreadSheet::slot_copy()
{

}

void spreadSheet::slot_paste()
{

}

void spreadSheet::slot_delete()
{

}

void spreadSheet::slot_selectRow()
{

}

void spreadSheet::slot_selectColumn()
{

}

void spreadSheet::slot_recalculate()
{

}

bool spreadSheet::autoRecalculate()
{
	return m_autoRecalculate;
}

void spreadSheet::slot_setAutoRecalculate(bool flag)
{
	m_autoRecalculate=flag;
}

void spreadSheet::findNext(const QString& str,Qt::CaseSensitivity){

}
void spreadSheet::findPrevious(const QString& str,Qt::CaseSensitivity){

}


