#include "ui_text_edit.h"

class TextEditWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit TextEditWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), ui(new Ui::TextEdit) {
        ui->setupUi(this);
    }

    ~TextEditWindow() {
        delete ui;
    }

private:
    Ui::TextEdit *ui;
};
