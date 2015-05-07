/*
Rôle : Regroupe les fonctions gérant la partie "continue" du jeu accessible par le menu principal.
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
#include "continue.h"//Bibliothèque contenant les prototypes de continue.c
#include "fonctions.h"//Bibliothèque contenant les prototypes de fonction.c


void choix_continue(SDL_Surface *ecran, int *music, int *sound, int *mode)
{
    SDL_Surface *back = NULL, *choix = NULL;
    SDL_Rect positionBack, positionChoix;
    SDL_Event event;

    int continuer = 1, boucleChoix = 0, choixMenu = 1, nbre_partie = 0, nbre_caractere = 0, nbre_mot = 0, i = 0, x = 50, y = 50, compteur = 0, compteur2 = 0;
    char caractere, *nom, *partie, *score;

    Struct_Partie *final;

    SDL_Color couleurBlanche = {255, 255, 255}, couleurOrange = {255, 128, 0};//Variable de type couleur stockant la coucleur blanche.

    back = IMG_Load("sprites/back.png");
    positionBack.x = 254;
    positionBack.y = 430;

    choix = IMG_Load("sprites/choix.png");
    positionChoix.x = 30;
    positionChoix.y = 132;

    FILE *fichier = NULL;

    fichier = fopen("config/saves/levels.save" ,"r");

    //Vérif si le fichier est bien ouvert.
    if(fichier == NULL)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());//Message d'erreur.
        exit(EXIT_FAILURE);//Ferme le programme.
    }

    TTF_Init();//Initialisation de la bibliothèque de gestion de texte.
    //Vérif l'initialisation.
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());//Message d'erreur.
        exit(EXIT_FAILURE);//Ferme le programme.
    }

    while((caractere = fgetc(fichier)) != EOF)
    {
        nbre_caractere++;
        if(caractere == '\n')
        {
            nbre_partie++;
        }
        if(caractere == ' ')
        {
            nbre_mot++;
        }
    }
    nbre_partie++;

    //Struct_Partie final[10];
    final = calloc(nbre_mot, sizeof(Struct_Partie));
    //Struct_Partie *final = calloc(nbre_partie, sizeof(Struct_Partie));

    if(nbre_caractere == 0)
    {
        choixMenu = 0;
        choix = NULL;
        back = IMG_Load("sprites/back_choix.png");
    }

    //Boucle princiale du programme.
    while(continuer)
    {
        boucleChoix = nbre_partie;
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
                        if(choixMenu == 0)
                        {
                            back = IMG_Load("sprites/back_choix.png");
                        }
                        else if(choixMenu > 1 && choixMenu <= nbre_partie)
                        {
                            positionChoix.y -= 60;
                            choixMenu--;
                            back = IMG_Load("sprites/back.png");
                        }
                        else if(choixMenu == 1)
                        {
                            choix = NULL;
                            positionChoix.y += 60 * nbre_partie - 1;
                            choixMenu = nbre_partie + 1;
                            back = IMG_Load("sprites/back_choix.png");
                        }
                        else if(choixMenu == nbre_partie + 1)
                        {
                            choix = IMG_Load("sprites/choix.png");
                            positionChoix.y -= 60;
                            choixMenu = nbre_partie;
                            back = IMG_Load("sprites/back.png");
                        }
                    break;
                    case SDLK_DOWN: //flèche du bas
                        if(choixMenu == 0)
                        {
                            back = IMG_Load("sprites/back_choix.png");
                        }
                        if(choixMenu >= 1 && choixMenu < nbre_partie)
                        {
                            positionChoix.y += 60;
                            choixMenu++;
                            back = IMG_Load("sprites/back.png");
                        }
                        else if(choixMenu == nbre_partie)
                        {
                            positionChoix.y += 60;
                            choix = NULL;
                            choixMenu++;
                            back = IMG_Load("sprites/back_choix.png");
                        }
                        else if(choixMenu == nbre_partie + 1)
                        {
                            choix = IMG_Load("sprites/choix.png");
                            positionChoix.y = 132;
                            choixMenu = 1;
                            back = IMG_Load("sprites/back.png");
                        }
                    break;
                    case SDLK_RETURN://Touche "entrée".
                        if(choixMenu == nbre_partie + 1 || choixMenu == 0)
                        {
                            continuer = 0;
                        }
                        else
                        {
                            i = 1, compteur = 0;
                            fseek(fichier, 0, SEEK_SET);//On revient au début.
                            while(i < choixMenu)
                            {
                                caractere = fgetc(fichier);
                                if(caractere == '\n')
                                {
                                    i++;
                                }
                                else if(caractere == ' ')
                                {
                                    compteur++;
                                }
                            }

                            nom = final[compteur].partie;
                            compteur++;
                            partie = final[compteur].partie;
                            compteur++;
                            score = final[compteur].partie;


                            /*for(i = 0 ; final[compteur].partie[i] != '\n' ; i++)
                            {
                                final[compteur].partie[i] = fgetc(fichier);
                                if(caractere = ' ')
                                {
                                    compteur++;
                                }
                            }*/

                            /*nom = strtok(final[compteur].partie[i], " ");
                            partie = strtok(NULL, " ");
                            score = strtok(NULL, " ");*/
                            //fc_texte(ecran, nom, 100, 120, couleurBlanche, 60);

                            //On ferme le fichier
                            fclose(fichier);
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                            jouer(ecran, nom, partie, score, choixMenu, music, sound, mode);
                            continuer = 0;
                        }
                    break;
                }
            break;
        }

        //Effacement de l'écran.
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        //Colle les surfaces.
        SDL_BlitSurface(back, NULL, ecran, &positionBack);
        SDL_BlitSurface(choix, NULL, ecran, &positionChoix);

        fseek(fichier, 0, SEEK_SET);//On revient au début.
        x = 50;
        y = 140;
        compteur = 0;
        compteur2 = 0;

        fc_texte(ecran, "Nom", 50, 60, couleurBlanche, 50);
        fc_texte(ecran, "Niveau", 270, 60, couleurBlanche, 50);
        fc_texte(ecran, "Score", 490, 60, couleurBlanche, 50);

        for(i = 0 ; i < nbre_caractere ; i++)
        {
            caractere = fgetc(fichier);
            if(caractere == '\n')
            {
                x = 50;
                y += 60;
            }
            else if(caractere == ' ')
            {
                fc_texte(ecran, final[compteur].partie, x, y, couleurBlanche, 50);
                x += 220;
                compteur++;
                compteur2 = 0;
            }
            else
            {
                final[compteur].partie[compteur2] = caractere;
                compteur2++;
            }
        }

        fc_texte(ecran, "Menu continue :", 10, 0, couleurOrange, 60);
        //Rafraichit l'écran.
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(back);
    SDL_FreeSurface(choix);

TTF_Quit();//On quitte la librairie qui gère le texte.

//On ferme le fichier
fclose(fichier);
}
