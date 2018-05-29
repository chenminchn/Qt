#include "cell.h"
#include "spreadsheet.h"
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QStringList>
#include <QChar>
#include <QTableWidget>
#include <QCursor>
#include <QTableWidgetSelectionRange>
#include <QClipboard>

spreadSheet::spreadSheet(QWidget *parent):QTableWidget(parent)
{
	autoRecalc = true;
	setSelectionMode(ContiguousSelection);
	//�ӹ�ʽ
	setItemPrototype(new Cell);
	connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));
	clear();
}

void spreadSheet::somethingChanged() {
	//�ęn���޸�
	//���ѡ�����¼��㣬�����¼���
	if (autoRecalc) {
		recalculate();
	}
	emit modified();
}

void spreadSheet::recalculate()
{

}

void spreadSheet::clear() {
	//��յ�Ԫ�񣬻ָ���Ԫ���ԭʼ�趨
	setRowCount(0);
	setColumnCount(0);
	setRowCount(RowCount);
	setColumnCount(ColumnCount);
	for (int i = 0; i < ColumnCount; i++) {
		QTableWidgetItem *item = new QTableWidgetItem;//�����item�ڴ���tableWidget�������ü�this
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

QTableWidgetSelectionRange spreadSheet::selectedRange()
{
	QList<QTableWidgetSelectionRange> range = selectedRanges();
	if (range.isEmpty()) {
		return QTableWidgetSelectionRange();
	}
	return range.first();
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
	//��QDatastream������
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

void spreadSheet::cut()
{
	copy();
	del();
}

void spreadSheet::copy(){
	QTableWidgetSelectionRange range = selectedRange();
	QString str;
	for (int i = 0; i < range.rowCount(); i++) {
		if (i > 0) {
			str += "\n";
		}
		for (int j = 0; j < range.columnCount(); j++) {
			if (j > 0) {
				str += "\t";
			}
			str += formula(range.topRow() + j, range.leftColumn() + i);
		}
	}
	QApplication::clipboard()->setText(str);
}

void spreadSheet::paste()
{
	QTableWidgetSelectionRange range = selectedRange();
	if (range.columnCount() == 0)
		return;
	QString str = QApplication::clipboard()->text();

	QStringList strlist = str.split('\n');
	QStringList list = strlist.first().split('\t');

	int strColumnCount = list.count();
	int strRowCount = strlist.count();
	int columnFactor = range.rowCount() / strRowCount;
	int rowFactor = range.columnCount() / strColumnCount;

	if (range.columnCount() == 1) {
		//����1��ֻ��һ�У��б���Ϊ����������Ȼֻճ��һ��
		if (range.columnCount() % strRowCount != 0||rowFactor==1)
			//range.columnCount()%strRowCount!=0,ճ��һ��
			pasteOnce(range.topRow(), range.leftColumn(), str);
		else {
			//range.columnCount()%strRowCount==0��ճ��rowFactor��
			int TopRow = range.topRow();
			int LeftColumn = range.leftColumn();
			while (rowFactor) {
				pasteOnce(TopRow, LeftColumn, str);
				TopRow += strRowCount;
				rowFactor--;
			}
		}
	}
	else if (range.columnCount()%strColumnCount==0) {
		//����2����Ϊ���������б���Ϊ����������Ȼֻճ��һ��
		if (range.rowCount() % strRowCount != 0 || range.rowCount() == 1)
			pasteOnce(range.topRow(), range.leftColumn(), str);
		else {
			int TopRow = range.topRow();
			int LeftColumn = range.leftColumn();
			for (int i = 0; i < rowFactor; i++) {
				for (int j = 0; j < columnFactor; j++) {
					pasteOnce(TopRow + i*strRowCount, LeftColumn + j*strColumnCount, str);
				}
			}
		}
	}
	else {
		//����3���в�����������Ҳ������1���������Ƿ�����������ֻճ��һ��
		pasteOnce(range.topRow(), range.leftColumn(), str);
	}
	somethingChanged();
}

void spreadSheet::pasteOnce(int TopRow, int LeftColumn,QString str){
	QString::iterator it = str.begin();
	int tabNum = 0;
	int retNum = 0;
	while (it != str.end()) {
		QString word;
		if (*it != '\t' || *it != '\n') {
			word += *it;
			it++;
		}
		else {
			if (*it == '\t') {
				str = str.mid(word.length() + 1);
				it = str.begin();
				setFormula(TopRow + retNum, LeftColumn + tabNum, word);
				tabNum += 1;

			}
			else {
				str = str.mid(word.length() + 1);
				it = str.begin();
				setFormula(TopRow + retNum, LeftColumn + tabNum, word);
				retNum += 1;
				tabNum = 0;
			}
		}
	}
}

QString spreadSheet::text(int row, int col) const
{
	Cell *c = cell(row, col);
	if (!c) {
		return c->text();
	}
	return "";
}

void spreadSheet::del()
{
	QList<QTableWidgetItem*> selected = selectedItems();
	if (!selected.isEmpty()) {
		foreach(auto item, selected) {
			if (!item) {
				delete item;
				somethingChanged();
			}
		}
	}
}

void spreadSheet::selectCurrentRow()
{
	selectRow(currentRow());
}

void spreadSheet::selectCurrentColumn()
{
	selectColumn(currentColumn());
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

void spreadSheet::findNext(const QString& str,Qt::CaseSensitivity cs){

	for (int i = currentRow(); i < RowCount; i++) {
		for (int j = 0; j < ColumnCount; j++) {
			//����while�ͺ��ˣ��汿�����ų����԰�
			if (i == currentRow() && j < currentColumn())
				continue;
			if (text(i,j).contains(str,cs)) {
				setCurrentCell(i, j);
				activateWindow();
				return;
			}
		}
	}
	QApplication::beep();	
}

void spreadSheet::findPrevious(const QString& str,Qt::CaseSensitivity){

}


