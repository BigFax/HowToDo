#ifndef MUSIC_H
#define MUSIC_H

#include <string>
#include <windows.h>
#include "fmod.hpp"
#include "fmod_errors.h"

using namespace std;

class Music
{
private:
	string m_name;
	void ERRCHECK(FMOD_RESULT result);

public:
	Music(string name);
	~Music(void);

	void play(int loop, int volume);
};

#endif

