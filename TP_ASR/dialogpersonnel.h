#ifndef DIALOGPERSONNEL_H
#define DIALOGPERSONNEL_H

#include <QDialog>

namespace Ui {
class DialogPersonnel;
}

class DialogPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPersonnel(QWidget *parent = 0);
    ~DialogPersonnel();

private:
    Ui::DialogPersonnel *ui;
};

#endif // DIALOGPERSONNEL_H
