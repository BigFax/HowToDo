/*
Rôle : Regroupe les fonctions gérant la partie "options" du jeu accessible par le menu principal.
*/
//Inclusion des bibliothèques "standard".
#include <stdlib.h>//Bibliothèque de base.
#include <stdio.h>//Bibliothèque de base.
#include <time.h>//Bibliothèque pour gérer le temps.
#include <SDL/SDL.h>//Bibliothèque SDL.
#include <SDL_image.h>//Bibliothèque pour gérer les images en SDL.
#include <fmodex/fmod.h>//Bibliothèque pour gérer le son.
#include <SDL/SDL_ttf.h>//Bibliothèque pour gérer le texte.
//Inclusion des bibliothèques "spéciales" au projet.
#include "constantes.h"//Bibliothèque contenant variables globales et structures.
#include "options.h"//Bibliothèque contenant les prototypes de options.c
#include "fonctions.h"//Bibliothèque contenant les prototypes de fonction.c


void choix_options(SDL_Surface *ecran, int *music, int *sound, int *mode)
{
    SDL_Surface *back = NULL, *on = NULL, *on2 = NULL, *off = NULL, *off2 = NULL, *facile = NULL, *moyen = NULL, *difficile = NULL, *flecheGauche = NULL, *flecheDroite = NULL;
    SDL_Rect positionBack, positionMusic, positionSound, positionMode, positionFlecheGauche, positionFlecheDroite;
    SDL_Event event;

    int continuer = 1, choixMenu = 1;

    SDL_Color couleurBlanche = {255, 255, 255}, couleurOrange = {255, 128, 0};//Variable de type couleur stockant la coucleur blanche.

    back = IMG_Load("sprites/back.png");
    positionBack.x = 254;
    positionBack.y = 430;

    flecheGauche = IMG_Load("sprites/flechegauche.png");
    positionFlecheGauche.x = 260;
    positionFlecheGauche.y = 100;

    flecheDroite = IMG_Load("sprites/flechedroite.png");
    positionFlecheDroite.x = 420;
    positionFlecheDroite.y = 100;

    on = IMG_Load("sprites/on.png");
    on2 = IMG_Load("sprites/on2.png");
    off = IMG_Load("sprites/off.png");
    off2 = IMG_Load("sprites/off2.png");
    facile = IMG_Load("sprites/easy.png");
    moyen = IMG_Load("sprites/normal.png");
    difficile = IMG_Load("sprites/hard.png");


    positionMusic.x = 330;
    positionMusic.y = 100;
    positionSound.x = 330;
    positionSound.y = 180;
    positionMode.x = 280;
    positionMode.y = 260;


    TTF_Init();//Initialisation de la bibliothèque de gestion de texte.
    //Vérif l'initialisation.
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());//Message d'erreur.
        exit(EXIT_FAILURE);//Ferme le programme.
    }

    //Boucle princiale du programme.
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            exit(0);
            break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                    case SDLK_UP://flèche du haut
                        if(choixMenu != 4)
                        {
                            flecheGauche = IMG_Load("sprites/flechegauche.png");
                            flecheDroite = IMG_Load("sprites/flechedroite.png");
                            positionFlecheGauche.y = positionFlecheGauche.y - 80;
                            positionFlecheDroite.y = positionFlecheDroite.y - 80;
                        }

                        if(choixMenu == 1)
                        {
                            choixMenu = 4;
                            back = IMG_Load("sprites/back_choix.png");
                            flecheGauche = NULL;
                            flecheDroite = NULL;
                        }
                        else if(choixMenu == 2)
                        {
                            choixMenu = 1;
                        }
                        else if(choixMenu == 3)
                        {
                            choixMenu = 2;
                        }
                        else if(choixMenu == 4)
                        {
                            choixMenu = 3;
                            back = IMG_Load("sprites/back.png");
                            flecheGauche = IMG_Load("sprites/flechegauche.png");
                            flecheDroite = IMG_Load("sprites/flechedroite.png");
                            positionFlecheGauche.y = 260;
                            positionFlecheDroite.y = 260;
                        }
                    break;
                    case SDLK_DOWN: // flèche du bas
                        if(choixMenu != 4)
                        {
                            flecheGauche = IMG_Load("sprites/flechegauche.png");
                            flecheDroite = IMG_Load("sprites/flechedroite.png");
                            positionFlecheGauche.y = positionFlecheGauche.y + 80;
                            positionFlecheDroite.y = positionFlecheDroite.y + 80;
                        }

                        if(choixMenu == 1)
                        {
                            choixMenu = 2;
                        }
                        else if(choixMenu == 2)
                        {
                            choixMenu = 3;
                        }
                        else if(choixMenu == 3)
                        {
                            choixMenu = 4;
                            back = IMG_Load("sprites/back_choix.png");
                            flecheGauche = NULL;
                            flecheDroite = NULL;
                        }
                        else if(choixMenu == 4)
                        {
                            choixMenu = 1;
                            back = IMG_Load("sprites/back.png");
                            flecheGauche = IMG_Load("sprites/flechegauche.png");
                            flecheDroite = IMG_Load("sprites/flechedroite.png");
                            positionFlecheGauche.y = 100;
                            positionFlecheDroite.y = 100;
                        }
                    break;
                    case SDLK_LEFT:
                        if(choixMenu == 1)
                        {
                            if(*music == 0)
                            {
                                *music = 1;
                            }
                            else if(*music == 1)
                            {
                                *music = 0;
                            }
                        }
                        else if(choixMenu == 2)
                        {
                            if(*sound == 0)
                            {
                                *sound = 1;
                            }
                            else if(*sound == 1)
                            {
                                *sound = 0;
                            }
                        }
                        else if(choixMenu == 3)
                        {
                            if(*mode == 0)
                            {
                                *mode = 2;
                            }
                            else if(*mode == 1)
                            {
                                *mode = 0;
                            }
                            else if(*mode == 2)
                            {
                                *mode = 1;
                            }
                        }
                    break;
                    case SDLK_RIGHT:
                        if(choixMenu == 1)
                        {
                            if(*music == 0)
                            {
                                *music = 1;
                            }
                            else if(*music == 1)
                            {
                                *music = 0;
                            }
                        }
                        else if(choixMenu == 2)
                        {
                            if(*sound == 0)
                            {
                                *sound = 1;
                            }
                            else if(*sound == 1)
                            {
                                *sound = 0;
                            }
                        }
                        else if(choixMenu == 3)
                        {
                            if(*mode == 0)
                            {
                                *mode = 1;
                            }
                            else if(*mode == 1)
                            {
                                *mode = 2;
                            }
                            else if(*mode == 2)
                            {
                                *mode = 0;
                            }
                        }
                    break;
                    case SDLK_RETURN: //Touche "entrée".
                        if(choixMenu == 4)//Choix 2 (back) sélectionné.
                        {
                            continuer = 0;
                        }
                    break;
                }
            break;
        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        SDL_BlitSurface(flecheGauche, NULL, ecran, &positionFlecheGauche);
        SDL_BlitSurface(flecheDroite, NULL, ecran, &positionFlecheDroite);

        if(*music == 0)
        {
            SDL_BlitSurface(off, NULL, ecran, &positionMusic);
        }
        else if(*music == 1)
        {
            SDL_BlitSurface(on, NULL, ecran, &positionMusic);
        }

        if(*sound == 0)
        {
            SDL_BlitSurface(off, NULL, ecran, &positionSound);
        }
        else if(*sound == 1)
        {
            SDL_BlitSurface(on, NULL, ecran, &positionSound);
        }

        if(*mode == 0)
        {
            SDL_BlitSurface(facile, NULL, ecran, &positionMode);
        }
        else if(*mode == 1)
        {
            SDL_BlitSurface(moyen, NULL, ecran, &positionMode);
        }
        else if(*mode == 2)
        {
            SDL_BlitSurface(difficile, NULL, ecran, &positionMode);
        }

        SDL_BlitSurface(back, NULL, ecran, &positionBack);
        fc_texte(ecran, "Options menu :", 10, 0, couleurOrange, 60);
        fc_texte(ecran, "Music :", 25, 100, couleurBlanche, 40);
        fc_texte(ecran, "Sound :", 25, 175, couleurBlanche, 40);
        fc_texte(ecran, "Mode :", 25, 250, couleurBlanche, 40);
        SDL_Flip(ecran);

    }

    SDL_FreeSurface(back);
    //SDL_FreeSurface(choix);

TTF_Quit();//On quitte la librairie qui gère le texte.

}
