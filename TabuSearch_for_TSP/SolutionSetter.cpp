#include "SolutionSetter.h"


void SolutionSetter::generateSolution()
{
    int position = 0;
    //add startpoint
    std::cout << "Generating solution manually." <<std::endl;
    std::cout << "Set starting point's position: ";
    std::cin >> position; //check for errors
    pSol->addPoint(position);
}

void pointSolution (Solution& solution);
