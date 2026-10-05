TARGET = ru.neochapay.maximus

CONFIG += sailfishapp
CONFIG += link_pkgconfig
PKGCONFIG += sailfishapp

INCLUDEPATH += ../libs/qmsgpack \
               ../libs/qtwebsockets5 \
               ../libs/qmaxmessenger \
               ../libs/libqwebp

LIBS += -L../libs/qmsgpack -lqmsgpack \
        -L../libs/qtwebsockets5 -lqtwebsockets \
        -L../libs/qmaxmessenger -lqmaxmessenger \
        -L../libs/libqwebp -lqwebp \
        -L../libs/libwebp -lwebp

SOURCES += \
    emojimodel.cpp \
    main.cpp

RESOURCES += qml.qrc

HEADERS += \
    emojimodel.h

DISTFILES += \
    qml/* \
    qml/pages/* \
    qml/cover/* \
    qml/js/* \
    qml/components/* \
    qml/emojiSvgs/* \
    translations/*

TRANSLATIONS += \
    translations/ru.neochapay.maximus.ts \
    translations/ru.neochapay.maximus-ru.ts

target.path = /usr/bin
INSTALLS += target
