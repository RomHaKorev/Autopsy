TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += -L$$PWD/../../thirdParty/lib/googletest/lib/ -lgtest

INCLUDEPATH += $$PWD/../../thirdParty/src/googletest/googletest/include/
DEPENDPATH += $$PWD/../../thirdParty/src/googletest/googletest/include/

LIBS += -L$$OUT_PWD/../Compiler/ -lCompiler

INCLUDEPATH += $$PWD/../Compiler
DEPENDPATH += $$PWD/../Compiler
