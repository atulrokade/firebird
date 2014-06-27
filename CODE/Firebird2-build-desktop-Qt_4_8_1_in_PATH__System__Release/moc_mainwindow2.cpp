/****************************************************************************
** Meta object code from reading C++ file 'mainwindow2.h'
**
** Created: Fri Jun 27 13:01:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/media/Local Disk/MTP/Firebird2/mainwindow2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x05,
      36,   13,   12,   12, 0x05,
      57,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,   89,   12,   12, 0x0a,
     116,   13,   12,   12, 0x0a,
     135,   13,   12,   12, 0x0a,
     156,   12,   12,   12, 0x0a,
     181,   12,   12,   12, 0x0a,
     208,   12,   12,   12, 0x0a,
     233,   12,   12,   12, 0x0a,
     253,   12,   12,   12, 0x0a,
     274,   12,   12,   12, 0x0a,
     302,   12,   12,   12, 0x0a,
     334,  323,   12,   12, 0x0a,
     371,  369,   12,   12, 0x0a,
     407,  405,   12,   12, 0x0a,
     443,  441,   12,   12, 0x0a,
     483,  477,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow2[] = {
    "MainWindow2\0\0str\0setEnvName(string)\0"
    "setRobotName(string)\0"
    "setRobotLocation(robotLocation)\0menu\0"
    "menuClicked(QAction*)\0getEnvName(string)\0"
    "getRobotName(string)\0browseEnvButtonClicked()\0"
    "browseRobotButtonClicked()\0"
    "initRobotButtonClicked()\0undoButtonClicked()\0"
    "resetButtonClicked()\0locationSaveButtonClicked()\0"
    "startButtonClicked()\0portNumber\0"
    "portNumberspinBoxValueChanged(int)\0x\0"
    "locationXspinBoxValueChanged(int)\0y\0"
    "locationYspinBoxValueChanged(int)\0z\0"
    "locationZspinBoxValueChanged(int)\0"
    "angle\0locationAnglespinBoxValueChanged(int)\0"
};

void MainWindow2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow2 *_t = static_cast<MainWindow2 *>(_o);
        switch (_id) {
        case 0: _t->setEnvName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->setRobotName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->setRobotLocation((*reinterpret_cast< robotLocation(*)>(_a[1]))); break;
        case 3: _t->menuClicked((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->getEnvName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 5: _t->getRobotName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 6: _t->browseEnvButtonClicked(); break;
        case 7: _t->browseRobotButtonClicked(); break;
        case 8: _t->initRobotButtonClicked(); break;
        case 9: _t->undoButtonClicked(); break;
        case 10: _t->resetButtonClicked(); break;
        case 11: _t->locationSaveButtonClicked(); break;
        case 12: _t->startButtonClicked(); break;
        case 13: _t->portNumberspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->locationXspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->locationYspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->locationZspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->locationAnglespinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow2,
      qt_meta_data_MainWindow2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow2))
        return static_cast<void*>(const_cast< MainWindow2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow2::setEnvName(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow2::setRobotName(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow2::setRobotLocation(robotLocation _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
