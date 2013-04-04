/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 4. Apr 06:59:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      58,   51,   11,   11, 0x08,
      96,   85,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     247,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     306,  298,   11,   11, 0x08,
     331,  298,   11,   11, 0x08,
     354,  298,   11,   11, 0x08,
     383,  377,   11,   11, 0x08,
     412,   11,   11,   11, 0x08,
     450,  443,   11,   11, 0x08,
     472,  468,   11,   11, 0x08,
     487,  298,   11,   11, 0x08,
     516,  510,   11,   11, 0x08,
     549,   11,   11,   11, 0x08,
     591,   11,   11,   11, 0x08,
     632,   11,   11,   11, 0x08,
     657,   11,   11,   11, 0x08,
     698,  693,   11,   11, 0x08,
     745,  693,   11,   11, 0x08,
     792,  693,   11,   11, 0x08,
     836,  693,   11,   11, 0x08,
     880,  693,   11,   11, 0x08,
     923,  693,   11,   11, 0x08,
     966,  693,   11,   11, 0x08,
    1011,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0quit()\0timeout()\0"
    "on_Startlog_clicked()\0string\0"
    "insertTextConsola(QString)\0tipo,value\0"
    "newParamValue(Tipo_Param,float)\0"
    "on_boton_ruta_clicked()\0on_boton_home_clicked()\0"
    "on_reset_button_clicked()\0"
    "on_pushButton_armarDesarmarMotores_clicked()\0"
    "on_dialYaw_sliderPressed()\0"
    "on_boton_view_clicked()\0lat,lng\0"
    "addWaypoint(float,float)\0"
    "setHome(double,double)\0setView(double,double)\0"
    "value\0on_dialYaw_valueChanged(int)\0"
    "dialYaw_valueChanged_timeout()\0altura\0"
    "newAltura(double)\0yaw\0newYaw(double)\0"
    "setGoto(double,double)\0index\0"
    "on_tabWidget_currentChanged(int)\0"
    "on_verticalSlider_altura_sliderReleased()\0"
    "on_verticalSlider_altura_sliderPressed()\0"
    "timerSetAltura_timeout()\0"
    "on_pushButton_read_params_clicked()\0"
    "arg1\0on_doubleSpinBox_altura_P_valueChanged(double)\0"
    "on_doubleSpinBox_altura_D_valueChanged(double)\0"
    "on_doubleSpinBox_yaw_P_valueChanged(double)\0"
    "on_doubleSpinBox_yaw_D_valueChanged(double)\0"
    "on_doubleSpinBox_XY_P_valueChanged(double)\0"
    "on_doubleSpinBox_XY_D_valueChanged(double)\0"
    "on_doubleSpinBox_altura_valueChanged(double)\0"
    "on_pushButton_casa_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->timeout(); break;
        case 2: _t->on_Startlog_clicked(); break;
        case 3: _t->insertTextConsola((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->newParamValue((*reinterpret_cast< Tipo_Param(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->on_boton_ruta_clicked(); break;
        case 6: _t->on_boton_home_clicked(); break;
        case 7: _t->on_reset_button_clicked(); break;
        case 8: _t->on_pushButton_armarDesarmarMotores_clicked(); break;
        case 9: _t->on_dialYaw_sliderPressed(); break;
        case 10: _t->on_boton_view_clicked(); break;
        case 11: _t->addWaypoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 12: _t->setHome((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 13: _t->setView((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 14: _t->on_dialYaw_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->dialYaw_valueChanged_timeout(); break;
        case 16: _t->newAltura((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->newYaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->setGoto((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 19: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_verticalSlider_altura_sliderReleased(); break;
        case 21: _t->on_verticalSlider_altura_sliderPressed(); break;
        case 22: _t->timerSetAltura_timeout(); break;
        case 23: _t->on_pushButton_read_params_clicked(); break;
        case 24: _t->on_doubleSpinBox_altura_P_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->on_doubleSpinBox_altura_D_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->on_doubleSpinBox_yaw_P_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->on_doubleSpinBox_yaw_D_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->on_doubleSpinBox_XY_P_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->on_doubleSpinBox_XY_D_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->on_doubleSpinBox_altura_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->on_pushButton_casa_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
