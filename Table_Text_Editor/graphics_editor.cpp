#include "graphics_editor.h"
#include "circle.h"
#include "line.h"
#include "triangle.h"
#include "rectangle.h"
#include <QGraphicsView>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QInputDialog>
#include <QColorDialog>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFontDialog>
#include <QGraphicsPixmapItem>
#include <QComboBox>
#include "customgraphicsview.h"
#include "movabletextitem.h"
#include "butterfly.h"
#include "QtMath"
#include "complexobject.h"
#include "khai.h"


GraphicsEditorWindow::GraphicsEditorWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)),
      currentBrushSize(10), isEraserMode(false), currentBrushStyle(Qt::SolidPattern) {

    // Создаем вид и добавляем сцену
    QGraphicsView *view = new CustomGraphicsView(scene, this);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("QGraphicsView { border: 3px solid black; background-color: white; }");

    setCentralWidget(view);
    setWindowTitle("Graphics Editor");

    // Устанавливаем минимальный и максимальный размер окна
    setMinimumSize(1600, 1200);  // Минимальный размер окна
    setAcceptDrops(true);     // Разрешаем перетаскивание

    // Создаем панель инструментов
    QToolBar *toolbar = addToolBar("Shapes");

    QAction *addTextAction = new QAction(QIcon(":/res/res/free-icon-text-3721901.png"),"Add Text", this);
    toolbar->addAction(addTextAction);
    connect(addTextAction, &QAction::triggered, this, &GraphicsEditorWindow::addText);

    // Добавляем кнопку для сохранения изображения
    QAction *saveAction = new QAction(QIcon(":/res/res/free-icon-save-button-4148884.png"),"Save", this);
    toolbar->addAction(saveAction);
    connect(saveAction, &QAction::triggered, this, &GraphicsEditorWindow::saveImage);

    // Кнопка для удаления выбранного элемента
    QAction *deleteAction = new QAction(QIcon(":/res/res/free-icon-delete-1214594.png"),"Delete", this);
    toolbar->addAction(deleteAction);
    connect(deleteAction, &QAction::triggered, this, &GraphicsEditorWindow::deleteSelectedItem);

    // Добавляем кнопку для круга
    QAction *addCircleAction = new QAction(QIcon(":/res/res/circle.png"),"Add Circle", this);
    toolbar->addAction(addCircleAction);
    connect(addCircleAction, &QAction::triggered, this, &GraphicsEditorWindow::addCircle);

    // Добавляем кнопку для прямоугольника
    QAction *addRectangleAction = new QAction(QIcon(":/res/res/free-icon-square-15704779.png"),"Add Rectangle", this);
    toolbar->addAction(addRectangleAction);
    connect(addRectangleAction, &QAction::triggered, this, &GraphicsEditorWindow::addRectangle);

    // Добавляем кнопку для треугольника
    QAction *addTriangleAction = new QAction(QIcon(":/res/res/free-icon-triangle-15704787.png"),"Add Triangle", this);
    toolbar->addAction(addTriangleAction);
    connect(addTriangleAction, &QAction::triggered, this, &GraphicsEditorWindow::addTriangle);

    // Добавляем кнопку для линии
    QAction *addLineAction = new QAction(QIcon(":/res/res/free-icon-line-2708438.png"),"Add Line", this);
    toolbar->addAction(addLineAction);
    connect(addLineAction, &QAction::triggered, this, &GraphicsEditorWindow::addLine);

    // Добавляем кнопку для импорта изображения
    QAction *importAction = new QAction(QIcon(":/res/res/free-icon-image-11429526.png"),"Import Image", this);
    toolbar->addAction(importAction);
    connect(importAction, &QAction::triggered, this, &GraphicsEditorWindow::importImage);


    // Кнопка для изменения фона
    QAction *backgroundAction = new QAction(QIcon(":/res/res/paint.png"),"Background Color", this);
    toolbar->addAction(backgroundAction);
    connect(backgroundAction, &QAction::triggered, this, &GraphicsEditorWindow::changeBackgroundColor);

    // Кнопка для изменения цвета кисти
    QAction *brushColorAction = new QAction(QIcon(":/res/res/free-icon-color-palette-7168912.png"),"Brush Color", this);
    toolbar->addAction(brushColorAction);
    connect(brushColorAction, &QAction::triggered, this, &GraphicsEditorWindow::setBrushColor);


    // Кнопка для изменения размера кисти
    QAction *brushSizeAction = new QAction(QIcon(":/res/res/kist.png"),"Brush Size", this);
    toolbar->addAction(brushSizeAction);
    connect(brushSizeAction, &QAction::triggered, this, &GraphicsEditorWindow::setBrushSize);

    // Кнопка для ластика
    QAction *eraserAction = new QAction(QIcon(":/res/res/rubber.png"),"Eraser", this);
    toolbar->addAction(eraserAction);
    connect(eraserAction, &QAction::triggered, this, &GraphicsEditorWindow::setEraser);

     QComboBox *brushStyleComboBox = new QComboBox(this);
     brushStyleComboBox->addItem("Solid", QVariant::fromValue(Qt::SolidPattern));
     brushStyleComboBox->addItem("Dense 1", QVariant::fromValue(Qt::Dense5Pattern));
     brushStyleComboBox->addItem("Dense 2", QVariant::fromValue(Qt::Dense6Pattern));
     brushStyleComboBox->addItem("Dense 3", QVariant::fromValue(Qt::Dense7Pattern));
     brushStyleComboBox->addItem("Dense 4", QVariant::fromValue(Qt::Dense7Pattern));
     brushStyleComboBox->addItem("Dense 5", QVariant::fromValue(Qt::Dense5Pattern));
     brushStyleComboBox->addItem("Dense 6", QVariant::fromValue(Qt::Dense6Pattern));
     brushStyleComboBox->addItem("Dense 7", QVariant::fromValue(Qt::Dense7Pattern));
     brushStyleComboBox->addItem("Cross", QVariant::fromValue(Qt::CrossPattern));
     brushStyleComboBox->addItem("Horizontal", QVariant::fromValue(Qt::HorPattern));
     brushStyleComboBox->addItem("Vertical", QVariant::fromValue(Qt::VerPattern));
     toolbar->addWidget(brushStyleComboBox);
     connect(brushStyleComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GraphicsEditorWindow::setBrushStyle);


     QTimer *timer = new QTimer(this);
     timer->start(16); // Set the timer interval (e.g., 16 ms for ~60 FPS)

     Butterfly *butterfly = new Butterfly();
     butterfly->setPos(200, 400);
     connect(timer, &QTimer::timeout, [butterfly, view]() { butterfly->move(view); }); // Передаем представление в функцию перемещения
     scene->addItem(butterfly);

     Khai* khai = new Khai();
     scene->addItem(khai);
     connect(timer, &QTimer::timeout, [khai, view]() { khai->move(view); });
     khai->setPos(450, 450);


}

