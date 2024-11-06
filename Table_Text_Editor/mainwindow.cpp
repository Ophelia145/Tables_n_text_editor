#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>

#include <QFontDialog>
#include <QColorDialog>
#include <QToolBar>
#include <QComboBox>
#include <QSpinBox>

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
    connect(ui->findButton, &QToolButton::clicked, this, &MainWindow::findText);
    connect(ui->replaceButton, &QToolButton::clicked, this, &MainWindow::replaceText);
    connect(ui->clearButton, &QToolButton::clicked, this, &MainWindow::clearText);
    connect(ui->undoButton, &QToolButton::clicked, this, &MainWindow::restoreText);

    documentSaved = true;

    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);

    QStringList headers = { "1", "2", "3", "4", "5" };
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    loadSettings();

    setTablePadding(10);

    loadSettings();
    setupControlPanel();
    setupShortcuts();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::documentModified() {
    documentSaved = false;
}

void MainWindow::newFile() {
    if (!documentSaved) {
        auto reply = QMessageBox::question(this, "Сохранить изменения?",
                                           "Вы правда не хотите сохранить изменения в этом файле?",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            saveFile();
        } else if (reply == QMessageBox::Cancel) {
            return;
        }
    }
    ui->textEdit->clear();
    currentFilePath.clear();
    documentSaved = true;
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
            currentFilePath = fileName;
            documentSaved = true;
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        }
    }
}

void MainWindow::saveFile() {
    if (currentFilePath.isEmpty()) {

        currentFilePath = QFileDialog::getSaveFileName(this, "Сохранить файл");
    }

    if (!currentFilePath.isEmpty()) {
        QFile file(currentFilePath);
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
    if (!ui->textEdit->find(searchText)) {
        QMessageBox::information(this, "Результат поиска", "Текст потерялся.");
        ui->textEdit->moveCursor(QTextCursor::Start);
    }
}

void MainWindow::replaceText() {
    QString searchText = ui->searchLineEdit->text();
    QString replaceText = ui->replaceLineEdit->text();

    ui->textEdit->textCursor().beginEditBlock();

    while (ui->textEdit->find(searchText)) {
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.insertText(replaceText);
    }

    ui->textEdit->textCursor().endEditBlock();
    ui->textEdit->moveCursor(QTextCursor::Start);
}

void MainWindow::clearText() {

    QFile tempFile(tempFilePath);
    if (tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&tempFile);
        out << ui->textEdit->toPlainText();
        tempFile.close();
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить временный файл");
    }

    ui->textEdit->clear();
    documentSaved = false;
}

void MainWindow::restoreText() {

    QFile tempFile(tempFilePath);
    if (tempFile.exists() && tempFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&tempFile);
        ui->textEdit->setPlainText(in.readAll());
        tempFile.close();
        documentSaved = false;
    } else {
        QMessageBox::warning(this, "Ошибка", "Временный файл потерялся");
    }
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

    QSpinBox *fontSizeBox = new QSpinBox();
    fontSizeBox->setRange(8, 48);
    connect(fontSizeBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeFontSize);
    controlPanel->addWidget(fontSizeBox);

    QAction *fontColorAction = new QAction("Цвет текста", this);
    connect(fontColorAction, &QAction::triggered, this, &MainWindow::changeFontColor);
    controlPanel->addAction(fontColorAction);

    QAction *bgColorAction = new QAction("Цвет фона", this);
    connect(bgColorAction, &QAction::triggered, this, &MainWindow::changeBackgroundColor);
    controlPanel->addAction(bgColorAction);


    QSpinBox *paddingBox = new QSpinBox();
    paddingBox->setRange(0, 50); //менть отступы
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

void MainWindow::changeBackgroundColor() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет фона");
    if (color.isValid()) {
        QPalette palette = ui->textEdit->palette();
        palette.setColor(QPalette::Base, color);
        ui->textEdit->setPalette(palette);
        saveSettings();
    }
}


void MainWindow::setTablePadding(int padding) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            if (!item) {
                item = new QTableWidgetItem();
                ui->tableWidget->setItem(row, col, item);
            }
            item->setTextAlignment(Qt::AlignCenter);  //центрирование текста
            item->setData(Qt::UserRole, padding);  //сохранение отступа в пользодате
        }
    }
    saveSettings(); //сэйвим настройки при измен отступов
}



void MainWindow::loadSettings() {
    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(800, 600)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    ui->textEdit->setFontPointSize(settings.value("fontSize", 12).toInt());
    settings.endGroup();
}

void MainWindow::saveSettings() {
    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.setValue("fontSize", ui->textEdit->fontPointSize());
    int padding = 10;
    settings.setValue("tablePadding", padding);
    settings.endGroup();
}



void MainWindow::setupShortcuts() {
    ui->toolButton_3->setShortcut(QKeySequence("Ctrl+N"));
    ui->toolButton_2->setShortcut(QKeySequence("Ctrl+O"));
    ui->toolButton->setShortcut(QKeySequence("Ctrl+S"));
    ui->findButton->setShortcut(QKeySequence("Ctrl+F"));
    ui->replaceButton->setShortcut(QKeySequence("Ctrl+R"));
    ui->clearButton->setShortcut(QKeySequence("Ctrl+L"));
    ui->undoButton->setShortcut(QKeySequence("Ctrl+U"));
}






























