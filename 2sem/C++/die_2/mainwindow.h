#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <vector>
#include <QMessageBox>

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

    void on_getBirthday_userDateChanged(const QDate &date);
    void on_openFile_clicked();
    bool CheckFile(QString date);
    void on_AddDate_clicked();
    void on_ChangeDate_clicked();
    void on_saveButton_clicked();

    void on_DeleteDate_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Date> dates;
    int countRow = 0;
};
#endif // MAINWINDOW_H
