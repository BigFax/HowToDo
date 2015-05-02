#include <iostream>
#include <thread>
#include "Game.h"

using namespace std;

int main(int argc, char ** argv)
{
	string music("tetris");
	Game game(music);

    thread gameThread = thread(&Game::start, game);
	gameThread.join();

	cout << endl;
	system("PAUSE");

	return 0;
}