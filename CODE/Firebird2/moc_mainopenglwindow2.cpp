/****************************************************************************
** Meta object code from reading C++ file 'mainopenglwindow2.h'
**
** Created: Fri Jun 27 12:54:53 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainopenglwindow2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainopenglwindow2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainOpenglWindow2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   19,   18,   18, 0x0a,
      45,   19,   18,   18, 0x0a,
      74,   66,   18,   18, 0x0a,
      95,   93,   18,   18, 0x0a,
     130,   18,   18,   18, 0x0a,
     138,   18,   18,   18, 0x0a,
     146,   18,   18,   18, 0x0a,
     156,   18,   18,   18, 0x0a,
     166,   18,   18,   18, 0x0a,
     177,   18,   18,   18, 0x0a,
     185,   18,   18,   18, 0x0a,
     192,   18,   18,   18, 0x0a,
     199,   18,   18,   18, 0x0a,
     209,  207,   18,   18, 0x0a,
     233,  207,   18,   18, 0x0a,
     258,  207,   18,   18, 0x0a,
     278,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainOpenglWindow2[] = {
    "mainOpenglWindow2\0\0strPrm\0getEnvName(string)\0"
    "getRobotName(string)\0portnum\0"
    "getPortNumber(int)\0r\0"
    "updateRobotLocation(robotLocation)\0"
    "start()\0reset()\0receive()\0forward()\0"
    "backward()\0right()\0left()\0stop()\0"
    "stops()\0v\0setVelocityLeft(double)\0"
    "setVelocityRight(double)\0setVelocity(double)\0"
    "move()\0"
};

void mainOpenglWindow2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mainOpenglWindow2 *_t = static_cast<mainOpenglWindow2 *>(_o);
        switch (_id) {
        case 0: _t->getEnvName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->getRobotName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->getPortNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateRobotLocation((*reinterpret_cast< robotLocation(*)>(_a[1]))); break;
        case 4: _t->start(); break;
        case 5: _t->reset(); break;
        case 6: _t->receive(); break;
        case 7: _t->forward(); break;
        case 8: _t->backward(); break;
        case 9: _t->right(); break;
        case 10: _t->left(); break;
        case 11: _t->stop(); break;
        case 12: _t->stops(); break;
        case 13: _t->setVelocityLeft((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setVelocityRight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->setVelocity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->move(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mainOpenglWindow2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mainOpenglWindow2::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_mainOpenglWindow2,
      qt_meta_data_mainOpenglWindow2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainOpenglWindow2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainOpenglWindow2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainOpenglWindow2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainOpenglWindow2))
        return static_cast<void*>(const_cast< mainOpenglWindow2*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int mainOpenglWindow2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
