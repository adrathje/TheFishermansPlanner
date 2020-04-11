QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_plannertest.cpp \
        ../src/weather.cpp \
        ../src/fish.cpp \
        ../src/planner.cpp \
        ../src/boat.cpp \
        ../src/equipment.cpp \
        ../src/location.cpp \
        ../src/results.cpp
INCLUDEPATH += ../src

