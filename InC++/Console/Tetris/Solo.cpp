#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <vector>
#include <conio.h>
#include "Solo.h"
#include "Map.h"
#include "Tetrimino.h"

using namespace std;

Solo::Solo(void)
{
	m_rollOn = true;
	m_time = 0;
	m_timePastTetrimino = 0;
	m_timePastInput = 0;
	m_speed = 250;
	m_acceleration = 3;
	m_downActive = true;
	m_linesToShift = 0;
	m_direction = 5;
	m_count = 0;
	m_score = "0";
	newTetrimino();
	m_tetriminoActive = true;
	m_scores[0] = 40;
	m_scores[1] = 100;
	m_scores[2] = 300;
	m_scores[3] = 1200;
}


Solo::~Solo(void)
{

}


void Solo::newTetrimino()
{
	int random1 = random(7);
	m_tetriminos.push_back(Tetrimino(random1, 1));

	rollOn();

	m_tetriminoTemp = m_tetriminos.back();
	m_tetriminoActive = true;
}

int Solo::random(int number)
{
	// Random beetween 1 and number
	srand ((unsigned int) time(NULL));
	return (rand() % number);
}

void Solo::setTetrimino(Tetrimino &tetrimino, char value)
{
	for(size_t i = 0 ; i < tetrimino.getSquares().size() ; ++i)
	{
		tetrimino.getSquares()[i].setValue(value);
		m_map.setSquare(tetrimino.getSquares()[i]);
	}
}

void Solo::start(void)
{
	while(m_rollOn)
	{
		m_time = GetTickCount();
		if((m_time - m_timePastInput) >= m_speed / 2) {
			input();
			update();
			display();
			if((m_time - m_timePastTetrimino) >= m_speed) {
				move(m_direction = DOWN);
				update();
				display();
				m_timePastTetrimino = m_time;
			}
			m_timePastInput = m_time;
		}
	}
}

void Solo::update(void)
{
	if(!m_tetriminoActive)
		newTetrimino();

	updateMap();
	updateScore();

	m_rollOn = true;
}

void Solo::seeInfos(void)
{
	system("cls");
	display();
	cout << "Map :" << endl;
	for(int i = 16 ; i < 22 ; i++) {
		cout << " " << 1 << " / " << i << " " << m_map.getSquare(1, i).getValue() << endl
			 << " " << 2 << " / " << i << " " << m_map.getSquare(2, i).getValue() << endl
			 << " " << 3 << " / " << i << " " << m_map.getSquare(3, i).getValue() << endl
		     << " " << 4 << " / " << i << " " << m_map.getSquare(4, i).getValue() << endl
			 << " " << 5 << " / " << i << " " << m_map.getSquare(5, i).getValue() << endl
			 << " " << 6 << " / " << i << " " << m_map.getSquare(6, i).getValue() << endl
			 << " " << 7 << " / " << i << " " << m_map.getSquare(7, i).getValue() << endl
			 << " " << 8 << " / " << i << " " << m_map.getSquare(8, i).getValue() << endl
		     << endl << endl;
	}
	
	cout << "Tetrimino :" << endl;
	for(size_t i = 0 ; i < m_tetriminos.back().getSquares().size() ; ++i)
	{
		cout << " " << m_tetriminos.back().getSquares()[i].getAxisX() << " / " << m_tetriminos.back().getSquares()[i].getAxisY() << " "  << m_tetriminos.back().getSquares()[i].getValue()
		     << endl;
	}

}

void Solo::updateMap(void)
{
	collisions();
	for(size_t i = 0 ; i < m_tetriminos.back().getSquares().size() ; ++i)
	{
		m_map.setSquare(m_tetriminos.back().getSquares()[i]);
	}
}

void Solo::updateScore(void)
{
	/*int x = m_map.getSizeX() - 3, y = 2;
	for (int i = 0 ; i < m_score.size() ; ++i)
	{
		m_map.setSquare(x, y, m_score[i]);
		x--;
	}
	m_linesToShift = 0;*/
}

