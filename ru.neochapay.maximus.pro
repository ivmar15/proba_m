TEMPLATE = subdirs

SUBDIRS = libs src_sailfish
CONFIG += ordered

OTHER_FILES += \
    LICENSE \
    README.md \
    rpm/*.spec