GraphicsEditorWindow::~GraphicsEditorWindow() {
    delete scene;
}


// Слот для добавления круга
void GraphicsEditorWindow::addCircle() {
    // Запрашиваем радиус
    bool ok;
    qreal radius = QInputDialog::getDouble(this, "Circle Radius", "Enter circle radius:", 50, 1, 200, 1, &ok);
    if (!ok) return;

    // Выбор цвета заливки
    QColor fillColor = QColorDialog::getColor(Qt::blue, this, "Select Fill Color");
    if (!fillColor.isValid()) return;

    // Выбор цвета обводки
    QColor borderColor = QColorDialog::getColor(Qt::black, this, "Select Border Color");
    if (!borderColor.isValid()) return;

    QBrush brush(fillColor);
    QPen pen(borderColor);
    pen.setWidth(2); // Устанавливаем ширину обводки

    Circle *circle = new Circle(radius, brush, pen); // Создаём круг с заданными параметрами
    scene->addItem(circle); // Добавляем круг на сцену
    circle->setPos(100, 200);
}

// Слот для сохранения изображения
void GraphicsEditorWindow::saveImage() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG Files (*.png)");

    if (!filePath.isEmpty()) {
        // Устанавливаем размер изображения под размер сцены
        QPixmap pixmap(scene->sceneRect().size().toSize());

        // Создаём QPainter для рисования на QPixmap
        QPainter painter(&pixmap);

        // Отрисовываем сцену на QPixmap
        scene->render(&painter);

        // Сохраняем изображение в фал
        pixmap.save(filePath, "PNG");
    }
}

