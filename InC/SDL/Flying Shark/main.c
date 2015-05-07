/*
#############################################
#   Projet Flying Shark                     #
#   Langage C avec librairie SDL            #
#                                           #
#   Jacques Adrien HENRI                    #
#   Sébastien LEHUEDE                       #
#   Fabrice MORIN                           #
#   Maxime PLATIER                          #
#   Jonathan VON TEICHMEISTER - MOMRELLE    #
#                                           #
#          Fichier main.c                   #
#                                           #
#############################################
*/
//Inclusion des bibliothèques "standard".
#include <stdlib.h>//Bibliothèque de base.
#include <stdio.h>//Bibliothèque de base.
#include <SDL/SDL.h>//Bibliothèque SDL.
#include <SDL_image.h>//Bibliothèque pour gérer les images en SDL.
//#include <SDL/SDL_rotozoom.h>
//Inclusion des bibliothèques "spéciales" au projet.
#include "constantes.h"//Bibliothèque contenant variables globales et structures.
#include "jouer.h"//Bibliothèque contenant les prototypes de jouer.c
#include "continue.h"//Bibliothèque contenant les prototypes de continue.c
#include "scores.h"//Bibliothèque contenant les prototypes de scores.c
#include "options.h"//Bibliothèque contenant les prototypes de options.c

