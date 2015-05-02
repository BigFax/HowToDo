#include <iostream>
#include <ctime>
#include <windows.h>

#include "Map.h"
#include "Square.h"


using namespace std;

Map::Map(void) : m_sizeX(30), m_sizeY(23), m_topSide(0), m_bottomSide(0), m_leftSide(0), m_rightSide(9)
{
	m_cases = new Square * [m_sizeY];

	for(int y = 0 ; y < m_sizeY ; ++y) {
		m_cases[y] = new Square [m_sizeX];
		for(int x = 0 ; x < m_sizeX ; ++x) {
			m_cases[y][x].setCoordinates(x, y);
			if(
				((y == m_topSide || y == m_sizeY - 1) && x >= m_leftSide && x <= m_rightSide)//Horizontal side left square
					||
				((y == m_topSide || y == m_rightSide) && x >= m_rightSide + 2 && x <= m_sizeX)//Horizontal side rigth square
					||
				((x == m_leftSide || x == m_rightSide) && y >= m_topSide && y < m_sizeY)//Vertical side left square
					||
				((x == m_rightSide + 2 || x == m_sizeX - 1) && y >= m_topSide && y <= m_rightSide)//Vertical side right square
			  )
			{
				m_cases[y][x].setValue('#');
			} else {
				m_cases[y][x].setValue(' ');
			}
		}
	}
}


Map::~Map(void)
{
	for(int x = 0 ; x <= m_sizeX ; ++x) {
		delete[] m_cases[x];
	}
 
	delete[] m_cases;
}

int Map::getSizeX() { return m_sizeX; }
int Map::getSizeY() { return m_sizeY; }
int Map::getRightSide() { return m_rightSide; }
int Map::getLeftSide() { return m_leftSide; }
int Map::getTopSide() { return m_topSide; }
int Map::getBottomSide() { return m_bottomSide; }

Square Map::getSquare(int x, int y)
{
	if(x < m_sizeX && y < m_sizeY) {
		return m_cases[y][x];
	} else {
		exit(0);
	}
}

void Map::setSquare(Square& caseToCopy)
{
	m_cases[caseToCopy.getAxisY()][caseToCopy.getAxisX()] = caseToCopy;
}

void Map::setSquare(int x, int y, char value)
{
	m_cases[y][x].setCoordinates(x, y);
	m_cases[y][x].setValue(value);
}