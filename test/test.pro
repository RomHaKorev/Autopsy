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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Compiler/release/ -lCompiler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Compiler/debug/ -lCompiler
else:unix: LIBS += -L$$OUT_PWD/../Compiler/ -lCompiler

INCLUDEPATH += $$PWD/../Compiler
DEPENDPATH += $$PWD/../Compiler
