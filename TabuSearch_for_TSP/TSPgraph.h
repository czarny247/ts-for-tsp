#ifndef TSPGRAPH_H
#define TSPGRAPH_H
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <string>
#include <iostream>
#include <QtXml/QXmlSimpleReader>

class TSPgraph //maybe allow to create only one graph? -> do it later
{
private:
    std::string m_Name;
    int m_Vertices;
    int m_Edges;
    std::vector <Vertex*> Vertices; //maybe store pointers? CHANGE name to v_Vertices


public:
    TSPgraph();
    TSPgraph(std::string name);
    TSPgraph(std::string name, int vertices);
    ~TSPgraph();

    TSPgraph& operator=(const TSPgraph& other); //make it private if allowing to create only one graph and make private ctors (copy ctor!)

    void setupTSPgraph(int vertices); //for creating graph without loading data from .xml file
    void showTSPgraph();
    void addVertex();
    //void loadFromXml(std::string path);

    int getVertices() const;
    std::vector <Vertex*>& getVerticesVec();
    //void showEdges() const; maybe usueful later?
};

#endif // TSPGRAPH_H
