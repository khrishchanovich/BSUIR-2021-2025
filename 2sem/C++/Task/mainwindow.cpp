#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

my_unique_ptr<int> *Urr = new my_unique_ptr<int>[20];
my_shared_ptr<int> *Srr = new my_shared_ptr<int>[20];
my_weak_ptr<int> *Wrr = new my_weak_ptr<int>[20];



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Urr[0].reset();
    Urr[0] = my_unique_ptr<int>(new int(16));
    Urr[1].reset();
    Urr[1] = my_unique_ptr<int>(new int(17));
    Srr[0] = my_shared_ptr<int>(new int(6 ));
    Wrr[0] = Srr[0];

    Srr[1] = Srr[0];
    Srr[2] = Srr[1];
    Srr[3] = Srr[2];
    Srr[4] = Srr[3];
    Srr[5] = Srr[4];
    Srr[6] = Srr[5];
    Srr[7] = Srr[6];
    Srr[8] = Srr[7];
    Srr[9] = Srr[8];


    Wrr[1] = Wrr[0];
    Wrr[2] = Wrr[1];
    Wrr[3] = Wrr[2];
    Wrr[4] = Wrr[3];
    Wrr[5] = Wrr[4];
    Wrr[6] = Wrr[5];
    Wrr[7] = Wrr[6];
    Wrr[8] = Wrr[7];
    Wrr[9] = Wrr[8];

    ui->setupUi(this);
    UTable = new QStandardItemModel(10,2,this);
    STable = new QStandardItemModel(10,3,this);
    WTable = new QStandardItemModel(10,4,this);

    ui->UTableViw->setModel(UTable);
    ui->STableView->setModel(STable);
    ui->WEakTablView->setModel(WTable);



    UTable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    UTable->setHeaderData(1, Qt::Horizontal, "Adress");

    for(int  i = 0; i < UTable->rowCount(); i++){
        QString buffer = "Unique_ptr_" + QString::number(i+1);
        UTable->setData(UTable->index(i,0), buffer);
    }

    for(int  i = 0; i < UTable->rowCount(); i++){
        QString t;
        t.sprintf("%08p", Urr[i].operator->());
        UTable->setData(UTable->index(i,1), QString::asprintf("%08p", Urr[i].operator->()));
    }

    //===============================================================================

    STable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    STable->setHeaderData(1, Qt::Horizontal, "Adress");
    STable->setHeaderData(2, Qt::Horizontal, "Owner");

    for(int  i = 0; i < STable->rowCount(); i++){
        QString buffer = "Shared_ptr_" + QString::number(i+1);
        STable->setData(STable->index(i,0), buffer);
    }

    for(int  i = 0; i < STable->rowCount(); i++){
        QString t;
        t.sprintf("%08p", Srr[i].operator->());
        STable->setData(STable->index(i,1), t);
    }

    for(int  i = 0; i < STable->rowCount(); i++){
        STable->setData(STable->index(i,2), QString::number(Srr[i].use_count()));
    }

    //=================================================================================

    WTable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    WTable->setHeaderData(1, Qt::Horizontal, "Adress");
    WTable->setHeaderData(2, Qt::Horizontal, "Owner");
    WTable->setHeaderData(3,Qt::Horizontal, "Observers");

    for(int  i = 0; i < WTable->rowCount(); i++){
        QString buffer = "Weak_ptr_" + QString::number(i+1);
        WTable->setData(WTable->index(i,0), buffer);
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        QString t;
        t.sprintf("%08p", Srr[i].operator->());
        WTable->setData(WTable->index(i,1), t);
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        WTable->setData(WTable->index(i,2), QString::number(Wrr[i].get_shared_count()));
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        WTable->setData(WTable->index(i,3), QString::number(Wrr[i].get_weak_count()));
    }

    ui->U_Move_1->setRange(1,10);
    ui->U_Move_2->setRange(1,10);
    ui->U_sw_1->setRange(1,10);
    ui->U_sw_2->setRange(1,10);
    ui->u_release->setRange(1,10);
    ui->u_reset->setRange(1,10);

    ui->sha_reset->setRange(1,10);
    ui->sha_sw->setRange(1,10);
    ui->sha_2sw->setRange(1,10);

    ui->we_res->setRange(1,10);
    ui->we_lo->setRange(1,10);
    ui->we_sw1->setRange(1,10);
    ui->we_sw2->setRange(1,10);


    ui->unique_ptr->setDisabled(false);
    ui->shared_ptr->setDisabled(false);
    ui->weak_ptr->setDisabled(false);

    ui->Uni_move->setDisabled(true);
    ui->Uni_release->setDisabled(true);
    ui->Uni_reset->setDisabled(true);
    ui->Uni_swap->setDisabled(true);

    ui->Sha_reset->setDisabled(true);
    ui->Sha_swap->setDisabled(true);

    ui->We_lock->setDisabled(true);
    ui->We_reset->setDisabled(true);
    ui->We_swap->setDisabled(true);

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_unique_ptr_clicked()
{
    ui->unique_ptr->setDisabled(true);
    ui->shared_ptr->setDisabled(false);
    ui->weak_ptr->setDisabled(false);

    ui->Uni_move->setDisabled(false);
    ui->Uni_release->setDisabled(false);
    ui->Uni_reset->setDisabled(false);
    ui->Uni_swap->setDisabled(false);

    ui->Sha_reset->setDisabled(true);
    ui->Sha_swap->setDisabled(true);

    ui->We_lock->setDisabled(true);
    ui->We_reset->setDisabled(true);
    ui->We_swap->setDisabled(true);
}


