#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "Square.h"

class Tetrimino
{
protected:
	int m_type, m_direction;
	std::vector<Square> m_cases;
	enum {I, O, T, L, J, Z, S};

public:
	Tetrimino(void);
	Tetrimino(int type, int direction);
	~Tetrimino(void);

	Tetrimino& operator=(Tetrimino const& tetriminoToCopy);
	int getType(void);
	int getDirection(void);
	Square& getSquare(int x, int y);
	std::vector<Square>& getSquares(void);
	void setDirection(void);
	void setSquares(void);
};

#endif