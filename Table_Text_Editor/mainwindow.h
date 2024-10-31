#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void undoAction();
   //void copyText();
    //void pasteText();


private:
    Ui::MainWindow *ui;
    bool documentSaved; //флаг для слежки за измен
};

#endif // MAINWINDOW_H
