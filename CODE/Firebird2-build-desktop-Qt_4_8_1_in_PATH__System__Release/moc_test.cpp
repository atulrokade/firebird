/****************************************************************************
** Meta object code from reading C++ file 'test.h'
**
** Created: Wed May 14 10:14:24 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/media/Local Disk/MTP/Firebird2/test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_test[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   29,    5,    5, 0x0a,
      56,    6,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_test[] = {
    "test\0\0str\0setEnvName(string)\0menu\0"
    "menuClicked(QAction*)\0getEnvName(string)\0"
};

void test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        test *_t = static_cast<test *>(_o);
        switch (_id) {
        case 0: _t->setEnvName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->menuClicked((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->getEnvName((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData test::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject test::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_test,
      qt_meta_data_test, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_test))
        return static_cast<void*>(const_cast< test*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void test::setEnvName(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
