#include "vues/mainwindow.h"
#include "vues/dialogconnexion.h"
#include <QApplication>
#include "modeles/client.h"
#include "c_init_bd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    C_INIT_BD::Creation_BD();

    MainWindow w;

    // Authentification
    /*DialogConnexion dlgConnexion;
    int dialogCode = dlgConnexion.exec();

    if (dialogCode == QDialog::Accepted)
        w.show();
    else
        return 0;*/

    w.show();

    return a.exec();
}
