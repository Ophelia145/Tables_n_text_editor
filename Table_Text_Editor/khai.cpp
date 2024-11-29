#include "khai.h"
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

Khai::Khai() : ComplexObject() {
    qreal x = 0;
    qreal y = 0;
    qreal spacing = 60;

    QBrush brush(Qt::black);
    QPen pen(Qt::black);
    pen.setWidth(2);

    //буква "Х"
    {
        QGraphicsLineItem* leftDiag = new QGraphicsLineItem(x, y, x + 30, y + 60);
        leftDiag->setPen(pen);
        addItem(leftDiag);

        QGraphicsLineItem* rightDiag = new QGraphicsLineItem(x + 30, y, x, y + 60);
        rightDiag->setPen(pen);
        addItem(rightDiag);
    }
    x += spacing;

    //"А"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y + 60, x + 15, y);
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y + 60, x + 15, y);
        rightLine->setPen(pen);
        addItem(rightLine);

        QGraphicsLineItem* midLine = new QGraphicsLineItem(x + 7, y + 30, x + 23, y + 30);
        midLine->setPen(pen);
        addItem(midLine);
    }
    x += spacing;

    // "Й"
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

        QGraphicsEllipseItem* dot = new QGraphicsEllipseItem(x + 10, y - 10, 10, 10);
        dot->setBrush(brush);
        dot->setPen(pen);
        addItem(dot);
    }
    x += spacing;

    // "Б"
    {
        QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y, x, y + 60);
        leftLine->setPen(pen);
        addItem(leftLine);

        QGraphicsLineItem* topLine = new QGraphicsLineItem(x, y, x + 30, y);
        topLine->setPen(pen);
        addItem(topLine);

        QGraphicsLineItem* middleLine = new QGraphicsLineItem(x, y + 30, x + 25, y + 30);
        middleLine->setPen(pen);
        addItem(middleLine);

        QGraphicsEllipseItem* bottomCircle = new QGraphicsEllipseItem(x, y + 30, 30, 30);
        bottomCircle->setPen(pen);
        addItem(bottomCircle);
    }
    x += spacing;

    //"У"
    {
            QGraphicsLineItem* leftDiag = new QGraphicsLineItem(x, y, x + 15, y + 30);
            leftDiag->setPen(pen);
            addItem(leftDiag);

            QGraphicsLineItem* rightDiag = new QGraphicsLineItem(x + 30, y, x + 15, y + 30);
            rightDiag->setPen(pen);
            addItem(rightDiag);

            QGraphicsLineItem* bottomDiag = new QGraphicsLineItem(x + 15, y + 30, x - 10, y + 60); // диагональная линия вниз
            bottomDiag->setPen(pen);
            addItem(bottomDiag);
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
        //"А"
        {
            QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y + 60, x + 15, y);
            leftLine->setPen(pen);
            addItem(leftLine);

            QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y + 60, x + 15, y);
            rightLine->setPen(pen);
            addItem(rightLine);

            QGraphicsLineItem* midLine = new QGraphicsLineItem(x + 7, y + 30, x + 23, y + 30);
            midLine->setPen(pen);
            addItem(midLine);
        }
        x += spacing;

        // "Е"
        {
            QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y, x, y + 60);
            leftLine->setPen(pen);
            addItem(leftLine);

            QGraphicsLineItem* topLine = new QGraphicsLineItem(x, y, x + 30, y);
            topLine->setPen(pen);
            addItem(topLine);

            QGraphicsLineItem* middleLine = new QGraphicsLineItem(x, y + 30, x + 25, y + 30);
            middleLine->setPen(pen);
            addItem(middleLine);

            QGraphicsLineItem* bottomLine = new QGraphicsLineItem(x, y + 60, x + 30, y + 60);
            bottomLine->setPen(pen);
            addItem(bottomLine);
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

//"А"
{
    QGraphicsLineItem* leftLine = new QGraphicsLineItem(x, y + 60, x + 15, y);
    leftLine->setPen(pen);
    addItem(leftLine);

    QGraphicsLineItem* rightLine = new QGraphicsLineItem(x + 30, y + 60, x + 15, y);
    rightLine->setPen(pen);
    addItem(rightLine);

    QGraphicsLineItem* midLine = new QGraphicsLineItem(x + 7, y + 30, x + 23, y + 30);
    midLine->setPen(pen);
    addItem(midLine);
}
x += spacing;
}
