#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <rect.h>

#include <QMainWindow>
#include <QGraphicsView>

#include <QTimer>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class Scene : public QGraphicsView
{
    Q_OBJECT; // QGraphicsView не поддерживает сигналы и слоты
public:
    Scene(int inputFloor = 0, QWidget *parent = nullptr);
private:
    QGraphicsScene *scene;
    QTimer *myTimer;
    QLabel *textOn;
    Rect *rectItem;

    int inputFloor, currentFloor;
};
#endif // MAINWINDOW_H
