TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    testsuite/assertions.cpp \
    testsuite/testresult.cpp \
    testsuite/testsuite.cpp \
    testsuite/notsamesizeexception.cpp
HEADERS += \
    testsuite/assertions.h \
    testsuite/notequalsexception.h \
    testsuite/testresult.h \
    testsuite/testsuite.h \
    testsuite/notsamesizeexception.h \
    testsuite/notequalsitemexception.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Compiler/release/ -lCompiler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Compiler/debug/ -lCompiler
else:unix: LIBS += -L$$OUT_PWD/../Compiler/ -lCompiler

INCLUDEPATH += $$PWD/../Compiler
DEPENDPATH += $$PWD/../Compiler
