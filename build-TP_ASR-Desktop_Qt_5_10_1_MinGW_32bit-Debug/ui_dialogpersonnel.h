/********************************************************************************
** Form generated from reading UI file 'dialogpersonnel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPERSONNEL_H
#define UI_DIALOGPERSONNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogPersonnel
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPersonnel)
    {
        if (DialogPersonnel->objectName().isEmpty())
            DialogPersonnel->setObjectName(QStringLiteral("DialogPersonnel"));
        DialogPersonnel->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogPersonnel);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogPersonnel);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPersonnel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPersonnel, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPersonnel);
    } // setupUi

    void retranslateUi(QDialog *DialogPersonnel)
    {
        DialogPersonnel->setWindowTitle(QApplication::translate("DialogPersonnel", "Ajout d'un personnel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogPersonnel: public Ui_DialogPersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPERSONNEL_H
