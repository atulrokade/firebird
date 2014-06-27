/****************************************************************************
** Meta object code from reading C++ file 'createenvironmentopenglwindow.h'
**
** Created: Fri Jun 27 13:01:52 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/media/Local Disk/MTP/Firebird2/createenvironmentopenglwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createenvironmentopenglwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_createEnvironmentOpenglWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      45,   31,   30,   30, 0x0a,
      80,   30,   30,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_createEnvironmentOpenglWindow[] = {
    "createEnvironmentOpenglWindow\0\0"
    "prmObjectList\0updateObject(vector_envObjectType)\0"
    "currentObject(QString)\0"
};

void createEnvironmentOpenglWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        createEnvironmentOpenglWindow *_t = static_cast<createEnvironmentOpenglWindow *>(_o);
        switch (_id) {
        case 0: _t->updateObject((*reinterpret_cast< vector_envObjectType(*)>(_a[1]))); break;
        case 1: _t->currentObject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData createEnvironmentOpenglWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject createEnvironmentOpenglWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_createEnvironmentOpenglWindow,
      qt_meta_data_createEnvironmentOpenglWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &createEnvironmentOpenglWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *createEnvironmentOpenglWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *createEnvironmentOpenglWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_createEnvironmentOpenglWindow))
        return static_cast<void*>(const_cast< createEnvironmentOpenglWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int createEnvironmentOpenglWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
