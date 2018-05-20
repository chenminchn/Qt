#include <QMutableStringListIterator>
#include "mainwindow.h"
#include "spreadsheet.h"
#include "aboutdialog.h"
#include "finddialog.h"
#include <QApplication>
#include <QIcon>
#include <QKeySequence>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVariant>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QCloseEvent>
#include <QStringList>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    //spreadsheet=new spreadSheet(this);
    setCentralWidget(spreadsheet);
    setMinimumSize(600,500);
	createActions();
    createMenus();
    createToolBars();
    createContextMenu();
    createStatusBar();
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
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

	saveAsAction=new QAction(tr("&Save As..."),this);
	saveAsAction->setIcon(QIcon(":/images/save.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
	saveAsAction->setStatusTip(tr("Save spreadsheet."));
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

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
    connect(copyAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_copy()));

	pasteAction=new QAction(tr("&Paste"),this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste cells"));
    connect(pasteAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_paste()));

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
    connect(findAction,SIGNAL(triggered()),this,SLOT(find()));

    gotocellAction=new QAction(tr("&Go to Cell..."),this);
    gotocellAction->setIcon(QIcon(":/images/gotocell.png"));
    gotocellAction->setShortcut(tr("Ctrl+G"));
    gotocellAction->setStatusTip(tr("Go to cell"));
    connect(gotocellAction,SIGNAL(triggered()),SLOT(slot_goToCellDialog()));

	//Tools
	recalculateAction=new QAction(tr("&Recalculate"),this);
    recalculateAction->setShortcut(tr("F9"));
    recalculateAction->setStatusTip(tr("Recalculate"));
    connect(recalculateAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_recalculate()));

	sortAction=new QAction(tr("&Sort..."),this);
    sortAction->setStatusTip(tr("Sort"));
    connect(sortAction,SIGNAL(triggered()),spreadsheet,SLOT(slot_sort()));

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

    //Help
	aboutAction=new QAction(tr("&About"),this);
	aboutAction->setStatusTip(tr("About this application."));
	connect(aboutAction,SIGNAL(triggered()),this,SLOT(aboutSlot()));

	aboutQtAction=new QAction(tr("About &Qt"),this);
	aboutAction->setStatusTip(tr("Show the Qt library's About box."));
	connect(aboutAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinue()){
        writeSettings();
        event->accept();
    }
    else{
        event->ignore();
    }
}

void MainWindow::writeSettings(){

}

void MainWindow::createMenus()
{

    //file menu
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

    //Edit menu
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
    editMenu->addAction(gotocellAction);

    //Tools menu
    toolsMenu=menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    //Options menu
    optionsMenu=menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalculateAction);

    //Help menu
    helpMenu=menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    fileToolBar=addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar=addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(gotocellAction);
}

