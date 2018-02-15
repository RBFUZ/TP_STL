/********************************************************************************
** Form generated from reading UI file 'dialogapropos.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAPROPOS_H
#define UI_DIALOGAPROPOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogAPropos
{
public:
    QLabel *lblLogo;
    QLabel *lblDescriptionAPropos;

    void setupUi(QDialog *DialogAPropos)
    {
        if (DialogAPropos->objectName().isEmpty())
            DialogAPropos->setObjectName(QStringLiteral("DialogAPropos"));
        DialogAPropos->resize(191, 169);
        lblLogo = new QLabel(DialogAPropos);
        lblLogo->setObjectName(QStringLiteral("lblLogo"));
        lblLogo->setGeometry(QRect(10, 80, 181, 81));
        lblDescriptionAPropos = new QLabel(DialogAPropos);
        lblDescriptionAPropos->setObjectName(QStringLiteral("lblDescriptionAPropos"));
        lblDescriptionAPropos->setGeometry(QRect(10, 10, 171, 71));
        lblDescriptionAPropos->setPixmap(QPixmap(QString::fromUtf8(":/myLogo/images/logo_polytech.png")));
        lblDescriptionAPropos->setScaledContents(true);

        retranslateUi(DialogAPropos);

        QMetaObject::connectSlotsByName(DialogAPropos);
    } // setupUi

    void retranslateUi(QDialog *DialogAPropos)
    {
        DialogAPropos->setWindowTitle(QApplication::translate("DialogAPropos", "A propos", nullptr));
        lblLogo->setText(QApplication::translate("DialogAPropos", "<html><head/><body><p><span style=\" font-weight:600;\">Version 1.0</span></p><p>Projet de d\303\251veloppement C++</p><p>J\303\251r\303\251my Bouchard &amp; R\303\251my Bouteloup</p></body></html>", nullptr));
        lblDescriptionAPropos->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogAPropos: public Ui_DialogAPropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAPROPOS_H
