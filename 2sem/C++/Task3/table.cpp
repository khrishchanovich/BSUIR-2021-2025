//#include "table.h"
//#include <QDebug>
//#include <QPushButton>

//Table::Table(QString FilePath, QString birthday, QWidget *parent) :
//    QDialog(parent), ui2(new Ui2::Table) {
//    ui2->setupUi(this);
//    Date *dates = new Date[4];

//    QFile file(FilePath);

//    file.open(QFile::ReadOnly);

//    ui->tableWidget->setRowCount(5);
//    ui->tableWidget->setColumnCount(8);

//    QTextStream stream(&file);
//    QString buffer;

//    for (short i = 1, j = 0; i < ui->tableWidget->rowCount(); ++i, ++j) {
//        buffer = stream.readLine();

//        dates[j].setData(buffer, birthday);

//        QTableWidgetItem *itm = new QTableWidgetItem(buffer);
//        ui->tableWidget->setItem(i, 0, itm);
//        buffer = "";
//    }

//    QTableWidgetItem *itm1 = new QTableWidgetItem("Разница между текущим и след.");
//    ui->tableWidget->setItem(0, 1, itm1);


//    QTableWidgetItem *itm2 = new QTableWidgetItem("NextDay");
//    ui->tableWidget->setItem(0, 2, itm2);


//    QTableWidgetItem *itm3 = new QTableWidgetItem("PrevDay");
//    ui->tableWidget->setItem(0, 3, itm3);


//    QTableWidgetItem *itm4 = new QTableWidgetItem("isLeap");
//    ui->tableWidget->setItem(0, 4, itm4);


//    QTableWidgetItem *itm5 = new QTableWidgetItem("WeekNumber");
//    ui->tableWidget->setItem(0, 5, itm5);


//    QTableWidgetItem *itm6 = new QTableWidgetItem("DaysTillBday");
//    ui->tableWidget->setItem(0, 6, itm6);

//    QTableWidgetItem *itm7 = new QTableWidgetItem("Duration");
//    ui->tableWidget->setItem(0, 7, itm7);

//    file.close();

//    for (short i = 1, k = 0; i < ui->tableWidget->rowCount(); ++i, ++k)
//        for (short j = 1; j < ui->tableWidget->columnCount(); ++j) {

//            switch (j) {

//            case 1:
//                if (k == 3) buffer = QString::number(dates[k].Duration(dates[0]));
//                else buffer = QString::number(dates[k].Duration(dates[k + 1]));
//                break;
//            case 2:
//                buffer = dates[k].NextDay();
//                break;
//            case 3:
//                buffer = dates[k].PreviousDay();
//                break;
//            case 4:
//                buffer = dates[k].isLeap() ? "Да" : "Нет";
//                break;
//            case 5:
//                buffer = QString::number(dates[k].WeekNumber());
//                break;
//            case 6:
//                buffer = QString::number(dates[k].DaysTillYourBirthday());
//                break;
//            case 7:
//                buffer = QString::number(dates[k].Duration(Date("25.04.2000")));
//            }

//            QTableWidgetItem *itm = new QTableWidgetItem(buffer);
//            ui->tableWidget->setItem(i, j, itm);
//            buffer = "";
//        }

//}

//Table::~Table() {
//    delete ui;
//}

//void Table::on_CorrectData_clicked()
//{

//    QTableWidget *newtable = new QTableWidget(this);

//    newtable->resize(400, 400);

//    QFile newfile("C:/Users/admin/Desktop/dateCopy.txt");

//    newfile.open(QFile::ReadWrite);

//    newtable->setRowCount(4);
//    newtable->setColumnCount(2);

//    QTextStream stream(&newfile);
//    QString buffer;

//    qint64 positions[4];

//    for (short i = 0; i < newtable->rowCount(); ++i) {
//        buffer = stream.readLine();
//        QTableWidgetItem *itm = new QTableWidgetItem(buffer);
//        newtable->setItem(i, 0, itm);

//        positions[i] = buffer.length() + 2;

//        buffer = "";
//    }

//    newfile.flush();
//    newfile.close();

//    newfile.open(QFile::WriteOnly);

//    qint64 costyl = 0;

//    for (short i = 0; i < ui->tableWidget->rowCount(); ++i) {
//        QString str = newtable->item(i, 1)->text();
//        const char* newdata = str.toStdString().c_str();
//        newfile.write("        \n");
//        newfile.seek(costyl);
//        newfile.write(newdata);
//        costyl += positions[i];
//    }
//    newfile.close();

//}


