#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getBirthday_userDateChanged(const QDate &date)
{
    Date birthday = Date(date.year(), date.month(), date.day());
    QDate today = today.currentDate();
    Date td = Date(today.year(), today.month(), today.day());
    ui->number->setText(QString::number(td.DaysTillYourBithday(birthday)));
}



void MainWindow::on_openFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    if (in.atEnd()){
        dates.clear();
        QMessageBox::critical(this,"Ошибка", "Неверный формат в файле");
        return;
    }
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!CheckFile(line)){
            dates.clear();
            QMessageBox::critical(this,"Ошибка", "Неверный формат в файле");
            return;
        }

            QDate date = date.fromString(line, "dd.MM.yyyy");
            dates.push_back(Date(date.year(), date.month(), date.day()));
    }

    file.close();
    //countRow += dates.size();
    ui->datesd->setRowCount(dates.size());
    ui->datesd->setEditTriggers(0);
    for (int i = 0; i < dates.size(); ++i) {
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size(); ++i) {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i + 1]))));
    }
    qDebug() << dates.size();
}

bool MainWindow::CheckFile(QString date)
{
    if (date[2] != '.' || date[5] != '.' || date.length() != 10){
        return false;
    }
    for(int i = 0; i < date.length(); ++i){
        if ((date[i] > '9' || date[i] < '0') && date[i] != '.' ){
            return false;
        }
    }
    QString Day, Month, Year;
    Day += date[0];
    Day += date[1];
    Month += date[3];
    Month += date[4];
    Year += date[6];
    Year += date[7];
    Year += date[8];
    Year += date[9];
    int day = Day.toInt(), month = Month.toInt(), year = Year.toInt();
    Date dats(year,month,day);
    if (month > 12 || day > 31){
        return false;
    }
    if (!dats.IsLeap() && month == 2 && day > 28){
        return false;
    }
    if (dats.IsLeap() && month == 2 && day > 29){
        return false;
    }
    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        return false;
    }
    /*if (day = "" || month = "" || year = "") {
        return false;
    }*/
    return true;
}

void MainWindow::on_AddDate_clicked()
{
    QDate d = ui->getDay->date();
    dates.push_back(Date(d.year(), d.month(), d.day()));
    ui->datesd->setRowCount(dates.size());
    for(int i = 0; i < dates.size(); ++i){
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size() - 1; ++i) {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i+1]))));
    }
    QFile file("date.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            return;
    QTextStream out(&file);
    out << dates[dates.size()-1].ToString() << '\n';
}

void MainWindow::on_ChangeDate_clicked()
{
    if(!dates.size())
    {
        return;
    }
    if (ui->NumDate->text().toInt() > dates.size() || ui->NumDate->text().toInt() <= 0)
    {
        return;
    }
    QDate d = ui->getDay2->date();
    dates[ui->NumDate->text().toInt() - 1] = Date(d.year(), d.month(), d.day());
    ui->datesd->setRowCount(dates.size());
    for(int i = 0; i < dates.size(); ++i){
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }
    for (int i = 0; i < dates.size() - 1; ++i)
    {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i+1]))));
    }
    QFile file("date.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            return;
    QTextStream out(&file);
    out.seek((ui->NumDate->text().toInt() - 1) * 12);
    out << dates[ui->NumDate->text().toInt() - 1].ToString();
}

/*
void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
    QTextStream out(&file);
    for (int i = 0; i < dates.size(); ++i)
    {
        out << dates[i].ToString() << '\n';
    }
    file.flush();
    file.close();
}
*/

void MainWindow::on_DeleteDate_clicked()
{
    if (!dates.size())
    {
        return;
    }

    if (ui->NumDelete->text().toInt() > dates.size() || ui->NumDelete->text().toInt() <= 0)
    {
        return;
    }

    for (int i = ui->NumDelete->text().toInt() - 1; i < dates.size() - 1; ++i)
    {
        dates[i] = dates[i + 1];
    }

    dates.pop_back();

    ui->datesd->setRowCount(dates.size());

    for (int i = 0; i < dates.size(); ++i)
    {
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem(dates[i].IsLeap() ? QString("Yes") : QString("No")));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
    }

    for (int i = 0; i < dates.size() - 1; ++i)
    {
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(dates[i + 1]))));
    }

    QFile file("date.txt");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append))
    {
        return;
    }

    file.seek(12 * (ui->NumDelete->text().toInt() - 1));

    QString label, line;

    while(!file.atEnd())
    {
        line = file.readLine();
        label.append(line);
    }

    file.seek(12 * ((ui->NumDelete->text().toInt() - 1) - 1));

    QTextStream writeStream(&file);
    writeStream << label;
    file.resize(12 * (dates.size()));
}

