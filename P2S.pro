TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    src \
    test \
    dependencies \

OTHER_FILES += \
    .gitignore \
    .travis.yml \
    LICENSE \
