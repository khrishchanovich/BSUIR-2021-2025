#include "mainwindow.h"
#include <QBrush>

MainWindow::MainWindow(int InputFloor, QWidget *parent)
    : QMainWindow(parent)
{
    this->InputFloor = InputFloor;

    resize(1300, 1100);

    LayoutScene = new QHBoxLayout(this);
    MovingRect = new Elevator(InputFloor);

    LayoutScene->addWidget(MovingRect);

    setLayout(LayoutScene);
    MovingRect->show();

}

MainWindow::~MainWindow()
{
    delete LayoutScene;
    delete MovingRect;
}

Elevator::Elevator(int InputFloor, QWidget *parent) : QGraphicsView (parent)
{
    RainbowDash = new QLabel;
    FlyingGif = new QMovie(":/new/prefix1/flyingPony.gif.mp4");
    RainbowDash->setStyleSheet("background: transparent;");
    RainbowDash->resize(550, 500);
    RainbowDash->move(900, 280);
    RainbowDash->setMovie(FlyingGif);
    FlyingGif->start();

    cloud = new QLabel;
    cloud->resize(200, 138);
    cloud->move(900, 850);
    cloud->setStyleSheet("background: transparent;");
    cloud->setPixmap(QPixmap(":/new/prefix1/pictureS/cloud_pic.png"));

    TextOnCloud = new QLabel;
    TextOnCloud->resize(200, 138);
    TextOnCloud->move(900, 860);
    TextOnCloud->setStyleSheet("background: transparent;");
    TextOnCloud->setAlignment(Qt::AlignCenter);

    QFont font = TextOnCloud->font(); //создание объекта класса QFont копированием свойсв QFont у QLabel
    font.setPointSize(20);

    TextOnCloud->setFont(font);

    TextOnCloud->setNum(0);

    BackgroundScene = new QBrush;
    BackgroundScene->setTextureImage(QImage(":/n/ff/rqTJpL.png"));

    scene = new QGraphicsScene(0, 0, 1200, 1000, this);
    scene->addRect(scene->sceneRect());
    scene->setBackgroundBrush(*BackgroundScene);

    setScene(scene);

    BalloonImage = new QBrush;
    BalloonImage->setTextureImage(QImage(":/n/ff/balloon.png"));

    rect = new QGraphicsRectItem(0, 0, 200, 300);
    rect->setPen(Qt::NoPen);
    rect->setBrush(*BalloonImage);
    scene->addItem(rect);

    scene->addWidget(cloud);
    scene->addWidget(TextOnCloud);
    scene->addWidget(RainbowDash);

    AnimationTimer = new QTimer(this);
    AnimationTimer->start(1000 / 600);

    CurrentFloor = 0;
    this->InputFloor = InputFloor;

    connect(AnimationTimer, SIGNAL(timeout()), this, SLOT(Moving()));

    FlyingPonyTimer = new QTimer(this);
    FlyingPonyTimer->start(1000 / 200);
    connect(FlyingPonyTimer, SIGNAL(timeout()), this, SLOT(FlyingPony()));

}

Elevator::~Elevator()
{
    delete FlyingPonyTimer;
    delete AnimationTimer;
    delete rect;
    delete scene;
    delete BackgroundScene;
    delete BalloonImage;
    delete cloud;
    delete TextOnCloud;
    delete RainbowDash;
    delete FlyingGif;
}

void Elevator::MovingCostyl()
{
    static int y_costyl = scene->height()-200;
    rect->setPos(200, --y_costyl);
    if (y_costyl == 700)
        disconnect(AnimationTimer, SIGNAL(timeout()), this, SLOT(MovingCostyl()));
}

void Elevator::FlyingPony()
{
    static int x = scene->width()-500;
    RainbowDash->move(--x, 280);
    if (x == -900)
        disconnect(FlyingPonyTimer, SIGNAL(timeout()), this, SLOT(FlyingPony()));
}

void Elevator::Moving()
{
    static int y = scene->height()-200;

    rect->setPos(200, --y);

    if (y == -310) {
        y = scene->height()-200;
        ++CurrentFloor;
    }
    TextOnCloud->setNum(CurrentFloor);
    if (CurrentFloor == InputFloor) {
        disconnect(AnimationTimer, SIGNAL(timeout()), this, SLOT(Moving()));
        connect(AnimationTimer, SIGNAL(timeout()), this, SLOT(MovingCostyl()));
    }
}

Menu::Menu(QWidget *parent)
{
    Q_UNUSED(parent);

    resize(900, 563);

    QLabel *background = new QLabel(this);
    background->resize(900, 563);

    QPixmap bkgnd(":/n/ff/menu_background.png");

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    background->setPixmap(bkgnd);

    QCursor cursor = QCursor(QPixmap(":/n/ff/cursor.png"));

    window = new QMainWindow;
    text = new QLabel("Введите номер этажа:", this);
    MainLayer = new QHBoxLayout;
    MainLayer->addWidget(text);

costyl = false;
    text->setStyleSheet("background: transparent;");
    text->setAlignment(Qt::AlignCenter);
    QFont font = text->font();
    font.setPointSize(12);
    text->setFont(font);
    text->move(320, 150);
    text->adjustSize();

    InputFloor = new QLineEdit(this);
    InputFloor->resize(150, 40);
    InputFloor->move(350, 190);
    MainLayer->addWidget(InputFloor);

    Enter = new QPushButton("Старт", this);
    connect(Enter, SIGNAL(clicked()), this, SLOT(CreateAnimation()));
    Enter->adjustSize();
    Enter->resize(150, 50);
    Enter->move(350, 240);
    setLayout(MainLayer);

    setCursor(cursor);
}

Menu::~Menu()
{
    delete window;
    delete text;
    delete InputFloor;
    delete Enter;
    delete MainLayer;
}

void Menu::CreateAnimation()
{
    QRegularExpressionMatch result;
    QString floor = InputFloor->text();

    QRegularExpression CheckFloor("^\\d+\\d?\\d?$");
    QRegularExpressionMatch match = CheckFloor.match(floor);
    bool hasMatch = match.hasMatch();

    if (!hasMatch)
        QMessageBox::critical(this, "Ошибка ввода!", "Некорректный ввод. Попробуйте ввести\nцелое положительное число.");
    else {
        int Floor = floor.toInt();
        MainWindow *w = new MainWindow(Floor);

        Q_UNUSED(w);
    }
}


