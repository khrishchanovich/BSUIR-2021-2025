#ifndef RECT_H
#define RECT_H

#include <mainwindow.h>

#include <QGraphicsRectItem>

#include <QPainter>
#include <QCursor>

#include <QLabel>

class Rect : public QGraphicsRectItem
{
public:
    Rect(int x0 = 0, int y0 = 500, int h0 = 200, int w0 = 300);
    void paintRect(QPainter *painter);
protected:
    int w, x, y, h, currentFloor, inputFloor;
    QLabel *textOn;
};

#endif // RECT_H
