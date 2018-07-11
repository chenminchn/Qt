#include "calculatecodenum.h"
#include <QDir>
#include <QFileDialog>
#include <QStringList>
#include <QFileInfo>
#include <QFile>
#include <QMapIterator>
#include <QTreeWidgetItem>
#include <QPair>

calculateCodeNum::calculateCodeNum(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(calculate()));
	connect(ui.pushButton_2, SIGNAL(clicked()), ui.treeWidget, SLOT(clear()));
	connect(ui.pushButton_2, SIGNAL(clicked()), ui.label_3, SLOT(clear()));
	connect(ui.pushButton_2, SIGNAL(clicked()), ui.label_4, SLOT(clear()));
}

void calculateCodeNum::calculate()
{
	map.clear();
	filesPath();
	showResult();
}

QStringList calculateCodeNum::DirectoryOf()
{//文件绝对路径
	QString directory = QDir::toNativeSeparators(
		QFileDialog::getExistingDirectory(this,
			tr("Select directory"), QDir::currentPath()));
	if (directory.isEmpty())
		return QStringList();
	QStringList filePaths;
	QDir dir(directory);
	QStringList filters;
	filters << "*.h" << ".cpp" << "*.qss" << ".pro";
	foreach(QString fileName, dir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot))
	{
		filePaths += directory + QDir::separator() + fileName;
	}
	return filePaths;
}

void calculateCodeNum::filesPath()
{
	QStringList filePaths = DirectoryOf();
	if (filePaths.isEmpty())
		return;
	foreach(QString filePath, filePaths) {

		QFile file(filePath);
		if (!file.open(QFile::ReadOnly))
			return;
		/*QString text = file.readAll();*/
		QString line;
		int validLineNum = 0, invalidLineNum = 0;
		while (!file.atEnd()) {
			line = file.readLine();
			if (!line.startsWith(QChar('\r')))
				validLineNum++;
			else
				invalidLineNum++;
		}
		map[filePath] = { validLineNum + invalidLineNum,validLineNum,invalidLineNum };
		file.close();
	}
}

void calculateCodeNum::showResult()
{
	if (map.isEmpty())
		return;
	QMapIterator<QString, QVector<int> > mpIter(map);
	int sum = 0, valid = 0;
	QTreeWidgetItem *root = ui.treeWidget->invisibleRootItem();
	while (mpIter.hasNext()) {
		mpIter.next();
		QTreeWidgetItem *item = new QTreeWidgetItem(root);
		item->setText(0, mpIter.key());
		item->setText(1, QString::number(mpIter.value().at(0)));
		item->setText(2, QString::number(mpIter.value().at(1)));
		item->setText(3, QString::number(mpIter.value().at(2)));
		ui.treeWidget->addTopLevelItem(item);
		sum += mpIter.value().at(0);
		valid += mpIter.value().at(1);
	}
	//ui.treeWidget->update();

	ui.label_3->setText(QString::number(sum));
	ui.label_4->setText(QString::number(valid));

}
