#ifndef SOLUTIONGENERATOR_H
#define SOLUTIONGENERATOR_H
#include "Solution.h"

//enum class WayOfGenerate {SET,RAND}; //only 2 but can implement more later

class SolutionGenerator
{
protected:
    Solution* pSol = nullptr; //maybe solutions container instead of pointer

public:
    virtual void generateSolution();
    void pointSolution (Solution& solution); //to edit
    bool checkPosition (int& pos);

};
#endif // SOLUTIONGENERATOR_H