void MainWindow::on_shared_ptr_clicked()
{
    ui->unique_ptr->setDisabled(false);
    ui->shared_ptr->setDisabled(true);
    ui->weak_ptr->setDisabled(false);

    ui->Uni_move->setDisabled(true);
    ui->Uni_release->setDisabled(true);
    ui->Uni_reset->setDisabled(true);
    ui->Uni_swap->setDisabled(true);

    ui->Sha_reset->setDisabled(false);
    ui->Sha_swap->setDisabled(false);

    ui->We_lock->setDisabled(true);
    ui->We_reset->setDisabled(true);
    ui->We_swap->setDisabled(true);
}


void MainWindow::on_weak_ptr_clicked()
{
    ui->unique_ptr->setDisabled(false);
    ui->shared_ptr->setDisabled(false);
    ui->weak_ptr->setDisabled(true);

    ui->Uni_move->setDisabled(true);
    ui->Uni_release->setDisabled(true);
    ui->Uni_reset->setDisabled(true);
    ui->Uni_swap->setDisabled(true);

    ui->Sha_reset->setDisabled(true);
    ui->Sha_swap->setDisabled(true);

    ui->We_lock->setDisabled(false);
    ui->We_reset->setDisabled(false);
    ui->We_swap->setDisabled(false);
}

//QLineEdit::Normal
void MainWindow::on_Uni_release_clicked()
{
     int num = ui->u_release->value() -1;

     Urr[num].release();

     reload_un();
}


void MainWindow::on_Uni_swap_clicked()
{
     int num1 = ui->U_sw_1->value()-1;

      int num2 = ui->U_sw_2->value()-1;

     Urr[num1].swap(Urr[num2]);
     reload_un();
}


void MainWindow::on_Uni_reset_clicked()
{
     int num = ui->u_reset->value()-1;

     Urr[num].reset();

     UTable = new QStandardItemModel(10,2,this);

     ui->UTableViw->setModel(UTable);
     UTable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
     UTable->setHeaderData(1, Qt::Horizontal, "Adress");

     for(int  i = 0; i < UTable->rowCount(); i++)
     {
         QString buffer = "Unique_ptr_" + QString::number(i+1);
         UTable->setData(UTable->index(i,0), buffer);
     }

     for(int  i = 0; i < UTable->rowCount(); i++)
     {
         if(i == num)
         {
             QString t = "nullptr";
             UTable->setData(UTable->index(i,1), t);
             continue;
         }
         QString t;
         //if(Srr[i].operator->() != nullptr){
         t.sprintf("%08p", Urr[i].operator->());

         UTable->setData(UTable->index(i,1), QString::asprintf("%08p", Urr[i].operator->()));
     }

     reload_un();
}


