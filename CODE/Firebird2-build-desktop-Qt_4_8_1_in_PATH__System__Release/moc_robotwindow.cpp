/****************************************************************************
** Meta object code from reading C++ file 'robotwindow.h'
**
** Created: Fri Jun 27 13:01:54 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "/media/Local Disk/MTP/Firebird2/robotwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_robotWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      56,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     109,   12,   12,   12, 0x0a,
     134,   12,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     187,   12,   12,   12, 0x0a,
     215,   12,   12,   12, 0x0a,
     243,   12,   12,   12, 0x0a,
     273,   12,   12,   12, 0x0a,
     293,   12,   12,   12, 0x0a,
     315,   12,   12,   12, 0x0a,
     335,   12,   12,   12, 0x0a,
     360,   12,   12,   12, 0x0a,
     382,   12,   12,   12, 0x0a,
     406,  402,   12,   12, 0x0a,
     431,  429,   12,   12, 0x0a,
     466,  464,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_robotWindow[] = {
    "robotWindow\0\0robotObjectUpdated(vector_robotObjectType)\0"
    "roboName(string)\0timerSlot()\0"
    "newRobotButtonClicked()\0"
    "loadRobotButtonClicked()\0"
    "addMotorButtonClicked()\0"
    "addLineSensorButtonClicked()\0"
    "addIRPSensorButtonClicked()\0"
    "addIRDSensorButtonClicked()\0"
    "addSonarSensorButtonClicked()\0"
    "editButtonClicked()\0deleteButtonClicked()\0"
    "saveButtonClicked()\0saveRobotButtonClicked()\0"
    "cancelButtonClicked()\0exitButtonClicked()\0"
    "row\0currentRowChanged(int)\0d\0"
    "distanceSpinBoxValueChanged(int)\0c\0"
    "countSpinBoxValueChanged(int)\0"
};

void robotWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        robotWindow *_t = static_cast<robotWindow *>(_o);
        switch (_id) {
        case 0: _t->robotObjectUpdated((*reinterpret_cast< vector_robotObjectType(*)>(_a[1]))); break;
        case 1: _t->roboName((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->timerSlot(); break;
        case 3: _t->newRobotButtonClicked(); break;
        case 4: _t->loadRobotButtonClicked(); break;
        case 5: _t->addMotorButtonClicked(); break;
        case 6: _t->addLineSensorButtonClicked(); break;
        case 7: _t->addIRPSensorButtonClicked(); break;
        case 8: _t->addIRDSensorButtonClicked(); break;
        case 9: _t->addSonarSensorButtonClicked(); break;
        case 10: _t->editButtonClicked(); break;
        case 11: _t->deleteButtonClicked(); break;
        case 12: _t->saveButtonClicked(); break;
        case 13: _t->saveRobotButtonClicked(); break;
        case 14: _t->cancelButtonClicked(); break;
        case 15: _t->exitButtonClicked(); break;
        case 16: _t->currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->distanceSpinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->countSpinBoxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData robotWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject robotWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_robotWindow,
      qt_meta_data_robotWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &robotWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *robotWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *robotWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_robotWindow))
        return static_cast<void*>(const_cast< robotWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int robotWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void robotWindow::robotObjectUpdated(vector_robotObjectType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void robotWindow::roboName(string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
