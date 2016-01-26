#include "Solution.h"

Solution::Solution()
    : m_Name("default solution"),
      m_TotalCost(0.0)
{

}

Solution::Solution(std::string name)
    : m_Name(name),
      m_TotalCost(0.0)
{

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
    if(pos < pGraph->getVerticesVec().size()) //only addPoint if pos is inside vector - it will be checked in generator
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

    //set starting point
}

std::vector<Vertex *> &Solution::getVerticesVec()
{
    return Vertices;
}
