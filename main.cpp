#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect rec = QApplication::desktop()->screenGeometry();
    MainWindow w;
    w.setGeometry((rec.width() - 1280) / 2, (rec.height() - 720) / 2, 1280, 720);
    w.show();

    return a.exec();
}
