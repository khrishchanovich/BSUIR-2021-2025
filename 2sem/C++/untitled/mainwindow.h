#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsView> //widget
#include <QGraphicsScene>
#include <QGraphicsItem> //base class
#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>
#include <QHBoxLayout>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMovie>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QRegularExpression>

class Elevator : public QGraphicsView {
    Q_OBJECT
public:
    Elevator(int InputFloor = 0, QWidget *parent = 0);
    ~Elevator();
private:
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    QTimer *AnimationTimer, *FlyingPonyTimer;
    QBrush *BackgroundScene, *BalloonImage;
    QLabel *cloud, *TextOnCloud, *RainbowDash;
    QMovie *FlyingGif;
    int CurrentFloor, InputFloor;

private slots:
    void Moving();
    void MovingCostyl();
    void FlyingPony();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int InputFloor = 0, QWidget *parent = 0);
    ~MainWindow();
private:
    QHBoxLayout *LayoutScene;
    Elevator *MovingRect;
    int InputFloor;
};

class Menu : public QMainWindow {
    Q_OBJECT

public:
    Menu(QWidget *parent = 0);
    ~Menu();
    bool costyl;
private:
    QMainWindow *window;
    QLabel *text;
    QLineEdit *InputFloor;
    QPushButton *Enter;
    QHBoxLayout *MainLayer;
private slots:
    void CreateAnimation();
};




#endif // MAINWINDOW_H
