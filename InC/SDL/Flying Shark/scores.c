/*
Rôle : Regroupe les fonctions gérant la partie "scores" du jeu accessible par le menu principal.
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
#include "scores.h"//Bibliothèque contenant les prototypes de scores.c
#include "fonctions.h"//Bibliothèque contenant les prototypes de fonction.c


void choix_scores(SDL_Surface *ecran)
{
    SDL_Surface *back = NULL;
    SDL_Rect positionBack;
    SDL_Event event;

    Struct_Partie *final;

    int continuer = 1, choixMenu = 1, nbre_partie = 1, nbre_caractere = 0, nbre_mot = 0, i = 0, x = 150, y = 50, compteur = 0, compteur2 = 0, annul = 1;
    char caractere;

    SDL_Color couleurBlanche = {255, 255, 255}, couleurOrange = {255, 128, 0};//Variable de type couleur stockant la coucleur blanche.

    back = IMG_Load("sprites/back_choix.png");
    positionBack.x = 254;
    positionBack.y = 430;

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

    //Struct_Partie final[10];
    final = calloc(nbre_mot, sizeof(Struct_Partie));
    //Struct_Partie *final = calloc(nbre_partie, sizeof(Struct_Partie));


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
                    case SDLK_RETURN: //Touche "entrée".
                        continuer = 0;
                    break;
                }
            break;
        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        fseek(fichier, 0, SEEK_SET);//On revient au début.
        x = 150;
        y = 150;
        compteur = 0;
        compteur2 = 0;

        fc_texte(ecran, "Nom", 150, 80, couleurBlanche, 50);
        fc_texte(ecran, "Score", 400, 80, couleurBlanche, 50);
        i = 0;
        while(i < nbre_caractere)
        {
            if(i == 0){annul = 1;}
            caractere = fgetc(fichier);
            i++;
            if(caractere == '\n')
            {
                annul = 1;
                x = 150;
                y += 60;
            }
            else if(caractere == ' ')
            {
                if(annul != 1)
                {
                    fc_texte(ecran, final[compteur].partie, x, y, couleurBlanche, 50);
                    x += 250;
                    compteur++;
                    compteur2 = 0;
                }
                else
                {
                    fc_texte(ecran, final[compteur].partie, x, y, couleurBlanche, 50);
                    x += 250;
                    compteur++;
                    compteur2 = 0;
                    caractere = fgetc(fichier);
                    i++;
                    while(caractere != ' ')
                    {
                        caractere = fgetc(fichier);
                        i++;
                        compteur2++;
                    }
                    compteur2 = 0;

                    annul = 0;
                }
            }
            else
            {
                final[compteur].partie[compteur2] = caractere;
                compteur2++;
            }
        }

        SDL_BlitSurface(back, NULL, ecran, &positionBack);
        fc_texte(ecran, "Menu scores :", 10, 0, couleurOrange, 60);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(back);

TTF_Quit();//On quitte la librairie qui gère le texte.
//On ferme le fichier
fclose(fichier);

}
