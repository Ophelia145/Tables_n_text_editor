#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ActionCreateNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->ActionOpenFile, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->ActionSave, &QAction::triggered, this, &MainWindow::saveFile);

    connect(ui->toolButton_3, &QToolButton::clicked, this, &MainWindow::newFile);
    connect(ui->toolButton_2, &QToolButton::clicked, this, &MainWindow::openFile);
    connect(ui->toolButton, &QToolButton::clicked, this, &MainWindow::saveFile);

    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::documentModified);
    documentSaved = true;



    connect(ui->findButton, &QToolButton::clicked, this, &MainWindow::findText);
    connect(ui->replaceButton, &QToolButton::clicked, this, &MainWindow::replaceText);
    connect(ui->clearButton, &QToolButton::clicked, this, &MainWindow::clearText);
    connect(ui->undoButton, &QToolButton::clicked, this, &MainWindow::undoAction);
    loadSettings();
        setupControlPanel();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::documentModified() {
    documentSaved = false;
}

void MainWindow::newFile() {
    if (!documentSaved) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Сохранить изменения?",
                                      "Вы хотите сохранить изменения в текущем файле?",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            saveFile();
        } else if (reply == QMessageBox::Cancel) {
            return;
        }
    }

    ui->textEdit->clear();
    documentSaved = true;
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
            documentSaved = true;
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        }
    }
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            documentSaved = true;
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл");
        }
    }
}

void MainWindow::findText() {
    QString searchText = ui->searchLineEdit->text();
    if (!ui->textEdit->find(searchText)) { // ищет текст от текущей позиции курсора
        QMessageBox::information(this, "Результат поиска", "Текст не найден.");
        ui->textEdit->moveCursor(QTextCursor::Start); // вернём курсор в начало для нового поиска
    }
}

void MainWindow::replaceText() {
    QString searchText = ui->searchLineEdit->text();
    QString replaceText = ui->replaceLineEdit->text();

    ui->textEdit->textCursor().beginEditBlock(); // начало транзакции для отмены нескольких изменений

    // Поиск и замена текста
    while (ui->textEdit->find(searchText)) {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.insertText(replaceText);
    }

    ui->textEdit->textCursor().endEditBlock(); // завершение транзакции
    ui->textEdit->moveCursor(QTextCursor::Start); // сброс позиции курсора
}

void MainWindow::clearText() {
    ui->textEdit->clear();
}

void MainWindow::undoAction() {
    ui->textEdit->undo();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (!documentSaved) {
        auto reply = QMessageBox::question(this, "Сохранить изменения???",
                                           "Вы хотите сохранить изменения в этом файле?!?",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            saveFile();
            event->accept();
        } else if (reply == QMessageBox::Cancel) {
            event->ignore();
        } else {
            event->accept();
        }
    } else {
        event->accept();
    }
}



void MainWindow::setupControlPanel() {
    QToolBar *controlPanel = addToolBar("Панель управления");

    // Размер шрифта
    QSpinBox *fontSizeBox = new QSpinBox();
    fontSizeBox->setRange(8, 48);
    connect(fontSizeBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeFontSize);
    controlPanel->addWidget(fontSizeBox);

    // Цвет текста
    QAction *fontColorAction = new QAction("Цвет текста", this);
    connect(fontColorAction, &QAction::triggered, this, &MainWindow::changeFontColor);
    controlPanel->addAction(fontColorAction);

    // Цвет фона
    QAction *bgColorAction = new QAction("Цвет фона", this);
    connect(bgColorAction, &QAction::triggered, this, &MainWindow::changeBackgroundColor);
    controlPanel->addAction(bgColorAction);

    // Отступы таблицы
    QSpinBox *paddingBox = new QSpinBox();
    paddingBox->setRange(0, 50);
    connect(paddingBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setTablePadding);
    controlPanel->addWidget(paddingBox);
}

void MainWindow::changeFontSize(int size) {
    ui->textEdit->setFontPointSize(size);
    saveSettings();
}

void MainWindow::changeFontColor() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
        saveSettings();
    }
}
void MainWindow::loadSettings() {    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(800, 600)).toSize());    move(settings.value("pos", QPoint(200, 200)).toPoint());
    ui->textEdit->setFontPointSize(settings.value("fontSize", 12).toInt());    settings.endGroup();
}
void MainWindow::saveSettings() {    settings.beginGroup("MainWindow");
    settings.setValue("size", size());    settings.setValue("pos", pos());
    settings.setValue("fontSize", ui->textEdit->fontPointSize());    int padding = 10;  // Задайте значение отступа, который нужно сохранить
    settings.setValue("tablePadding", padding);    settings.endGroup();
}


