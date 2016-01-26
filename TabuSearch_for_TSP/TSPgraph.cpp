#include "TSPgraph.h"

//typedef std::vector <Vertex>::const_iterator VecIterator; - used 'auto' keyword instead of it

TSPgraph::TSPgraph()
    :m_Name("Default"),
     m_Vertices(0),
     m_Edges(0)
{
}

TSPgraph::TSPgraph(std::string name)
    :m_Name(name),
     m_Vertices(0),
     m_Edges(0)
{
}

TSPgraph::TSPgraph(std::string name, int vertices)
    :m_Name(name),
     m_Vertices(vertices)
{
}

TSPgraph::~TSPgraph()
{
    for(int i=0; i<Vertices.size(); ++i)
    {
        if(Vertices[i] != NULL)
        {
            //std::cout << Vertices.size() << std::endl;
            delete Vertices[i];
        }
    }
}

TSPgraph& TSPgraph::operator=(const TSPgraph& other)
{
    m_Vertices = other.m_Vertices;
    m_Edges = other.m_Edges;
    m_Name = other.m_Name;
    Vertices = other.Vertices;
    return *this;
}

void TSPgraph::setupTSPgraph(int vertices) //was used for tests
{
//    //create vertices
//    for(int vertex=0; vertex<vertices; ++vertex)
//    {
//        Vertices.emplace_back();
//    }

//    //create edges
//    for(auto it = Vertices.begin(); it != Vertices.end(); ++it)
//    {
//       for(int vertex=0; vertex<Vertices.size(); ++vertex)
//       {
//           std::string nameToCompare = "Vertex "+std::to_string(vertex);
//           if(nameToCompare!=it->getName()) //vertex can't create an edge to itself
//           {
//            //Edge e ("to"+std::to_string(vertex),0);
//            //it->addEdge(e);

//           }
//       }
//    }
    
//    //erase duplicate edges - unnecessary
//    for(auto it = Vertices.begin(); it != Vertices.end(); ++it)
//    {
//        for(int vertex=0; vertex<Vertices.size(); ++vertex)
//        {
//            //if(Vertices[vertex].edgeExist(it-Vertices.begin()))
//            {

//            }
//        }
//    }
}

int TSPgraph::getVertices() const
{
    return m_Vertices;
}

void TSPgraph::showTSPgraph()
{
    for(auto it = Vertices.begin(); it != Vertices.end(); ++it)
    {
        std::cout << (*it)->getName() << std::endl;

        for (auto ti = Vertices.at(it-Vertices.begin())->getEdges().begin(); ti != Vertices.at(it-Vertices.begin())->getEdges().end(); ++ti)
        {
            std::cout << (*ti)->getName() << ": " << (*ti)->getValue() << std::endl;
        }
    }



}

void TSPgraph::addVertex()
{
    Vertices.push_back(new Vertex());
    ++m_Vertices;
}

std::vector<Vertex *> &TSPgraph::getVerticesVec()
{
    return Vertices;
}


//void TSPgraph::showEdges() const
//{
//    std::cout << "Edges: " << std::endl;
//    std::cout << Edges.size() << std::endl;
//}
