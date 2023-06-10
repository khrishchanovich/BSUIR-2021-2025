#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

MainWindow::~MainWindow()
{
    delete ui;
    delete ChooseFile; delete Enter;
    delete LE_Bday;
}


void MainWindow::on_ChooseFile_clicked()
{
    FilePath = QFileDialog::getOpenFileName(this, "Выбрать текстовый файл",
                                                    "C:/Users/admin/Desktop",
                                                    "TXT File (*.txt);" );
    if (!FilePath.isEmpty()) ChooseFile->setText(FilePath);

}


void MainWindow::on_Enter_clicked()
{

    Bday = LE_Bday->text();
    QRegularExpression reg("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");
    if (!Bday.contains(reg))
        QMessageBox::critical(this, "Ошибка", "Формат ввода:\ndd.mm.yyyy");
    else if (!FilePath.isEmpty()) {

        QTableWidget *tableWidget = new QTableWidget(this);

        tableWidget->resize(1000, 700);

        Date *dates = new Date[4];

            QFile file(FilePath);

            file.open(QFile::ReadOnly);

            tableWidget->setRowCount(5);
           tableWidget->setColumnCount(8);

            QTextStream stream(&file);
            QString buffer;

            for (short i = 1, j = 0; i < tableWidget->rowCount(); ++i, ++j) {
                buffer = stream.readLine();

                dates[j].setData(buffer, Bday);

                QTableWidgetItem *itm = new QTableWidgetItem(buffer);
                tableWidget->setItem(i, 0, itm);
                buffer = "";
            }

            QTableWidgetItem *itm1 = new QTableWidgetItem("Разница между текущим и след.");
            tableWidget->setItem(0, 1, itm1);


            QTableWidgetItem *itm2 = new QTableWidgetItem("NextDay");
            tableWidget->setItem(0, 2, itm2);


            QTableWidgetItem *itm3 = new QTableWidgetItem("PrevDay");
            tableWidget->setItem(0, 3, itm3);


            QTableWidgetItem *itm4 = new QTableWidgetItem("isLeap");
            tableWidget->setItem(0, 4, itm4);


            QTableWidgetItem *itm5 = new QTableWidgetItem("WeekNumber");
            tableWidget->setItem(0, 5, itm5);


            QTableWidgetItem *itm6 = new QTableWidgetItem("DaysTillBday");
            tableWidget->setItem(0, 6, itm6);

            QTableWidgetItem *itm7 = new QTableWidgetItem("Duration");
            tableWidget->setItem(0, 7, itm7);

            file.close();

            for (short i = 1, k = 0; i < tableWidget->rowCount(); ++i, ++k)
                for (short j = 1; j < tableWidget->columnCount(); ++j) {

                    switch (j) {

                    case 1:
                        if (k == 3) buffer = QString::number(dates[k].Duration(dates[0]));
                        else buffer = QString::number(dates[k].Duration(dates[k + 1]));
                        break;
                    case 2:
                        buffer = dates[k].NextDay();
                        break;
                    case 3:
                        buffer = dates[k].PreviousDay();
                        break;
                    case 4:
                        buffer = dates[k].isLeap() ? "Да" : "Нет";
                        break;
                    case 5:
                        buffer = QString::number(dates[k].WeekNumber());
                        break;
                    case 6:
                        buffer = QString::number(dates[k].DaysTillYourBirthday());
                        break;
                    case 7:
                        buffer = QString::number(dates[k].Duration(Date("25.04.2000")));
                    }

                    QTableWidgetItem *itm = new QTableWidgetItem(buffer);
                    tableWidget->setItem(i, j, itm);
                    buffer = "";
                }

            QPushButton *btn = new QPushButton("ddf", tableWidget);

            btn->move(300, 400);

            connect(btn, SIGNAL(clicked()), this, SLOT(CorretData()));

            tableWidget->show();

    }
}

void MainWindow::CorrectData()
{

    QFile newfile("C:/Users/admin/Desktop/dateCopy.txt");

    newfile.open(QFile::WriteOnly);

    newfile.write("be be be");

    newfile.close();
}