//Fonction main, fonction principale du programme. Celle-ci est lue en première au démarrage du programme.
int main(int argc, char *argv[])
{
    //Déclaration des variables de type SDL.
    SDL_Surface *ecran = NULL, *ecranTitre = NULL, *menuStartGame = NULL, *menuContinue = NULL, *menuScores = NULL, *menuOptions = NULL, *menuExit = NULL;
    SDL_Rect positionEcranTitre, positionStartGame, positionContinue, positionScores, positionOptions, positionExit;
    SDL_Event event;

    //Déclaration des autres variables.
    int continuer = 1, choixMenu = 1, music = 1, sound = 1, mode = 1;
    char nom[100];
    nom[0] = '\0';

    //Initialisation de la SDL.
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);//Les modes de la SDL.
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//Définition de la fenêtre dans le pointeur "ecran".
    SDL_WM_SetCaption("Flying Shark", NULL);//Titre de la fenêtre.

    //Déclaration des coordonnées.
    //Charge les images dans des pointeurs de surface :
    ecranTitre = IMG_Load("sprites/ecran_titre.png");
    menuStartGame = IMG_Load("sprites/start_game_choix.png");
    menuContinue = IMG_Load("sprites/continue.png");
    menuScores = IMG_Load("sprites/scores.png");
    menuOptions = IMG_Load("sprites/options.png");
    menuExit = IMG_Load("sprites/exit.png");

    //Définit les coordonnées pour chacunes des images chargées ci dessus.
    positionEcranTitre.x = 0;//Abscisse de l'image.
    positionEcranTitre.y = 0;//Ordonnée de l'image.

    positionStartGame.x = 248;//Abscisse de l'image.
    positionStartGame.y = 230;//Ordonnée de l'image.

    positionContinue.x = 248;//Abscisse de l'image.
    positionContinue.y = 265;//Ordonnée de l'image.

    positionScores.x = 248;//Abscisse de l'image.
    positionScores.y = 300;//Ordonnée de l'image.

    positionOptions.x = 248;//Abscisse de l'image.
    positionOptions.y = 335;//Ordonnée de l'image.

    positionExit.x = 248;//Abscisse de l'image.
    positionExit.y = 370;//Ordonnée de l'image.

    //Boucle princiale du programme. Arrêt si continuer = 0.
    //Continuer = 0 : Si bouton "Exit" sélectionné ou fermeture fenêtre.
    while(continuer)
    {
        SDL_WaitEvent(&event);//Regarde si il y a un événement (Action bloquante).
        switch(event.type)//Condition prenant en compte le type de l'événement (Ex : SDL_QUIT). Les types d'évent possible sont testés par les "case".
        {
            case SDL_QUIT://Si on ferme le programme normalement (La croix rouge).
            continuer = 0;//Variable mise à valeur de sortie de boucle.
            break;

            case SDL_KEYDOWN://Si on appuie sur une touche.
                switch(event.key.keysym.sym)//Condition prenant en compte le type de touche appuyée.
                {
                    case SDLK_UP://Si flèche du haut.
                        if(choixMenu == 1)//Si choix précédent = 1 (Start game)
                        {
                            choixMenu = 5;//On passe le choix actuel à 5 (Exit).
                            //Changement des surfaces.
                            menuExit = IMG_Load("sprites/exit_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                        }
                        else if(choixMenu == 2)//Si choix précédent = 2 (Continue).
                        {
                            choixMenu = 1;//On passe le choix actuel à 1 (Start game).
                            //Changement des surfaces.
                            menuStartGame = IMG_Load("sprites/start_game_choix.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 3)//Si choix précédent = 3 (Scores).
                        {
                            choixMenu = 2;//On passe le choix actuel à 2 (Continue).
                            //Changement des surfaces.
                            menuContinue = IMG_Load("sprites/continue_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 4)//Si choix précédent = 4 (Options).
                        {
                            choixMenu = 3;//On passe le choix actuel à 3 (Scores).
                            //Changement des surfaces.
                            menuScores = IMG_Load("sprites/scores_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 5)//Si Choix précédent = 5 (Exit).
                        {
                            choixMenu = 4;//On passe le choix actuel à 4 (Options).
                            //Changement des surfaces.
                            menuOptions = IMG_Load("sprites/options_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                    break;

                    case SDLK_DOWN://Si flèche du bas
                        if(choixMenu == 1)//Si Choix précédent = 1 (Start Game).
                        {
                            choixMenu = 2;//On passe le choix actuel à 2 (Continue).
                            //Changement des surfaces.
                            menuContinue = IMG_Load("sprites/continue_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 2)//Si Choix précédent = 2 (Continue).
                        {
                            choixMenu = 3;//On passe le choix actuel à 3 (Scores).
                            //Changement des surfaces.
                            menuScores = IMG_Load("sprites/scores_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 3)//Si Choix précédent = 3 (Scores).
                        {
                            choixMenu = 4;//On passe le choix actuel à 4 (Options).
                            //Changement des surfaces.
                            menuOptions = IMG_Load("sprites/options_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                        else if(choixMenu == 4)//Si Choix précédent = 4 (Options).
                        {
                            choixMenu = 5;//On passe le choix actuel à 5 (Exit).
                            //Changement des surfaces.
                            menuExit = IMG_Load("sprites/exit_choix.png");
                            menuStartGame = IMG_Load("sprites/start_game.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                        }
                        else if(choixMenu == 5)//Si Choix précédent = 5 (Exit).
                        {
                            choixMenu = 1;//On passe le choix actuel à 1 (Start game).
                            //Changement des surfaces.
                            menuStartGame = IMG_Load("sprites/start_game_choix.png");
                            menuContinue = IMG_Load("sprites/continue.png");
                            menuScores = IMG_Load("sprites/scores.png");
                            menuOptions = IMG_Load("sprites/options.png");
                            menuExit = IMG_Load("sprites/exit.png");
                        }
                    break;

                    case SDLK_RETURN://Si Touche "entrée".
                        if(choixMenu == 1)//Choix 1 (Start game) sélectionné.
                        {
                            //Effacement de l'écran
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                            jouer(ecran, nom, "1", "0", 0, &music, &sound, &mode);//Appel fonction "jouer".
                        }
                        else if(choixMenu == 2)//Choix 2 (Continue) sélectionné.
                        {
                            //Effacement de l'écran
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                            choix_continue(ecran, &music, &sound, &mode);//Appel fonction "choix_continue".
                        }
                        else if(choixMenu == 3)//Choix 3 (Scores) sélectionné.
                        {
                            //Effacement de l'écran
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                            choix_scores(ecran);//Appel fonction "choix_scores".
                        }
                        else if(choixMenu == 4)//Choix 4 (Options) sélectionné.
                        {
                            //Effacement de l'écran
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                            choix_options(ecran, &music, &sound, &mode);//Appel fonction "choix_options".
                        }
                        else if(choixMenu == 5)//Choix 5 (Exit) sélectionné.
                        {
                            continuer = 0;//Variable mise à valeur de sortie de boucle.
                        }
                    break;
                }
            break;
        }

        //Effacement de l'écran.
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        //Colle les surfaces préalablement chargées dans des pointeurs de surface.
        SDL_BlitSurface(ecranTitre, NULL, ecran, &positionEcranTitre);
        SDL_BlitSurface(menuStartGame, NULL, ecran, &positionStartGame);
        SDL_BlitSurface(menuContinue, NULL, ecran, &positionContinue);
        SDL_BlitSurface(menuScores, NULL, ecran, &positionScores);
        SDL_BlitSurface(menuOptions, NULL, ecran, &positionOptions);
        SDL_BlitSurface(menuExit, NULL, ecran, &positionExit);

        //Mise à jour de l'écran
        SDL_Flip(ecran);
    }

    //Désallocation des surfaces.
    SDL_FreeSurface(ecranTitre);
    SDL_FreeSurface(menuStartGame);
    SDL_FreeSurface(menuContinue);
    SDL_FreeSurface(menuScores);
    SDL_FreeSurface(menuOptions);
    SDL_FreeSurface(menuExit);
    SDL_FreeSurface(ecran);
    //Quitte la SDL.
    SDL_Quit();

    remove("score.txt");//Suppression du fichier "score.txt".

return EXIT_SUCCESS;//Retourne un succès à la fonction main (EXIT_SUCCESS est une variable globale SDL).
}
