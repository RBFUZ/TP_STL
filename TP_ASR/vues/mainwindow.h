#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDateEdit>
#include <QTableView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void searchClient(QList<QLineEdit *> listLineEdit, QList<QDateEdit *> listDateEdit, QTableView * tableView);

private slots:
    void on_actionQuitter_triggered();

    void on_actionClient_triggered();

    void on_actionPersonnel_triggered();

    void on_actionA_propos_triggered();

    void on_btnRechercherclient_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
