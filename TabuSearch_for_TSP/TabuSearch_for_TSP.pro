TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
CONFIG += c++11

SOURCES += main.cpp \
    Vertex.cpp \
    Edge.cpp \
    TSPgraph.cpp \
    myXmlContentHandler.cpp \
    Solution.cpp \
    SolutionSetter.cpp \
    SolutionGenerator.cpp \
    SolutionRndGen.cpp \
    UI.cpp \
    AreaOfSolutions.cpp

HEADERS += \
    TSPgraph.h \
    Vertex.h \
    Edge.h \
    myXmlContentHandler.h \
    Solution.h \
    SolutionGenerator.h \
    SolutionSetter.h \
    SolutionRndGen.h \
    UI.h \
    AreaOfSolutions.h

QT += xml
QT += widgets

