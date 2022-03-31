#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "mymodel.h"
#include "QGridLayout"
#include "linedelegate.h"
#include "editpitomecdialog.h"
#include "dialogdelegate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Данные о питомце");
    tableView = new QTableView();
    myModel = new MyModel(this);
    tableView->setModel( myModel );

      DialogDelegate* ddel = new DialogDelegate(nullptr,this);

      lineDelegate* ldel = new lineDelegate();
      tableView->setItemDelegateForColumn(0,ddel);
      tableView->setItemDelegateForColumn(1,ldel);
      tableView->setItemDelegateForColumn(2,ldel);
      tableView->setItemDelegateForColumn(3,ldel);
      tableView->setItemDelegateForColumn(4,ldel);
      //tableView->setItemDelegateForColumn(5,ldel);
      tableView->viewport()->setAttribute(Qt::WA_Hover);

    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Добавить ");
    QPushButton* pb2 = new QPushButton("Удалить ");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditPitomecDialog* addDialog = new EditPitomecDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Pitomec* std = new Pitomec(addDialog->id(),addDialog->name(),addDialog->age(),addDialog->breed(),addDialog->fio(),this);
        myModel->AddPitomec(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    myModel->DeletePitomec(selList.row());
}