// Слот для импорта изображения

void GraphicsEditorWindow::importImage() {
    QString filePath = QFileDialog::getOpenFileName(this, "Import Image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);

        if (!pixmap.isNull()) {
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
            item->setPos(0, 0);
            item->setFlag(QGraphicsItem::ItemIsMovable);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            scene->addItem(item);
        }
    }
}

void GraphicsEditorWindow::mousePressEvent(QMouseEvent *event) {
    if (scene->itemAt(event->pos(), QTransform()) != nullptr) {
        event->accept();
    } else {
        event->ignore();
    }
}

void GraphicsEditorWindow::setBrushStyle() {
    QComboBox *brushStyleComboBox = qobject_cast<QComboBox*>(sender());
    if (brushStyleComboBox) {
        Qt::BrushStyle style = static_cast<Qt::BrushStyle>(brushStyleComboBox->currentData().toInt());
        currentBrushStyle = style;
        static_cast<CustomGraphicsView*>(centralWidget())->setBrushStyle(currentBrushStyle);
    }
}

void GraphicsEditorWindow::setBrushSize() {
    bool ok;
    qreal size = QInputDialog::getDouble(this, "Brush Size", "Enter brush size:", currentBrushSize, 1, 50, 1, &ok);
    if (ok) {
        currentBrushSize = size;
        static_cast<CustomGraphicsView*>(centralWidget())->setBrushSize(currentBrushSize);
    }
}

void GraphicsEditorWindow::setBrushColor() {
    QColor color = QColorDialog::getColor(Qt::blue, this, "Select Brush Color");
    if (color.isValid()) {
        currentBrushColor = color;
        isEraserMode = false;
        static_cast<CustomGraphicsView*>(centralWidget())->setBrushColor(currentBrushColor);
    }
}

void GraphicsEditorWindow::setEraser() {
    isEraserMode = true;
    static_cast<CustomGraphicsView*>(centralWidget())->setBrushColor(Qt::white);
}

void GraphicsEditorWindow::changeBackgroundColor() {
    QColor color = QColorDialog::getColor(Qt::blue, this, "Select Background Color");
    if (color.isValid()) {
        scene->setBackgroundBrush(color);
        if (isEraserMode) {
            static_cast<CustomGraphicsView*>(centralWidget())->setBrushColor(color);
        }
    }
}

// Слот для добавлеия текста
void GraphicsEditorWindow::addText() {
    // Запрашиваем текст
    bool ok;
    QString text = QInputDialog::getText(this, "Add Text", "Enter your text:", QLineEdit::Normal, "", &ok);
    if (!ok || text.isEmpty()) return;

    // Запрашиваем шрифт
    bool fontOk;
    QFont font = QFontDialog::getFont(&fontOk, QFont("Arial", 12), this, "Select Font");
    if (!fontOk) return;

    // Создаем элемент текста с поведением перемещения правой кнопкой мыши
    MovableTextItem *textItem = new MovableTextItem(text);
    textItem->setFont(font);

    // Добавляем текст на сцену
    scene->addItem(textItem);
    textItem->setPos(100, 200);
}


void GraphicsEditorWindow::deleteSelectedItem() {
    // Получаем выбранные элементы
    QList<QGraphicsItem*> selectedItems = scene->selectedItems();
    if (selectedItems.isEmpty()) {
        qDebug() << "No items selected for deletion."; // Отладочное сообщение
        return;
    }

    // Удаляем все выбранные элементы
    for (QGraphicsItem *item : selectedItems) {
        scene->removeItem(item); // Удаляем элемент из сцены
        delete item; // Удаляем объект из памяти
        qDebug() << "Item deleted."; // Подтверждение удаления
    }
}


