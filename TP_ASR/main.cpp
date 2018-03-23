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

    multimap<int, string> myMap ;
    myMap.insert(pair<int, string> (1, "titi"));
    myMap.insert(pair<int, string> (4, "toto"));
    myMap.insert(pair<int, string> (3, "tutu"));
    myMap.insert(pair<int, string> (4, "tata"));

    for (multimap<int,string>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
       if ( (*it).first == 3)
           myMap.erase(it);

    myMap.insert(pair<int,string> (0, "tete"));


     for (multimap<int,string>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
        std::cout << (*it).first << " => " << (*it).second << '\n';

    return a.exec();
}
