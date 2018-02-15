/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionA_propos;
    QAction *actionClient;
    QAction *actionPersonnel;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *leIdentifiant;
    QLabel *lblIdentifiant;
    QLineEdit *lePrenom;
    QLabel *lblNom;
    QLabel *lblPrenom;
    QDateEdit *deRendezvous;
    QLineEdit *leNom;
    QLabel *lblDaterendezvous;
    QPushButton *btnRechercherclient;
    QTableView *tableView;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *lblRendezvous;
    QDateEdit *deRendezvousplanification;
    QPushButton *btnRechercherplanification;
    QTableView *tableView_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAjouter;
    QMenu *menu;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(616, 517);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionClient = new QAction(MainWindow);
        actionClient->setObjectName(QStringLiteral("actionClient"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/myLogo/images/logo_client.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionClient->setIcon(icon);
        actionPersonnel = new QAction(MainWindow);
        actionPersonnel->setObjectName(QStringLiteral("actionPersonnel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/myLogo/images/logo_personnel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPersonnel->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 591, 391));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 561, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leIdentifiant = new QLineEdit(gridLayoutWidget);
        leIdentifiant->setObjectName(QStringLiteral("leIdentifiant"));

        gridLayout->addWidget(leIdentifiant, 0, 4, 1, 1);

        lblIdentifiant = new QLabel(gridLayoutWidget);
        lblIdentifiant->setObjectName(QStringLiteral("lblIdentifiant"));

        gridLayout->addWidget(lblIdentifiant, 0, 3, 1, 1);

        lePrenom = new QLineEdit(gridLayoutWidget);
        lePrenom->setObjectName(QStringLiteral("lePrenom"));

        gridLayout->addWidget(lePrenom, 0, 1, 1, 1);

        lblNom = new QLabel(gridLayoutWidget);
        lblNom->setObjectName(QStringLiteral("lblNom"));

        gridLayout->addWidget(lblNom, 1, 0, 1, 1);

        lblPrenom = new QLabel(gridLayoutWidget);
        lblPrenom->setObjectName(QStringLiteral("lblPrenom"));

        gridLayout->addWidget(lblPrenom, 0, 0, 1, 1);

        deRendezvous = new QDateEdit(gridLayoutWidget);
        deRendezvous->setObjectName(QStringLiteral("deRendezvous"));

        gridLayout->addWidget(deRendezvous, 1, 4, 1, 1);

        leNom = new QLineEdit(gridLayoutWidget);
        leNom->setObjectName(QStringLiteral("leNom"));

        gridLayout->addWidget(leNom, 1, 1, 1, 1);

        lblDaterendezvous = new QLabel(gridLayoutWidget);
        lblDaterendezvous->setObjectName(QStringLiteral("lblDaterendezvous"));

        gridLayout->addWidget(lblDaterendezvous, 1, 3, 1, 1);

        btnRechercherclient = new QPushButton(gridLayoutWidget);
        btnRechercherclient->setObjectName(QStringLiteral("btnRechercherclient"));

        gridLayout->addWidget(btnRechercherclient, 0, 5, 2, 1);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 28, 561, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lblRendezvous = new QLabel(gridLayoutWidget_2);
        lblRendezvous->setObjectName(QStringLiteral("lblRendezvous"));

        gridLayout_2->addWidget(lblRendezvous, 0, 0, 1, 1);

        deRendezvousplanification = new QDateEdit(gridLayoutWidget_2);
        deRendezvousplanification->setObjectName(QStringLiteral("deRendezvousplanification"));

        gridLayout_2->addWidget(deRendezvousplanification, 0, 1, 1, 1);

        btnRechercherplanification = new QPushButton(gridLayoutWidget_2);
        btnRechercherplanification->setObjectName(QStringLiteral("btnRechercherplanification"));

        gridLayout_2->addWidget(btnRechercherplanification, 0, 2, 1, 1);

        tableView_2 = new QTableView(gridLayoutWidget_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));

        gridLayout_2->addWidget(tableView_2, 1, 0, 1, 3);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuAjouter = new QMenu(menuFichier);
        menuAjouter->setObjectName(QStringLiteral("menuAjouter"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setCursor(QCursor(Qt::ArrowCursor));
        statusBar->setStyleSheet(QStringLiteral(""));
        statusBar->setInputMethodHints(Qt::ImhNone);
        statusBar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(menuAjouter->menuAction());
        menuFichier->addAction(actionQuitter);
        menuAjouter->addAction(actionClient);
        menuAjouter->addAction(actionPersonnel);
        menu->addAction(actionA_propos);
        toolBar->addAction(actionClient);
        toolBar->addSeparator();
        toolBar->addAction(actionPersonnel);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fen\303\252tre principale", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", nullptr));
        actionClient->setText(QApplication::translate("MainWindow", "Client", nullptr));
        actionPersonnel->setText(QApplication::translate("MainWindow", "Personnel", nullptr));
        lblIdentifiant->setText(QApplication::translate("MainWindow", "Identifiant", nullptr));
        lblNom->setText(QApplication::translate("MainWindow", "Nom", nullptr));
        lblPrenom->setText(QApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        lblDaterendezvous->setText(QApplication::translate("MainWindow", "Date de rendez-vous", nullptr));
        btnRechercherclient->setText(QApplication::translate("MainWindow", "Rechercher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Recherche de client", nullptr));
        lblRendezvous->setText(QApplication::translate("MainWindow", "Date de rendez-vous", nullptr));
        btnRechercherplanification->setText(QApplication::translate("MainWindow", "Rechercher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Planification", nullptr));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", nullptr));
        menuAjouter->setTitle(QApplication::translate("MainWindow", "Ajouter", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "?", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
