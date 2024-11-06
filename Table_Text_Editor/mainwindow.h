#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

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
    void newFile();
    void openFile();
    void saveFile();
    void documentModified();
    void findText();
    void replaceText();
    void clearText();
    void restoreText();
    void closeEvent(QCloseEvent *event);
    void changeFontSize(int size);
    void changeFontColor();
    void changeBackgroundColor();
    void setTablePadding(int padding);

    void on_toolButton_3_triggered();

private:
    Ui::MainWindow *ui;
    bool documentSaved;
    void loadSettings();
    void saveSettings();
    void setupControlPanel();
    QSettings settings;//для сохр настроек
    QString currentFilePath;
    QString tempFilePath = "temporary_file.txt";
    void setupShortcuts();

};

#endif // MAINWINDOW_H





