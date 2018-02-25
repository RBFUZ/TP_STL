#include "dialogpersonnel.h"
#include "ui_dialogpersonnel.h"

DialogPersonnel::DialogPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPersonnel)
{
    ui->setupUi(this);
}

DialogPersonnel::~DialogPersonnel()
{
    delete ui;
}
