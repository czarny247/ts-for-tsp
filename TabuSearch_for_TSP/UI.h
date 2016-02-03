#ifndef UI_H
#define UI_H
#include "TSPgraph.h"
#include "SolutionGenerator.h"
#include "myXmlContentHandler.h"
#include "iostream"

class UI
{

private:
    TSPgraph* pGraph = nullptr;
    SolutionGenerator* pSg = nullptr;
    MyXmlContentHandler* pHandler = nullptr;
    QXmlSimpleReader* pParser = nullptr;

public:
    UI();
    ~UI();
    void mainLoop();
    void parseToGraph();
    void chooseGenerator();

};

#endif // UI_H