void MainWindow::createStatusBar()
{
    locationLabel=new QLabel(tr("W999"),this);
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel=new QLabel(tr("test"),this);
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel,1);//1是伸展因子，可以将formulaLabel伸展

    connect(spreadsheet,SIGNAL(currentCellChangebdd(int,int,int,int)),this,SLOT(updateStatusBar()));
    updateStatusBar();
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::newFile()
{
    //文件未修改
    if(okToContinue()){
        spreadsheet->clear();
        setCurrentFile("");
    }
}
bool MainWindow::okToContinue(){
    if(isWindowModified()){
        int r=QMessageBox::warning(this, tr("Spreadsheet"), tr("The document has been modified.\n "
                                                               "Do you want to save your changes?"),
                                   QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        if(r==QMessageBox::Yes){
            return save();
        }else if(r==QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}

void MainWindow::openFile()
{
    if(okToContinue()){
        QString fileName=QFileDialog::getOpenFileName(this,tr("Open Spreadsheet"),".","Spreadsheet files (*sp)");
        if(!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString& file){
    if(!spreadsheet->readFile(file)){
        statusBar()->showMessage(tr("loading canceled"),2000);
        return false;
    }
    setCurrentFile(file);
    statusBar()->showMessage(tr("file loaded"),2000);
    return true;
}

void MainWindow::setCurrentFile(const QString& file){
    m_fileName=file;
    setWindowModified(false);
    QString shownName=tr("Untitled");
    if(!m_fileName.isEmpty()){
        shownName=strippedName(m_fileName);
        recentFiles.removeAll(m_fileName);
        recentFiles.prepend(m_fileName);
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*]-%2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString& fileName){
    return QFileInfo(fileName).fileName();
}

void MainWindow::updateRecentFileActions(){
    QMutableStringListIterator it(recentFiles);
    while(it.hasNext()){//java風格迭代器，指向begin之前，每次hasnext迭代器自動加一
        if(!QFile::exists(it.next())){
            it.remove();
        }
    }
    for(int i=0;i<MaxRecentFiles;i++){
        if(i<recentFiles.count()){
            QString text=tr("&%1 %2").arg(i+1).arg(strippedName(recentFiles[i]));
            recentFileAction[i]->setText(text);
            recentFileAction[i]->setData(QVariant(recentFiles[i]));
            recentFileAction[i]->setVisible(true);
        }
        else{
            recentFileAction[i]->setVisible(false);
        }
    }
    if(recentFiles.count()==0){
        separatorAction->setVisible(false);
    }
}

bool MainWindow::save(){
    //文件名存在》是一个已经存在的文件
    if(!m_fileName.isEmpty()){
        return saveFile(m_fileName);
    }
    //文件名不存在》是一个新建的文件
    else{
        return saveAs();
    }

}

bool MainWindow::saveAs()
{
    /*QString *selected=new QString("Text files (*.txt)");
    m_fileName=QFileDialog::getSaveFileName(this, tr("Save File"),
                                                  "/home/cm/Qt/sheet/untitled.sht",
                                                  "Sheet files(*.sht);;Text files (*.txt);;XML files (*.xml)",selected);
    save();
    delete selected;
    selected=NULL;*/
    QString fileName=QFileDialog::getSaveFileName(this,tr("save spreadsheet"),".",tr("Spreadsheet files(.sp)"));
    if(fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString& fileName){
    /*QFile file(m_fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug("open file failed");
        return;
    }
    QTextStream output(&file);
    QVector<QTableWidgetItem*> vItems;
    QTableWidgetItem *tempItem;
    for(int row=0;row<spreadsheet->rowCount()-1;row++){
        for(int col=0;col<spreadsheet->columnCount();col++){
            tempItem=spreadsheet->item(row,col);
            if(!tempItem){
                qDebug("空指针");
                continue;
            }
            else{
                if(!tempItem->data(Qt::DisplayRole).toString().isEmpty())
                    vItems.push_back(tempItem);
                else
                    continue;
            }
        }
    }
    foreach(auto vItem,vItems){
        QString str=vItem->data(Qt::DisplayRole).toString();
        if(!str.isEmpty()){
            output<<vItem->row()<<" "<<vItem->column()<<" "<<vItem->data(Qt::DisplayRole).toString()<<"\n";
        }
    }
    file.flush();
    file.close();*/
    if(!spreadsheet->writeFile(fileName)){
        statusBar()->showMessage(tr("saving canceled"),2000);
        return false;
    }
    else{
        statusBar()->showMessage(tr("file saved"),2000);
        return true;
    }
}

void MainWindow::openRecentFile()
{
    if(okToContinue()){
        QAction *action=qobject_cast<QAction*>(sender());
        if(action){
            loadFile(action->data().toString());
        }
    }
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

void MainWindow::slot_goToCellDialog()
{

}

void MainWindow::aboutSlot()
{
	aboutdialog->show();
}

void MainWindow::find()
{
    if(!p_finddialog){
        p_finddialog=new findDialog(this);
        connect(p_finddialog,SIGNAL(findNext(QString,Qt::CaseSensitivity)),
                spreadsheet,SLOT(findNext(QString,Qt::CaseSensitivity)));
        connect(p_finddialog,SIGNAL(findPrevious(QString,Qt::CaseSensitivity)),
                spreadsheet,SLOT(findPrevious(QString,Qt::CaseSensitivity)));
    }
    p_finddialog->show();
    p_finddialog->raise();
    p_finddialog->activateWindow();
}

