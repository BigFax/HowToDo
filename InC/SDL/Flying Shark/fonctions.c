/*
Rôle : Regroupe les fonctions globales du programme.
*/
//Inclusion des bibliothèques "standard".
#include <stdlib.h>//Bibliothèque de base.
#include <stdio.h>//Bibliothèque de base.
#include <string.h>//Bibliothèque pour gérer les chaines de caractères.
#include <time.h>//Bibliothèque pour gérer le temps.
#include <SDL/SDL.h>//Bibliothèque SDL.
#include <SDL_image.h>//Bibliothèque pour gérer les images en SDL.
#include <fmodex/fmod.h>//Bibliothèque pour gérer le son.
#include <SDL/SDL_ttf.h>//Bibliothèque pour gérer le texte.
//Inclusion des bibliothèques "spéciales" au projet.
#include "constantes.h"//Bibliothèque contenant variables globales et structures.
#include "fonctions.h"//Bibliothèque contenant les prototypes de fonction.c


void fc_tir(Struct_Tir tir[], Struct_Bombe bombe[], SDL_Rect *positionMainPlane, int *numeroTir, int *numeroBombe, FMOD_SYSTEM **system, FMOD_SOUND **tirSound, int choix, int *music, int *sound, int *mode, int *bonus)
{
    if(choix)
    {
        if(*numeroBombe > NBRE_TIR_MAX - 1)
        {
            *numeroBombe = 0;
        }

        bombe[*numeroBombe].surfaceBombe = IMG_Load("sprites/bombe.png");
        bombe[*numeroBombe].positionBombe.x = positionMainPlane->x + 25;
        bombe[*numeroBombe].positionBombe.y = positionMainPlane->y - 5;
        if(*sound == 1)
        {
            FMOD_System_PlaySound(system, 1, tirSound, 0, NULL);
        }

        *numeroBombe += 1;
    }
    else
    {
        if(*bonus == 0)
        {
            if(*numeroTir > NBRE_TIR_MAX - 1)
            {
                *numeroTir = 0;
            }

            tir[*numeroTir].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir].positionTir.x = positionMainPlane->x + 25;
            tir[*numeroTir].positionTir.y = positionMainPlane->y - 5;
            if(*sound == 1)
            {
                FMOD_System_PlaySound(system, 1, tirSound, 0, NULL);
            }

            *numeroTir += 1;
        }
        else if(*bonus == 1)
        {
            if(*numeroTir > NBRE_TIR_MAX - 2)
            {
                *numeroTir = 0;
            }

            tir[*numeroTir].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir + 1].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir].positionTir.x = positionMainPlane->x + 10;
            tir[*numeroTir].positionTir.y = positionMainPlane->y - 5;
            tir[*numeroTir + 1].positionTir.x = positionMainPlane->x + 30;
            tir[*numeroTir + 1].positionTir.y = positionMainPlane->y - 5;
            if(*sound == 1)
            {
                FMOD_System_PlaySound(system, 1, tirSound, 0, NULL);
            }

            *numeroTir += 2;
        }
        else if(*bonus == 2)
        {
            if(*numeroTir > NBRE_TIR_MAX - 4)
            {
                *numeroTir = 0;
            }

            tir[*numeroTir].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir + 1].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir + 2].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir + 3].surfaceTir = IMG_Load("sprites/tir001.png");
            tir[*numeroTir].positionTir.x = positionMainPlane->x - 10;
            tir[*numeroTir].positionTir.y = positionMainPlane->y - 5;
            tir[*numeroTir + 1].positionTir.x = positionMainPlane->x + 10;
            tir[*numeroTir + 1].positionTir.y = positionMainPlane->y - 5;
            tir[*numeroTir + 2].positionTir.x = positionMainPlane->x + 30;
            tir[*numeroTir + 2].positionTir.y = positionMainPlane->y - 5;
            tir[*numeroTir + 3].positionTir.x = positionMainPlane->x + 50;
            tir[*numeroTir + 3].positionTir.y = positionMainPlane->y - 5;
            if(*sound == 1)
            {
                FMOD_System_PlaySound(system, 1, tirSound, 0, NULL);
            }

            *numeroTir += 4;
        }

    }
}

