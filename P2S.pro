TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    dependencies \
    src \
    test \

OTHER_FILES += \
    .gitignore \
    .travis.yml \
    Dockerfile \
    LICENSE \
