#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include "TSPgraph.h"
//#include "SolutionGenerator.h"

class SolutionGenerator;

class Solution
{
private:
    static std::string generationMode;
    static SolutionGenerator* globalGenerator;
    static int SolutionsCounter;

    std::string m_Name;
    std::vector <Vertex*> vVertices;
    double m_TotalCost;
    TSPgraph* pGraph = nullptr;
    SolutionGenerator* pSg = nullptr;

public:
    Solution();
    Solution(std::string name, TSPgraph* graph); //pSg will be assigned in method inside the constructor
    ~Solution();
    void pointGraph(TSPgraph& graph);
    void pointGenerator(SolutionGenerator& generator);
    void setName(std::string name);
    std::string getName() const;
    double getTotalCost() const;
    void setTotalCost(double tcost);
    void addPoint(int pos);
    void setUpSolution(); //solution will be setted in constructor not here or this method in constructor
    std::vector <Vertex*>& getVerticesVec();
    bool operator == (const Solution& anotherSolution) const; //useful for unordered_set
    std::string setGenerationMode();
    void chooseGenerator();
    void setGlobalGenerator();
    int getSolutionsCounter() const;
    std::string getGenerationMode() const;
    void showSolution() const;
    bool operator< (const Solution &right) const; //for set of solutions
};


#endif // SOLUTION_H
