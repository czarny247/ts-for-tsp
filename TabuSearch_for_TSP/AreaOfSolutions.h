#ifndef AREAOFSOLUTIONS_H
#define AREAOFSOLUTIONS_H
#include "Solution.h"
#include <set>

class AreaOfSolutions
{
private:
    std::set <Solution* > sSolutions;

public:
    AreaOfSolutions();
    void addSolution(Solution sol);
    Solution getSolution(int position);
};

#endif // AREAOFSOLUTIONS_H
