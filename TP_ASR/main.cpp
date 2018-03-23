#include "vues/mainwindow.h"
#include "vues/dialogconnexion.h"
#include <QApplication>
#include "modeles/client.h"
#include "bdmanager/c_init_bd.h"

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

    QMultiMap<int, string> myMap = new QMultiMap<int,string>();
    myMap.insert(1, "titi");
    myMap.insert(4, "toto");
    myMap.insert(3, "tutu");
    myMap.insert(4, "tata");

    myMap.remove(3);
    myMap.insert(0, "tete");

    return a.exec();
}
