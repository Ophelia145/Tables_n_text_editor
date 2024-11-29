#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QFontDialog>
#include <QColorDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void saveFileAsHtml(const QString &filePath);
    void openHtmlFile(const QString &filePath);
    void newFile();
    void openFile();
    void saveFile();
    void documentModified();
    void findText();
    void replaceText();
    void clearText();
    void restoreText();
    void closeEvent(QCloseEvent *event) override;
    void on_TextSize_valueChanged(int fontSize);
    void on_TextColor_clicked();
    void changeFont(const QFont &font);





    void addTable();
    void addColumn();
    void addRow();
    void deleteColumn();
    void deleteRow();
    void deleteTable();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    bool documentSaved;
    void loadSettings();
    void saveSettings();
    void setupControlPanel();
    void setupShortcuts();
    bool promptSaveIfModified();

    QWidget *textTablesWidget;

    QSettings settings;
    QString currentFilePath;
    QString tempFilePath = "temporary_file.txt";
};

#endif // MAINWINDOW_H




