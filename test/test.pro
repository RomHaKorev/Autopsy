TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../thirdParty/build-googletest-Desktop_Qt_5_12_7_MinGW_64_bit-Release/lib/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../thirdParty/build-googletest-Desktop_Qt_5_12_7_MinGW_64_bit-Release/lib/ -lgtest

INCLUDEPATH += $$PWD/../../thirdParty/googletest/googletest/include
DEPENDPATH += $$PWD/../../thirdParty/googletest/googletest/include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Compiler/release/ -lCompiler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Compiler/debug/ -lCompiler
else:unix: LIBS += -L$$OUT_PWD/../Compiler/ -lCompiler

INCLUDEPATH += $$PWD/../Compiler
DEPENDPATH += $$PWD/../Compiler
