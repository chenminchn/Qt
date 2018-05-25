#include <QSplashScreen>
#include <QApplication>
#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <qobject.h>
#include "mainwindow.h"

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

void loadModules(){

}

void establishConnections(){

}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    qInstallMessageHandler(outputMessage);
    QPixmap pixmap(":/images/splash.png");
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(pixmap);
    splash->show();

    splash->showMessage(QObject::tr("Setting the main window"),Qt::AlignTop|Qt::AlignRight,Qt::white);
    MainWindow *MainWin=new MainWindow;

    splash->showMessage(QObject::tr("Loading modules..."),Qt::AlignTop|Qt::AlignRight,Qt::white);
    loadModules();

    splash->showMessage(QObject::tr("Establishing connections..."),Qt::AlignTop|Qt::AlignRight,Qt::white);
    establishConnections();

    MainWin->show();
    splash->finish(MainWin);
    delete splash;

	return app.exec();
}