// Обработка события входа перетаскивания
void GraphicsEditorWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasImage()) {
        event->acceptProposedAction();
    }
}

// Обработка события завершения перетаскивания
void GraphicsEditorWindow::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasImage()) {
        QPixmap pixmap = qvariant_cast<QPixmap>(event->mimeData()->imageData());
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item->setPos(event->pos()); // Устанавливаем позицию на сцене
        scene->addItem(item);        // Добавляем изображение на сцену
        event->acceptProposedAction();
    }
}
// Конструктор и слот для добавления линии
void GraphicsEditorWindow::addLine() {
    // Запрашиваем длину и угол
    bool ok;
    qreal length = QInputDialog::getDouble(this, "Line Length", "Enter line length:", 100, 1, 500, 1, &ok);
    if (!ok) return;

    qreal angle = QInputDialog::getDouble(this, "Line Angle", "Enter line angle (in degrees):", 0, -360, 360, 1, &ok);
    if (!ok) return;

    // Выбор цвета обводки
    QColor borderColor = QColorDialog::getColor(Qt::black, this, "Select Border Color");
    if (!borderColor.isValid()) return;

    QPen pen(borderColor);
    pen.setWidth(2); // Устанавливаем ширину обводки

    Line *line = new Line(length, qDegreesToRadians(angle), pen); // Создаём линию с заданными параметрами
    scene->addItem(line); // Добавляем линию на сцену
    line->setPos(100, 200);
}


// Конструктор и слот для добавления прямоугольника
void GraphicsEditorWindow::addRectangle() {
    // Запрашиваем ширину и высоту
    bool ok;
    qreal width = QInputDialog::getDouble(this, "Rectangle Width", "Enter rectangle width:", 100, 1, 500, 1, &ok);
    if (!ok) return;

    qreal height = QInputDialog::getDouble(this, "Rectangle Height", "Enter rectangle height:", 100, 1, 500, 1, &ok);
    if (!ok) return;

    // Выбор цвета заливки
    QColor fillColor = QColorDialog::getColor(Qt::blue, this, "Select Fill Color");
    if (!fillColor.isValid()) return;

    // Выбор цвета обводки
    QColor borderColor = QColorDialog::getColor(Qt::black, this, "Select Border Color");
    if (!borderColor.isValid()) return;

    QBrush brush(fillColor);
    QPen pen(borderColor);
    pen.setWidth(2); // Устанавливаем ширину бводки

    Rectangle *rect = new Rectangle(width, height, brush, pen); // Создаём прямоугольник с заданными параметрми
    scene->addItem(rect); // Добавляем прямоугольник на сцену
    rect->setPos(100, 200);
}

// Конструктор и слот для добавления треугольника
void GraphicsEditorWindow::addTriangle() {
    // Запрашиваем основание и высоту
    bool ok;
    qreal base = QInputDialog::getDouble(this, "Triangle Base", "Enter triangle base:", 100, 1, 500, 1, &ok);
    if (!ok) return;

    qreal height = QInputDialog::getDouble(this, "Triangle Height", "Enter triangle height:", 100, 1, 500, 1, &ok);
    if (!ok) return;

    // Выбор цвета заливки
    QColor fillColor = QColorDialog::getColor(Qt::blue, this, "Select Fill Color");
    if (!fillColor.isValid()) return;

    // Выбор цвета обводки
    QColor borderColor = QColorDialog::getColor(Qt::black, this, "Select Border Color");
    if (!borderColor.isValid()) return;

    QBrush brush(fillColor);
    QPen pen(borderColor);
    pen.setWidth(2); // Устанавливаем ширину обводки

    Triangle *triangle = new Triangle(base, height, brush, pen); // Создаём треугольник с заданными параметрами
    scene->addItem(triangle); // Добавляем треугольник на сцену
    triangle->setPos(100, 200);
}





