#ifndef MYXMLCONTENTHANDLER_H
#define MYXMLCONTENTHANDLER_H
#include <QtXml>
#include "TSPgraph.h"
#include <vector>

class MyXmlContentHandler :public QXmlDefaultHandler
{
  public:
    MyXmlContentHandler();
    ~MyXmlContentHandler();

    bool startElement(const QString&namespaceURI, const QString& localName, const QString& qName, const QXmlAttributes& atts);
    void addToGraphFromXml(const QString& localName, QString value="none");
    static constexpr unsigned int str2int(const char* str, int h=0);

    void pointGraph(TSPgraph& graph);

    void showParsedElements();
    void copyPEtoGraph();

private:
    TSPgraph* pGraph=nullptr;
    std::vector <std::vector <double> > parsedElements;
};

#endif // MYXMLCONTENTHANDLER_H
