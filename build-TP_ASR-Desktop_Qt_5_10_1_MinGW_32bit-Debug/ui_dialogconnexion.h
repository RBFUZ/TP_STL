/********************************************************************************
** Form generated from reading UI file 'dialogconnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConnexion
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnAnnuler;
    QLabel *lblLogin;
    QLabel *lblMotdepasse;
    QLineEdit *leLogin;
    QLineEdit *leMotdepasse;
    QPushButton *btnConnecter;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QStringLiteral("DialogConnexion"));
        DialogConnexion->resize(332, 130);
        gridLayoutWidget = new QWidget(DialogConnexion);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 20, 228, 106));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnAnnuler = new QPushButton(gridLayoutWidget);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));

        gridLayout->addWidget(btnAnnuler, 2, 1, 1, 1);

        lblLogin = new QLabel(gridLayoutWidget);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));

        gridLayout->addWidget(lblLogin, 0, 0, 1, 1);

        lblMotdepasse = new QLabel(gridLayoutWidget);
        lblMotdepasse->setObjectName(QStringLiteral("lblMotdepasse"));

        gridLayout->addWidget(lblMotdepasse, 1, 0, 1, 1);

        leLogin = new QLineEdit(gridLayoutWidget);
        leLogin->setObjectName(QStringLiteral("leLogin"));

        gridLayout->addWidget(leLogin, 0, 1, 1, 2);

        leMotdepasse = new QLineEdit(gridLayoutWidget);
        leMotdepasse->setObjectName(QStringLiteral("leMotdepasse"));

        gridLayout->addWidget(leMotdepasse, 1, 1, 1, 2);

        btnConnecter = new QPushButton(gridLayoutWidget);
        btnConnecter->setObjectName(QStringLiteral("btnConnecter"));

        gridLayout->addWidget(btnConnecter, 2, 2, 1, 1);


        retranslateUi(DialogConnexion);

        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QApplication::translate("DialogConnexion", "Authentification", nullptr));
        btnAnnuler->setText(QApplication::translate("DialogConnexion", "Annuler", nullptr));
        lblLogin->setText(QApplication::translate("DialogConnexion", "Login", nullptr));
        lblMotdepasse->setText(QApplication::translate("DialogConnexion", "Mot de passe", nullptr));
        btnConnecter->setText(QApplication::translate("DialogConnexion", "Connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
