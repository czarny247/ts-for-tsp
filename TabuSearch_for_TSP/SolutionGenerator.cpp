#include "SolutionGenerator.h"

TSPgraph* SolutionGenerator::pGraph = nullptr;

bool SolutionGenerator::checkPosition (int& pos)
{

}

std::string SolutionGenerator::getName() const
{
    return m_Name;
}

void SolutionGenerator::setName(std::string name)
{
    m_Name = name;
}

void SolutionGenerator::pointGraph(TSPgraph& graph)
{
    pGraph=&graph;
}