void MainWindow::on_Uni_move_clicked()
{


     int num1 = ui->U_Move_1->value()-1;

      int num2 = ui->U_Move_2->value()-1;

      qDebug() << num1 <<',' << num2;

     Urr[num1].move(Urr[num2]);
     reload_un();
}


void MainWindow::on_Sha_reset_clicked()
{
     int num = ui->sha_reset->value()-1;

     Srr[num].reset();
     reload_sha();
}


void MainWindow::on_Sha_swap_clicked()
{
     int num1 = ui->sha_sw->value()-1;
      int num2 = ui->sha_2sw->value()-1;
      Srr[num1].swap(Srr[num2]);

      reload_sha();
}


void MainWindow::on_We_reset_clicked()
{

     int num = ui->we_res->value()-1;
    Wrr[num].reset();

    reload_we();

}


void MainWindow::on_We_swap_clicked()
{
     int num1 = ui->we_sw1->value()-1;

      int num2 = ui->we_sw2->value()-1;

      Wrr[num1].swap(Wrr[num2]);

      reload_we();
}


void MainWindow::on_We_lock_clicked()
{


     int num = ui->we_lo->value()-1;

     if(Wrr[num].operator->() != nullptr){

     Srr[num] = Wrr[num].lock();

     reload_we();
     reload_sha();
     }
}

void MainWindow::reload_un()
{
    //UTable = new QStandardItemModel(10,2,this);

    //ui->UTableViw->setModel(UTable);
    //UTable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    //UTable->setHeaderData(1, Qt::Horizontal, "Adress");

    for(int  i = 0; i < UTable->rowCount(); i++){
        QString buffer = "Unique_ptr_" + QString::number(i+1);
        UTable->setData(UTable->index(i,0), buffer);
    }

    for(int  i = 0; i < UTable->rowCount(); i++){
        QString t;
       // if(Srr[i].operator->() != nullptr){
        t.sprintf("%08p", Urr[i].operator->());
        UTable->setData(UTable->index(i,1), t);

    }
}

void MainWindow::reload_sha()
{
    STable = new QStandardItemModel(10,3,this);

    ui->STableView->setModel(STable);

    STable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    STable->setHeaderData(1, Qt::Horizontal, "Adress");
    STable->setHeaderData(2, Qt::Horizontal, "Owner");

    for(int  i = 0; i < STable->rowCount(); i++){
        QString buffer = "Shared_ptr_" + QString::number(i+1);
        STable->setData(STable->index(i,0), buffer);
    }

    for(int  i = 0; i < STable->rowCount(); i++){
        QString t;
        t.sprintf("%08p", Srr[i].operator->());
        STable->setData(STable->index(i,1), t);
    }

    for(int  i = 0; i < STable->rowCount(); i++){
        if(Srr[i].operator->() != nullptr){                              /////////////////////////////////////////////////////
        STable->setData(STable->index(i,2), QString::number(Srr[i].use_count()));
        } else {
            STable->setData(STable->index(i,2),"nullptr");
        }
    }
}

void MainWindow::reload_we()
{
    WTable = new QStandardItemModel(10,4,this);

    ui->WEakTablView->setModel(WTable);

    WTable->setHeaderData(0, Qt::Horizontal, "Ptr Name");
    WTable->setHeaderData(1, Qt::Horizontal, "Adress");
    WTable->setHeaderData(2, Qt::Horizontal, "Owner");
    WTable->setHeaderData(3,Qt::Horizontal, "Observers");

    for(int  i = 0; i < WTable->rowCount(); i++){
        QString buffer = "Weak_ptr_" + QString::number(i+1);
        WTable->setData(WTable->index(i,0), buffer);
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        QString t;
        t.sprintf("%08p", Srr[i].operator->());
        WTable->setData(WTable->index(i,1), t);
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        if(Wrr[i].operator->() != nullptr){
        WTable->setData(WTable->index(i,2), QString::number(Wrr[i].get_shared_count()));
        } else {
            WTable->setData(WTable->index(i,2),"nullptr");
        }
    }

    for(int  i = 0; i < WTable->rowCount(); i++){
        if(Wrr[i].operator->() != nullptr){
        WTable->setData(WTable->index(i,3), QString::number(Wrr[i].get_weak_count()));
        } else {
            WTable->setData(WTable->index(i,2),"nullptr");
        }
    }
}

