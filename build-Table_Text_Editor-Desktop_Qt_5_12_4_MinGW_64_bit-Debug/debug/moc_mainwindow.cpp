/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Table_Text_Editor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "saveFileAsHtml"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "filePath"
QT_MOC_LITERAL(4, 36, 12), // "openHtmlFile"
QT_MOC_LITERAL(5, 49, 7), // "newFile"
QT_MOC_LITERAL(6, 57, 8), // "openFile"
QT_MOC_LITERAL(7, 66, 8), // "saveFile"
QT_MOC_LITERAL(8, 75, 16), // "documentModified"
QT_MOC_LITERAL(9, 92, 8), // "findText"
QT_MOC_LITERAL(10, 101, 11), // "replaceText"
QT_MOC_LITERAL(11, 113, 9), // "clearText"
QT_MOC_LITERAL(12, 123, 11), // "restoreText"
QT_MOC_LITERAL(13, 135, 10), // "closeEvent"
QT_MOC_LITERAL(14, 146, 12), // "QCloseEvent*"
QT_MOC_LITERAL(15, 159, 5), // "event"
QT_MOC_LITERAL(16, 165, 24), // "on_TextSize_valueChanged"
QT_MOC_LITERAL(17, 190, 8), // "fontSize"
QT_MOC_LITERAL(18, 199, 20), // "on_TextColor_clicked"
QT_MOC_LITERAL(19, 220, 10), // "changeFont"
QT_MOC_LITERAL(20, 231, 4), // "font"
QT_MOC_LITERAL(21, 236, 8), // "addTable"
QT_MOC_LITERAL(22, 245, 9), // "addColumn"
QT_MOC_LITERAL(23, 255, 6), // "addRow"
QT_MOC_LITERAL(24, 262, 12), // "deleteColumn"
QT_MOC_LITERAL(25, 275, 9), // "deleteRow"
QT_MOC_LITERAL(26, 285, 11), // "deleteTable"
QT_MOC_LITERAL(27, 297, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(28, 324, 5) // "index"

    },
    "MainWindow\0saveFileAsHtml\0\0filePath\0"
    "openHtmlFile\0newFile\0openFile\0saveFile\0"
    "documentModified\0findText\0replaceText\0"
    "clearText\0restoreText\0closeEvent\0"
    "QCloseEvent*\0event\0on_TextSize_valueChanged\0"
    "fontSize\0on_TextColor_clicked\0changeFont\0"
    "font\0addTable\0addColumn\0addRow\0"
    "deleteColumn\0deleteRow\0deleteTable\0"
    "on_tabWidget_tabBarClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x08 /* Private */,
       4,    1,  122,    2, 0x08 /* Private */,
       5,    0,  125,    2, 0x08 /* Private */,
       6,    0,  126,    2, 0x08 /* Private */,
       7,    0,  127,    2, 0x08 /* Private */,
       8,    0,  128,    2, 0x08 /* Private */,
       9,    0,  129,    2, 0x08 /* Private */,
      10,    0,  130,    2, 0x08 /* Private */,
      11,    0,  131,    2, 0x08 /* Private */,
      12,    0,  132,    2, 0x08 /* Private */,
      13,    1,  133,    2, 0x08 /* Private */,
      16,    1,  136,    2, 0x08 /* Private */,
      18,    0,  139,    2, 0x08 /* Private */,
      19,    1,  140,    2, 0x08 /* Private */,
      21,    0,  143,    2, 0x08 /* Private */,
      22,    0,  144,    2, 0x08 /* Private */,
      23,    0,  145,    2, 0x08 /* Private */,
      24,    0,  146,    2, 0x08 /* Private */,
      25,    0,  147,    2, 0x08 /* Private */,
      26,    0,  148,    2, 0x08 /* Private */,
      27,    1,  149,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   28,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveFileAsHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->openHtmlFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->newFile(); break;
        case 3: _t->openFile(); break;
        case 4: _t->saveFile(); break;
        case 5: _t->documentModified(); break;
        case 6: _t->findText(); break;
        case 7: _t->replaceText(); break;
        case 8: _t->clearText(); break;
        case 9: _t->restoreText(); break;
        case 10: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 11: _t->on_TextSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_TextColor_clicked(); break;
        case 13: _t->changeFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 14: _t->addTable(); break;
        case 15: _t->addColumn(); break;
        case 16: _t->addRow(); break;
        case 17: _t->deleteColumn(); break;
        case 18: _t->deleteRow(); break;
        case 19: _t->deleteTable(); break;
        case 20: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
