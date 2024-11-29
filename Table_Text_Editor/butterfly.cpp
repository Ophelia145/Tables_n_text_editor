#include "butterfly.h"
#include <QBrush>
#include <QPen>
#include <QPolygonF>
#include <QColor>


Butterfly::Butterfly() : ComplexObject() {
    QColor bodyColor(75, 0, 130);
    QColor wingColor(100, 150, 200);
    QColor black(0, 0, 0);

    //тело
    QGraphicsRectItem* body = new QGraphicsRectItem(-10, -30, 20, 60);
    body->setBrush(QBrush(bodyColor));
    body->setPen(QPen(Qt::black));
    addItem(body);

    //голова(круг)
    QGraphicsEllipseItem* head = new QGraphicsEllipseItem(-15, -50, 30, 30);
    head->setBrush(QBrush(black));
    head->setPen(QPen(Qt::black));
    addItem(head);



    QGraphicsEllipseItem* leftBottomWing = new QGraphicsEllipseItem(-70, 0, 60, 80);
    leftBottomWing->setBrush(QBrush(wingColor));
    leftBottomWing->setPen(QPen(Qt::black));
    leftBottomWing->setTransformOriginPoint(-150, 0);
    leftBottomWing->setRotation(-30);
    addItem(leftBottomWing);


    QGraphicsEllipseItem* rightTopWing = new QGraphicsEllipseItem(10, -60, 60, 80);
    rightTopWing->setBrush(QBrush(wingColor));
    rightTopWing->setPen(QPen(Qt::black));
    rightTopWing->setTransformOriginPoint(20, 40);
    rightTopWing->setRotation(30);
    //addItem(rightTopWing);

    QGraphicsEllipseItem* rightBottomWing = new QGraphicsEllipseItem(10, 0, 60, 80);
    rightBottomWing->setBrush(QBrush(wingColor));
    rightBottomWing->setPen(QPen(Qt::black));
    rightBottomWing->setTransformOriginPoint(150, 0);
    rightBottomWing->setRotation(30);
    addItem(rightBottomWing);



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
