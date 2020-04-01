TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../thirdParty/lib/googletest/lib/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../thirdParty/lib/googletest/lib/ -lgtestd
else:unix: LIBS += -L$$PWD/../../thirdParty/lib/googletest/lib/ -lgtest


INCLUDEPATH += $$PWD/../../thirdParty/src/googletest/googletest/include/
DEPENDPATH += $$PWD/../../thirdParty/src/googletest/googletest/include/

LIBS += -L$$OUT_PWD/../Compiler/ -lCompiler

INCLUDEPATH += $$PWD/../Compiler
DEPENDPATH += $$PWD/../Compiler
