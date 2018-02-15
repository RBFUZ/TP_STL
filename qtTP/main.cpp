#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog d;
    int dialogCode = d.exec();

    if (dialogCode == QDialog::Accepted)
        w.show();
    else
        return 0;

    return a.exec();
}
