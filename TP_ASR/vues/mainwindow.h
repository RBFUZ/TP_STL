#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    QSqlTableModel * model;
    void addModifAndRemoveOption();
};

#endif // MAINWINDOW_H
