#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>
#include "Edge.h"


class Vertex
{
private:
    std::string m_Name;
    static int s_VerticesCounter;
    std::vector <Edge*> vEdges;
    bool m_First; //first in solution
    bool m_Visited;

public:

    Vertex();
    Vertex(std::string name);
    ~Vertex();

    Vertex& operator=(const Vertex& other);

    void setName(std::string name);

    std::string getName() const;

    int getVerticesCounter() const;
    std::vector <Edge*>& getEdges();
    void addEdge(std::string name, double value);
    //void showEdges();

    bool getVisited() const;
    bool getFirst() const;

    void setVisited(bool visited);
    void setFirst(bool first);

};
#endif // VERTEX_H
