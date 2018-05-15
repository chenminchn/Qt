#include <QApplication>
#include <QDialog>

#include "sortdialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    sortDialog dialog;
    dialog.show();

    return app.exec();
}
