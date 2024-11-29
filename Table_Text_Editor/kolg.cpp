#include "kolg.h"
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

Kolginova::Kolginova() : ComplexObject() {
    qreal x = 0;
    qreal y = 0;
    qreal spacing = 60;

    QBrush brush(Qt::black);
    QPen pen(Qt::black);
    pen.setWidth(2);

    // "К"
    {
        QGraphicsLineItem* verticalLine = new QGraphicsLineItem(x, y, x, y + 60);
        verticalLine->setPen(pen);
        addItem(verticalLine);

        QGraphicsLineItem* topDiag = new QGraphicsLineItem(x, y + 30, x + 30, y);
        topDiag->setPen(pen);
        addItem(topDiag);

        QGraphicsLineItem* bottomDiag = new QGraphicsLineItem(x, y + 30, x + 30, y + 60);
        bottomDiag->setPen(pen);
        addItem(bottomDiag);
    }
    x += spacing;

    // "О"
    {
        QGraphicsEllipseItem* circle = new QGraphicsEllipseItem(x, y, 40, 60);
        circle->setPen(pen);
        addItem(circle);
    }
    x += spacing;

    // "Л"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y + 60, x + 15, y); // левая диагональная линия
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y + 60, x + 15, y); // правая диагональная линия
        rightLine->setPen(pen);
        addItem(rightLine);
    }
    x += spacing;

    // "Г"
    {
        QGraphicsLineItem* verticalLine = new QGraphicsLineItem(x, y, x, y + 60);
        verticalLine->setPen(pen);
        addItem(verticalLine);

        QGraphicsLineItem* topLine = new QGraphicsLineItem(x, y, x + 30, y);
        topLine->setPen(pen);
        addItem(topLine);
    }
    x += spacing;

    // "И"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y, x, y + 60);
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y, x + 30, y + 60);
        rightLine->setPen(pen);
        addItem(rightLine);

        QGraphicsLineItem* diagLine = new QGraphicsLineItem(x, y + 60, x + 30, y);
        diagLine->setPen(pen);
        addItem(diagLine);
    }
    x += spacing;

    // "Н"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y, x, y + 60);
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y, x + 30, y + 60);
        rightLine->setPen(pen);
        addItem(rightLine);

        QGraphicsLineItem* middleLine = new QGraphicsLineItem(x, y + 30, x + 30, y + 30);
        middleLine->setPen(pen);
        addItem(middleLine);
    }
    x += spacing;

    // "О"
    {
        QGraphicsEllipseItem* circle = new QGraphicsEllipseItem(x, y, 40, 60);
        circle->setPen(pen);
        addItem(circle);
    }
    x += spacing;

    // "В"
    {
        QGraphicsLineItem* verticalLine = new QGraphicsLineItem(x, y, x, y + 60);
        verticalLine->setPen(pen);
        addItem(verticalLine);

        QGraphicsEllipseItem* topCircle = new QGraphicsEllipseItem(x, y, 30, 30);
        topCircle->setPen(pen);
        addItem(topCircle);

        QGraphicsEllipseItem* bottomCircle = new QGraphicsEllipseItem(x, y + 30, 30, 30);
        bottomCircle->setPen(pen);
        addItem(bottomCircle);
    }
    x += spacing;

    // "А"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y + 60, x + 15, y);
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y + 60, x + 15, y);
        rightLine->setPen(pen);
        addItem(rightLine);

        QGraphicsLineItem* middleLine = new QGraphicsLineItem(x + 7, y + 30, x + 23, y + 30);
        middleLine->setPen(pen);
        addItem(middleLine);
    }
}
