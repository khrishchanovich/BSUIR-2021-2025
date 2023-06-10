#include "mainwindow.h"
#include <QPushButton>
#include <QLineEdit>

#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new MainWindow) {

    resize(400, 400);
    ChooseFile = new QPushButton("choose file", this);
    ChooseFile->adjustSize();
    ChooseFile->move(200, 100);

    Enter = new QPushButton("enter", this); Enter->adjustSize();
    Enter->move(200, 300);

    LE_Bday = new QLineEdit(this);
    LE_Bday->resize(100, 40);
    LE_Bday->move(170, 200);

    connect(Enter, SIGNAL(clicked()), this, SLOT(on_Enter_clicked()));
    connect(ChooseFile, SIGNAL(clicked()), this, SLOT(on_ChooseFile_clicked()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete ChooseFile; delete Enter;
    delete LE_Bday;
}

void MainWindow::on_ChooseFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/admin/Desktop",
                                                    "TXT File (*.txt);" );
    if (!FilePath.isEmpty()) ui->ChooseFile->setText(FilePath);

}


void MainWindow::on_Enter_clicked()
{




}