/**
* \brief	Detect tetriminos' collisions.
*			Look at all squares of the temporary tetrimino to check if they are in collision with squares not empty (tetriminos & sides) already on the map.
*			Two collision's type : continue to fall / stop to fall. 
*/
void Solo::collisions(void)
{
	bool collisions = false, continueToFall = false;
	char value = '/0';
	setTetrimino(m_tetriminos.back(), ' ');

	// Loop : Check all squares of the temporary tetrimino.
	for(size_t i = 0 ; i < m_tetriminoTemp.getSquares().size() ; ++i)
	{
		value = m_map.getSquare(m_tetriminoTemp.getSquares()[i].getAxisX(), m_tetriminoTemp.getSquares()[i].getAxisY()).getValue();
		if(value == '#' || (value == 'O'))
		{
			collisions = true;
			if(m_tetriminoTemp.getSquares()[i].getAxisY() <= m_map.getTopSide() || m_tetriminoTemp.getSquares()[i].getAxisX() <= m_map.getLeftSide() || m_tetriminoTemp.getSquares()[i].getAxisX() >= m_map.getRightSide() || m_direction != DOWN)
				continueToFall = true;
		}
	}

	// Conditions : Check which kind of collision is found
	if(!collisions) {
		m_tetriminos.back() = m_tetriminoTemp;
	} else if (continueToFall) {
		setTetrimino(m_tetriminos.back(), 'O');
		m_tetriminoTemp = m_tetriminos.back();
	} else {
		setTetrimino(m_tetriminos.back(), 'O');
		m_tetriminoActive = false;
		verifLines();
	}
}

/**
* \brief	Detect tetriminos' collisions.
*			Look at all squares of the temporary tetrimino to check if they are in collision with squares already on the map.
*			Two collision's type : continue to fall / stop to fall
*/
void Solo::verifLines(void)
{
	bool destroy(false);
	int axisY(m_map.getTopSide()), pastAxisY(m_map.getTopSide());
	for(size_t i = 0 ; i < m_tetriminos.back().getSquares().size() ; ++i)
	{
		for(size_t x = m_map.getLeftSide() + 1 ; x < m_map.getRightSide(); ++x)
		{
			if(m_map.getSquare(x, m_tetriminos.back().getSquares()[i].getAxisY()).getValue() == ' ')
			{
				x = m_map.getRightSide();
			} else {
				m_count++;
			}
		}

		if(m_count == 8) {
			destroyLines(m_tetriminos.back().getSquares()[i].getAxisY(), axisY, pastAxisY);
			destroy = true;
			i = -1;
		}
		m_count = 0;
	}
	
	if(destroy) {
		display();
		Sleep(800);
		shiftLines(pastAxisY);
		display();
		destroy = false;
	}
}

/**
* \brief	Detect tetriminos' collisions.
*			Look at all squares of the temporary tetrimino to check if they are in collision with the map.
*			Two collision's type : continue to fall / stop to fall
*/
void Solo::destroyLines(int y, int &axisY, int &pastAxisY)
{
	m_linesToShift++;
	for(size_t x = m_map.getLeftSide() + 1 ; x < m_map.getRightSide(); ++x)
	{
		m_map.setSquare(x, y, ' ');
	}

	for(size_t i = 0; i < m_tetriminos.back().getSquares().size(); ++i)
	{
		axisY = m_tetriminos.back().getSquares()[i].getAxisY();
		if(axisY == y) {
			m_tetriminos.back().getSquares().erase(m_tetriminos.back().getSquares().begin() + i);
			i = -1;
			if(axisY > pastAxisY)
				pastAxisY = axisY;
		}
	}
}

void Solo::shiftLines(int axisY)
{
	int x = 0, shiftLine = 0;
	for(int y = axisY ; y > 0 ; --y)
	{
		//for(size_t j = 0; j < m_tetriminos.back().getSquares().size(); ++j)
		//{
		//	if(m_tetriminos.back().getSquares()[j].getAxisY() <= axisY)
		//		m_tetriminos.back().getSquares()[j].setCoordinates(m_tetriminos.back().getSquares()[j].getAxisX(), m_tetriminos.back().getSquares()[j].getAxisY() + shiftLine);
		//}

		for(x = m_map.getLeftSide() + 1 ; x < m_map.getRightSide() ; ++x)
		{
			if (m_tetriminos.back().getSquare(x, y).getAxisX() == x &&  m_tetriminos.back().getSquare(x, y).getAxisY() == y)
				m_tetriminos.back().getSquare(x, y).setCoordinates(m_tetriminos.back().getSquare(x, y).getAxisX(), m_tetriminos.back().getSquare(x, y).getAxisY() + shiftLine);
			
			if (m_map.getSquare(x, y).getValue() == ' ')
				m_count++;
		}

		if(m_count != 8) {
			for(x = m_map.getLeftSide() + 1 ; x < m_map.getRightSide() ; ++x)
			{
				m_map.setSquare(x, y + shiftLine, m_map.getSquare(x, y).getValue());
				m_map.setSquare(x, y, ' ');
			}
		}
		else {
			y--;
			shiftLine++;
		}
		m_count = 0;
	}

	//m_score += (m_scores[m_linesToShift] * (m_level + 1));
	//Sleep(10);
}

