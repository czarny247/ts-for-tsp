#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include "TSPgraph.h"
//#include "SolutionGenerator.h"

class SolutionGenerator;

class Solution
{
private:
    std::string m_Name;
    std::vector <Vertex*> vVertices;
    double m_TotalCost;
    TSPgraph* pGraph = nullptr;
    SolutionGenerator* pSg = nullptr;

public:
    Solution();
    Solution(std::string name);
    ~Solution();
    void pointGraph(TSPgraph& graph);
    void pointGenerator(SolutionGenerator& generator);
    void setName(std::string name);
    std::string getName() const;
    double getTotalCost() const;
    void setTotalCost(double tcost);
    void addPoint(int pos);
    void setUpSolution();
    std::vector <Vertex*>& getVerticesVec();
};


#endif // SOLUTION_H
