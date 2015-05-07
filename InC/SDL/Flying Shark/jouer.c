/*
Rôle : Regroupe les fonctions gérant la partie "start game" du jeu accessible par le menu principal.
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
#include "jouer.h"//Bibliothèque contenant les prototypes de jouer.c
#include "fonctions.h"//Bibliothèque contenant les prototypes de fonction.c

//Fonction choix_startgame, fonction gérant le lancement d'une nouvelle partie. Celle-ci est lue après que "Start game" soit validé dans le menu principal.
void jouer(SDL_Surface *ecran, char nom[100], char levelRecup[100], char scoreRecup[100], int choixMenu, int *music, int *sound, int *mode)
{
    nom[0] = '\0';
    //Déclaration des variables de type SDL.
    SDL_Surface *mainPlane = NULL, *mainPlaneOmbre = NULL, *map = NULL, *texte = NULL, *gameover = NULL;
    SDL_Rect positionMainPlane, positionMainPlaneOmbre, positionMap, position, positionGameover;
    SDL_Event event;

    //Déclaration des autres variables.
    int continuer = 1, sens = STATIC, numeroTir = 0, numeroTirEnnemi = 0, i = 0, y = 0, z = 0, numeroEnnemi = 0, numeroExplosion = 0, numeroBombe = 0, numeroBombeAffichage = 3, game_over_on, typeExplosion = TIR;
    int tempsPresentTir = 0, tempsPasseTir = 0, tempsPresentBombe = 0, tempsPasseBombe = 0, tempsPresentPause = 0, tempsPassePause = 0, tempsPresentAnimation = 0, tempsPasseAnimation = 0;
    int level = 0, score = 0, avertissement = 0, bonus = 0, tempsBonus = 0;
    float compteur;
    char caractere = 0, text_score[50];
    FILE *fichier = NULL;

    level = atoi(levelRecup);
    score = atoi(scoreRecup);

    //Sert à gérer les événements plus facilement.
    Struct_Event worker;//Variable worker de type Struct_Event (Type créé dans le fichier constantes.h).

    //Les tableaux ci-dessous servent à gérer les tirs, les ennemis et les explosions.
    Struct_Tir tir[NBRE_TIR_MAX];//Tableau tir de type Struct_Tir (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_TIR_MAX".
    Struct_Tir tir_ennemi[NBRE_TIR_ENNEMI_MAX];//Tableau tir de type Struct_Tir (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_TIR_MAX".
    Struct_Ennemi ennemi[NBRE_ENNEMI_MAX];//Tableau ennemi de type Struct_Ennemi (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_ENNEMI_MAX".
    Struct_Explosion explosion[NBRE_ENNEMI_MAX];//Tableau explosion de type Struct_Explosion (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_ENNEMI_MAX".
    Struct_Bombe bombe[NBRE_TIR_MAX];//Tableau bombe de type Struct_Bombe (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_TIR_MAX".
    Struct_Bombe bombe_affichage[NBRE_BOMBE_MAX];//Tableau bombe de type Struct_Bombe (Type créé dans le fichier constantes.h) dont la taille est la constante "NBRE_TIR_MAX".
    //NBRE_TIR_MAX est utilisé pour le tableau bombe afin de simplifier le code malgré que ce soit moins claire au niveau lecture.

    //Initialisation des caractéristiques relatives aux tableaux.
    for(i = 0 ; i < NBRE_TIR_MAX ; i++)
    {
        tir[i].surfaceTir = NULL;
        tir[i].positionTir.x = -999;
        tir[i].positionTir.y = -999;
    }

    for(i = 0 ; i < NBRE_TIR_ENNEMI_MAX ; i++)
    {
        tir_ennemi[i].surfaceTir = NULL;
        tir_ennemi[i].positionTir.x = -999;
        tir_ennemi[i].positionTir.y = -999;
    }

    for(i = 0 ; i < NBRE_ENNEMI_MAX ; i++)
    {
        ennemi[i].surfaceEnnemi = NULL;//Pas de surface assignée.
        ennemi[i].positionEnnemi.x = -999;//Place hors de l'écran.
        ennemi[i].positionEnnemi.y = -999;//Place hors de l'écran.
        ennemi[i].sensEnnemi = 0;
        ennemi[i].type = 0;

        explosion[i].surfaceExplosion = NULL;
        explosion[i].positionExplosion.x = -999;//Place hors de l'écran.
        explosion[i].positionExplosion.y = -999;//Place hors de l'écran.
        explosion[i].compteurAnimation = 0;
    }

    for(i = 0 ; i < NBRE_BOMBE_MAX ; i++)
    {
        if(i == 0)
        {
            bombe_affichage[i].surfaceBombe = IMG_Load("sprites/bombe.png");//Charge l'image.
            bombe_affichage[i].positionBombe.x = 600;
            bombe_affichage[i].positionBombe.y = 440;
        }
        else if(i == 1)
        {
            bombe_affichage[i].surfaceBombe = IMG_Load("sprites/bombe.png");//Charge l'image.
            bombe_affichage[i].positionBombe.x = 560;
            bombe_affichage[i].positionBombe.y = 440;
        }
        else if(i == 2)
        {
            bombe_affichage[i].surfaceBombe = IMG_Load("sprites/bombe.png");//Charge l'image.
            bombe_affichage[i].positionBombe.x = 520;
            bombe_affichage[i].positionBombe.y = 440;
        }
        else
        {
            bombe_affichage[i].surfaceBombe = NULL;
            bombe_affichage[i].positionBombe.x = -999;
            bombe_affichage[i].positionBombe.y = -999;
        }
    }

    for(i = 0 ; i < NBRE_TIR_MAX ; i++)
    {
        bombe[i].surfaceBombe = NULL;
        bombe[i].positionBombe.x = -999;
        bombe[i].positionBombe.y = -999;
    }

    if(level == 1)
    {
        //Ouverture du fichier correspondant à la mission 1.
        fichier = fopen("config/missions/mission1.level" , "r");
        map = IMG_Load("sprites/level1.png");//Charge l'image.
    }
    else if(level == 2)
    {
        //Ouverture du fichier correspondant à la mission 2.
        fichier = fopen("config/missions/mission2.level" , "r");
        map = IMG_Load("sprites/level2.png");//Charge l'image.
    }

    //Vérif si le fichier est bien ouvert.
    if(fichier == NULL)
    {
        fprintf(stderr, "Erreur d'ouverture de fichier : %s\n", TTF_GetError());//Message d'erreur.
        exit(EXIT_FAILURE);//Ferme le programme.
    }

    TTF_Init();//Initialisation de la bibliothèque de gestion de texte.
    //Vérif l'initialisation.
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());//Message d'erreur.
        exit(EXIT_FAILURE);//Ferme le programme.
    }

    SDL_Color couleurBlanche = {255, 255, 255};//Variable de type couleur stockant la couleur blanche.
    SDL_Color couleurRouge = {200, 0, 0};//Variable de type couleur stockant la coucleur rouge.

    //Déclaration des variables de type FMOD.
    FMOD_SYSTEM *system;

    FMOD_SOUND *tirSound;
    FMOD_RESULT resultat;

    FMOD_SOUND *fondSound;
    FMOD_RESULT resultatFond;

    FMOD_SOUND *explosionSound;
    FMOD_RESULT resultatExplosion;

    FMOD_SOUND *gameoverSound;
    FMOD_RESULT resultatGameover;

    //Initialisation de FMOD.
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 4, FMOD_INIT_NORMAL, NULL);

    resultat = FMOD_System_CreateSound(system, "songs/tir.wav", FMOD_CREATESAMPLE, 0, &tirSound);
    resultatFond = FMOD_System_CreateSound(system, "songs/song001.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &fondSound);
    resultatExplosion = FMOD_System_CreateSound(system, "songs/explosion.mp3", FMOD_CREATESAMPLE, 0, &explosionSound);
    resultatGameover = FMOD_System_CreateSound(system, "songs/gameover.mid", FMOD_CREATESAMPLE, 0, &gameoverSound);

    //FMOD_Sound_SetLoopCount(fondSound, -1);//Active la répétition du son de fond.

    if(*music == 1)
    {
    FMOD_System_PlaySound(system, 0, fondSound, 0, NULL);//Joue le son de fond sur le canal 0.
    }

    //Déclaration des coordonnées de l'image de la map.
    positionMap.x = 0;//Abscisse de l'image.
    positionMap.y = 0;//Ordonnée de l'image.

    compteur = 9120;//Variable gérant les coordonnées pour le scrolling (Taille de la map - HAUTEUR_FENETRE).

    //Déclaration des coordonnées et chargement de l'image de l'avion.
    mainPlane = IMG_Load("sprites/avionmain2.gif");//Charge l'image.
    positionMainPlane.x = 412;//Abscisse de l'image.
    positionMainPlane.y = 276;//Ordonnée de l'image.

    positionMainPlaneOmbre.x = 430;//Abscisse de l'image.
    positionMainPlaneOmbre.y = 300;//Ordonnée de l'image.

    //Déclaration des coordonnées et chargement de l'image de game over.
    gameover = IMG_Load("sprites/gameover.jpg");//Charge l'image.
    positionGameover.x = 0;//Abscisse de l'image.
    positionGameover.y = 0;//Ordonnée de l'image.

    memset(&worker, 0, sizeof(worker));//Met la structure worker à 0 (key et quit).

    //Décollage
    SDL_BlitSurface(map, NULL, ecran, &positionMap);
    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
    SDL_Flip(ecran);

    for(i = 0 ; i != 330 ; i++)
    {
        positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
        compteur = compteur - 2;//Nouvelle valeure pour le compteur.

        if(i == 300)
        {
            mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
            mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
            positionMainPlane.x -= 2;//Abscisse de l'image.
            positionMainPlaneOmbre.x -= 2;//Abscisse de l'image.

            positionMainPlaneOmbre.x += 10;//Abscisse de l'image.
            positionMainPlaneOmbre.y += 10;//Ordonnée de l'image.
        }
        else if(i == 329)
        {
            mainPlane = IMG_Load("sprites/avionmain.gif");//Charge l'image.
            mainPlaneOmbre = IMG_Load("sprites/avionmainombre.gif");//Charge l'image.
            positionMainPlane.x -= 2;//Abscisse de l'image.
            positionMainPlaneOmbre.x -= 2;//Abscisse de l'image.

            positionMainPlaneOmbre.x += 10;//Abscisse de l'image.
            positionMainPlaneOmbre.y += 10;//Ordonnée de l'image.
        }

        SDL_BlitSurface(map, NULL, ecran, &positionMap);
        SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
        SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
        fc_texte(ecran, "Décollage !", 5, 50, couleurRouge, 60);
        SDL_Flip(ecran);


        SDL_Delay(10);

    }
    //Fin décollage.

    while(!worker.key[SDLK_ESCAPE] && continuer == 1)//Tant que la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "échap") contenu dans la variable "worker" de type Struct_Event est différent de 1 (Tant qu'on appuie pas sur "echap").
    {
        gestion_events_poll(&worker);//Appel de la fonction "gestion_events_poll" (dans le fichier fonctions.c) avec adresse de worker en paramètre. Si des touches sont enfoncées elles sont mises à 1 (0 pas enfoncées) dans leurs cases correspondantes dans le tableau "worker.key".
        if(worker.key[SDLK_LEFT])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "flèche ") contenu dans la variable "worker" de type Struct_Event est = à 1.
        {
            sens = GAUCHE;//Assigne le sens de déplacement (ici gauche) pour l'avion du joueur.
            fc_sens(&mainPlane, &positionMainPlane, &mainPlaneOmbre, &positionMainPlaneOmbre, &sens);//Appel de la fonction fc_sens (fichier fonctions.c).
            sens = STATIC;//Assigne le sens de déplacement (ici aucun déplacement) pour l'avion du joueur.
        }

        if(worker.key[SDLK_RIGHT])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "flèche droite") contenu dans la variable worker de type Struct_Event est = à 1.
        {
            sens = DROITE;//Assigne le sens de déplacement (ici droite) pour l'avion du joueur.
            fc_sens(&mainPlane, &positionMainPlane, &mainPlaneOmbre, &positionMainPlaneOmbre, &sens);//Appel de la fonction fc_sens (fichier fonctions.c).
            sens = STATIC;//Assigne le sens de déplacement (ici aucun déplacement) pour l'avion du joueur.
        }

        if(worker.key[SDLK_UP])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "flèche haut") contenu dans la variable worker de type Struct_Event est = à 1.
        {
            sens = HAUT;//Assigne le sens de déplacement (ici droite) pour l'avion du joueur.
            fc_sens(&mainPlane, &positionMainPlane, &mainPlaneOmbre, &positionMainPlaneOmbre, &sens);//Appel de la fonction fc_sens (fichier fonctions.c).
            sens = STATIC;//Assigne le sens de déplacement (ici aucun déplacement) pour l'avion du joueur.
        }

        if(worker.key[SDLK_DOWN])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "flèche bas") contenu dans la variable worker de type Struct_Event est = à 1.
        {
            sens = BAS;//Assigne le sens de déplacement (ici droite) pour l'avion du joueur.
            fc_sens(&mainPlane, &positionMainPlane, &mainPlaneOmbre, &positionMainPlaneOmbre, &sens);//Appel de la fonction fc_sens (fichier fonctions.c).
            sens = STATIC;//Assigne le sens de déplacement (ici aucun déplacement) pour l'avion du joueur.
        }

        if(worker.key[SDLK_p])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "p") contenu dans la variable worker de type Struct_Event est = à 1.
        {
            FMOD_CHANNEL *channel;//Pointeur de type channel.
            FMOD_System_GetChannel(system, 0, &channel);//On récupère le channel 0 dans le pointeur "channel".

            FMOD_Channel_SetPaused(channel, 1);//On met en pause le channel contenu dans le pointeur "channel" (ici c'est le channel 0).

            fc_texte(ecran, "PAUSE", 260, 200, couleurBlanche, 50);//Affiche "pause" à l'écran.
            SDL_Flip(ecran);

            while(worker.key[SDLK_p] != 0)//Tant que la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "touche p") contenu dans la variable worker de type Struct_Event est != de 0 (Tant que la touche "p" n'est pas relevé).
            {
                gestion_events_poll(&worker);//Appel de la fonction "gestion_events_poll" (dans le fichier fonctions.c) avec adresse de worker en paramètre. Si des touches sont enfoncées elles sont mises à 1 (0 pas enfoncées) dans leurs cases correspondantes dans le tableau "worker.key".
            }

            fc_pause();//La touche p vient d'être enfoncée puis relevée, on appel maintenant la fonction pause afin d'attendre qu'on réappuie sur la touche "p".

            if(*music == 1)
            {
                FMOD_Channel_SetPaused(channel, 0);//On enlève la pause du channel contenu dans le pointeur "channel" (ici c'est le channel 0).
            }

            memset(&worker, 0, sizeof(worker));//Met la structure worker à 0 (key et quit).
        }

        if(worker.key[SDLK_b])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "b") contenu dans la variable worker de type Struct_Event est = à 1.
        {
            if(numeroBombeAffichage > 0)
            {
                if(numeroBombe < NBRE_TIR_MAX)//Si le numero de la bombe actuelle n'est pas supérieur au nombre de bombe max autorisée sur l'écran.
                {
                    tempsPresentBombe = SDL_GetTicks();//On stocke le temps écoulé depuis le lancement du programme.
                    if(tempsPresentBombe - tempsPasseBombe > 1000)// Si le temps écoulé depuis le lancement du programme - le temps écoulé depuis la dernière fois qu'on a appuyé sur b est supérieur à 200ms.
                    {
                    fc_tir(tir, bombe, &positionMainPlane, &numeroTir, &numeroBombe, system, tirSound, 1, music, sound, mode, &bonus);//Appel de la fonction fc_tir (fichier fonctions.c). Gère la création d'une bombe.
                    numeroBombeAffichage--;
                    tempsPasseBombe = tempsPresentBombe;//On stocke le temps contenu dans tempsPresentTir (Evite de rappeler encore la fonction SDL_GetTicks).
                    }
                }
            }
        }

        if(worker.key[SDLK_RIGHT] == 0 && worker.key[SDLK_LEFT] == 0 || worker.key[SDLK_RIGHT] == 1 && worker.key[SDLK_LEFT] == 1)//Remise de l'avion en static après l'appuie de touches simultanées vers la droite ou gauche.
        {
            //Pas besoin de "sens = STATIC" ici car le sens est déjà en static à chaque fin de condition, il suffit de recharger l'image static.
            fc_sens(&mainPlane, &positionMainPlane, &mainPlaneOmbre, &positionMainPlaneOmbre, &sens);//Appel de la fonction fc_sens (fichier fonctions.c).
        }

        if(worker.key[SDLK_SPACE])//Si la valeur contenu dans le tableau "key" (à l'adresse du tableau de la valeur de la touche "espace") contenu dans la variable "worker" de type Struct_Event est = à 1. Si espace est enfoncé.
        {
            if(numeroTir <= NBRE_TIR_MAX)//Si le numero du tir actuel n'est pas supérieur au nombre de tir max autorisé sur l'écran.
            {
                tempsPresentTir = SDL_GetTicks();//On stocke le temps écoulé depuis le lancement du programme.
                if(tempsPresentTir - tempsPasseTir > 200)// Si le temps écoulé depuis le lancement du programme - le temps écoulé depuis la dernière fois qu'on a appuyé sur espace est supérieur à 200ms.
                {
                fc_tir(tir, bombe, &positionMainPlane, &numeroTir, &numeroBombe, system, tirSound, 0, music, sound, mode, &bonus);//Appel de la fonction fc_tir (fichier fonctions.c). Gère la création d'un tir.
                tempsPasseTir = tempsPresentTir;//On stocke le temps contenu dans tempsPresentTir (Evite de rappeler encore la fonction SDL_GetTicks).
                }
            }
        }

        if(worker.quit)//Si la valeur contenu dans la variable "quit" dans la variable "worker" de type Struct_Event est = à 1.
        {
            exit(EXIT_SUCCESS);//On arrête le programme.
        }

        caractere = fgetc(fichier);//On lit un caractère à partir de la position actuel du curseur dans le fichier et on stocke se caractère dans la variable "caractere".

        if(caractere != NULL)//Si un caractère a bien était lu.
        {
            fc_analyse_caractere(ennemi, caractere, &numeroEnnemi, fichier, &bonus);//On appel la fonction chargée d'analyser le caractère et d'agir en conséquence (création d'ennemi principalement).
        }

        if(compteur > 0 && (compteur > 5400 || compteur < 5400 - SCROLL) && (compteur > 5000 || compteur < 5000 - SCROLL) && (compteur > 4800 || compteur < 4800 - SCROLL) && (compteur > 800 || compteur < 800 - SCROLL) && (compteur > 200 || compteur < 200 - SCROLL))
        {
            positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
            compteur = compteur - SCROLL;//Nouvelle valeure pour le compteur.
        }
        else if(compteur <= 5400 && compteur >= 5400 - SCROLL || compteur <= 800 && compteur >= 800 - SCROLL)
        {
            avertissement = 1;
            positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
            compteur = compteur - SCROLL;//Nouvelle valeure pour le compteur.
        }
        else if(compteur <= 5000 && compteur >= 5000 - SCROLL || compteur <= 400 && compteur >= 400 - SCROLL)
        {
            avertissement = 0;
            positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
            compteur = compteur - SCROLL;//Nouvelle valeure pour le compteur.
        }
        else if(compteur <= 4800 && compteur >= 4800 - SCROLL)
        {
            if(positionMainPlane.x < 315 || positionMainPlane.x > 400)
            {
                for(i = 0 ; i <= 150 ; i++)
                {
                    positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                    compteur = compteur - 2;//Nouvelle valeure pour le compteur.

                    if(i == 50)
                    {
                        mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }
                    else if(i == 90)
                    {
                        mainPlane = IMG_Load("sprites/avionmain2.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmainombre2.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }

                    SDL_BlitSurface(map, NULL, ecran, &positionMap);
                    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
                    SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
                    SDL_Flip(ecran);

                    SDL_Delay(10);
                }
                mainPlane = NULL;//On enlève la suface assignée au à l'ennemi en colision.
                explosion[y].positionExplosion.x = positionMainPlane.x - 25;//On met l'abscisse de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                explosion[y].positionExplosion.y = positionMainPlane.y - 25;//On met l'ordonnée de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                explosion[y].surfaceExplosion = IMG_Load("sprites/explosion01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                typeExplosion = TIR;
            }
            else
            {
                for(i = 0 ; i <= 150 ; i++)
                {
                    positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                    compteur = compteur - 2;//Nouvelle valeure pour le compteur.

                    if(i == 50)
                    {
                        mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }
                    else if(i == 90)
                    {
                        mainPlane = IMG_Load("sprites/avionmain2.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmainombre2.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }

                    SDL_BlitSurface(map, NULL, ecran, &positionMap);
                    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
                    SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
                    SDL_Flip(ecran);

                    SDL_Delay(10);
                }
                while(numeroBombeAffichage > 3)
                {
                    score += 3000;
                    numeroBombeAffichage--;
                }
                fc_texte(ecran, "Merci pour les stocks de bombes.", 50, 50, couleurRouge, 50);
                SDL_Flip(ecran);
                SDL_Delay(5000);
                for(i = 0 ; i <= 150 ; i++)
                {
                    positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                    compteur = compteur - 2;//Nouvelle valeure pour le compteur.

                    if(i == 100)
                    {
                        mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
                        positionMainPlane.x -= 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x -= 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x += 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y += 10;//Ordonnée de l'image.
                    }
                    else if(i == 150)
                    {
                        mainPlane = IMG_Load("sprites/avionmain.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmainombre.gif");//Charge l'image.
                        positionMainPlane.x -= 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x -= 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x += 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y += 10;//Ordonnée de l'image.
                    }

                    SDL_BlitSurface(map, NULL, ecran, &positionMap);
                    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
                    SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
                    fc_texte(ecran, "Décollage !", 5, 50, couleurRouge, 60);
                    SDL_Flip(ecran);

                    SDL_Delay(10);
                }
            }
            positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
            compteur = compteur - SCROLL;//Nouvelle valeure pour le compteur.
        }
        else if(compteur <= 200 && compteur >= 1 - SCROLL)
        {
            if(positionMainPlane.x < 420 || positionMainPlane.x > 510)
            {
                for(i = 0 ; i <= 150 ; i++)
                {
                    positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                    compteur = compteur - 2;//Nouvelle valeure pour le compteur.

                    if(i == 50)
                    {
                        mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }
                    else if(i == 90)
                    {
                        mainPlane = IMG_Load("sprites/avionmain2.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmainombre2.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }

                    SDL_BlitSurface(map, NULL, ecran, &positionMap);
                    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
                    SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
                    SDL_Flip(ecran);

                    SDL_Delay(10);
                }
                mainPlane = NULL;//On enlève la suface assignée au à l'ennemi en colision.
                explosion[y].positionExplosion.x = positionMainPlane.x - 25;//On met l'abscisse de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                explosion[y].positionExplosion.y = positionMainPlane.y - 25;//On met l'ordonnée de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                explosion[y].surfaceExplosion = IMG_Load("sprites/explosion01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                typeExplosion = TIR;
            }
            else
            {
                for(i = 0 ; i <= 150 ; i++)
                {
                    positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                    compteur = compteur - 2;//Nouvelle valeure pour le compteur.

                    if(i == 50)
                    {
                        mainPlane = IMG_Load("sprites/avionmain3.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmain3ombre.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }
                    else if(i == 90)
                    {
                        mainPlane = IMG_Load("sprites/avionmain2.gif");//Charge l'image.
                        mainPlaneOmbre = IMG_Load("sprites/avionmainombre2.gif");//Charge l'image.
                        positionMainPlane.x += 2;//Abscisse de l'image.
                        positionMainPlaneOmbre.x += 2;//Abscisse de l'image.

                        positionMainPlaneOmbre.x -= 10;//Abscisse de l'image.
                        positionMainPlaneOmbre.y -= 10;//Ordonnée de l'image.
                    }

                    SDL_BlitSurface(map, NULL, ecran, &positionMap);
                    SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
                    SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);
                    SDL_Flip(ecran);

                    SDL_Delay(10);
                }
                positionMap.y = 0 - compteur;//Ordonnée de la map = 0 - la valeur du compteur.
                compteur = compteur - SCROLL;//Nouvelle valeure pour le compteur.
            }
        }
        else if(compteur < 1 - SCROLL)
        {
            //Effacement de l'écran
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

            //Recolle des surfaces.
            SDL_BlitSurface(map, NULL, ecran, &positionMap);
            SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);

            fc_texte(ecran, "Saisissez un nom de joueur pour la sauvegarde :", 3, 50, couleurBlanche, 35);
            SDL_Flip(ecran);

            sauvegarde(ecran, couleurBlanche, nom, level, score, choixMenu);

            continuer = 0;
        }

        //Gestion des déplacements des tirs créés précèdement ainsi que leurs conditions de collision.
        for(i = 0 ; i < NBRE_TIR_MAX ; i++)//On parcourt chaque tir jusqu'au nombre maximum de tir possible sur la map (définit par NBRE_TIR_MAX).
        {
            if(tir[i].positionTir.y > 10 && tir[i].surfaceTir != NULL)//Si le tir contient bien une surface et que celui-ci n'est pas arrivé en haut de l'écran.
            {
                tir[i].positionTir.y -= 5;//On le bouge de 5 pixels vers le haut de l'écran.
            }
            if(bombe[i].positionBombe.y > 10 && bombe[i].surfaceBombe != NULL)//Si la bombe contient bien une surface et que celle-ci n'est pas arrivée en haut de l'écran.
            {
                bombe[i].positionBombe.y -= 5;//On la bouge de 5 pixels vers le haut de l'écran.
            }
            if(tir[i].positionTir.y <= 10 && tir[i].surfaceTir != NULL)//Si le tir contient bien une surface et que celui-ci est arrivé en haut de l'écran.
            {
                tir[i].surfaceTir = NULL;//On lui enlève la surface assignée.
                tir[i].positionTir.x = -999;//On met la position abscisse à 0. A gauche sur l'écran.
                tir[i].positionTir.y = -999;//On met la position ordonnée à 480. En bas sur l'écran.
            }
            if(bombe[i].positionBombe.y <= 10 && bombe[i].surfaceBombe != NULL)//Si la bombe contient bien une surface et que celle-ci est arrivée en haut de l'écran.
            {
                bombe[i].surfaceBombe = NULL;//On lui enlève la surface assignée.
                bombe[i].positionBombe.x = -999;//On met la position abscisse à 0. A gauche sur l'écran.
                bombe[i].positionBombe.y = -999;//On met la position ordonnée à 480. En bas sur l'écran.
            }
            if(tir_ennemi[i].positionTir.y < 480 && tir_ennemi[i].surfaceTir != NULL)//Si le tir contient bien une surface et que celui-ci n'est pas arrivé en bas de l'écran.
            {
                tir_ennemi[i].positionTir.y += 3;//On le bouge de 5 pixels vers le bas de l'écran.
            }
            if(tir_ennemi[i].positionTir.y >= 480 && tir_ennemi[i].surfaceTir != NULL)//Si le tir contient bien une surface et que celui-ci est arrivé en bas de l'écran.
            {
                tir_ennemi[i].surfaceTir = NULL;//On lui enlève la surface assignée.
                tir_ennemi[i].positionTir.x = -999;//On met la position abscisse à 0. A gauche sur l'écran.
                tir_ennemi[i].positionTir.y = -999;//On met la position ordonnée à 480. En bas sur l'écran.
            }

            for(y = 0 ; y < NBRE_ENNEMI_MAX ; y++)//Pour chaque tir, on parcourt chaque ennemi jusqu'au nombre maximum d'ennemi possible sur la map afin de gérer les colisions.
            {
                if(ennemi[y].type == 0)
                {
                    //Test de la colision entre l'ennemi en cours et l'avion principal.
                    if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x > positionMainPlane.x - 25 && ennemi[y].positionEnnemi.x < positionMainPlane.x + 50 && ennemi[y].positionEnnemi.y > positionMainPlane.y - 34 && ennemi[y].positionEnnemi.y < positionMainPlane.y + 34))
                    {
                        mainPlane = NULL;
                        ennemi[y].surfaceEnnemi = NULL;
                        explosion[y].positionExplosion.x = positionMainPlane.x - 25;//On met l'abscisse de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].positionExplosion.y = positionMainPlane.y - 25;//On met l'ordonnée de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].surfaceExplosion = IMG_Load("sprites/explosion01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                        explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                        typeExplosion = TIR;
                        game_over_on = 1;
                    }


                    /*Ci dessous : Chaque explosion correspond à un ennemi (NBRE_ENNEMI_MAX = NBRE_EXPLOSION_MAX).
                    On vérifie si la surface de l'explosion est bien nulle (Inutile mais précaution pour la suite en cas d'ajout d'autres règles).
                    On vérifie si le tir en cours contient bien une surface.
                    Enfin on vérifie si les coorconnées du tir en cours et de l'ennemi testé sont en correspondances pour qu'il y ait bien colision.
                    Si tout est vérifié, on rentre dans la condition.
                    */
                    if(ennemi[y].surfaceEnnemi != NULL && explosion[y].surfaceExplosion == NULL && tir[i].surfaceTir != NULL && tir[i].positionTir.y > ennemi[y].positionEnnemi.y && tir[i].positionTir.y < (ennemi[y].positionEnnemi.y + 40) && tir[i].positionTir.x > ennemi[y].positionEnnemi.x && tir[i].positionTir.x < (ennemi[y].positionEnnemi.x + 50))
                    {
                        score += 200;
                        if(*sound == 1)
                        {
                        //FMOD_System_PlaySound(system, 2, explosionSound, 0, NULL);
                        }
                        tir[i].surfaceTir = NULL;//On enlève la suface assignée au tir actuel.
                        ennemi[y].surfaceEnnemi = NULL;//On enlève la surface assignée à l'ennemi en colision.
                        tir[i].positionTir.x = -999;//On remet l'abscisse hors de l'écran.
                        tir[i].positionTir.y = -999;//On remet l'ordonnée hors de l'écran.
                        explosion[y].positionExplosion.x = ennemi[y].positionEnnemi.x - 25;//On met l'abscisse de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].positionExplosion.y = ennemi[y].positionEnnemi.y - 25;//On met l'ordonnée de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].surfaceExplosion = IMG_Load("sprites/explosion01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                        explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                        typeExplosion = TIR;
                    }
                    else if(ennemi[y].surfaceEnnemi != NULL && explosion[y].surfaceExplosion == NULL && bombe[i].surfaceBombe != NULL && bombe[i].positionBombe.y > ennemi[y].positionEnnemi.y && bombe[i].positionBombe.y < (ennemi[y].positionEnnemi.y + 40) && bombe[i].positionBombe.x > ennemi[y].positionEnnemi.x && bombe[i].positionBombe.x < (ennemi[y].positionEnnemi.x + 50))
                    {
                        if(*sound == 1)
                        {
                        //FMOD_System_PlaySound(system, 2, explosionSound, 0, NULL);
                        }
                        explosion[y].positionExplosion.x = ennemi[y].positionEnnemi.x - 230;//On met l'abscisse de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].positionExplosion.y = ennemi[y].positionEnnemi.y - 230;//On met l'ordonnée de l'ennemi dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].surfaceExplosion = IMG_Load("sprites/explosionBombe01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                        explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                        for(z = 0 ; z < NBRE_ENNEMI_MAX ; z++)
                        {
                            if(ennemi[z].surfaceEnnemi != NULL && ennemi[z].positionEnnemi.x < (bombe[i].positionBombe.x + 200) && ennemi[z].positionEnnemi.x > (bombe[i].positionBombe.x - 200) && ennemi[z].positionEnnemi.y < (bombe[i].positionBombe.y + 200) && ennemi[z].positionEnnemi.y > (bombe[i].positionBombe.y - 200))
                            {
                                score += 200;
                                ennemi[z].surfaceEnnemi = NULL;//On enlève la suface assignée au à l'ennemi en colision.
                                ennemi[z].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                                ennemi[z].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                                ennemi[z].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                            }
                        }
                        bombe[i].surfaceBombe = NULL;//On enlève la suface assignée à la bombe actuel.
                        bombe[i].positionBombe.x = -999;//On remet l'abscisse hors de l'écran.
                        bombe[i].positionBombe.y = -999;//On remet l'ordonnée hors de l'écran.
                        typeExplosion = BOMBE;
                    }
                    else if(mainPlane != NULL && explosion[y].surfaceExplosion == NULL && tir_ennemi[i].surfaceTir != NULL && tir_ennemi[i].positionTir.y > positionMainPlane.y && tir_ennemi[i].positionTir.y < (positionMainPlane.y + 40) && tir_ennemi[i].positionTir.x > positionMainPlane.x && tir_ennemi[i].positionTir.x < (positionMainPlane.x + 50))
                    {
                        score += 200;
                        if(*sound == 1)
                        {
                        //FMOD_System_PlaySound(system, 2, explosionSound, 0, NULL);
                        }
                        tir_ennemi[i].surfaceTir = NULL;//On enlève la suface assignée à la bombe actuel.
                        mainPlane = NULL;//On enlève la suface assignée au à l'ennemi en colision.
                        tir_ennemi[i].positionTir.x = -999;//On remet l'abscisse hors de l'écran.
                        tir_ennemi[i].positionTir.y = -999;//On remet l'ordonnée hors de l'écran.
                        explosion[y].positionExplosion.x = positionMainPlane.x - 25;//On met l'abscisse du main plane dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].positionExplosion.y = positionMainPlane.y - 25;//On met l'ordonnée du main plane dans l'explosion afin de jouer l'animation à la bonne place.
                        explosion[y].surfaceExplosion = IMG_Load("sprites/explosion01.png");//Charge l'image d'anim. Chargée ici pour faire une vérif de plus dans l'autre boucle.
                        positionMainPlane.x = -999;//On remet l'abscisse hors de l'écran.
                        positionMainPlane.y = -999;//On remet l'ordonnée hors de l'écran.
                        explosion[y].compteurAnimation = 4;//Compteur animation à 4 afin de déclencher l'animation.
                        game_over_on = 1;
                        typeExplosion = TIR;
                    }
                }
                else if(ennemi[y].type == 1)
                {
                    if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x > positionMainPlane.x - 25 && ennemi[y].positionEnnemi.x < positionMainPlane.x + 50 && ennemi[y].positionEnnemi.y > positionMainPlane.y - 34 && ennemi[y].positionEnnemi.y < positionMainPlane.y + 34))
                    {
                        bonus = 1;
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                    else if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x < 10 || ennemi[y].positionEnnemi.x > 640 || ennemi[y].positionEnnemi.y < 10 || ennemi[y].positionEnnemi.y > 480))
                    {
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                }
                else if(ennemi[y].type == 2)
                {
                    if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x > positionMainPlane.x - 25 && ennemi[y].positionEnnemi.x < positionMainPlane.x + 50 && ennemi[y].positionEnnemi.y > positionMainPlane.y - 34 && ennemi[y].positionEnnemi.y < positionMainPlane.y + 34))
                    {
                        bombe_affichage[numeroBombeAffichage].surfaceBombe = IMG_Load("sprites/bombe.png");//Charge l'image.
                        bombe_affichage[numeroBombeAffichage].positionBombe.x = bombe_affichage[numeroBombeAffichage - 1].positionBombe.x - 40;
                        bombe_affichage[numeroBombeAffichage].positionBombe.y = 440;
                        numeroBombeAffichage++;
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                    else if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x < 10 || ennemi[y].positionEnnemi.x > 640 || ennemi[y].positionEnnemi.y < 10 || ennemi[y].positionEnnemi.y > 480))
                    {
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                }
                else if(ennemi[y].type == 3)
                {
                    if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x > positionMainPlane.x - 25 && ennemi[y].positionEnnemi.x < positionMainPlane.x + 50 && ennemi[y].positionEnnemi.y > positionMainPlane.y - 34 && ennemi[y].positionEnnemi.y < positionMainPlane.y + 34))
                    {
                        bonus = 2;
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                    else if(ennemi[y].surfaceEnnemi != NULL && (ennemi[y].positionEnnemi.x < 10 || ennemi[y].positionEnnemi.x > 640 || ennemi[y].positionEnnemi.y < 10 || ennemi[y].positionEnnemi.y > 480))
                    {
                        ennemi[y].surfaceEnnemi = NULL;
                        ennemi[y].positionEnnemi.x = -999;//On remet l'abscisse hors de l'écran.
                        ennemi[y].positionEnnemi.y = -999;//On remet l'ordonnée hors de l'écran.
                        ennemi[y].sensEnnemi = 0;//On remet le sens à 0, correspond à l'initialisation.
                    }
                }
            }
        }

        if(typeExplosion == TIR)
        {
            for(i = 0 ; i < NBRE_EXPLOSION_MAX ; i++)//On parcourt chaque explosion jusqu'au nombre maximum d'explosion possible sur la map (définit par NBRE_EXPLOSION_MAX).
            {
                if(explosion[i].compteurAnimation != 0 && explosion[i].surfaceExplosion != NULL)//si l'animation n'est pas fini et l'explosion n'est pas nulle.
                {
                    if(explosion[i].compteurAnimation == 4)//Si l'animation est à 4.
                    {
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(3);
                    }
                    else if(explosion[i].compteurAnimation == 3)//Si l'animation est à 3.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosion02.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(3);
                    }
                    else if(explosion[i].compteurAnimation == 2)//Si l'animation est à 2.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosion03.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(3);
                    }
                    else if(explosion[i].compteurAnimation == 1)//Si l'animation est à 1.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosion04.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(3);
                        explosion[i].surfaceExplosion = NULL;//C'était la dernière image de l'animation, on met l'explosion à nulle.
                    }
                }
            }
        }
        else if(typeExplosion == BOMBE)
        {
            for(i = 0 ; i < NBRE_EXPLOSION_MAX ; i++)//On parcourt chaque explosion jusqu'au nombre maximum d'explosion possible sur la map (définit par NBRE_EXPLOSION_MAX).
            {
                if(explosion[i].compteurAnimation != 0 && explosion[i].surfaceExplosion != NULL)//si l'animation n'est pas fini et l'explosion n'est pas nulle.
                {
                    if(explosion[i].compteurAnimation == 4)//Si l'animation est à 4.
                    {
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(5);
                    }
                    else if(explosion[i].compteurAnimation == 3)//Si l'animation est à 3.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosionBombe02.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(5);
                    }
                    else if(explosion[i].compteurAnimation == 2)//Si l'animation est à 2.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosionBombe03.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(5);
                    }
                    else if(explosion[i].compteurAnimation == 1)//Si l'animation est à 1.
                    {
                        explosion[i].surfaceExplosion = IMG_Load("sprites/explosionBombe04.png");//Charge l'image d'anim correspondante.
                        SDL_BlitSurface(explosion[i].surfaceExplosion, NULL, ecran, &explosion[i].positionExplosion);//On colle la surface
                        explosion[i].compteurAnimation--;//On descend le compteur de 1.
                        SDL_Flip(ecran);//Rafraichit l'écran.
                        SDL_Delay(5);
                        explosion[i].surfaceExplosion = NULL;//C'était la dernière image de l'animation, on met l'explosion à nulle.
                    }
                }
            }
        }


        if(game_over_on == 1)
        {
            if(*music == 1)
            {
            //Le niveau est fini.
            FMOD_CHANNEL *channel;//Pointeur de type channel.
            FMOD_System_GetChannel(system, 0, &channel);//On récupère le channel 0 dans le pointeur "channel".

            FMOD_Channel_SetPaused(channel, 1);//On met en pause le channel contenu dans le pointeur "channel" (ici c'est le channel 0).
            FMOD_System_PlaySound(system, 3, gameoverSound, 0, NULL);//Joue le son de game over.
            }

            for(i = 0 ; i != 255 ; i++)
            {
                SDL_SetAlpha(gameover, SDL_SRCALPHA, i);
                SDL_BlitSurface(gameover, NULL, ecran, &positionGameover);
                SDL_Flip(ecran);
                fc_gameover();
            }

            SDL_Delay(3000);
            fc_gameover();

            return EXIT_SUCCESS;//Retourne un succès à la fonction main (EXIT_SUCCESS est une variable globale SDL).
        }


        if(bonus == 1 || bonus == 2)
        {
            if(tempsBonus != 1500)
            {
                tempsBonus++;
            }
            else
            {
                bonus = 0;
                tempsBonus = 0;
            }
        }

        fc_ennemi_map(ennemi, numeroEnnemi, &numeroTirEnnemi, tir_ennemi, music, sound, mode, system, tirSound);//Appel de la fonction qui gère le déplacement des ennemis sur la map.

        //Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        //Recolle des surfaes.
        SDL_BlitSurface(map, NULL, ecran, &positionMap);
        SDL_BlitSurface(mainPlane, NULL, ecran, &positionMainPlane);
        SDL_BlitSurface(mainPlaneOmbre, NULL, ecran, &positionMainPlaneOmbre);

        for(i = 0 ; i < numeroBombeAffichage ; i++)//Parcours toutes les bombes en possession du joueur.
        {
            if(bombe_affichage[i].surfaceBombe != NULL)//Si la surface de la bombe actuelle est différente de nulle.
            {
                SDL_BlitSurface(bombe_affichage[i].surfaceBombe, NULL, ecran, &bombe_affichage[i].positionBombe);//On colle cette surface.
            }
        }

        for(i = 0 ; i < NBRE_BOMBE_MAX ; i++)//Parcours toutes les bombes.
        {
            if(bombe[i].surfaceBombe != NULL)//Si la surface de la bombe actuelle est différente de nulle.
            {
                SDL_BlitSurface(bombe[i].surfaceBombe, NULL, ecran, &bombe[i].positionBombe);//On colle cette surface.
            }
        }

        for(i = 0 ; i < NBRE_TIR_MAX ; i++)//Parcours tous les tirs.
        {
            if(tir[i].surfaceTir != NULL)//Si la surface du tir actuel est différente de nulle.
            {
                SDL_BlitSurface(tir[i].surfaceTir, NULL, ecran, &tir[i].positionTir);//On colle cette surface.
            }
        }

        for(i = 0 ; i < NBRE_ENNEMI_MAX ; i++)//Parcours tous les ennemis.
        {
            if(ennemi[i].surfaceEnnemi != NULL)//Si la surface de l'ennemi actuel est différent de nulle.
            {
                SDL_BlitSurface(ennemi[i].surfaceEnnemi, NULL, ecran, &ennemi[i].positionEnnemi);//On colle cette surface.
            }
        }

        for(i = 0 ; i < NBRE_TIR_ENNEMI_MAX ; i++)//Parcours tous les tirs ennemis.
        {
            if(tir_ennemi[i].surfaceTir != NULL)//Si la surface de l'ennemi actuel est différent de nulle.
            {
                SDL_BlitSurface(tir_ennemi[i].surfaceTir, NULL, ecran, &tir_ennemi[i].positionTir);//On colle cette surface.
            }
        }

        if(avertissement == 1)
        {
            fc_texte(ecran, "Préparez-vous, atterrissage !.", 50, 50, couleurRouge, 60);
        }

        fc_texte(ecran, "Score :", 5, 0, couleurBlanche, 50);//Affiche "Score" à l'écran.
        itoa(score, text_score, 10);
        //sprintf(text_score, "%d", score);
        fc_texte(ecran, text_score, 125, 0, couleurBlanche, 50);//Affiche le contenu de "score" à l'écran.

        SDL_Flip(ecran);//On actualise l'écran.
    }

    //On libère la mémoire allouée pour le son.
    FMOD_Sound_Release(tirSound);
    FMOD_Sound_Release(fondSound);
    FMOD_System_Close(system);
	FMOD_System_Release(system);

    //On ferme le fichier
	fclose(fichier);

    //On libère la mémoire allouée pour les surfaces de la SDL.
    SDL_FreeSurface(texte);
    SDL_FreeSurface(mainPlane);
    SDL_FreeSurface(map);

    for(i = 0 ; i < NBRE_BOMBE_MAX ; i++)//Boucle ou on parcours les tirs allouer.
    {
        SDL_FreeSurface(bombe_affichage[i].surfaceBombe);//On libère de la mémoire.
    }

    for(i = 0 ; i < NBRE_BOMBE_MAX ; i++)//Boucle ou on parcours les tirs allouer.
    {
        SDL_FreeSurface(bombe[i].surfaceBombe);//On libère de la mémoire.
    }

    for(i = 0 ; i < NBRE_TIR_MAX ; i++)//Boucle ou on parcours les tirs allouer.
    {
        SDL_FreeSurface(tir[i].surfaceTir);//On libère de la mémoire.
    }

    for(i = 0 ; i < NBRE_TIR_ENNEMI_MAX ; i++)//Boucle ou on parcours les tirs allouer.
    {
        SDL_FreeSurface(tir_ennemi[i].surfaceTir);//On libère de la mémoire.
    }

    for(i = 0 ; i < NBRE_ENNEMI_MAX ; i++)//Boucle ou on parcours les tirs allouer.
    {
        SDL_FreeSurface(ennemi[i].surfaceEnnemi);//On libère de la mémoire.
    }

    for(i = 0 ; i < NBRE_EXPLOSION_MAX ; i++)//Boucle ou on parcours les explosions allouer.
    {
        SDL_FreeSurface(explosion[i].surfaceExplosion);//On libère de la mémoire.
    }


    TTF_Quit();//On quitte la librairie qui gère le texte.

}
