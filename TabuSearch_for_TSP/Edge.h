#ifndef EDGE_H
#define EDGE_H
#include <string>

class Edge
{
private:
    std::string m_Name; //defines to which vertex goes
    double m_Value;
    static int s_EdgesCounter;
    //add startVert and endVert to omit duplications - maybe duplications are useful?

public:
    Edge();
    Edge(std::string name, float value);
    ~Edge();

    void setName(std::string name);
    void setValue(double value);

    std::string getName() const;
    float getValue() const;
};

#endif // EDGE_H
