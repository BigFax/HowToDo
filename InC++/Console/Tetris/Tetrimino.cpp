#include <vector>
#include "Tetrimino.h"
#include "Square.h"
#include "Game.h"

using namespace std;

Tetrimino::Tetrimino(void)
{
}

Tetrimino::Tetrimino(int type, int direction)
{
	m_type = type;
	m_direction = direction;
	int i = 0;

	if(m_type == I) {
		for (i = 3 ; i <= 6 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
	} else if(m_type == O) {
		for (i = 4 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		for (i = 4 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 2, 'O'));
	} else if(m_type == T) {
		for (i = 3 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		m_cases.push_back(Square(4, 2, 'O'));
	} else if(m_type == L) {
		for (i = 3 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		m_cases.push_back(Square(3, 2, 'O'));
	} else if(m_type == J) {
		for (i = 3 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		m_cases.push_back(Square(5, 2, 'O'));
	} else if(m_type == Z) {
		for (i = 3 ; i <= 4 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		for (i = 4 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 2, 'O'));
	} else if(m_type == S) {
		for (i = 4 ; i <= 5 ; ++i)
			m_cases.push_back(Square(i, 1, 'O'));
		for (i = 3 ; i <= 4 ; ++i)
			m_cases.push_back(Square(i, 2, 'O'));
	} else {
		Game::display("exit");
		exit(0);
	}
}


Tetrimino::~Tetrimino(void)
{
}

Tetrimino& Tetrimino::operator=(Tetrimino const& tetriminoToCopy) 
{
    if(this != &tetriminoToCopy)
    {
	    m_type = tetriminoToCopy.m_type;
		m_direction = tetriminoToCopy.m_direction;
		m_cases = tetriminoToCopy.m_cases;
    }

    return *this;
}

int Tetrimino::getType(void) { return m_type; }
int Tetrimino::getDirection(void) { return m_direction; }
Square& Tetrimino::getSquare(int x, int y) { 
	for(int i = 0 ; i < m_cases.size() ; ++i)
	{
		if(m_cases[i].getAxisX == x && m_cases[i].getAxisY())
			return m_cases[i];
	}
}
vector<Square>& Tetrimino::getSquares(void) { return m_cases; }

void Tetrimino::setDirection(void)
{
	m_direction++;
	if(m_direction == 5)
		m_direction = 1;
	setSquares();
}

void Tetrimino::setSquares(void)
{
	if(m_type == I) {
		if (m_direction == 1 || m_direction == 3) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 2, m_cases[3].getAxisY() - 2);
		} else if (m_direction == 2 || m_direction == 4) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 2, m_cases[3].getAxisY() + 2);
		}
	} else if(m_type == O) {
		//Nothing to do
	} else if(m_type == T) {
		if (m_direction == 1) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 1, m_cases[3].getAxisY() + 1);
		} else if (m_direction == 2) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 1, m_cases[3].getAxisY() - 1);
		} else if (m_direction == 3) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 1, m_cases[3].getAxisY() - 1);
		} else if (m_direction == 4) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 1, m_cases[3].getAxisY() + 1);
		}
	} else if(m_type == L) {
		if (m_direction == 1) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 2, m_cases[3].getAxisY());
		} else if (m_direction == 2) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX(), m_cases[3].getAxisY() - 2);
		} else if (m_direction == 3) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 2, m_cases[3].getAxisY());
		} else if (m_direction == 4) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX(), m_cases[3].getAxisY() + 2);
		}
	} else if(m_type == J) {
		if (m_direction == 1) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX(), m_cases[3].getAxisY() + 2);
		} else if (m_direction == 2) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 2, m_cases[3].getAxisY());
		} else if (m_direction == 3) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX(), m_cases[3].getAxisY() - 2);
		} else if (m_direction == 4) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 2, m_cases[3].getAxisY());
		}
	} else if(m_type == Z) {
		if (m_direction == 1 || m_direction == 3) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() - 1, m_cases[0].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 1, m_cases[2].getAxisY() + 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 2, m_cases[3].getAxisY());
		} else if (m_direction == 2 || m_direction == 4) {
			m_cases[0].setCoordinates(m_cases[0].getAxisX() + 1, m_cases[0].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 1, m_cases[2].getAxisY() - 1);
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 2, m_cases[3].getAxisY());
		}
	} else if(m_type == S) {
		if (m_direction == 1 || m_direction == 3) {
			m_cases[1].setCoordinates(m_cases[1].getAxisX() + 1, m_cases[1].getAxisY() + 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() - 2, m_cases[2].getAxisY());
			m_cases[3].setCoordinates(m_cases[3].getAxisX() - 1, m_cases[3].getAxisY() + 1);
		} else if (m_direction == 2 || m_direction == 4) {
			m_cases[1].setCoordinates(m_cases[1].getAxisX() - 1, m_cases[1].getAxisY() - 1);
			m_cases[2].setCoordinates(m_cases[2].getAxisX() + 2, m_cases[2].getAxisY());
			m_cases[3].setCoordinates(m_cases[3].getAxisX() + 1, m_cases[3].getAxisY() - 1);
		}
	} else {
		Game::display("exit");
		exit(0);
	}
}

	