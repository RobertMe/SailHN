# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = SailHN

CONFIG += sailfishapp

SOURCES += src/SailHN.cpp \
    src/hnmodel.cpp \
    src/topstories.cpp \
    src/hnmodelitem.cpp \
    src/hnconnection.cpp \
    src/hnlimitmodel.cpp

OTHER_FILES += qml/SailHN.qml \
    qml/cover/CoverPage.qml \
    rpm/SailHN.changes.in \
    rpm/SailHN.spec \
    rpm/SailHN.yaml \
    translations/*.ts \
    SailHN.desktop \
    qml/pages/TopStoriesPage.qml \
    qml/pages/BrowserPage.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
#TRANSLATIONS += translations/SailHN-de.ts

HEADERS += \
    src/hnmodel.h \
    src/topstories.h \
    src/hnmodelitem.h \
    src/hnconnection.h \
    src/hnlimitmodel.h