void fc_sens(SDL_Surface **mainPlane , SDL_Rect *positionMainPlane, SDL_Surface **mainPlaneOmbre, SDL_Rect *positionMainPlaneOmbre, int *sens)
{
    if(*sens == GAUCHE && positionMainPlane->x > 5)
    {
        *mainPlane = IMG_Load("sprites/avionmaingauche.gif");
        *mainPlaneOmbre = IMG_Load("sprites/avionmaingaucheombre.gif");
        positionMainPlane->x -= 1;
        positionMainPlaneOmbre->x -= 1;
    }
    else if(*sens == DROITE && positionMainPlane->x < 585)
    {
        *mainPlane = IMG_Load("sprites/avionmaindroite.gif");
        *mainPlaneOmbre = IMG_Load("sprites/avionmaindroiteombre.gif");
        positionMainPlane->x += 1;
        positionMainPlaneOmbre->x += 1;
    }
    else if(*sens == HAUT && positionMainPlane->y > 5)
    {
        positionMainPlane->y -= 1;
        positionMainPlaneOmbre->y -= 1;
    }
    else if(*sens == BAS && positionMainPlane->y < 441)
    {
        positionMainPlane->y += 1;
        positionMainPlaneOmbre->y += 1;
    }
    else if(*sens == STATIC)
    {
        *mainPlane = IMG_Load("sprites/avionmain.gif");
        *mainPlaneOmbre = IMG_Load("sprites/avionmainombre.gif");
    }
}

//Gère l'analyse d'un caractère
void fc_analyse_caractere(Struct_Ennemi ennemi[], char caractere, int *numeroEnnemi, FILE *fichier, int *bonus)
{
    char chaine[5] = "";//Prévoir le /0

    if(*numeroEnnemi > NBRE_ENNEMI_MAX - 1)
    {
        *numeroEnnemi = 0;
    }

    if(caractere == 'a')
    {
        fgets(chaine, 6, fichier);//On lit 5 caractères (avec le signe qu'on stocke dans chaine + le caractère '/0'
        if(chaine[2] == 'a' || chaine[3] == 'a' || chaine[4] == 'a')
        {
            ennemi[*numeroEnnemi].positionEnnemi.x = strtol(&chaine[0], (char **)NULL, 10);
            if(chaine[3] == 'a')
            {
                fseek(fichier, -1, SEEK_CUR);//On revient de 1, car on a lu un caractère de plus.
            }
            if(chaine[2] == 'a')
            {
                fseek(fichier, -2, SEEK_CUR);//On revient de 2, car on a lu deux caractères de plus.
            }
        }
    }
    else if(caractere == 'o')
    {
        fgets(chaine, 6, fichier);//On lit 5 caractères (avec le signe qu'on stocke dans chaine + le caractère '/0'
        if(chaine[2] == 'o' || chaine[3] == 'o' || chaine[4] == 'o')
        {
            ennemi[*numeroEnnemi].positionEnnemi.y = strtol(&chaine[0], (char **)NULL, 10);
            if(chaine[3] == 'o')
            {
                fseek(fichier, -1, SEEK_CUR);//On revient de 1, car on a lu un caractère de plus.
            }
            if(chaine[2] == 'o')
            {
                fseek(fichier, -2, SEEK_CUR);//On revient de 2, car on a lu deux caractères de plus.
            }
        }
    }
    else if(caractere == 's')
    {
        /*Sens :
        0 -> gauche 1 -> gauche haut 2 -> haut 3 -> droite haut 4 -> droite 5 -> droite bas 6 -> bas 7 -> gauche bas
        */
        fgets(chaine, 2, fichier);
        if(chaine[0] == '0')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 0;
        }
        else if(chaine[0] == '1')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 1;
        }
        else if(chaine[0] == '2')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 2;
        }
        else if(chaine[0] == '3')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 3;
        }
        else if(chaine[0] == '4')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 4;
        }
        else if(chaine[0] == '5')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 5;
        }
        else if(chaine[0] == '6')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 6;
        }
        else if(chaine[0] == '7')
        {
            ennemi[*numeroEnnemi].sensEnnemi = 7;
        }
    }
    else if(caractere == '1')
    {
        ennemi[*numeroEnnemi].surfaceEnnemi = IMG_Load("sprites/ennemi001.gif");
        *numeroEnnemi += 1;
        ennemi[*numeroEnnemi].type = 0;
    }
    else if(caractere == '2')
    {
        ennemi[*numeroEnnemi].surfaceEnnemi = IMG_Load("sprites/ennemi002.gif");
        *numeroEnnemi += 1;
        ennemi[*numeroEnnemi].type = 0;
    }
    else if(caractere == '3')
    {
        ennemi[*numeroEnnemi].surfaceEnnemi = IMG_Load("sprites/bonus1.gif");
        ennemi[*numeroEnnemi].type = 1;
        *numeroEnnemi += 1;
    }
    else if(caractere == '4')
    {
        ennemi[*numeroEnnemi].surfaceEnnemi = IMG_Load("sprites/bombe.png");
        ennemi[*numeroEnnemi].type = 2;
        *numeroEnnemi += 1;
    }
    else if(caractere == '5')
    {
        ennemi[*numeroEnnemi].surfaceEnnemi = IMG_Load("sprites/bonus2.gif");
        ennemi[*numeroEnnemi].type = 3;
        *numeroEnnemi += 1;
    }

}

