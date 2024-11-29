#include "complexobject.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QDebug>

ComplexObject::ComplexObject() : dx(1), dy(1) {
    collisionSound.setMedia(QUrl::fromLocalFile("../src/MEOW1.mp3"));
    collisionSound.setVolume(100);
}

void ComplexObject::checkCollision() {
    if (collidesWithWalls()) {
        collisionSound.play();
    }
}

bool ComplexObject::collidesWithWalls() {
    if (!scene()) return false;

    QRectF sceneBounds = scene()->sceneRect();  //gраницы сцены
    QRectF objectBounds = this->boundingRect();  //границы объекта

    QPointF pos = this->pos();  //текущ положение объекта

    //проверка на верхней или нижней границ
    if (pos.y() + objectBounds.top() <= sceneBounds.top() ||
        pos.y() + objectBounds.bottom() >= sceneBounds.bottom()) {
        dy = -dy;  //меняем направление по оси Y
        return true;
    }

    //проверка на столкновение с левой или правой границей
    if (pos.x() + objectBounds.left() <= sceneBounds.left() ||
        pos.x() + objectBounds.right() >= sceneBounds.right()) {
        dx = -dx;  //меняем направление по оси X
        return true;
    }

    return false;  //столкновения нет
}

ComplexObject::~ComplexObject() {
    qDeleteAll(items);
}

void ComplexObject::addItem(QGraphicsItem* item) {
    items.append(item);
    item->setParentItem(this);
}

void ComplexObject::removeItem(QGraphicsItem* item) {
    items.removeOne(item);
    delete item;
}

QRectF ComplexObject::boundingRect() const {
    QRectF rect;
    for (const QGraphicsItem* item : items) {
        rect = rect.united(item->boundingRect());
    }
    return rect;
}

void ComplexObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (QGraphicsItem* item : items) {
        item->paint(painter, option, widget);
    }
}

void ComplexObject::move(QGraphicsView *view) {
    QGraphicsScene *scene = view->scene();
    setPos(x() + dx, y() + dy);

    QRectF viewRect = view->mapToScene(view->viewport()->rect()).boundingRect();
    QRectF objectRect = boundingRect().translated(pos());

    if (objectRect.left() < viewRect.left() || objectRect.right() > viewRect.right() ||
        objectRect.top() < viewRect.top() || objectRect.bottom() > viewRect.bottom()) {
        dx = -dx; // Reverse direction on x-axis
        dy = -dy; // Reverse direction on y-axis
        collisionSound.play(); // Play sound on collision
    }

    // Check for collisions with other items
    QList<QGraphicsItem *> collidingItems = scene->collidingItems(this);
    for (QGraphicsItem *item : collidingItems) {
        if ((dynamic_cast<ComplexObject*>(item) || dynamic_cast<Shape*>(item)) && !items.contains(item)) {
            dx = -dx; // Reverse direction on x-axis
            dy = -dy; // Reverse direction on y-axis
            collisionSound.play(); // Play sound on collision
            break;
        }
    }
}
