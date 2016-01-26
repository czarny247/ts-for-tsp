#include "Edge.h"
#include <iostream>

int Edge::s_EdgesCounter =  0;

Edge::Edge()
    :m_Name("Edge "+std::to_string(s_EdgesCounter)),
     m_Value(0.0)
{
    ++s_EdgesCounter;
}

Edge::Edge(std::string name, float value)
    :m_Name(name),
     m_Value(value)
{
    ++s_EdgesCounter;
}

Edge::~Edge()
{
}

void Edge::setName(std::string name)
{
    m_Name = name;
}

void Edge::setValue(double value)
{
    m_Value = value;
}

float Edge::getValue() const
{
    return m_Value;
}

std::string Edge::getName() const
{
    return m_Name;
}
