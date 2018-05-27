#include "cell.h"
#include "spreadsheet.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QChar>
#include <QTableWidget>
#include <QCursor>



spreadSheet::spreadSheet(QWidget *parent):QTableWidget(parent)
{
	autoRecalc = true;
	setSelectionMode(ContiguousSelection);
	//加公式
	setItemPrototype(new Cell);
	connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));
	clear();
}

void spreadSheet::somethingChanged() {
	//文檔被修改
	//如果选中重新计算，需重新计算
	if (autoRecalc) {
		recalculate();
	}
	emit modified();
}

void spreadSheet::recalculate()
{

}

void spreadSheet::clear() {
	//清空单元格，恢复单元格的原始设定
	setRowCount(0);
	setColumnCount(0);
	setRowCount(RowCount);
	setColumnCount(ColumnCount);
	for (int i = 0; i < ColumnCount; i++) {
		QTableWidgetItem *item = new QTableWidgetItem;//这里的item内存由tableWidget管理，不用加this
		item->setText(QString(QChar('A' + i)));
		setHorizontalHeaderItem(i, item);
	}
	setCurrentCell(0, 0);
}

Cell * spreadSheet::cell(int row, int column) const
{
	return static_cast<Cell*>(item(row, column));
}

QString spreadSheet::formula(int row, int column)
{
	Cell *cel = cell(row, column);
	if (cel) {
		return cel->formula();
	}
	else {
		return "";
	}
}

spreadSheet::~spreadSheet()
{

}

bool spreadSheet::readFile(const QString& fileName){
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::warning(this, tr("Spreadsheet"), 
			tr("Can not read file %1:\n%2").arg(file.fileName()).arg(file.errorString()));
		return false;
	}
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_7);
	quint32 magic;
	in >> magic;
	if (magic != MagicNumber) {
		QMessageBox::warning(this, tr("Spreadsheet"), 
			tr("The file is not a spreadsheet file"));
		return false;
	}
	quint16 row, col;
	QString str;
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	while (!in.atEnd()) {
		in >> row >> col >> str;
		setFormula(row, col, str);
	}
	QApplication::restoreOverrideCursor();
	return true;
}

void spreadSheet::setFormula(int row, int col, QString & str)
{
	Cell *cel = cell(row, col);
	if (!cel) {
		cel = new Cell;
		setItem(row, col, cel);
	}
	cel->setFormula(str);

}

bool spreadSheet::writeFile(const QString& fileName){
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::warning(this, tr("Spreadsheet"), 
			tr("Can not write file %1:\n%2").arg(file.fileName()).arg(file.errorString()));
		return false;
	}
	QDataStream out(&file);
	//对QDatastream做设置
	out.setVersion(QDataStream::Qt_5_7);
	out << quint32(MagicNumber);
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	for (int row = 0; row < rowCount(); row++) {
		for (int col = 0; col < columnCount(); col++) {
			QString str = formula(row, col);
			if (!str.isEmpty()) {
				out << quint16(row) << quint16(col) << str;
			}
		}
	}
	QApplication::restoreOverrideCursor();
	return true;
}

QString spreadSheet::currentLocation()
{
	return QString(QChar(currentColumn() + 'A') + QString::number(currentRow()));
}

QString spreadSheet::currentFormula()
{
	return formula(currentRow(), currentColumn());
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
	return autoRecalc;
}

void spreadSheet::slot_setAutoRecalculate(bool flag)
{
	autoRecalc=flag;
}

void spreadSheet::findNext(const QString& str,Qt::CaseSensitivity){

}
void spreadSheet::findPrevious(const QString& str,Qt::CaseSensitivity){

}


