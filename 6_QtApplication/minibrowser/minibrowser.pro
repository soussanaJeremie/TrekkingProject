TEMPLATE = app
TARGET = minibrowser

QT += qml quick webview sql network\
    positioning core widgets

SOURCES += cpp/main.cpp \
    cpp/mycontext.cpp \
    cpp/utils.cpp \
    cpp/trek.cpp \
    cpp/gpspoint.cpp \
    cpp/filemanager.cpp \
    cpp/user.cpp \
    cpp/photo.cpp \
    cpp/httpserver.cpp \
    cpp/debugclass.cpp

RESOURCES += qml.qrc

EXAMPLE_FILES += doc

macos:QMAKE_INFO_PLIST = macos/Info.plist
ios:QMAKE_INFO_PLIST = ios/Info.plist

target.path = $$[QT_INSTALL_EXAMPLES]/webview/minibrowser
INSTALLS += target

HEADERS += \
    cpp/mycontext.h \
    cpp/utils.h \
    cpp/trek.h \
    cpp/gpspoint.h \
    cpp/filemanager.h \
    cpp/user.h \
    cpp/photo.h \
    cpp/httpserver.h \
    cpp/debugclass.h
