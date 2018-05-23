#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class spreadSheet;
class findDialog;
class QMenu;
class QAction;
class QMenuBar;
class QToolBar;
class QLabel;
class QStringList;
class QRect;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent=0);
    ~MainWindow();
protected:
	void closeEvent(QCloseEvent  *event);

public slots:
	
private slots:
	//file
	void newFile();
	void openFile();
    bool save();
    bool saveAs();
	void openRecentFile();
    void find();
    //edit
    void slot_findNext(const QString& text,Qt::CaseSensitivity cs);
    void slot_findPrevious(const QString& text,Qt::CaseSensitivity cs);
    void goToCell();
	void selectAll();
    //tools
    void sort();
    void close();



	//help
    void about();

    //status Bar
    void updateStatusBar();


private:
	void createActions();
	void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    bool saveFile(const QString& fileName);
    bool okToContinue();
    bool loadFile(const QString& file);
    void setCurrentFile(const QString& file);
    QString strippedName(const QString& fileName);
    void updateRecentFileActions();
    void writeSettings();
    void readSettings();

	//file
	QAction *newAction;
	QAction *openAction;
	QAction *saveAction;
	QAction *saveAsAction;
	QAction *separatorAction;
	enum{MaxRecentFiles=5};
	QAction *recentFileAction[MaxRecentFiles];
    QAction *closeAction;
    QAction *exitAction;

	//edit
	QAction *cutAction;
	QAction *copyAction;
	QAction *pasteAction;
	QAction *deleteAction;
	QAction *selectAction;
	QAction *selectRowAction;
	QAction *selectColumnAction;
	QAction *selectAllAction;
	QAction *findAction;
	QAction *gotocellAction;

	//Tools
	QAction *recalculateAction;
	QAction *sortAction;

	//options
	QAction *showGridAction;
	QAction *autoRecalculateAction;

	//help
	QAction *aboutAction;
	QAction *aboutQtAction;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *selectMenu;
	QMenu *toolsMenu;
	QMenu *optionsMenu;
	QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *editToolBar;

    //status bar
    QLabel *locationLabel;
    QLabel *formulaLabel;

	spreadSheet *spreadsheet;
    findDialog *p_finddialog=NULL;

    QString m_fileName;
    QStringList recentFiles;

};
#endif
