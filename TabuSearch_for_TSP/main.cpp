#include <iostream>
#include "TSPgraph.h"
#include "Vertex.h"
#include "Edge.h"
#include "myXmlContentHandler.h"
#include "UI.h"

using namespace std;

int main()
{
////    TSPgraph g1("Sample TSPgraph",3);
////    g1.setupTSPgraph(g1.getVertices());
////    g1.showTSPgraph();

//    //make parsing internally? where?
//    QXmlSimpleReader* parser = new QXmlSimpleReader();
//    MyXmlContentHandler* handler = new MyXmlContentHandler();

//    TSPgraph graph("Sample TSPgraph");
//    handler->pointGraph(graph);

//    parser->setContentHandler(handler);

//    std::cout<<	"Starting parsing"<< std::endl;

//        if(parser->parse(new QXmlInputSource(new QFile("/home/mateusz/Pulpit/berlin52.xml"))))
//        {
//        std::cout<<"Parsed Successfully!"<< std::endl;
//        }
//        else
//        {
//        std::cout<<"Parsing Failed..."<< std::endl;
//        }
//    //handler->showParsedElements();
//    //handler->copyPEtoGraph();
//    //graph.showTSPgraph();
    UI ui;

    ui.mainLoop();

    return 0;
}

