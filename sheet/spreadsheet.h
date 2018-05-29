#include <QTableWidget>
#include <QTableWidgetSelectionRange>

class Cell;

class spreadSheet : public QTableWidget
{
    Q_OBJECT
public:
    spreadSheet(QWidget *parent=0);
    ~spreadSheet();
	bool showGrid();
	bool autoRecalculate();
    QString currentLocation();
    QString currentFormula();
    bool readFile(const QString& fileName);
	void setFormula(int row, int col, QString& str);
    bool writeFile(const QString& fileName);

signals:
	void modified();

public slots:
	void slot_setShowGrid(bool flag);
	void cut();
	void copy();
	void paste(); 
	void del();
	void slot_selectRow();
	void slot_selectColumn();
	void slot_recalculate();
	void slot_setAutoRecalculate(bool flag);
    void findNext(const QString& str,Qt::CaseSensitivity);
    void findPrevious(const QString& str,Qt::CaseSensitivity);

private slots:
	void somethingChanged();

private:
	enum { MagicNumber=0x7F51C883, RowCount = 999, ColumnCount = 26 };
	void recalculate();
	void clear();
	Cell *cell(int row, int column) const;
	QString formula(int row, int column);
	QTableWidgetSelectionRange selectedRange();
	void pasteOnce(int TopRow, int LeftColumn, QString str);

	bool m_showgrid;
	bool autoRecalc;
    QString m_currentLocation;
    QString m_currentFormula;
};
