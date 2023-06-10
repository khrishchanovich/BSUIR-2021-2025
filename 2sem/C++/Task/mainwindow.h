#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

#include "unique_ptr.h"
#include "shared_ptr.h"
#include "weak_ptr.h"
#include <QStandardItemModel>

class Item
{
public:
    Item()
    {
        std::cout << "create\n";
    }
    ~Item()
    {
        std::cout << "delete\n";
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_unique_ptr_clicked();

    void on_shared_ptr_clicked();

    void on_weak_ptr_clicked();

    void on_Uni_release_clicked();

    void on_Uni_swap_clicked();

    void on_Uni_reset_clicked();

    void on_Uni_move_clicked();

    void on_Sha_reset_clicked();

    void on_Sha_swap_clicked();

    void on_We_reset_clicked();

    void on_We_swap_clicked();

    void on_We_lock_clicked();

    void reload_un();
    void reload_sha();
    void reload_we();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* UTable;
    QStandardItemModel* STable;
    QStandardItemModel* WTable;
};
#endif // MAINWINDOW_H
