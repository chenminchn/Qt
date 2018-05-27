#pragma once

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
	Cell();
	QString formula();
	void setFormula(QString& str);
	~Cell();


};