//Gestion des ennemis sur la map
void fc_ennemi_map(Struct_Ennemi ennemi[], int *numeroEnnemi, int *numeroTirEnnemi, Struct_Tir tir_ennemi[], int *music, int *sound, int *mode, FMOD_SYSTEM **system, FMOD_SOUND **tirSound)
{
    int i = 0, min = 1, max = 1000, random = 0;

    for(i = 0 ; i < NBRE_ENNEMI_MAX ; i++)
    {
        if(ennemi[i].surfaceEnnemi != NULL)
        {
            random = rand()%(max-min)+min;

            if(random < 5 && ennemi[i].type == 0)
            {
                if(*numeroTirEnnemi > NBRE_TIR_ENNEMI_MAX - 1)
                {
                    *numeroTirEnnemi = 0;
                }

                tir_ennemi[*numeroTirEnnemi].surfaceTir = IMG_Load("sprites/tir001.png");
                tir_ennemi[*numeroTirEnnemi].positionTir.x = ennemi[i].positionEnnemi.x + 25;
                tir_ennemi[*numeroTirEnnemi].positionTir.y = ennemi[i].positionEnnemi.y + 35;
                if(*sound == 1)
                {
                FMOD_System_PlaySound(system, 1, tirSound, 0, NULL);
                }

                *numeroTirEnnemi += 1;
            }

            if(ennemi[i].sensEnnemi == 0)
            {
                ennemi[i].positionEnnemi.x -= 1;
            }
            else if(ennemi[i].sensEnnemi == 1)
            {
                ennemi[i].positionEnnemi.x -= 1;
                ennemi[i].positionEnnemi.y -= 1;
            }
            else if(ennemi[i].sensEnnemi == 2)
            {
                ennemi[i].positionEnnemi.y -= 1;
            }
            else if(ennemi[i].sensEnnemi == 3)
            {
                ennemi[i].positionEnnemi.x += 1;
                ennemi[i].positionEnnemi.y -= 1;
            }
            else if(ennemi[i].sensEnnemi == 4)
            {
                ennemi[i].positionEnnemi.x += 1;
            }
            else if(ennemi[i].sensEnnemi == 5)
            {
                ennemi[i].positionEnnemi.x += 1;
                ennemi[i].positionEnnemi.y += 1;
            }
            else if(ennemi[i].sensEnnemi == 6)
            {
                ennemi[i].positionEnnemi.y += 1;
            }
            else if(ennemi[i].sensEnnemi == 7)
            {
                ennemi[i].positionEnnemi.x -= 1;
                ennemi[i].positionEnnemi.y += 1;
            }
            if(ennemi[i].positionEnnemi.x > 800 || ennemi[i].positionEnnemi.x < -200 || ennemi[i].positionEnnemi.y > 600 || ennemi[i].positionEnnemi.y < -200)
            {
                ennemi[i].surfaceEnnemi = NULL;
                ennemi[i].positionEnnemi.x = -999;
                ennemi[i].positionEnnemi.y = -999;
                *numeroEnnemi--;
            }
        }
    }
}

//Gestion des events simplifié !
//Merci à Fvirtman et au site du zér0.
void gestion_events_poll(Struct_Event *worker)
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
            case SDL_KEYDOWN:
                worker->key[event.key.keysym.sym] = 1;
            break;

            case SDL_KEYUP:
                worker->key[event.key.keysym.sym] = 0;
            break;

            case SDL_QUIT:
                worker->quit = 1;
            break;

            default:
            break;
		}
	}
}


void fc_pause()
{
    //Déclaration des variables.
    int continuer = 1;
    SDL_Event event;

    while(continuer)//Tant que continuer = 1.
    {
        SDL_PollEvent(&event);//Regarde si il y a un événement.
        switch(event.type)//Condition prenant en compte le type.
        {
            case SDL_QUIT://Si on ferme le programme normalement (La croix rouge).
            exit(0);//On arrête le programme.
            break;
            case SDL_KEYDOWN://Si on appuie sur une touche.
                switch(event.key.keysym.sym)//Condition prenant en compte le type.
                {
                    case SDLK_p://Si touche "p".
                    continuer = 0;//Variable mise à valeur de sortie de boucle.
                    break;
                }
            break;
        }
    }
}



void fc_texte(SDL_Surface *ecran, char chaine[100], int x, int y, SDL_Color couleurBlanche, int taille)
{
    SDL_Surface *texte = NULL;
    TTF_Font *police;
    SDL_Rect position;

    position.x = x;//Abscisse de l'image.
    position.y = y;//Ordonnée de l'image.

    police = TTF_OpenFont("angelina.ttf", taille);

    texte = TTF_RenderUTF8_Blended(police, chaine, couleurBlanche);

    SDL_BlitSurface(texte, NULL, ecran, &position);

    TTF_CloseFont(police);
}


