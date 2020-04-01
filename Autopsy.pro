TEMPLATE = subdirs

SUBDIRS += \
    App \
    Compiler \
    test

test.depends = Compiler
App.depends = Compiler