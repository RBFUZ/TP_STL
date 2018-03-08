#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "bdmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();
    void on_actionClient_triggered();
    void on_actionPersonnel_triggered();
    void on_actionA_propos_triggered();
    void on_tableView_activated(const QModelIndex &index);
    void on_btnRechercherclient_clicked();

    void on_treeView_clicked(const QModelIndex &index);

    void on_btnModifier_clicked();

    void on_btnSupprimer_clicked();

private:
    Ui::MainWindow *ui;
    BDManager * bdManager;
    QSqlTableModel * model; // TODO A revoir, inutile peut être
    QMap<QString, QList<Personnel *>> mapPersonnel;

    void addModifAndRemoveOption();
    void initClient();
    void setPropertyTableView();
    void initPersonnel();
};

#endif // MAINWINDOW_H
