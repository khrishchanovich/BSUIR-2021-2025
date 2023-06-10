#pragma once

#ifndef STAR_H
#define STAR_H

#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>

class Star : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Star(int VerticlesAmount = 5, int R = 100, int r = 50, QObject *parent = nullptr) :
        QObject(parent), QGraphicsItem ()
    {
        this->R = R;
        this->r = r;
        this->VerticlesAmount = VerticlesAmount;

        DefaultSize = R > r ? R : r;


        x = DefaultSize/2;
        y = DefaultSize/2;

        degree = 0;

        size = 1;

        p_x = new double[VerticlesAmount * 2+1];
        p_y = new double[VerticlesAmount * 2+1];

    }

    ~Star() {
        delete p_x;
        delete p_y;
    }

private:

    virtual QRectF boundingRect() const {

        return QRectF(-DefaultSize-140, -DefaultSize-140, DefaultSize*7., DefaultSize*7.);
    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

        painter->setPen(Qt::black);

        painter->setBrush(Qt::green);

        double a = 0;

        for (int i=0; i < VerticlesAmount*2; ++i)
        {
         if (!(i%2)) //При выполнении условия четности следующие формулы
          {
           p_x[i]=x+r/2*cos(a*M_PI/180);
           p_y[i]=y-r/2*sin(a*M_PI/180);
          }
          else //При невыполнении условия четности следующие формулы
           {
            p_x[i]=x+R*cos(a*M_PI/180);
            p_y[i]=y-R*sin(a*M_PI/180);
           }
           a += 180/VerticlesAmount;
        }//Завершаем построение звезды соединяя её окончание с начальной точкой

        p_x[VerticlesAmount*2]=p_x[0];
        p_y[VerticlesAmount*2]=p_y[0];

        QPainterPath star12;
//изначально угол 0
        if (degree) {
            for (int i = 0; i < VerticlesAmount*2+1;++i) {
                p_x[i] = p_x[i]*cos(degree)-p_y[i]*sin(degree);
                p_y[i] = p_x[i]*sin(degree)+p_y[i]*cos(degree);
            }
        }

        degree += 0.075;

        if (size < 1) {

            /*
                Матрица сжатия: (3., 0)
                                (0, 1.5)
                */

            for (int i = 0; i < VerticlesAmount*2+1;++i) {
                p_x[i] = p_x[i]/3.;
                p_y[i] = p_y[i]/1.5;
            }
        }

        star12.moveTo(p_x[0], p_y[0]);

        for (int i=0;i<VerticlesAmount*2+1;++i) {
           star12.lineTo(p_x[i], p_y[i]);
       }

        painter->drawPath(star12);

        painter->drawPoint(boundingRect().center());

        QTimer::singleShot(0,this, SLOT(update()));

        Q_UNUSED(option);
        Q_UNUSED(widget);

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

    virtual void wheelEvent(QGraphicsSceneWheelEvent *event) {
        if (event->delta() < 0)
            size -= 0.1;
    }

    int R, r, VerticlesAmount;
    double degree;

    double DefaultSize, size;

    double *p_x, *p_y;

    double x, y;

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
        delete this;
        Q_UNUSED(event);
    }

public:
    QString Parametrs() {
        QString Parametrs = "Площадь: ";
        int S_value = R * R * VerticlesAmount * sin(2 * M_PI / VerticlesAmount) / 2;
        Parametrs += QString::number(S_value);
        QString P = ", Периметр: ";
        int P_value = 2 * S_value / r;
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

#endif // STAR_H
