#include "rect.h"

Rect::Rect(int x0, int y0, int h0, int w0)
{
    x = x0;
    y = y0;
    h = h0;
    w = w0;
}

void Rect::paintRect(QPainter *painter)
{
    /*
    int x1 = x - w/2;
    int y1 = y - h/2;
    int w1 = w;
    int h1 = h;
    */
    /*
    int x1 = 0;
    int y1 = 500;
    int w1 = 200;
    int h1 = 300;
    */

    int i = 500;
    painter->setBrush(Qt::black);
    painter->drawRect(0, 500, 200, 300);

    if ( i <= -800)
    {
        i = 300;
        painter->drawRect(0, --i, 200, 300);
        Scene();
        ++currentFloor;
    }

    textOn->setNum(currentFloor);

    if (currentFloor == inputFloor)
    {
        i = 0;
        painter->drawRect(0, i, 200, 300);
    }
}
