#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QtMath>

class Triangle: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Triangle(short x1 = 10, short y1 = 20, short x2 = 20, short y2 = 10,
             short x3 = 30, short y3 = 30, QObject *parent = nullptr) : QObject (parent) {

        this->x1 = x1; this->y1 = y1;
        this->x2 = x2; this->y2 = y2;
        this->x3 = x3; this->y3 = y3;

        size = 1; degree = 0;

        r = rand()%255;
        g = rand()%255;
        b = rand()%255;

        AB = sqrt(pow((x1 - x2), 2)+pow((y1 - y2), 2));
        BC = sqrt(pow((x2 - x3), 2)+pow((y2 - y3), 2));
        AC = sqrt(pow((x1 - x3), 2)+pow((y1 - y3), 2));

        DefaultSize = AB > BC ? AB : BC;
        DefaultSize = DefaultSize > AC? DefaultSize : AC;
    }

private:
    short x1, y1, x2, y2, x3, y3;
    double size, degree;

    double DefaultSize;
    double AB, BC, AC;

    short r, g, b;

    QRectF boundingRect() const {
        return QRectF(-DefaultSize*2, -DefaultSize*2, DefaultSize*4, DefaultSize*4);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 0.5;

        painter->setPen(Qt::gray);
        painter->setBrush(QColor(r, g, b));

        QPolygon poly;
        poly<<QPoint(x1,y1)<<QPoint(x2,y2)<<QPoint(x3,y3);

        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }

        painter->drawPoint(boundingRect().center());

        painter->drawPolygon(poly);

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

        int p = (AB + BC + AC)/2;

        int S_value = sqrt(p*(p - AB)*(p-AC)*(p-AC));
        Parametrs += QString::number(S_value);
        QString P = ", Периметр: ";
        int P_value = AB + BC + AC;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Координаты центра масс: (";
        CentrMass += QString::number(double(x1 + x2 + x3/3));
        CentrMass += ", ";
        CentrMass += QString::number(double(y1 + y2 + 3/3));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
};


class Hexagon : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Hexagon(QObject *parent = nullptr) : QObject (parent),
        degree(0), size(1), r(rand()%255), g(rand()%255), b(rand()%255) {}
  ~Hexagon() {}



private:
    double degree, size;
    short r, g, b;
    double DefaultSize = 350;

    QRectF boundingRect() const {
        return QRectF(-DefaultSize*2, -DefaultSize*2, DefaultSize*4, DefaultSize*4);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->rotate(degree);
        degree += 0.5;

        painter->setPen(Qt::gray);
        painter->setBrush(QColor(r, g, b));

        QPolygon poly;
        poly<<QPoint(100, 0)<<QPoint(300, 0)<<QPoint(400, 100) << QPoint(300, 200)
           << QPoint(100, 200) << QPoint(0, 100) << QPoint(100, 0);

        if (size < 1) {
            painter->scale(size, size);
            //prepareGeometryChange();
        }

        painter->drawPoint(boundingRect().center());

        painter->drawPolygon(poly);

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
        int S_value = 1200;
        Parametrs += QString::number(S_value);
        QString P = ", Периметр: ";
        int P_value = 600;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Координаты центра масс: (";
        CentrMass += "100.0";
        CentrMass += ", ";
        CentrMass += QString::number(double(200*sin(M_PI/3)));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }

};

#endif // TRIANGLE_H
