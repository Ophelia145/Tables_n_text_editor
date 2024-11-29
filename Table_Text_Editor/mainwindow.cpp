#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics_editor.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QColorDialog>
#include <QToolBar>
#include <QComboBox>
#include <QTextTableCell>
#include <QSpinBox>
#include<QInputDialog>
#include <QVBoxLayout>
#include <QLabel>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    GraphicsEditorWindow *editorWindow = new GraphicsEditorWindow(this);

    //QTabWidget *tabWidget = new QTabWidget(this);



    //QWidget *textTablesWidget = new QWidget();
        //QVBoxLayout *layout = new QVBoxLayout(textTablesWidget);

//        QTabWidget *localTabWidget = new QTabWidget(textTablesWidget);
//        localTabWidget->addTab(ui->tab_5, "Tab 1");  // Добавляем оригинал

//        layout->addWidget(localTabWidget);


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



    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addTable);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::addColumn);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::deleteColumn);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::deleteTable);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::deleteRow);

    connect(ui->TextSize, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_TextSize_valueChanged);

    //connect(ui->TextColor, &QPushButton::clicked, this, &MainWindow::on_TextColor_clicked);
    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, this, &MainWindow::changeFont);

    ui->TextSize->setRange(8, 72);
    ui->TextSize->setValue(12);

    documentSaved = true;
    //loadSettings();
    setupShortcuts();



    //tabWidget->addTab(new QWidget(), "Текст_Таблицы");  // Первая вкладка
    //tabWidget->addTab(new QWidget(), "Графика");  // Вторая вкладка для редактора

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [this, editorWindow](int index) {
        if (ui->tabWidget->widget(index) == ui->tab_6) {  // Проверка на активность tab_6
            editorWindow->show();  // Показываем графический редактор
        } else {
            editorWindow->hide();  // Скрываем графический редактор
        }
    });


        setCentralWidget(ui->tabWidget);

}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::documentModified() {
    documentSaved = false;
}


void MainWindow::saveFileAsHtml(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        QString htmlContent = ui->textEdit->toHtml();
        out << htmlContent;
        file.close();
        documentSaved = true;
        currentFilePath = filePath;
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить файл.");
    }
}


void MainWindow::openHtmlFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString htmlContent = in.readAll();
        file.close();
        ui->textEdit->setHtml(htmlContent);
        currentFilePath = filePath;
        documentSaved = true;
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
    }
}





void MainWindow::newFile()
{
    if (!documentSaved) {
        auto reply = QMessageBox::question(this, "Сохранить изменения?",
                                           "Вы хотите сохранить изменения в этом файле?",
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

void MainWindow::saveFile()
{
    if (currentFilePath.isEmpty()) {
        QString filePath = QFileDialog::getSaveFileName(this, "Сохранить как", "", "HTML Files (*.html)");
        if (!filePath.isEmpty()) {
            saveFileAsHtml(filePath);
        }
    } else {
        saveFileAsHtml(currentFilePath);
    }
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл", "", "HTML Files (*.html)");
    if (!filePath.isEmpty()) {
        openHtmlFile(filePath);
    }
}

void MainWindow::findText() {
    QString searchText = ui->searchLineEdit->text();
    if (!ui->textEdit->find(searchText)) {
        QMessageBox::information(this, "Результат поиска", "Текст не найден.");
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
        QMessageBox::warning(this, "Ошибка", "Временный файл не найден");
    }
}
void MainWindow::closeEvent(QCloseEvent *event) {
    if (!promptSaveIfModified()) {
        event->ignore();
    } else {
        saveSettings();
        event->accept();
    }
}

bool MainWindow::promptSaveIfModified() {
    if (!documentSaved) {
        auto reply = QMessageBox::question(this, "Сохранить изменения?",
                                           "Вы хотите сохранить изменения в этом файле?",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            saveFile();
            return true;
        } else if (reply == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}





void MainWindow::loadSettings() {
    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();
}

void MainWindow::saveSettings() {
    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}



void MainWindow::addTable()
{
    bool ok;
    int rows = QInputDialog::getInt(this, tr("Сколько строк"),
                                     tr("Строки:"), 3, 1, 100, 1, &ok);
    if (!ok) { return; }

    int columns = QInputDialog::getInt(this, tr("Сколько столбцов"),
                                        tr("Столбцы:"), 3, 1, 100, 1, &ok);
    if (!ok) { return; }

    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(10);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.insertTable(rows, columns, tableFormat);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            QTextTableCell cell = table->cellAt(i, j);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(" ");
        }
    }
}

void MainWindow::addRow()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.currentTable();
    if (table) {
        table->appendRows(1);
    } else {
        QMessageBox::information(this, tr("Упс"), tr("Нет таблицы для добавления строки."));
    }
}

void MainWindow::addColumn()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.currentTable();
    if (table) {
        int rows = table->rows();
        int columns = table->columns();
        table->insertColumns(columns, 1);

        for (int i = 0; i < rows; ++i) {
            QTextTableCell cell = table->cellAt(i, columns);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(" ");
        }
    } else {
        QMessageBox::information(this, tr("Ой-ой"), tr("Нет таблицы для добавления столбца."));
    }
}

void MainWindow::deleteRow()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.currentTable();
    if (table && table->rows() > 0) {
        table->removeRows(table->rows() - 1, 1);
    } else {
        QMessageBox::information(this, tr("Как дальше жить!"), tr("Нет строк для удаления."));
    }
}

void MainWindow::deleteColumn()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.currentTable();
    if (table && table->columns() > 0) {
        table->removeColumns(table->columns() - 1, 1);
    } else {
        QMessageBox::information(this, tr("Вот это да"), tr("Нет столбцов для удаления."));
    }
}

void MainWindow::deleteTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTable *table = cursor.currentTable();
    if (table) {
        table->deleteLater();
    } else {
        QMessageBox::information(this, tr("Всё плохо"), tr("Нет таблицы для удаления."));
    }
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



void MainWindow::on_TextColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет текста");
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);

        QTextCursor cursor = ui->textEdit->textCursor();
        if (cursor.hasSelection()) {
            cursor.mergeCharFormat(format);
        } else {
            ui->textEdit->mergeCurrentCharFormat(format);
        }
    }
}


void MainWindow::on_TextSize_valueChanged(int fontSize)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCharFormat format;
    format.setFontPointSize(fontSize);

    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(format);
    } else {
        ui->textEdit->mergeCurrentCharFormat(format);
    }
}

void MainWindow::changeFont(const QFont &font)
{
    QTextCharFormat format;
    format.setFont(font);

    QTextCursor cursor = ui->textEdit->textCursor();
    if (cursor.hasSelection()) {
        cursor.mergeCharFormat(format);
    } else {
        ui->textEdit->mergeCurrentCharFormat(format);
    }
}





void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    // Проверяем, нажата ли определенная вкладка, скажем, третья вкладка (индекс 2)
      if (index == 2) {
          // Создаем окно графического редактора
          GraphicsEditorWindow *editorWindow = new GraphicsEditorWindow(this);

          // Устанавливаем поведение удаления окна после закрытия
          editorWindow->setAttribute(Qt::WA_DeleteOnClose);

          // Показываем окно
          editorWindow->show();
      }


}
