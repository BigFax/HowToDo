#ifndef GAME_H
#define GAME_H

#include <string>
#include "Music.h"
#include "Menu.h"

class Game
{
protected:
	static std::string m_choice;
	enum {SOLO, MULTI, OPTIONS, QUIT};
	Music m_music;
	Menu m_menu;

public:
	Game(string music);
	~Game(void);
	std::string getType();

	static void display(string action);
	void start(void);
	void playMusic(void);
};

#endif