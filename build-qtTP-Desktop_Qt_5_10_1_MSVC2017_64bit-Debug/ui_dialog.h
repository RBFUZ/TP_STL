/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gdlDialog;
    QLineEdit *leMotDePasse;
    QLineEdit *leLogin;
    QLabel *lblLogin;
    QLabel *lblMotDePasse;
    QPushButton *btnConnecter;
    QPushButton *btnAnnuler;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 90, 241, 106));
        gdlDialog = new QGridLayout(gridLayoutWidget);
        gdlDialog->setObjectName(QStringLiteral("gdlDialog"));
        gdlDialog->setContentsMargins(0, 0, 0, 0);
        leMotDePasse = new QLineEdit(gridLayoutWidget);
        leMotDePasse->setObjectName(QStringLiteral("leMotDePasse"));
        leMotDePasse->setFocusPolicy(Qt::StrongFocus);
        leMotDePasse->setCursorPosition(0);

        gdlDialog->addWidget(leMotDePasse, 1, 1, 1, 2);

        leLogin = new QLineEdit(gridLayoutWidget);
        leLogin->setObjectName(QStringLiteral("leLogin"));
        leLogin->setFocusPolicy(Qt::StrongFocus);

        gdlDialog->addWidget(leLogin, 0, 1, 1, 2);

        lblLogin = new QLabel(gridLayoutWidget);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));

        gdlDialog->addWidget(lblLogin, 0, 0, 1, 1);

        lblMotDePasse = new QLabel(gridLayoutWidget);
        lblMotDePasse->setObjectName(QStringLiteral("lblMotDePasse"));

        gdlDialog->addWidget(lblMotDePasse, 1, 0, 1, 1);

        btnConnecter = new QPushButton(gridLayoutWidget);
        btnConnecter->setObjectName(QStringLiteral("btnConnecter"));

        gdlDialog->addWidget(btnConnecter, 3, 2, 1, 1);

        btnAnnuler = new QPushButton(gridLayoutWidget);
        btnAnnuler->setObjectName(QStringLiteral("btnAnnuler"));

        gdlDialog->addWidget(btnAnnuler, 3, 1, 1, 1);

        QWidget::setTabOrder(leLogin, leMotDePasse);
        QWidget::setTabOrder(leMotDePasse, btnConnecter);
        QWidget::setTabOrder(btnConnecter, btnAnnuler);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        lblLogin->setText(QApplication::translate("Dialog", "Login", nullptr));
        lblMotDePasse->setText(QApplication::translate("Dialog", "Mot de passe", nullptr));
        btnConnecter->setText(QApplication::translate("Dialog", "Connecter", nullptr));
        btnAnnuler->setText(QApplication::translate("Dialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
