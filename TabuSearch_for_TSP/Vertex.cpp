#include "Vertex.h"
#include <iostream>

//typedef std::map<std::string, Edge>::const_iterator MapIterator; - used 'auto' keyword instead of it

int Vertex::s_VerticesCounter = 0;

Vertex::Vertex()
    : m_Name("Vertex "+std::to_string(s_VerticesCounter))

{
    ++s_VerticesCounter;
}

Vertex::~Vertex()
{
    for(int i=0; i<vEdges.size(); ++i)
    {
        if(vEdges[i]!=NULL)
        {
            //std::cout << vEdges.size() << std::endl;
            delete vEdges[i];
        }
    }
}

Vertex& Vertex::operator =(const Vertex& other)
{
    m_Name = other.m_Name;
    return *this;
}

void Vertex::setName(std::string name)
{
    m_Name = name;
}

std::string Vertex::getName() const
{
    return m_Name;
}

int Vertex::getVerticesCounter() const
{
    return s_VerticesCounter;
}

//void Vertex::assignPedges(std::vector<Edge> edges)
//{
//    size_t pos = m_Name.find("x");
//    ++pos;
//    std::string number = m_Name.substr(pos);
//    std::cout << number << std::endl;
//    for(auto it = edges.begin(); it != edges.end(); ++it)
//    {
//        std::size_t found = it->getName().find("from "+number+" to ");
//        if(found != std::string::npos)
//        {
//            std::cout << it->getName() << std::endl;
//            Edge* pEdge = &(*it);
//            pEdges.push_back(pEdge);
//        }
//    }
//}

std::vector<Edge *> &Vertex::getEdges()
{
    return vEdges;
}

void Vertex::addEdge(std::string name, double value)
{
    vEdges.push_back(new Edge(name,value));
}

//void Vertex::showPedges()
//{
//    for(auto it = pEdges.begin(); it != pEdges.end(); ++it)
//    {
//        std::cout << (*it)->getName() << ": " << (*it)->getValue() << std::endl;
//    }
//}

bool Vertex::getVisited() const
{
    return m_Visited;
}

bool Vertex::getFirst() const
{
    return m_First;
}

void Vertex::setVisited(bool visited)
{
    m_Visited = visited;
}

void Vertex::setFirst(bool first)
{
    m_First = first;
}
