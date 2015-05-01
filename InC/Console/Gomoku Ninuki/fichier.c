/*
Fichier fichier.c

Rôle : Contient les fonctions qui gèrent le fichier score.txt.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

void ecrireFichier(int *fichier, int partie, int victoire)//On écrit le résultat d'une partie dans le fichier "score.txt".
{
    fichier = fopen("score.txt" , "r+");

    if (fichier != NULL)
    {
        fseek(fichier, 0, SEEK_END);//On se place à la fin.
        if(victoire == 2 || victoire == 1)
        {
            fprintf(fichier, "Vainqueur de la partie %d : joueur %d !\n", partie, victoire);//On écrit dans le fichier.
        }
        else if(victoire == 3)
        {
            fprintf(fichier, "Vainqueur de la partie %d : Match nul !\n", partie);//On écrit dans le fichier.
        }

        fclose(fichier);
    }
    else
    {
        printf("Impossibe d'ouvrir le fichier\n");
        exit(1);
    }

    printf("\n\n");
}


void lireFichier(int *fichier, char chaine[50])//On affiche les résultats des parties dans le fichier "score.txt".
{
    fichier = fopen("score.txt" , "r");
    if (fichier != NULL)
    {
        while(fgets(chaine, 50, fichier) != NULL)//Tant qu'il y a quelque chose d'écrit sur une ligne on prend les 50 premiers caractères.
        {
            printf("%s", chaine);//On affiche la ligne contenu dans le fichier.
        }
    }
    else
    {
        printf("\nProbleme d'ouverture de fichier\n");
        exit(1);
    }
    fclose(fichier);
}

