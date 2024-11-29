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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
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
    QAction *actionactionOpen_in_NewWindow;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QGroupBox *ALLBOX;
    QFormLayout *formLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QGroupBox *groupBoxIN;
    QGridLayout *gridLayout_3;
    QToolButton *undoButton;
    QLineEdit *replaceLineEdit;
    QLineEdit *searchLineEdit;
    QToolButton *findButton;
    QToolButton *replaceButton;
    QToolButton *clearButton;
    QToolBox *Funcs;
    QWidget *Tables;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QGroupBox *groupBox_Table;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *Text;
    QFormLayout *formLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QPushButton *TextColor;
    QPushButton *ColorBackground;
    QSpinBox *TextSize;
    QFontComboBox *fontComboBox;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout;
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
        actionactionOpen_in_NewWindow = new QAction(MainWindow);
        actionactionOpen_in_NewWindow->setObjectName(QString::fromUtf8("actionactionOpen_in_NewWindow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 11, -1, -1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 0, 1178, 1000));
        groupBox_4->setMinimumSize(QSize(1000, 1000));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit = new QTextEdit(groupBox_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(600, 350));

        gridLayout_2->addWidget(textEdit, 0, 2, 1, 1);

        ALLBOX = new QGroupBox(groupBox_4);
        ALLBOX->setObjectName(QString::fromUtf8("ALLBOX"));
        ALLBOX->setEnabled(true);
        ALLBOX->setMinimumSize(QSize(210, 100));
        ALLBOX->setMaximumSize(QSize(400, 1100));
        formLayout = new QFormLayout(ALLBOX);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupBox_2 = new QGroupBox(ALLBOX);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(150, 240));
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

        toolButton = new QToolButton(groupBox_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(100, 0));
        toolButton->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(toolButton, 3, 0, 1, 1);

        toolButton_2 = new QToolButton(groupBox_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(100, 0));
        toolButton_2->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(toolButton_2, 2, 0, 1, 1);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox_2);

        groupBoxIN = new QGroupBox(ALLBOX);
        groupBoxIN->setObjectName(QString::fromUtf8("groupBoxIN"));
        groupBoxIN->setMinimumSize(QSize(0, 390));
        groupBoxIN->setMaximumSize(QSize(200, 400));
        groupBoxIN->setCursor(QCursor(Qt::ArrowCursor));
        groupBoxIN->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBoxIN);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        undoButton = new QToolButton(groupBoxIN);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));

        gridLayout_3->addWidget(undoButton, 5, 0, 1, 1);

        replaceLineEdit = new QLineEdit(groupBoxIN);
        replaceLineEdit->setObjectName(QString::fromUtf8("replaceLineEdit"));

        gridLayout_3->addWidget(replaceLineEdit, 4, 0, 1, 1);

        searchLineEdit = new QLineEdit(groupBoxIN);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        gridLayout_3->addWidget(searchLineEdit, 2, 0, 1, 1);

        findButton = new QToolButton(groupBoxIN);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        gridLayout_3->addWidget(findButton, 1, 0, 1, 1);

        replaceButton = new QToolButton(groupBoxIN);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));

        gridLayout_3->addWidget(replaceButton, 3, 0, 1, 1);

        clearButton = new QToolButton(groupBoxIN);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout_3->addWidget(clearButton, 0, 0, 1, 1);


        formLayout->setWidget(1, QFormLayout::LabelRole, groupBoxIN);


        gridLayout_2->addWidget(ALLBOX, 0, 3, 1, 1);

        Funcs = new QToolBox(groupBox_4);
        Funcs->setObjectName(QString::fromUtf8("Funcs"));
        Funcs->setMinimumSize(QSize(100, 500));
        Funcs->setMaximumSize(QSize(400, 1200));
        Tables = new QWidget();
        Tables->setObjectName(QString::fromUtf8("Tables"));
        Tables->setGeometry(QRect(0, 0, 291, 892));
        gridLayout_6 = new QGridLayout(Tables);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox = new QGroupBox(Tables);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(200, 0));
        groupBox->setFlat(true);
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        groupBox_Table = new QGroupBox(groupBox);
        groupBox_Table->setObjectName(QString::fromUtf8("groupBox_Table"));
        groupBox_Table->setMinimumSize(QSize(240, 500));
        groupBox_Table->setMaximumSize(QSize(16777215, 700));
        gridLayout_5 = new QGridLayout(groupBox_Table);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_3 = new QPushButton(groupBox_Table);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_Table);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_Table);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(40, 40));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        pushButton_5->setFont(font1);

        gridLayout_5->addWidget(pushButton_5, 5, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_Table);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_6, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_Table);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(groupBox_Table);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(40, 40));

        gridLayout_5->addWidget(pushButton, 0, 0, 1, 1);


        formLayout_2->setWidget(0, QFormLayout::LabelRole, groupBox_Table);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 1);

        Funcs->addItem(Tables, QString::fromUtf8("\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270"));
        Text = new QWidget();
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setGeometry(QRect(0, 0, 308, 892));
        Text->setMaximumSize(QSize(16777215, 900));
        formLayout_3 = new QFormLayout(Text);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        groupBox_3 = new QGroupBox(Text);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 400));
        groupBox_3->setMaximumSize(QSize(400, 350));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        TextColor = new QPushButton(groupBox_3);
        TextColor->setObjectName(QString::fromUtf8("TextColor"));
        QFont font2;
        font2.setPointSize(9);
        TextColor->setFont(font2);

        gridLayout_7->addWidget(TextColor, 0, 0, 1, 1);

        ColorBackground = new QPushButton(groupBox_3);
        ColorBackground->setObjectName(QString::fromUtf8("ColorBackground"));
        ColorBackground->setFont(font2);

        gridLayout_7->addWidget(ColorBackground, 1, 0, 1, 1);

        TextSize = new QSpinBox(groupBox_3);
        TextSize->setObjectName(QString::fromUtf8("TextSize"));

        gridLayout_7->addWidget(TextSize, 2, 0, 1, 1);

        fontComboBox = new QFontComboBox(groupBox_3);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout_7->addWidget(fontComboBox, 3, 0, 1, 1);


        formLayout_3->setWidget(0, QFormLayout::LabelRole, groupBox_3);

        Funcs->addItem(Text, QString::fromUtf8("\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\265\320\272\321\201\321\202\320\276\320\274"));

        gridLayout_2->addWidget(Funcs, 0, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        horizontalLayout = new QHBoxLayout(tab_6);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget->addTab(tab_6, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

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

        tabWidget->setCurrentIndex(1);
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
        actionactionOpen_in_NewWindow->setText(QApplication::translate("MainWindow", "actionOpen_in_NewWindow", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        ALLBOX->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270", nullptr));
        groupBox_2->setTitle(QString());
        toolButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273  (ctrl+N)", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214  (ctrl+S)", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273  (ctrl+O)", nullptr));
        groupBoxIN->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \320\262 \321\204\320\260\320\271\320\273\320\265", nullptr));
        undoButton->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214  (ctrl+U)", nullptr));
        findButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272  (ctrl+F)", nullptr));
        replaceButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260  (ctrl+R)", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 (ctrl+L)", nullptr));
        groupBox->setTitle(QString());
        groupBox_Table->setTitle(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        Funcs->setItemText(Funcs->indexOf(Tables), QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\260\320\274\320\270", nullptr));
        groupBox_3->setTitle(QString());
        TextColor->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        ColorBackground->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        Funcs->setItemText(Funcs->indexOf(Text), QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \321\202\320\265\320\272\321\201\321\202\320\276\320\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Tab 2", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
