#ifndef SOLUTIONSETTER_H
#define SOLUTIONSETTER_H
#include "SolutionGenerator.h"

class SolutionSetter : public SolutionGenerator
{
private:

public:
    void generateSolution();
    void pointSolution (Solution& solution);
};


#endif // SOLUTIONSETTER_H
