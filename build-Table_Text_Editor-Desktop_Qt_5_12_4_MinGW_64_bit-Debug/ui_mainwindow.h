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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
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
    QTextEdit *textEdit;
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
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        MainWindow->setMinimumSize(QSize(900, 600));
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
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(600, 400));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(12);
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textEdit->setFrameShadow(QFrame::Sunken);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        ALLBOX = new QGroupBox(centralWidget);
        ALLBOX->setObjectName(QString::fromUtf8("ALLBOX"));
        ALLBOX->setMaximumSize(QSize(400, 600));
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
        groupBoxIN->setMaximumSize(QSize(200, 270));
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


        gridLayout_2->addWidget(ALLBOX, 0, 1, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

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
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:7.8pt;\"><br /></p></body></html>", nullptr));
        ALLBOX->setTitle(QString());
        groupBox_2->setTitle(QString());
        toolButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        groupBoxIN->setTitle(QString());
        findButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        undoButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\263\320\276 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217", nullptr));
        clearButton->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        replaceButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\260", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
