#include "UI.h"
#include "SolutionRndGen.h"
#include "SolutionSetter.h"
#include <cstdlib>

void clear_screen() //should be somwhere else in future, because will be used in other classes
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::cout << "\033[2J\033[1;1H";
#endif
}

UI::UI()
{

}

UI::~UI()
{
    delete pParser;
    delete pHandler;
    delete pGraph;
    delete pSg;
}

void UI::mainLoop()
{
    //1.Create graph
    //2.Parse xml to graph
    //3.Choose generator
    //4.Create first solution
    //5.Choose generation mode
    //6.Generate rest

    pGraph = new TSPgraph(); //1
    parseToGraph(); //2
    chooseGenerator(); //3
    pSg->generateSolution((*pGraph));  //4
    //5 next method - generation mode is attached to first solution
    //how to access first solution - generator -> area -> solutions
}

void UI::parseToGraph()
{
    pParser = new QXmlSimpleReader();
    pHandler = new MyXmlContentHandler();

    pHandler->pointGraph((*pGraph));

    pParser->setContentHandler(pHandler);

    std::cout<<	"Starting parsing"<< std::endl;

        if(pParser->parse(new QXmlInputSource(new QFile("/home/mateusz/Pulpit/berlin52.xml"))))
        {
        std::cout<<"Parsed Successfully!"<< std::endl;
        }
        else
        {
        std::cout<<"Parsing Failed..."<< std::endl;
        }
    //handler->showParsedElements();
    pHandler->copyPEtoGraph();
    //pGraph->showTSPgraph();
}

void UI::chooseGenerator()
{
    std::string choice = " ";
    bool valid = false;
    do
    {
        std::cout << "Choose generator (available options: manual || random): "
                  << "\n> ";
        std::cin  >> choice;
        if((choice != "random") && (choice != "manual"))
        {
            std::cout << "Incorrect data!\n";
            std::cin.clear();
            std::cin.sync();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            valid = false;
        }
        else valid = true;
        std::getchar();
        clear_screen();
    } while(!valid);

    if(choice=="manual") pSg = new SolutionSetter();
    if(choice=="random") pSg = new SolutionRndGen();
}
