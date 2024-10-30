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
