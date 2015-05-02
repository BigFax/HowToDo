#include <string>
#include <windows.h>
#include "Music.h"
#include "fmod.hpp"
#include "fmod_errors.h"


Music::Music(string name) : m_name(name)
{
}

Music::~Music(void)
{
}

void Music::play(int loop, int volume)
{
    FMOD_SYSTEM       *system_Fmod;
    FMOD_SOUND        *sound[1];
    FMOD_CHANNEL      *channel[1];
    int                key, count;
    FMOD_RESULT        result;
    unsigned int       version;

	result = FMOD_System_Create(&system_Fmod);
    ERRCHECK(result);

    result = FMOD_System_GetVersion(system_Fmod, &version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
		system("PAUSE");
        exit(-1);
    }

    result = FMOD_System_Init(system_Fmod, 32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    result = FMOD_System_CreateSound(system_Fmod, "tetris.mp3", FMOD_LOOP_NORMAL, 0, &sound[0]);
    ERRCHECK(result);

	for (count = 0; count < 1; count++)
    {
        result = FMOD_System_PlaySound(system_Fmod, FMOD_CHANNEL_FREE, sound[count], TRUE, &channel[count]);
        ERRCHECK(result);
        result = FMOD_Channel_SetPaused(channel[count], FALSE);
        ERRCHECK(result);
    }


    FMOD_System_Update(system_Fmod);

	Sleep(213000);

    printf("\n");

    for (count = 0; count < 1; count++)
    {
        result = FMOD_Sound_Release(sound[count]);
        ERRCHECK(result);
    }

	result = FMOD_System_Close(system_Fmod);
    ERRCHECK(result);
    result = FMOD_System_Release(system_Fmod);
    ERRCHECK(result);
}

void Music::ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		system("PAUSE");
		exit(-1);
	}
}