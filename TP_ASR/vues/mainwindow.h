#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "vues/tabclient.h"
#include "vues/tabpersonnel.h"

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

public slots:
    void setStatus(QString message);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
