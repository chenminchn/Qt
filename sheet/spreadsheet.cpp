#include "spreadsheet.h"

spreadSheet::spreadSheet(QWidget *parent):QTableWidget(parent)
{

}
spreadSheet::~spreadSheet()
{

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

void spreadSheet::slot_sort()
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


