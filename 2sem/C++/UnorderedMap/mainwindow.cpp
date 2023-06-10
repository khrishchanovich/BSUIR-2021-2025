#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hash_table = new Unordered_Map<QString, QString, HashFunctor>(10);

    ui->KeylineEdit->setValidator(new QIntValidator(0, 99, this));
    ui->ValuelineEdit->setValidator(new QIntValidator(0, 99, this));

    table = new QStandardItemModel;

    print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print() {
    delete table;

    int arr_size = hash_table->get_capacity();
    std::list<std::pair<QString, QString>>* arr = hash_table->get_arr();

    table = new QStandardItemModel(0, arr_size, this);

    for (int i = 0; i < arr_size; i++)
        table->setHeaderData(i, Qt::Horizontal, QString::number(i));

    ui->tableView->setModel(table);

    for(int i = 0; i < 10; i++){
        ui->tableView->setColumnWidth(i, 43);
    }

    for (int i = 0; i < arr_size; i++) {
        int row = 0;

        for (const auto& it : arr[i]) {
            if (row > table->rowCount() - 1)
                table->insertRow(row);

            QModelIndex index = table->index(row++, i);

            QString text =it.first + ", " + it.second;
            table->setData(index, text);
        }
    }

}

void MainWindow::on_addButton_clicked()
{
    hash_table->Insert(std::make_pair(ui->KeylineEdit->text(), ui->ValuelineEdit->text()));
    print();
}


void MainWindow::on_deleteButton_clicked()
{
    hash_table->Erase(ui->deleteSpinBox->text());
    print();
}


void MainWindow::on_clearButton_clicked()
{
    hash_table->Clear();
    print();
}


void MainWindow::on_SearchButton_clicked()
{
    QString key = ui->SearchSpinBox->text();

    if(hash_table->Search(key))
    {
        QString k = hash_table->Search(key)->first;
        QString v = hash_table->Search(key)->second;
        ui->label->setText(k + ", " + v);
    }
    else
        ui->label->setText("Не найдено!");
}


void MainWindow::on_SetButton_clicked()
{
    QString k = ui->SetKeyspinBox->text();

    hash_table->operator[](k) = ui->SetValueSpinBox->text();

    print();
}


