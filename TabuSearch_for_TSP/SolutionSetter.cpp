#include "SolutionSetter.h"

SolutionSetter::SolutionSetter()
{

}

void SolutionSetter::generateSolution(TSPgraph &graph)
{
    //1.point graph which will be used to generate solutions
    this->pointGraph(graph);

    //2.create area of solutions if there is no one
    if(pArea == nullptr) pArea = new AreaOfSolutions();

    //3.create solution
    pSol = new Solution();
    pSol->pointGraph(graph);
    std::cout << "Creating Solution (Manually).";
    int vnumber = 0;
    for (int v = 0; v<pGraph->getVertices(); ++v)
    {
        std::cout << "\nSet " << v+1 << " vertex [must be in <0;" << pGraph->getVertices() << ")]\n";
        std::cout << "> ";
        std::cin >> vnumber; //handle incorrect data type
        std::vector <Vertex* > ver = pSol->getVerticesVec();
        std::string vname = "Vertex " + std::to_string(vnumber);
        auto it = std::find_if(ver.begin(), ver.end(), [&vname](const Vertex* vert){return vert->getName() == vname;});
        if (it  == ver.end() && vnumber <pGraph->getVertices())
        {
            //prevent duplication of points in solution
            pSol->addPoint(vnumber); //point == vertex, maybe use one name?
        }
        else
        {
            std::cout << "Vertex " << vnumber << " is already in this solution or is not in <0;" << pGraph->getVertices() << ").\n";
            --v; //because it's not added to solution
        }
    }
    //add solution to area!
    //pSol->showSolution();
}
