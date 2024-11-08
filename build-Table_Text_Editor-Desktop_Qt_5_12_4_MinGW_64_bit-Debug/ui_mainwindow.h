/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionCreateNew;
    QAction *ActionOpenFile;
    QAction *ActionSave;
    QAction *ActionSearch;
    QAction *ActionReplacement;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *ALLBOX;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QGroupBox *groupBoxIN;
    QGridLayout *gridLayout_3;
    QToolButton *findButton;
    QToolButton *undoButton;
    QToolButton *clearButton;
    QLineEdit *searchLineEdit;
    QToolButton *replaceButton;
    QLineEdit *replaceLineEdit;
    QToolBox *Funcs;
    QWidget *Tables;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_Table;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QWidget *Text;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QPushButton *TextColor;
    QPushButton *ColorBackground;
    QSpinBox *TextSize;
    QFontComboBox *fontComboBox;
    QTextEdit *textEdit;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 750);
        MainWindow->setMinimumSize(QSize(1200, 700));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../src/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        ActionCreateNew = new QAction(MainWindow);
        ActionCreateNew->setObjectName(QString::fromUtf8("ActionCreateNew"));
        ActionOpenFile = new QAction(MainWindow);
        ActionOpenFile->setObjectName(QString::fromUtf8("ActionOpenFile"));
        ActionSave = new QAction(MainWindow);
        ActionSave->setObjectName(QString::fromUtf8("ActionSave"));
        ActionSearch = new QAction(MainWindow);
        ActionSearch->setObjectName(QString::fromUtf8("ActionSearch"));
        ActionReplacement = new QAction(MainWindow);
        ActionReplacement->setObjectName(QString::fromUtf8("ActionReplacement"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(10);
        gridLayout_2->setVerticalSpacing(7);
        gridLayout_2->setContentsMargins(-1, 11, -1, -1);
        ALLBOX = new QGroupBox(centralWidget);
        ALLBOX->setObjectName(QString::fromUtf8("ALLBOX"));
        ALLBOX->setMinimumSize(QSize(210, 0));
        ALLBOX->setMaximumSize(QSize(400, 750));
        verticalLayout = new QVBoxLayout(ALLBOX);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(ALLBOX);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(150, 170));
        groupBox_2->setMaximumSize(QSize(200, 240));
        groupBox_2->setFlat(true);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setVerticalSpacing(6);
        toolButton_3 = new QToolButton(groupBox_2);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(95, 0));
        toolButton_3->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(toolButton_3, 0, 0, 1, 1);

        toolButton_2 = new QToolButton(groupBox_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(100, 0));
        toolButton_2->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(toolButton_2, 2, 0, 1, 1);

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(100, 0));
        toolButton->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(toolButton, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBoxIN = new QGroupBox(ALLBOX);
        groupBoxIN->setObjectName(QString::fromUtf8("groupBoxIN"));
        groupBoxIN->setMaximumSize(QSize(200, 400));
        groupBoxIN->setCursor(QCursor(Qt::ArrowCursor));
        groupBoxIN->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBoxIN);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        findButton = new QToolButton(groupBoxIN);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        gridLayout_3->addWidget(findButton, 1, 0, 1, 1);

        undoButton = new QToolButton(groupBoxIN);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));

        gridLayout_3->addWidget(undoButton, 5, 0, 1, 1);

        clearButton = new QToolButton(groupBoxIN);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout_3->addWidget(clearButton, 0, 0, 1, 1);

        searchLineEdit = new QLineEdit(groupBoxIN);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        gridLayout_3->addWidget(searchLineEdit, 2, 0, 1, 1);

        replaceButton = new QToolButton(groupBoxIN);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));

        gridLayout_3->addWidget(replaceButton, 3, 0, 1, 1);

        replaceLineEdit = new QLineEdit(groupBoxIN);
        replaceLineEdit->setObjectName(QString::fromUtf8("replaceLineEdit"));

        gridLayout_3->addWidget(replaceLineEdit, 4, 0, 1, 1);


        verticalLayout->addWidget(groupBoxIN);


        gridLayout_2->addWidget(ALLBOX, 0, 0, 2, 2);

        Funcs = new QToolBox(centralWidget);
        Funcs->setObjectName(QString::fromUtf8("Funcs"));
        Funcs->setMinimumSize(QSize(100, 190));
        Funcs->setMaximumSize(QSize(400, 1200));
        Tables = new QWidget();
        Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->setGeometry(QRect(0, 0, 254, 597));
        gridLayout_6 = new QGridLayout(Tables);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(Tables);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_Table = new QGroupBox(groupBox);
        groupBox_Table->setObjectName(QString::fromUtf8("groupBox_Table"));
        gridLayout_5 = new QGridLayout(groupBox_Table);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton = new QPushButton(groupBox_Table);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_Table);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_Table);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_Table);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_Table);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_6, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_Table);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(40, 40));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        pushButton_5->setFont(font1);

        gridLayout_5->addWidget(pushButton_5, 5, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_Table);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        Funcs->addItem(Tables, QString::fromUtf8("\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270"));
        Text = new QWidget();
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(0, 0, 301, 576));
        gridLayout_7 = new QGridLayout(Text);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_3 = new QGroupBox(Text);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(400, 800));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        TextColor = new QPushButton(groupBox_3);
        TextColor->setObjectName(QString::fromUtf8("TextColor"));
        QFont font2;
        font2.setPointSize(9);
        TextColor->setFont(font2);

        gridLayout_4->addWidget(TextColor, 0, 0, 1, 1);

        ColorBackground = new QPushButton(groupBox_3);
        ColorBackground->setObjectName(QString::fromUtf8("ColorBackground"));
        ColorBackground->setFont(font2);

        gridLayout_4->addWidget(ColorBackground, 1, 0, 1, 1);

        TextSize = new QSpinBox(groupBox_3);
        TextSize->setObjectName(QString::fromUtf8("TextSize"));

        gridLayout_4->addWidget(TextSize, 2, 0, 1, 1);

        fontComboBox = new QFontComboBox(groupBox_3);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout_4->addWidget(fontComboBox, 3, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 0, 1, 1);

        Funcs->addItem(Text, QString::fromUtf8("\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\265\320\272\321\201\321\202\320\276\320\274"));

        gridLayout_2->addWidget(Funcs, 0, 3, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(680, 400));

        gridLayout_2->addWidget(textEdit, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Funcs->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Editor :)", nullptr));
        ActionCreateNew->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\235\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        ActionOpenFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        ActionSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        ActionSearch->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        ActionReplacement->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260", nullptr));
        ALLBOX->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270", nullptr));
        groupBox_2->setTitle(QString());
        toolButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273  (ctrl+N)", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273  (ctrl+O)", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214  (ctrl+S)", nullptr));
        groupBoxIN->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \320\262 \321\204\320\260\320\271\320\273\320\265", nullptr));
        findButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272  (ctrl+F)", nullptr));
        undoButton->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214  (ctrl+U)", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (ctrl+L)", nullptr));
        replaceButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260  (ctrl+R)", nullptr));
        groupBox->setTitle(QString());
        groupBox_Table->setTitle(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        Funcs->setItemText(Funcs->indexOf(Tables), QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270", nullptr));
        groupBox_3->setTitle(QString());
        TextColor->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        ColorBackground->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        Funcs->setItemText(Funcs->indexOf(Text), QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\265\320\272\321\201\321\202\320\276\320\274", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
