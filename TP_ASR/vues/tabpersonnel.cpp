#include "tabpersonnel.h"
#include "ui_tabpersonnel.h"

TabPersonnel::TabPersonnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPersonnel)
{
    ui->setupUi(this);

    bdManagerPersonnel = new BDManagerPersonnel();
    bdManagerPlanification = new BDManagerPlanification();

    allItem = NULL;

    // Fill TreeView (personnel)
    initPersonnel();
}

TabPersonnel::~TabPersonnel()
{
    delete ui;
    delete bdManagerPersonnel;
    delete bdManagerPlanification;

    freeOldTree();
}

void TabPersonnel::initPersonnel()
{
    QSqlQueryModel * listType = bdManagerPersonnel->selectAllType();
    QList<Personnel *> listPersonnel;

    freeOldTree();

    allItem = new QStandardItemModel(listType->rowCount(), 1); //  Contains all items

    for (int nodeNumber = 0; nodeNumber < listType->rowCount(); ++nodeNumber) // Iteration on each node
    {
        QStandardItem * item = new QStandardItem(listType->record(nodeNumber).value(1).toString()); // Node
        listPersonnel = bdManagerPersonnel->selectPersonnelSpecificType(listType->record(nodeNumber).value(0).toInt()); // Get all personnel of type item defined line above

        mapPersonnel.insert(listType->record(nodeNumber).value(1).toString(), listPersonnel); // Insert allPersonnel of one type to the map

        for (int childNumber = 0; childNumber < listPersonnel.size(); childNumber++) // Iteration on each child of one node
        {
            QStandardItem * child = new QStandardItem(listPersonnel.at(childNumber)->getNom()); // Child of one node
            item->appendRow(child); // Add child to the current node
        }
        allItem->setItem(nodeNumber, item); // Add the current node to the tree
    }

    ui->treeView->setModel(allItem);
    ui->treeView->show();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable edit mode
    allItem->setHeaderData(0, Qt::Horizontal, "", Qt::DisplayRole); // Set empty title to the column because print "1" by default

    delete listType;
}

void TabPersonnel::freeOldTree()
{
    if (allItem != NULL)
        delete allItem; // Old tree view
}

void TabPersonnel::on_treeView_clicked(const QModelIndex &index)
{
    if (index.parent().data().toString().compare("") != 0) // Check if child or node. If != child else node.
    {
        // Change properties of buttons
        ui->btnModifier->setEnabled(true);
        ui->btnSupprimer->setEnabled(true);
    }
    else
    {
        ui->btnModifier->setEnabled(false);
        ui->btnSupprimer->setEnabled(false);
    }
}

void TabPersonnel::on_btnModifier_clicked()
{
    QItemSelectionModel * model = ui->treeView->selectionModel();
    QModelIndex index = model->currentIndex();

    DialogPersonnel dialogPersonnel;
    dialogPersonnel.setCreate(false); // Set to modification mode
    dialogPersonnel.setPersonnel(mapPersonnel.find(index.parent().data().toString()).value().at(index.row()));
    dialogPersonnel.exec();

    initPersonnel();
    delete model;
    emit(changeStatus("Personnel modifié"));
}

void TabPersonnel::on_btnSupprimer_clicked()
{
    QItemSelectionModel * model = ui->treeView->selectionModel();
    QModelIndex index = model->currentIndex();

    int idPersonnel = mapPersonnel.find(index.parent().data().toString()).value().at(index.row())->getId();

    if (bdManagerPersonnel->isInformaticien(idPersonnel))
    {
        bdManagerPersonnel->removeCompte(idPersonnel);
    }

    bdManagerPersonnel->removePersonnel(idPersonnel);
    bdManagerPlanification->removeRdv(idPersonnel);

    initPersonnel();
    delete model;
    emit(changeStatus("Personnel supprimé"));
}
