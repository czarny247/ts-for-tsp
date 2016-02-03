#include "Solution.h"
#include <iostream>
#include "SolutionSetter.h"
#include "SolutionRndGen.h"
#include <QProcess>
#include <stdio.h>
#include <string>

std::string Solution::generationMode = "undefined"; //generation mode for all solutions
SolutionGenerator* Solution::globalGenerator = nullptr;
int Solution::SolutionsCounter = 0;

Solution::Solution()
    : m_Name("Solution" + std::to_string(SolutionsCounter)),
      m_TotalCost(0.0)
{
    SolutionsCounter++;
}

Solution::Solution(std::string name, TSPgraph* graph)
    : m_Name(name),
      m_TotalCost(0.0),
      pGraph(graph)
{
    //this->setUpSolution();
    SolutionsCounter++;
}

Solution::~Solution()
{
    for(int i=0; i<vVertices.size(); ++i)
    {
        if(vVertices[i]!=NULL)
        {
            //std::cout << vVertices.size() << std::endl;
            delete vVertices[i];
        }
    }

    //remember to dealocate pSg!
}

void Solution::pointGraph(TSPgraph& graph)
{
    pGraph=&graph;
}

void Solution::setName(std::string name)
{
    m_Name = name;
}

std::string Solution::getName() const
{
    return m_Name;
}
double Solution::getTotalCost() const
{
    return m_TotalCost;
}
void Solution::setTotalCost(double tcost)
{
    m_TotalCost = tcost;
}

void Solution::addPoint(int pos)
{
    Vertex* pVertex = nullptr;
    int graphSize = pGraph->getVerticesVec().size();
    if(pos < graphSize) //only addPoint if pos is inside vector - it will be checked in generator
    {
        pVertex = pGraph->getVerticesVec().at(pos);
        if(vVertices.size()==0) pVertex->setFirst(true);
        else pVertex->setFirst(false);
        pVertex->setVisited(true);
        vVertices.push_back(pVertex);
    }
}

void Solution::setUpSolution()
{
//    //1.Check if there is solution
//    if(SolutionsCounter>0)
//    {
//        if(generationMode != "undefined")
//        {
//           if(globalGenerator != nullptr) //will be only if generationMode is auto
//           {
//               //generate solution automatically
//               pSg = globalGenerator; //actual pSg is pSg of first solution
//               //pSg->generateSolution();

//           }
//           else
//           {
//               //generate solution manually
//               chooseGenerator();
//               pSg->generateSolution();
//           }
//        }
//        else generationMode = setGenerationMode();
//    }
//    else    //generate first solution
//    {
//        chooseGenerator();
//        pSg->generateSolution();
//        generationMode = setGenerationMode();
//        if(generationMode == "auto") setGlobalGenerator();
//    }
}

std::vector<Vertex *> &Solution::getVerticesVec()
{
    return vVertices;
}

bool Solution::operator == (const Solution& anotherSolution) const
{
    int sameVerticesCounter = 0;
    auto ti = anotherSolution.vVertices.begin();
    for(auto it = this->vVertices.begin(); it != this->vVertices.end(); it++)
    {
        if((*it)->getName() == (*ti)->getName()) sameVerticesCounter++;
        if(ti != anotherSolution.vVertices.end()) ti++;
    }

    if(anotherSolution.vVertices.size() == this->vVertices.size())
    {
        if(sameVerticesCounter == this->vVertices.size())
        {
            return true;
        }
        else return false;
    }
    else return false;
}

std::string Solution::setGenerationMode()
{
    std::string genMode = " ";
    std::cout << "Set generation mode: "
              << "(available options: auto - next solutions will be generated as first"
              << "|| manual - ask how to generate each solution)"
              << "\n> ";
    while(!( (std::cin  >> genMode) || (genMode == "auto") || (genMode == "manual")))
    {
        std::cout << "Incorrect data!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getchar();
        QProcess::execute("clear");
    }
    return genMode;
}

void Solution::chooseGenerator()
{
    std::string choice = " ";
    std::cout << "Choose generator for first solution: "
              << "(available options: manual || random)"
              << "\n> ";
    while(!( (std::cin  >> choice) || (choice == "random") || (choice == "manual")))
    {
        std::cout << "Incorrect data!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getchar();
        QProcess::execute("clear");
    }

    if(choice=="manual") pSg = new SolutionSetter();
    if(choice=="random") pSg = new SolutionRndGen();
}

void Solution::setGlobalGenerator()
{
    globalGenerator = pSg;
}

int Solution::getSolutionsCounter() const
{
    return SolutionsCounter;
}

std::string Solution::getGenerationMode() const
{
    return generationMode;
}

void Solution::showSolution() const
{
    size_t pos;
    std::string str;
    std::string vertex = "Vertex ";
    std::cout << this->m_Name << std::endl;
    std::cout << "(";
    for(auto it = vVertices.begin(); it != vVertices.end(); ++it)
    {
        pos = (*it)->getName().find("Vertex ");
        str = (*it)->getName().substr(pos+vertex.length()-1,3);
        std::cout << str;
        if(it != vVertices.end()-1) std::cout << ", ";
    }
    std::cout << ")\n";
}

bool Solution::operator< (const Solution &right) const
{
    return getTotalCost() < right.getTotalCost();
}
