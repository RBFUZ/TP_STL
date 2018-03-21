#ifndef TABPERSONNEL_H
#define TABPERSONNEL_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QStandardItemModel>

#include "vues/dialogpersonnel.h"
#include "bdmanager/bdmanagerpersonnel.h"
#include "bdmanager/bdmanagerplanification.h"

namespace Ui {
class TabPersonnel;
}

class TabPersonnel : public QWidget
{
    Q_OBJECT

public:
    explicit TabPersonnel(QWidget *parent = 0);
    ~TabPersonnel();
    void initPersonnel();
    void freeOldTree();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_btnModifier_clicked();

    void on_btnSupprimer_clicked();

private:
    Ui::TabPersonnel *ui;

    BDManagerPersonnel * bdManagerPersonnel;
    BDManagerPlanification * bdManagerPlanification;
    QMap<QString, QList<Personnel *> > mapPersonnel;

    QStandardItemModel * allItem;

signals:
    void changeStatus(QString message);
};

#endif // TABPERSONNEL_H
