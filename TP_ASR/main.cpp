#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>
#include "patient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    DialogConnexion dlgConnexion;
    int dialogCode = dlgConnexion.exec();

    if (dialogCode == QDialog::Accepted)
        w.show();
    else
        return 0;

    return a.exec();
}
