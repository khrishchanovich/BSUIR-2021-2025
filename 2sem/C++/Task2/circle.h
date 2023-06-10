#pragma once

#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QCursor>
#include <QtMath>


class Circle: public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Circle(short R = 20, QObject *parent = nullptr) : QObject (parent) {
        size = 1;
        this->R = static_cast<double>(R);
        r = rand()%255; g = rand()%255; b = rand()%255;
    }

private:
    short r, g, b;
    double R;
    double size;

    QRectF boundingRect() const {
        return QRectF(-R, -R, R*1.5, R*1.5);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->setPen(Qt::gray);
        painter->setBrush(QColor(r, g, b));

        if (size < 1)
            painter->scale(size, size);

        painter->drawPoint(boundingRect().center());

        painter->drawEllipse(boundingRect());

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

        int S_value = M_PI * R * R;
        Parametrs += QString::number(S_value);
        QString P = ", Периметр: ";
        int P_value = 2 * M_PI * R;
        P += QString::number(P_value);
        Parametrs += P;
        QString CentrMass = ", Координаты центра масс: (";
        CentrMass += QString::number(double(R/2));
        CentrMass += ", ";
        CentrMass += QString::number(double(R/2));
        CentrMass += ")";
        Parametrs += CentrMass;
        return Parametrs;
       }
};

#endif // CIRCLE_H
