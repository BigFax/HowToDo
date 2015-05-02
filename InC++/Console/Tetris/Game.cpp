#include <iostream>
#include <windows.h>
#include <string>
#include <thread>

#include "Game.h"
#include "Music.h"
#include "Menu.h"
#include "Solo.h"
#include "Tetrimino.h"

using namespace std;

string Game::m_choice = "";

Game::Game(string music) : m_music(music)
{
	m_menu.addAttributes(4, "Solo", "Multi", "Options", "Quit");
	m_menu.show();
	m_choice = m_menu.entry();
}

Game::~Game(void)
{

}

string Game::getType(void)
{
	return m_choice;
}

void Game::display(string action)
{
	system("cls");

	if (action == "start") {
		for(int time = 3; time > 0; --time) {
			cout << "Welcome in the " << m_choice << " mode !" << endl << endl;
			cout << "Begin in " << time << " seconds ";
			Sleep(1000);
			system("cls");
		}
	} else if (action == "exit") {
		for(int time = 3; time > 0; --time) {
			cout << "The game is over now." << endl;
			cout << "End in " << time << " seconds ";
			Sleep(1000);
			system("cls");
		}
	}
}

void Game::start(void)
{
	if (m_choice == m_menu.getAttribute(SOLO)) {
		display("start");
		//thread musicThread = thread(&Game::playMusic, this);
		Solo solo;
		solo.start();
		//musicThread.join();
	} else if (m_choice == m_menu.getAttribute(MULTI)) {
		display("exit");
		exit(0);
	} else if (m_choice == m_menu.getAttribute(OPTIONS)) {
		display("exit");
		exit(0);
	} else if (m_choice == m_menu.getAttribute(QUIT)) {
		display("exit");
		exit(0);
	} else {
		cout << "oO ?!" << endl;
		display("exit");
		exit(0);
	}
}

void Game::playMusic(void)
{
	m_music.play(0, 100);
}