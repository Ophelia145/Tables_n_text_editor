#include "butterfly.h"
#include <QBrush>
#include <QPen>
#include <QPolygonF>
#include <QColor>
//#include <complexobject.h>

Butterfly::Butterfly() : ComplexObject() {
    QColor bodyColor(75, 0, 130); // Индиго для тела
    QColor wingColor(255, 165, 0); // Оранжевый для крыльев
    QColor black(0, 0, 0); // Черный для головы и усиков

    // Тело бабочки (прямоугольник)
    QGraphicsRectItem* body = new QGraphicsRectItem(-10, -30, 20, 60);
    body->setBrush(QBrush(bodyColor));
    body->setPen(QPen(Qt::black));
    addItem(body);

    // Голова бабочки (круг)
    QGraphicsEllipseItem* head = new QGraphicsEllipseItem(-15, -50, 30, 30);
    head->setBrush(QBrush(black));
    head->setPen(QPen(Qt::black));
    addItem(head);

    // Левые крылья (большие полукруги)
    QGraphicsEllipseItem* leftTopWing = new QGraphicsEllipseItem(-70, -60, 60, 80);
    leftTopWing->setBrush(QBrush(wingColor));
    leftTopWing->setPen(QPen(Qt::black));
    addItem(leftTopWing);

    QGraphicsEllipseItem* leftBottomWing = new QGraphicsEllipseItem(-70, 0, 60, 80);
    leftBottomWing->setBrush(QBrush(wingColor));
    leftBottomWing->setPen(QPen(Qt::black));
    addItem(leftBottomWing);

    // Правые крылья (большие полукруги)
    QGraphicsEllipseItem* rightTopWing = new QGraphicsEllipseItem(10, -60, 60, 80);
    rightTopWing->setBrush(QBrush(wingColor));
    rightTopWing->setPen(QPen(Qt::black));
    addItem(rightTopWing);

    QGraphicsEllipseItem* rightBottomWing = new QGraphicsEllipseItem(10, 0, 60, 80);
    rightBottomWing->setBrush(QBrush(wingColor));
    rightBottomWing->setPen(QPen(Qt::black));
    addItem(rightBottomWing);

    // Усики бабочки (изогнутые линии)
    QGraphicsPathItem* leftAntenna = new QGraphicsPathItem();
    QPainterPath leftPath;
    leftPath.moveTo(0, -50);
    leftPath.cubicTo(-20, -70, -30, -80, -40, -90);
    leftAntenna->setPath(leftPath);
    leftAntenna->setPen(QPen(Qt::black, 2));
    addItem(leftAntenna);

    QGraphicsPathItem* rightAntenna = new QGraphicsPathItem();
    QPainterPath rightPath;
    rightPath.moveTo(0, -50);
    rightPath.cubicTo(20, -70, 30, -80, 40, -90);
    rightAntenna->setPath(rightPath);
    rightAntenna->setPen(QPen(Qt::black, 2));
    addItem(rightAntenna);
}
