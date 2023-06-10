#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QKeyEvent>



class Rectangle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Rectangle(short width = 0, short height = 0,
                       double RotationAngle = 0,
                       short r = rand()%255, short g = rand()%255, short b = rand()%255,
                       QObject *parent = nullptr) : QObject (parent) {
        size = 1;

        this->width = width; this->height = height;
        degree = RotationAngle;

        this->r = r; this->g = g; this->b = b;

        DefaultSize = width > height ? width : height;
    }
    ~Rectangle() {}

private:

    short width, height;
    double size;
    double DefaultSize;


    double degree;

    short r, g, b;

    QRectF boundingRect() const {
        return QRectF(-DefaultSize-20, -DefaultSize-20, DefaultSize*2+20, DefaultSize*2+20);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 0.5;

        painter->setPen(Qt::gray);
        painter->setBrush(QColor(r, g, b));

        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }
        painter->drawRect(-30, -30, width, height);

        painter->drawPoint(QRectF(-30, -30, width, height).center());

        QTimer::singleShot(0, this, SLOT(update()));

        Q_UNUSED(option); Q_UNUSED(widget);
    }

    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
        this->setPos(mapToScene(event->pos()));
    }


    virtual void mousePressEvent (QGraphicsSceneMouseEvent *event) {
        this->setCursor(QCursor(Qt::ClosedHandCursor));

        Q_UNUSED(event);
    }

    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {

        this->setCursor(QCursor(Qt::ArrowCursor));
        Q_UNUSED(event);
    }

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
        delete this;
        Q_UNUSED(event);
    }

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event) {
        if (event->delta() < 0)
            size -= 0.1;
    }
public:
    QString Parametrs (){
        QString Parametrs = "Площадь: ";
        int S_value = height * width;
        Parametrs += QString::number(S_value);
        QString P = ", Периметр: ";
        int P_value = 2*(height + width);
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Координаты центра масс: (";
        CentrMass += QString::number(double(height/2));
        CentrMass += ", ";
        CentrMass += QString::number(double(width/2));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
};

class Square : public Rectangle {
public:
    Square(short width = 0, double rotation = 0) :
        Rectangle(width, width, rotation) {}
};

class Rhombus : public Square {
public:
    Rhombus(short width = 0, double rotation = 45) :
        Square (width, rotation) {}
};


#endif // RECTANGLE_H
