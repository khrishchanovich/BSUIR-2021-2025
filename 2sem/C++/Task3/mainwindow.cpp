#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
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
    connect(ChooseFile, SIGNAL(clicked()), this, SLOT(on_Enter_clicked()));
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


    QTableWidget *newtable = new QTableWidget(this);

    newtable->resize(400, 400);

    QFile newfile("C:/Users/admin/Desktop/dateCopy.txt");

    newfile.open(QFile::ReadWrite);

    newtable->setRowCount(4);
    newtable->setColumnCount(2);

    QTextStream stream(&newfile);
    QString buffer;

    qint64 positions[4];

    for (short i = 0; i < newtable->rowCount(); ++i) {
        buffer = stream.readLine();
        QTableWidgetItem *itm = new QTableWidgetItem(buffer);
        newtable->setItem(i, 0, itm);

        positions[i] = buffer.length() + 2;

        buffer = "";
    }

    newfile.flush();
    newfile.close();

    newfile.open(QFile::WriteOnly);

    qint64 costyl = 0;

    for (short i = 0; i < table->rowCount(); ++i) {
        QString str = newtable->item(i, 1)->text();
        const char* newdata = str.toStdString().c_str();
        newfile.write("        \n");
        newfile.seek(costyl);
        newfile.write(newdata);
        costyl += positions[i];
    }
    newfile.close();


}
