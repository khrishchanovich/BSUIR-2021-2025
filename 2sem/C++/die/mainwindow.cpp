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

Scene::Scene(int inputFloor, QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, 1000, 800, this); // ширина и высота, родитель - графическое представление
    scene->addRect(scene->sceneRect());
    setScene(scene);

    rectItem = new Rect();
    scene->addItem(rectItem);

    myTimer = new QTimer(this);
    myTimer->start(1000 / 400);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(paintRect));

//    Elevator();

    currentFloor = 1;
    this->inputFloor = inputFloor;

    textOn = new QLabel;

    textOn->resize(50, 50);
    textOn->move(900, 50);
    //textOn->setStyleSheet("background: transparent;");
    textOn->setAlignment(Qt::AlignCenter);

    QFont font = textOn->font();
    font.setPointSize(15);

    textOn->setFont(font);

    textOn->setNum(1);
    scene->addWidget(textOn);
}

