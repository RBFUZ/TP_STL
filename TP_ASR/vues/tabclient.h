#ifndef TABCLIENT_H
#define TABCLIENT_H

#include <QWidget>
#include "bdmanager/bdmanagerclient.h"

namespace Ui {
class TabClient;
}

class TabClient : public QWidget
{
    Q_OBJECT

public:
    explicit TabClient(QWidget *parent = 0);
    ~TabClient();
    void initClient();

private slots:
    void on_btnRechercherclient_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::TabClient *ui;
    BDManagerClient * bdManagerClient;
    QSqlTableModel * model;

    void addModifAndRemoveOption();
    void setPropertyTableView();
};

#endif // TABCLIENT_H
