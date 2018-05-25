#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;
//class MainWindow;

class findDialog : public QDialog
{
    Q_OBJECT
public:
    explicit findDialog(QWidget *parent=0);
	~findDialog(); 
signals:
    void findNext(const QString&,Qt::CaseSensitivity);
    void findPrevious(const QString&,Qt::CaseSensitivity);


private slots:
    void enableFindButton(const QString& str);
    void findButtonClicked();
    void closeButtonClicked();

private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;

	//MainWindow *parentWindow;
	QString currentText;
};
#endif
