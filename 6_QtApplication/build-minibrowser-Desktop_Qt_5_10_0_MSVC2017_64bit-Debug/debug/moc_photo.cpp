/****************************************************************************
** Meta object code from reading C++ file 'photo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../minibrowser/cpp/photo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Photo_t {
    QByteArrayData data[11];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Photo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Photo_t qt_meta_stringdata_Photo = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Photo"
QT_MOC_LITERAL(1, 6, 12), // "titleChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "title"
QT_MOC_LITERAL(4, 26, 10), // "urlChanged"
QT_MOC_LITERAL(5, 37, 3), // "url"
QT_MOC_LITERAL(6, 41, 19), // "privatePhotoChanged"
QT_MOC_LITERAL(7, 61, 12), // "privatePhoto"
QT_MOC_LITERAL(8, 74, 8), // "setTitle"
QT_MOC_LITERAL(9, 83, 6), // "setUrl"
QT_MOC_LITERAL(10, 90, 15) // "setPrivatePhoto"

    },
    "Photo\0titleChanged\0\0title\0urlChanged\0"
    "url\0privatePhotoChanged\0privatePhoto\0"
    "setTitle\0setUrl\0setPrivatePhoto"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Photo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void Photo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Photo *_t = static_cast<Photo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->urlChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->privatePhotoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->setPrivatePhoto((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Photo::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Photo::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Photo::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Photo::urlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Photo::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Photo::privatePhotoChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Photo *_t = static_cast<Photo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->url(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->privatePhoto(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Photo *_t = static_cast<Photo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setUrl(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPrivatePhoto(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Photo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Photo.data,
      qt_meta_data_Photo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Photo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Photo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Photo.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Photo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Photo::titleChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Photo::urlChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Photo::privatePhotoChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
