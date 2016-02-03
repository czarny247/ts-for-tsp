#ifndef SOLUTIONSETTER_H
#define SOLUTIONSETTER_H
#include "SolutionGenerator.h"

class SolutionSetter : public SolutionGenerator
{
private:

public:
    SolutionSetter();
    void generateSolution(TSPgraph& graph);
};


#endif // SOLUTIONSETTER_H