void fc_gameover()
{
    SDL_Delay(10);
}


void sauvegarde(SDL_Surface *ecran, SDL_Color couleurBlanche, char nom[100], int level, int score, int choixMenu)
{
    SDL_Surface *curseur = NULL, *bufferEcran = NULL;
    SDL_Rect positionCurseur, positionBufferEcran, position;
    SDL_Event event;
    int continuer = 1, first = 1, i = 0, pos1 = 0, pos2 = 0;
    char caractere;
    caractere = '\0';
    char ligne[100], ligne2[100], char_level[100], char_score[100];
    ligne[0] = '\0';
    ligne2[0] = '\0';
    char_level[0] = '\0';
    char_score[0] = '\0';

    strcpy(ligne2, nom);

    FILE *fichier = NULL, *fichierTmp = NULL;

    if((fichier = fopen("config/saves/levels.save" ,"r+")) == NULL)
    {
        return EXIT_FAILURE;
    }

    if((fichierTmp = fopen("config/saves/levels.tmp" ,"w")) == NULL)
    {
        fclose(fichier);
        return EXIT_FAILURE;
    }

    position.x = 100;
    position.y = 120;

    bufferEcran = SDL_CreateRGBSurface(SDL_HWSURFACE, 5, 60, 32, 0, 0, 0, 0);
    SDL_FillRect(bufferEcran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    positionBufferEcran.x = 600;
    positionBufferEcran.y = 100;
    positionBufferEcran.w = 5;
    positionBufferEcran.h = 60;

    curseur = IMG_Load("sprites/curseur.png");
    positionCurseur.x = 120;
    positionCurseur.y = 120;
    positionCurseur.w = 5;
    positionCurseur.h = 60;

    char ch;

    while(continuer)
    {
        fc_texte(ecran, nom, position.x, position.y, couleurBlanche, 60);
        SDL_BlitSurface(ecran, &positionCurseur, bufferEcran, NULL);
        SDL_BlitSurface(curseur, NULL, ecran, &positionCurseur);
        SDL_Flip(ecran);
        SDL_Delay(100);

        fc_texte(ecran, nom, position.x, position.y, couleurBlanche, 60);
        SDL_FillRect(ecran, &positionCurseur, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(bufferEcran, NULL, ecran, &positionCurseur);
        SDL_Flip(ecran);
        SDL_Delay(100);

        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                        if(level == 1)
                        {
                            level++;
                            itoa(level, char_level, 10);
                            itoa(score, char_score, 10);
                            fseek(fichier, 0, SEEK_SET);
                            pos1 = ftell(fichier);
                            caractere = fgetc(fichier);
                            pos2 = ftell(fichier);
                            if(pos1 != pos2)
                            {
                                fseek(fichier, 0, SEEK_END);
                                fputc('\n', fichier);
                            }
                            else
                            {
                                fseek(fichier, 0, SEEK_END);
                            }
                            fputs(nom, fichier);
                            fputc(' ', fichier);
                            fputs(char_level, fichier);
                            fputc(' ', fichier);
                            fputs(char_score, fichier);
                            fputc(' ', fichier);

                            fclose(fichier);
                            fclose(fichierTmp);
                            continuer = 0;
                        }
                        else
                        {
                            i = 1;
                            fseek(fichier, 0, SEEK_SET);//On revient au début.
                            while(i < choixMenu)
                            {
                                caractere = fgetc(fichier);
                                if(caractere == '\n')
                                {
                                    i++;
                                }
                            }

                            while(fgets(ligne, sizeof ligne, fichier))
                            {
                                if(strcmp(nom, ligne2) != 0)
                                {
                                    fputs(ligne, fichierTmp);
                                }
                            }

                            fclose(fichier);
                            fclose(fichierTmp);

                            rename("config/saves/levels.tmp", "config/saves/levels.save");

                            continuer = 0;
                        }
                    break;
                    case SDLK_BACKSPACE:
                        first = 0;
                        i--;
                        nom[i] = '\0';
                        positionCurseur.x -= 18;
                    break;
                    default:
                        first = 0;
                        ch = event.key.keysym.sym;
                        nom[i] = ch;
                        i++;
                        nom[i] = '\0';
                        positionCurseur.x += 18;
                    break;
                }
            break;
        }

        /*
        nom = event.key.keysym.unicode;
        nom[position] = event.key.keysym.unicode;
        position++;
        nom[position] = '\0';
        }
        if(event.key.keysym.sym == SDLK_BACKSPACE)
        {
            if(position > 0)
            {
                position--;
                nom[position] = '\0';
            }
        }
        if(event.key.keysym.sym == SDLK_RETURN)
        {
            //SDL_EnableUNICODE(0);
            //continuer = 0;
        }
        */
    }

    SDL_FreeSurface(curseur);
    SDL_FreeSurface(bufferEcran);
}






