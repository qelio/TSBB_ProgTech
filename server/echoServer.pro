QT -= gui # Сервер консольный, отключение графического интерфейса

QT += network # Для работы с сетью

QT += sql

# Автоматически генерируемая конфигурация, задает используемый компилятор
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

DEFINES += QT_DEPRECATED_WARNINGS # Игнорирование warnings (то есть, если есть warnings, то проект все равно запустится)

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Здесь необходимо написать все файлы .cpp (если добавляем файл вручную или переименовываем - необходимо внести изменения)
SOURCES += \
    aes.cpp \
    database.cpp \
    dichotomymethod.cpp \
    dijkstra.cpp \
    functionserver.cpp \
    main.cpp \
    mytcpserver.cpp \
    sha512.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Здесь необходимо написать все заголовочные файлы .h (если добавляем файл вручную или переименовываем - необходимо внести изменения)
HEADERS += \
    aes.h \
    database.h \
    dichotomymethod.h \
    dijkstra.h \
    functionserver.h \
    mytcpserver.h \
    sha512.h

FORMS +=
