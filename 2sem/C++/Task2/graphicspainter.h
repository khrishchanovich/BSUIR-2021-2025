#pragma once

#ifndef GRAPHICSPAINTER_H
#define GRAPHICSPAINTER_H

#include <QWidget>

class GraphicsPainter : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicsPainter(QWidget *parent = nullptr);

    void SetDraw(bool bDraw);

signals:
    void singalDrawOver();

public slots:

protected:
    void paintEvent(QPaintEvent *);     //рисовать
    void mousePressEvent(QMouseEvent *e);       //Нажмите
    void mouseMoveEvent(QMouseEvent *e);        // мобильный
    void mouseReleaseEvent(QMouseEvent *e);     //выпуск
    void mouseDoubleClickEvent(QMouseEvent *event);        //Двойной щелчок


    bool bDraw;             // Находится ли он в состоянии рисования
    bool bLeftClick;            // Начался ли щелчок левой кнопкой мыши, и в то же время отметим, начинать ли рисование
    bool bMove;             // Находится ли мышь в состоянии рисования

    QVector<QPointF> pointList;
    QPointF movePoint;
};

#endif // GRAPHICSPAINTER_H
