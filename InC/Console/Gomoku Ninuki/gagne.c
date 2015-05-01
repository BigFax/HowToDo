/*
Fichier gagne.c

Rôle : Contient les fonctions qui vérifient et affichent le joueur qui a gagné, son mode de victoire et demande si il veut rejouer ou non.
*/
#include <stdio.h>
#include <stdlib.h>
#include "gagne.h"

void gagne(int victoire, int verif_alignement, int total[2])//Affichage du gagnant et du mode de victoire
{
    printf("\n\n");
    if(victoire == 1)//Si le joueur 1 a gagné.
    {
        if(verif_alignement == 1 )//Gagné par alignement.
        {
            printf("C'est le joueur 1 qui a gagne par alignement d'au moins 5 de ses pions !!!");
        }
        else if(total[0] > 4)//Gagné par prise d'au moins 5 pions.
        {
            printf("C'est le joueur 1 qui a gagne par prise d'au moins 5 paires adverses !!!");
        }
    }
    else if(victoire == 2)//Si le joueur 2 a gagné.
    {
        if(verif_alignement == 1 )//Gagné par alignement.
        {
            printf("C'est le joueur 2 qui a gagne par alignement d'au moins 5 de ses pions !!!");
        }
        else if(total[1] > 4)//Gagné par prise d'au moins 5 pions.
        {
            printf("C'est le joueur 2 qui a gagne par prise d'au moins 5 paires adverses !!!");
        }
    }
    else if(victoire == 3)//Si match nul.
    {
        printf("Match nul !!!");
    }
}


int rejouer(int partie)//Demande si on veut rejouer ou non.
{
    int choix = 0;

    while(choix != 1 && choix != 2)//Tant que choix n'est pas 1 ou 2.
    {
        printf("\nQue voulez vous faire ?\n\nTaper 1. Rejouer une partie\nTaper 2. Terminer le jeu\n\n");//Demande.
        scanf("%d", &choix);//Récupère le choix (un nombre) qu'on stocke à l'adresse de choix.
        printf("\n\n");

        if(choix == 1)//Si rejouer.
        {
            partie++;//On augmente le n° de la partie.
        }
        else if(choix == 2)//Si quitter.
        {
            partie = 0;//On met partie à 0.
        }
        else//Si le choix n'est pas 1 ou 2.
        {
            printf("Mauvais choix !");
        }
    }

    return partie;//On renvoie partie.
}


