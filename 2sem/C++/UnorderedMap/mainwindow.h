#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "unordered_map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class HashFunctor {
public:
    int operator()(const QString& str) {
        int sum = 0;
        for (const auto& i : str)
            sum += i.unicode();
        return sum;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_clearButton_clicked();

    void on_SearchButton_clicked();

    void on_SetButton_clicked();
private:
    Ui::MainWindow *ui;

    Unordered_Map<QString, QString, HashFunctor>* hash_table;

    QStandardItemModel* table;

    void print();
};
#endif // MAINWINDOW_H
