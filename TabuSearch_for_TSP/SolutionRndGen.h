#ifndef SOLUTIONRNDGEN_H
#define SOLUTIONRNDGEN_H
#include "SolutionGenerator.h"

class SolutionRndGen : public SolutionGenerator
{
public:
    SolutionRndGen();
    void generateSolution(TSPgraph& graph);
};

#endif // SOLUTIONRNDGEN_H
