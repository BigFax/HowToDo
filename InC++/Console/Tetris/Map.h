#ifndef MAP_H
#define MAP_H

#include "Square.h"

class Map
{
protected:
	const int m_sizeX, m_sizeY; //All the map (playground + score...)
	const int m_topSide, m_bottomSide, m_rightSide, m_leftSide; //Playground
	Square **m_cases;

public:
	Map(void);
	~Map(void);

	int getSizeX();
	int getSizeY();
	int getRightSide();
	int getLeftSide();
	int getTopSide();
	int getBottomSide();
	Square getSquare(int sizeX, int sizeY);
	void setSquare(Square& caseToCopy);
	void setSquare(int x, int y, char value);
};

#endif