#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include <QDialog>

class aboutDialog : public QDialog
{
    Q_OBJECT
public:
	aboutDialog(QWidget *parent=0);
    ~aboutDialog();
};
#endif
