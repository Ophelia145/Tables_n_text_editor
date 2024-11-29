#include "flower.h"
#include <QBrush>
#include <QPen>
#include <QPolygonF>
#include <QColor>
#include <cmath>

//#include <complexobject.h>

Flower::Flower() : ComplexObject() {
    QColor stemColor(34, 139, 34); // Зеленый для стебля
    QColor petalColor(255, 105, 180); // Розовый для лепестков
    QColor centerColor(255, 223, 0); // Желтый для центра цветка

    // Стебель цветка (прямоугольник)
    QGraphicsRectItem* stem = new QGraphicsRectItem(-5, 0, 10, 100);
    stem->setBrush(QBrush(stemColor));
    stem->setPen(QPen(Qt::black));
    addItem(stem);

    // Центр цветка (круг)
    QGraphicsEllipseItem* center = new QGraphicsEllipseItem(-15, -30, 30, 30);
    center->setBrush(QBrush(centerColor));
    center->setPen(QPen(Qt::black));
    addItem(center);

    // Параметры для лепестков
    int petalWidth = 30;
    int petalHeight = 50;
    int radius = 50; // Радиус для равномерного распределения лепестков
    int numPetals = 5; // Количество лепестков

    // Углы для 5 лепестков (360° / 5 = 72° между каждым)
    double angleStep = 360.0 / numPetals;

    for (int i = 0; i < numPetals; ++i) {
        double angle = i * angleStep * M_PI / 180.0; // Переводим угол в радианы

        // Вычисляем координаты для верхнего левого угла каждого лепестка
        int x = static_cast<int>(radius * cos(angle) - petalWidth / 2);
        int y = static_cast<int>(radius * sin(angle) - petalHeight / 2);

        // Лепесток
        QGraphicsEllipseItem* petal = new QGraphicsEllipseItem(x, y, petalWidth, petalHeight);
        petal->setBrush(QBrush(petalColor));
        petal->setPen(QPen(Qt::black));
        addItem(petal);
    }
}
