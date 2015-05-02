#include "Square.h"

using namespace std;

Square::Square(void)
{
}

Square::Square(int x, int y, char value) : m_axisX(x), m_axisY(y), m_value(value)
{
}


Square::~Square(void)
{

}

Square& Square::operator=(Square const& caseToCopy) 
{
    if(this != &caseToCopy)
    {
	    m_axisX = caseToCopy.m_axisX;
		m_axisY = caseToCopy.m_axisY;
		m_value = caseToCopy.m_value;
    }

    return *this;
}

int Square::getAxisX(void){ return m_axisX; }
int Square::getAxisY(void) { return m_axisY; }
char Square::getValue() { return m_value; }

void Square::setCoordinates(int x, int y)
{
	m_axisX = x;
	m_axisY = y;
}

void Square::setValue(char value)
{
	m_value = value;
}

bool Square::isEqual(Square const& case2) const
{
	if(m_axisX == case2.m_axisX && m_axisY == case2.m_axisY && m_value == case2.m_value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(Square const& case1, Square const& case2)
{
	if(case1.isEqual(case2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
