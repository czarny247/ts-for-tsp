#ifndef SOLUTIONGENERATOR_H
#define SOLUTIONGENERATOR_H
#include "AreaOfSolutions.h"
#include <algorithm>

class SolutionGenerator
{
protected:
    std::string m_Name;
    AreaOfSolutions* pArea = nullptr;
    static TSPgraph* pGraph; //static because all of generators will make solutions in same graph
    Solution* pSol = nullptr;
public:
    virtual void generateSolution(TSPgraph& graph) = 0;
    bool checkPosition (int& pos);

    std::string getName() const;
    void setName(std::string name);
    void pointGraph(TSPgraph& graph);
};
#endif // SOLUTIONGENERATOR_H
