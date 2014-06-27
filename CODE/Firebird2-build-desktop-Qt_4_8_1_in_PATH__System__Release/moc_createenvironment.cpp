/****************************************************************************
** Meta object code from reading C++ file 'createenvironment.h'
**
** Created: Fri Jun 27 13:01:50 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/media/Local Disk/MTP/Firebird2/createenvironment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createenvironment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_createEnvironment[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      55,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   18,   18,   18, 0x0a,
      94,   18,   18,   18, 0x0a,
     116,   18,   18,   18, 0x0a,
     139,   18,   18,   18, 0x0a,
     161,   18,   18,   18, 0x0a,
     186,   18,   18,   18, 0x0a,
     212,   18,   18,   18, 0x0a,
     240,   18,   18,   18, 0x0a,
     264,   18,   18,   18, 0x0a,
     289,   18,   18,   18, 0x0a,
     317,   18,   18,   18, 0x0a,
     346,   18,   18,   18, 0x0a,
     375,   18,   18,   18, 0x0a,
     395,   18,   18,   18, 0x0a,
     417,   18,   18,   18, 0x0a,
     439,  437,   18,   18, 0x0a,
     471,  469,   18,   18, 0x0a,
     503,  501,   18,   18, 0x0a,
     533,  437,   18,   18, 0x0a,
     567,  469,   18,   18, 0x0a,
     601,  501,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_createEnvironment[] = {
    "createEnvironment\0\0"
    "objectUpdated(vector_envObjectType)\0"
    "envName(string)\0currentRowChanged(int)\0"
    "newEnvButtonClicked()\0loadEnvButtonClicked()\0"
    "browseButtonClicked()\0addObjectButtonClicked()\0"
    "editObjectButtonClicked()\0"
    "deleteObjectButtonClicked()\0"
    "sizeUndoButtonClicked()\0"
    "sizeResetButtonClicked()\0"
    "locationUndoButtonClicked()\0"
    "locationResetButtonClicked()\0"
    "saveDimentionButtonClicked()\0"
    "saveButtonClicked()\0cancelButtonClicked()\0"
    "exitButtonClicked()\0x\0"
    "sizeXspinBoxValueChanged(int)\0y\0"
    "sizeYspinBoxValueChanged(int)\0z\0"
    "sizeZspinBoxValueChanged(int)\0"
    "locationXspinBoxValueChanged(int)\0"
    "locationYspinBoxValueChanged(int)\0"
    "locationZspinBoxValueChanged(int)\0"
};

void createEnvironment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        createEnvironment *_t = static_cast<createEnvironment *>(_o);
        switch (_id) {
        case 0: _t->objectUpdated((*reinterpret_cast< vector_envObjectType(*)>(_a[1]))); break;
        case 1: _t->envName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->newEnvButtonClicked(); break;
        case 4: _t->loadEnvButtonClicked(); break;
        case 5: _t->browseButtonClicked(); break;
        case 6: _t->addObjectButtonClicked(); break;
        case 7: _t->editObjectButtonClicked(); break;
        case 8: _t->deleteObjectButtonClicked(); break;
        case 9: _t->sizeUndoButtonClicked(); break;
        case 10: _t->sizeResetButtonClicked(); break;
        case 11: _t->locationUndoButtonClicked(); break;
        case 12: _t->locationResetButtonClicked(); break;
        case 13: _t->saveDimentionButtonClicked(); break;
        case 14: _t->saveButtonClicked(); break;
        case 15: _t->cancelButtonClicked(); break;
        case 16: _t->exitButtonClicked(); break;
        case 17: _t->sizeXspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->sizeYspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->sizeZspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->locationXspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->locationYspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->locationZspinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData createEnvironment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject createEnvironment::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_createEnvironment,
      qt_meta_data_createEnvironment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &createEnvironment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *createEnvironment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *createEnvironment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_createEnvironment))
        return static_cast<void*>(const_cast< createEnvironment*>(this));
    return QWidget::qt_metacast(_clname);
}

int createEnvironment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void createEnvironment::objectUpdated(vector_envObjectType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void createEnvironment::envName(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
