#include <QTableWidget>
class spreadSheet : public QTableWidget
{
    Q_OBJECT
public:
    spreadSheet(QWidget *parent=0);
    ~spreadSheet();
	bool showGrid();
	bool autoRecalculate();
    QString& currentLocation();
    QString& currentFormula();
    bool readFile(const QString& fileName);
    bool writeFile(const QString& fileName);

public slots:
	void slot_setShowGrid(bool flag);
	void slot_cut();
	void slot_copy();
	void slot_paste();
	void slot_delete();
	void slot_selectRow();
	void slot_selectColumn();
	void slot_recalculate();
	void slot_sort();
	void slot_setAutoRecalculate(bool flag);
    void findNext(const QString& str,Qt::CaseSensitivity);
    void findPrevious(const QString& str,Qt::CaseSensitivity);
private:

	bool m_showgrid;
	bool m_autoRecalculate;
    QString m_currentLocation;
    QString m_currentFormula;
};
