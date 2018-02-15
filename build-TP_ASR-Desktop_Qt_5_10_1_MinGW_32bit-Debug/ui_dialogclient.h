/********************************************************************************
** Form generated from reading UI file 'dialogclient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCLIENT_H
#define UI_DIALOGCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogClient
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogClient)
    {
        if (DialogClient->objectName().isEmpty())
            DialogClient->setObjectName(QStringLiteral("DialogClient"));
        DialogClient->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogClient);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogClient);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogClient, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogClient, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogClient);
    } // setupUi

    void retranslateUi(QDialog *DialogClient)
    {
        DialogClient->setWindowTitle(QApplication::translate("DialogClient", "Ajout d'un client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogClient: public Ui_DialogClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCLIENT_H
