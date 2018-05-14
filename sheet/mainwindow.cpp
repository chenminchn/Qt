#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QKeySequence>
#include <QAction>
#include "spreadsheet.h"
#include "aboutdialog.h"
#include <QMenu>
#include "finddialog.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    spreadsheet=new spreadSheet(this);
    aboutdialog=new aboutDialog(this);
    p_finddialog=new findDialog(this);
	createActions();
    createMenus();//类似这样的私有函数一般只在窗口初始化的时候使用，并且不用于继承，所以就定义为私有的成员函数
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::createActions()
{
	//file
	newAction=new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file."));
	connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

	openAction=new QAction(tr("&Open"),this);
	openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a spreadsheet file"));
	connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));

	saveAction=new QAction(tr("&Save"),this);
	saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save spreadsheet."));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));

	saveAsAction=new QAction(tr("&Save As..."),this);
	saveAsAction->setIcon(QIcon(":/images/save.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
	saveAsAction->setStatusTip(tr("Save spreadsheet."));
	connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAsFile()));

	for(int i=0;i<MaxRecentFiles;i++)
	{
		recentFileAction[i]=new QAction(this);
        recentFileAction[i]->setVisible(false);
        connect(recentFileAction[i],SIGNAL(triggered()),this,SLOT(openRecentFile()));
	}

	exitAction=new QAction(tr("&Exit"),this);
	exitAction->setIcon(QIcon(":/images/exit.png"));
    exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit this application."));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

	//edit
	cutAction=new QAction(tr("&Cut"),this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut cells"));
	connect(cutAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_cut()));

	copyAction=new QAction(tr("&Copy"),this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy cells"));
	connect(copyAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_copy));

	pasteAction=new QAction(tr("&Paste"),this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste cells"));
	connect(pasteAction,SIGNAL(triggered),spreadsheet,SLOT(slot_paste()));

	deleteAction=new QAction(tr("&Delete"),this);
    deleteAction->setIcon(QIcon(":/images/delete.png"));
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete cells"));
	connect(deleteAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_delete()));

	selectRowAction=new QAction(tr("&Row"),this);
	selectRowAction->setStatusTip(tr("Select row cells"));
	connect(selectRowAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_selectRow()));

	selectColumnAction=new QAction(tr("&Colunm"),this);
	selectColumnAction->setStatusTip(tr("Select column cells"));
	connect(selectColumnAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_selectColumn()));

	selectAllAction=new QAction(tr("&All"),this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet."));
	connect(selectAllAction,SIGNAL(triggered()),this,SLOT(selectAll()));

	findAction=new QAction(tr("&Find..."),this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);
	findAction->setStatusTip(tr("Find"));
	connect(findAction,SIGNAL(triggered()),this,SLOT(slot_findDialog()));

	//Tools
	recalculateAction=new QAction(tr("&Recalculate"),this);
    recalculateAction->setShortcut(tr("F9"));
    recalculateAction->setStatusTip(tr("Recalculate"));
	connect(recalculateAction,SIGNAL(triggered),spreadsheet,SLOT(slot_recalculate));

	sortAction=new QAction(tr("&Sort..."),this);
    sortAction->setStatusTip(tr("Sort"));
	connect(sortAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_sort));

	//options
	showGridAction=new QAction(tr("Show Grid"),this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadsheet->showGrid());
	showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid."));
	connect(showGridAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(setShowGrid(bool)));

	autoRecalculateAction=new QAction(tr("&Auto Recalculate"),this);
	autoRecalculateAction->setCheckable(true);
	autoRecalculateAction->setChecked(spreadsheet->autoRecalculate());
	autoRecalculateAction->setStatusTip(tr("Auto recalculate"));
	connect(autoRecalculateAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(slot_setAutoRecalculate(bool)));

	//about
	aboutAction=new QAction(tr("&About"),this);
	aboutAction->setStatusTip(tr("About this application."));
	connect(aboutAction,SIGNAL(triggered()),this,SLOT(aboutSlot()));

	aboutQtAction=new QAction(tr("About &Qt"),this);
	aboutAction->setStatusTip(tr("Show the Qt library's About box."));
	connect(aboutAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

void MainWindow::newFile()
{

}

void MainWindow::openFile()
{

}

void MainWindow::saveFile()
{

}

void MainWindow::saveAsFile()
{

}

void MainWindow::openRecentFile()
{

}

void MainWindow::selectAll()
{

}

void MainWindow::slot_findNext(const QString &text, Qt::CaseSensitivity cs)
{

}

void MainWindow::slot_findPrevious(const QString &text, Qt::CaseSensitivity cs)
{

}

void MainWindow::aboutSlot()
{
	aboutdialog->show();
}

void MainWindow::createMenus()
{
	//file
	fileMenu=menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
	separatorAction=fileMenu->addSeparator();//为什么这里要保存变量？
	for(int i=0;i<MaxRecentFiles;i++)
	{
		fileMenu->addAction(recentFileAction[i]);
	}
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	//Edit
	editMenu=menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);
	selectMenu=editMenu->addMenu(tr("&Select"));
	selectMenu->addAction(selectRowAction);
	selectMenu->addAction(selectColumnAction);
	selectMenu->addAction(selectAllAction);
	editMenu->addSeparator();
	editMenu->addAction(findAction);

	//Tools

}

void MainWindow::slot_findDialog()
{
	p_finddialog->show();//MainWindow与findDialog的事件处理层次？
}

