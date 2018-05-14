#include <QApplication>
#include <QDialog>

#include "gotocelldialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    goToCellDialog dialog;
    dialog.show();
    return app.exec();
}
