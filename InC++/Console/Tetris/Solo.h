#ifndef SOLO_H
#define SOLO_H

#include <string>
#include "Map.h"
#include "Tetrimino.h"

class Solo
{
protected:
	bool m_rollOn, m_tetriminoActive, m_downActive;
	HANDLE m_hStdout;
	DWORD m_timePastTetrimino, m_timePastInput, m_time, m_timePastDeplacement, m_timeDeplacement, m_speed, m_acceleration;
	Map m_map;
	std::vector<Tetrimino> m_tetriminos;
	Tetrimino m_tetriminoTemp;
	enum {I, O, T, L, J, Z, S};
	enum {LEFT, UP, RIGHT, DOWN};
	int m_scores[4];
	int m_linesToShift, m_direction, m_count, m_level;
	std::string m_score;

public:
	Solo(void);
	~Solo(void);

	void newTetrimino();
	int random(int number = 1);
	void setTetrimino(Tetrimino &tetrimino, char value);
	void start(void);
	void update(void);
	void updateMap(void);
	void updateScore(void);
	void collisions(void);
	void verifLines(void);
	void destroyLines(int y, int &axisY, int &pastAxisY);
	void shiftLines(int y);
	void input(void);
	void move(int direction);
	void display(void);
	void rollOn(void);
	void finish(void);
	void seeInfos(void);
	

	//void destructLines(void);
	//void decalLines(int y);
	void cls( HANDLE hConsole );
};

#endif
