#ifndef COMPLEXOBJECT_H
#define COMPLEXOBJECT_H
#include "shape.h"
#include <QGraphicsItem>
#include <QList>
#include <QTimer>
#include <QGraphicsView>
#include <QSoundEffect>
#include <QMediaPlayer>

class ComplexObject : public Shape
{
public:
    ComplexObject();
    ~ComplexObject();

    void addItem(QGraphicsItem* item);
    void removeItem(QGraphicsItem* item);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void move(QGraphicsView *view);
    void checkCollision();
    bool collidesWithWalls();
protected:
    qreal dx, dy;  // Направления движения
    QMediaPlayer collisionSound;  // Звук столкновения
private:
    QList<QGraphicsItem*> items;



};

#endif // COMPLEXOBJECT_H
