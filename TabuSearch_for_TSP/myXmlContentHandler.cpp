#include "myXmlContentHandler.h"
#include <QtWidgets>
#include <iostream>
#include <sstream>

MyXmlContentHandler::MyXmlContentHandler():QXmlDefaultHandler()
{

}

MyXmlContentHandler::~MyXmlContentHandler()
{

}

bool MyXmlContentHandler::startElement(const QString& namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts)
{
    //std::cout << "Read Start Tag : " << localName.toStdString()<< std::endl;
    if(localName.toStdString()=="vertex")
    {
        std::vector<double> costs;
        parsedElements.push_back(costs);
        //std::cout << "parsed size: " << parsedElements.size() << std::endl;
    }
    if(localName.toStdString()=="edge")
    {
        //std::cout << "Tag Attributes: " << std::endl;
        for(int index = 0 ; index < atts.length();index++)
            {
              //std::cout << atts.type(index).toStdString()<< "="
              //<< atts.value(index).toStdString()<< std::endl;
              parsedElements.at(parsedElements.size()-1).push_back(atts.value(index).toDouble());
              //std::cout << "parsed.at(size-1) size: " << parsedElements.at(parsedElements.size()-1).size() << std::endl;
              //std::cout << parsedElements.at(parsedElements.size()-1).at(parsedElements.at(parsedElements.size()-1).size()-1) << std::endl;
            }
    }


    //std::cout << "------------------------" << std::endl;

    return true;
}

constexpr unsigned int MyXmlContentHandler::str2int(const char* str, int h) //maybe in other file? additional_functions or something like that USELESS NOW
{
    return !str[h] ? 5381 : (str2int(str, h+1)*33) ^ str[h];
}

//void MyXmlContentHandler::addToGraphFromXml(const QString& localName, QString value)
//{
//    std::string localNameStdString = localName.toStdString();
//    const char* lName = localNameStdString.c_str();
//    std::cout << "A" << std::endl;
//    switch (str2int(lName))
//    {
//    case str2int("vertex"):
//    {
//        pGraph->addVertex(Vertex());
//        std::cout << "vert" << std::endl;

//    }
//    break;
//    case str2int("edge"):
//    {
//        pGraph->getVerticesVec()[pGraph->getVertices()-1].addEdge(Edge("to "+std::to_string(pGraph->getVertices()-1),value.toFloat()),"to "+std::to_string(pGraph->getVertices()-1));
//        std::cout << "edge" << std::endl;
//    }
//    break;
//    default:
//        std::cout << "default" << std::endl;
//        break;
//    }
//    if(localNameStdString=="vertex")
//    {
//        std::cout << "vertex" <<std::endl;
//        pGraph->addVertex(Vertex());
//    }
//    else if(localNameStdString=="edge")
//    {
//        int actualVert = pGraph->getVertices()-1;
//        std::cout << actualVert << std::endl;
//        std::cout << " edge" <<std::endl;
//        std::cout << "  cost: " << value.toFloat() << std::endl;
//        Edge e ("to"+std::to_string(actualVert),value.toFloat());
//        pGraph->getVerticesVec().at(actualVert).addEdge(e);
//    }
//}

void MyXmlContentHandler::pointGraph(TSPgraph& graph)
{
    pGraph=&graph;
}

void MyXmlContentHandler::showParsedElements()
{
    for(std::vector<std::vector<int>>::size_type i=0; i < parsedElements.size(); ++i)
    {
        std::cout << "V[" << i << "]: " << std::endl;
        for(std::vector<std::vector<int>>::size_type j=0; j < parsedElements[i].size(); ++j)
        {
            std::cout << " *E[" << j << "]: " << "cost: " << parsedElements[i][j] << std::endl;
        }
    }
}

void MyXmlContentHandler::copyPEtoGraph()
{
    std::vector<std::vector<int>>::size_type s = 0; //set auxiliary variable to omit showing 'i to j' edges, where i==j, because it's wrong
    for(std::vector<std::vector<int>>::size_type i=0; i < parsedElements.size(); ++i)
    {
        Vertex* pVertex = nullptr;
        pGraph->addVertex();
        pVertex = pGraph->getVerticesVec().back();

        for(std::vector<std::vector<int>>::size_type j=0; j != i; ++j)
        {
            pVertex->addEdge("from"+std::to_string(i)+"to"+std::to_string(j),parsedElements.at(i).at(j));
            s=j;
        }

        if(s<parsedElements.at(i).size())
        {
            for(std::vector<std::vector<int>>::size_type t=s; t < parsedElements.at(i).size(); ++t)
            {
                if(i!=t+1)
                {
                    pVertex->addEdge("from"+std::to_string(i)+"to"+std::to_string(t+1),parsedElements.at(i).at(t));
                }
            }
        }
//        for(std::vector<std::vector<int>>::size_type j=0; j < parsedElements.at(i).size(); ++j)
//        {
//            if(i==j)
//            {

//                //std::cout << "i: " << i << "j: " << j << "t: " << t << std::endl;
//                //std::cout << i << "to" << t << ": "<< parsedElements.at(i).at(j) << std::endl;
//                pVertex->addEdge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j)/100);
//                //Edge edge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j));
//                //pGraph->addEdge(e); //try to bring edges back to vertex
//                //pVertex->addEdge(Edge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j)))
//            }
//            else
//            {
//                //Edge edge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j));
//                //pGraph->addEdge(edge);//try to bring edges back to vertex
//                //pVertex->addEdge(Edge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j)));
//                //std::cout << i << "to" << t << ": "<< parsedElements.at(i).at(j) << std::endl;
//                pVertex->addEdge("from"+std::to_string(i)+"to"+std::to_string(t),parsedElements.at(i).at(j)/100);
//            }
//        }

    }

    //relocate it later
    //ASSIGN EDGES TO VERTEX
//    for(auto it = pGraph->getVerticesVec().begin(); it != pGraph->getVerticesVec().end(); ++it)
//    {
//        size_t pos = it->getName().find("x");
//        ++pos;
//        std::string number = it->getName().substr(pos);
//        //std::cout << number << std::endl;
//        for(auto ti = pGraph->getEdges().begin(); ti != pGraph->getEdges().end(); ++ti)
//        {
//            std::size_t found = ti->getName().find("from "+number+" to ");
//            if(found != std::string::npos)
//            {
//                std::cout << ti->getName() << std::endl;
//                Edge* pEdge = &(*ti);
//                it->getPedges().push_back(pEdge);
//            }
//        }
//    }

//    for(std::vector<std::vector<int>>::size_type i=0; i < parsedElements.size(); ++i)
//    {
//        std::cout << "V[" << i << "]: " << std::endl;
//        Vertex v;
//        pGraph->addVertex(v);
//        for(std::vector<std::vector<int>>::size_type j=0; j < parsedElements[i].size(); ++j)
//        {
//            std::cout << " *E[" << j << "]: " << "cost: " << parsedElements[i][j] << std::endl;
//            std::string name = "";
//            int tmp = 0;
//            if(i==j)
//            {
//                tmp=j+1;
//                name = "to"+std::to_string(tmp);
//            }
//            Edge e(name,parsedElements[i][j]);
//            pGraph->getVerticesVec().at(i).addEdge(e);
//        }

}