void Solo::input(void)
{
	if(GetAsyncKeyState(37))
	{
		move(m_direction = LEFT);
	}

	if(GetAsyncKeyState(38))
	{
		move(m_direction = UP);
	}

	if(GetAsyncKeyState(39))
	{
		move(m_direction = RIGHT);
	}

	if(GetAsyncKeyState(40))
	{
		//move(DOWN);
	}
}

void Solo::move(int direction)
{
	if(direction == LEFT)
	{
		for(size_t i = 0 ; i < m_tetriminoTemp.getSquares().size() ; ++i)
		{
			m_tetriminoTemp.getSquares()[i].setCoordinates(m_tetriminoTemp.getSquares()[i].getAxisX() - 1, m_tetriminoTemp.getSquares()[i].getAxisY());
		}
	} else if (direction == UP) {
		m_tetriminoTemp.setDirection();
	} else if (direction == RIGHT) {
		for(size_t i = 0 ; i < m_tetriminoTemp.getSquares().size() ; ++i)
		{
			m_tetriminoTemp.getSquares()[i].setCoordinates(m_tetriminoTemp.getSquares()[i].getAxisX() + 1, m_tetriminoTemp.getSquares()[i].getAxisY());
		}
	} else if (direction == DOWN) {
		for(size_t i = 0 ; i < m_tetriminoTemp.getSquares().size() ; ++i)
		{
			m_tetriminoTemp.getSquares()[i].setCoordinates(m_tetriminoTemp.getSquares()[i].getAxisX(), m_tetriminoTemp.getSquares()[i].getAxisY() + 1);
		}
	}
	
}


void Solo::rollOn(void)
{
	if(m_tetriminos.size() > 1)
	{
		for(size_t i = 0 ; i < m_tetriminos.back().getSquares().size() ; ++i)
		{
			for(size_t j = 0 ; j < m_tetriminos[m_tetriminos.size() - 2].getSquares().size() ; ++j)
			{
				if(m_tetriminos.back().getSquares()[i] == m_tetriminos[m_tetriminos.size() - 2].getSquares()[j])
				{
					finish();
				}
			}
		}
	}
}


void Solo::finish(void)
{
	for(int y = m_map.getTopSide() + 1 ; y < m_map.getSizeY() - 1 ; ++y) {
		for(int x = m_map.getLeftSide() + 1 ; x < m_map.getRightSide() ; ++x) {
			m_map.setSquare(x, y, 'O');
			display();
			Sleep(1);
		}
	}

	system("cls");
	cout << endl << "You loose !" << endl;
	Sleep(2000);
	exit(0);
}


/*void Solo::destructLines(void) 
{
	int y = 1, x = 1, compteur = 0;
	for(y = 1; y < m_map.getSizeY() - 1 ; y++)
	{
		for(x = 1 ; x < m_map.getRightSide() ; x++)
		{
			if(m_map.getSquare(x, y) != ' ')
			{
				compteur++;
			}
		}

		if(compteur == m_map.getRightSide() - 1) 
		{
			while(compteur > 0)
			{
				m_map.setSquare(x - 1, y, ' ');
				compteur--;
			}
			decalLines(y - 1);
		}

		compteur = 0;
	}
}*/

/*void Solo::decalLines(int y) 
{
	int x = 1;
	while(y > 0) {

		for(x = 1 ; x < m_map.getRightSide() ; x++) {
			m_map.setSquare(x, y + 1, m_map.getSquare(x, y));
		}

		y--;
	}
}*/

void Solo::display(void)
{
    m_hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(m_hStdout);

	//system("cls");

	cout << endl << "          TETRIS          " << endl << endl;

	for(int y = m_map.getTopSide() ; y < m_map.getSizeY() ; ++y)
	{
		for(int x = m_map.getLeftSide() ; x < m_map.getSizeX() ; ++x)
		{
			cout << m_map.getSquare(x, y).getValue();
		}
		cout << endl;
	}


}

/*
This method is not from me.
Source : http://msdn.microsoft.com/en-us/library/windows/desktop/ms682022(v=vs.85).aspx
*/

 /* Standard error macro for reporting API errors */ 
#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s \ on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

void Solo::cls( HANDLE hConsole )
{
   COORD coordScreen = {0, 0};    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;

// Get the number of character cells in the current buffer. 

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   //dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   dwConSize = 0;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}