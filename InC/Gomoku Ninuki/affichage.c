/*
Fichier main.c

Rôle : Contient les fonctions d'initialisation et d'affichage du jeu à l'écran.
*/
#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

//i correspond à l'abscisse, j à l'ordonnée.
void initialise(int tab[21][21])//Initialisation du plateau.
{
    int i = 0, j = 0;

    for(i = 0 ; i < 21 ; i++)//Boucle sur les abscisses de 0 à 20.
    {
        for(j = 0 ; j < 21 ; j++)//Boucle sur les ordonnées de 0 à 20.
        {
            if(i == 0 || i == 20)//Si on est sur la première colonne (abscisse 0) ou sur la dernière colonne (abscisse 20)
            {
                tab[j][i] = 3;//On assigne la valeur 3 à la case correspondante.
            }
            else if(j == 0 || j == 20)//Si on est sur la première ligne (ordonnée 0) ou sur la dernière ligne (ordonnée 20)
            {
                tab[j][i] = 3;//On assigne la valeur 3 à la case correspondante.
            }
            else//Dans tous les autres cas.
            {
                tab[j][i] = 0;//On assigne la valeur 3 à la case correspondante.
            }

        }
    }
}


void affiche(int tab[21][21], int total[2])//Appel les fonctions d'affichage.
{
    system("cls");//On efface la console.
    printf("           ########################################          \n");
    printf("           #             GOMOKU NINUKI            #          \n");
    printf("           #                  par                 #          \n");
    printf("           #                                      #          \n");
    printf("           #                Big Fax               #          \n");
    printf("           ########################################          \n");
    printf("\n\n");
    affiche_plateau(tab);//On affiche le plateau.
    affiche_paires(total);//On affiche le nombre paire prise.
}


void affiche_plateau(int tab[21][21])//Affichage du tableau.
{
    int i = 1, j = 1;
    printf("\n  ");//Retour à la ligne + marge pour un affichage plus propre.

    //On affiche d'abord la première ligne avec la boucle ci-dessous.
    for(i = 1 ; i < 20 ; i++)//Boucle sur les abscisses de 1 à 19.
    {
        if(i < 10)//Pour gérer un affichage plus propre on rajoute des espaces une fois qu'on affiche 2 chiffres.
        {
            printf(" ");
        }

        printf(" %d", i);//On affiche la valeur de l'abscisse afin de créer les colonnes.
    }

    i = 1, j = 1;//On réinitialise les valeurs des coordonnées.

    //On affiche ensuite le reste du tableau. Le tableau s'affichera par ligne.
    for(j = 1 ; j < 20 ; j++)//Boucle sur les ordonnées de 1 à 19.
    {
        printf("\n\n%d", j);//Espace entre les lignes.

        if(j < 10)//Pour gérer un affichage plus propre on rajoute des espaces une fois qu'on affiche 2 chiffres.
        {
            printf(" ");
        }

            for(i = 1 ; i < 20 ; i++)//Boucle sur les abscisses de 1 à 19.
            {
                printf("  ");//Espace entre les colonnes.
                //Ici on remplace les chiffres par des caractères.
                if(tab[j][i] == 0)
                {
                    printf(".");
                }
                else if(tab[j][i] == 1)
                {
                    printf("o");
                }
                if(tab[j][i] == 2)
                {
                    printf("x");
                }

            }
    }

printf("\n\n");//Espaces pour un affichage plus propre.

}


void affiche_paires(int total[2])//Affichage des paires.
{
    printf("\n");
    printf("-----------------------------------------------------------");
    printf("\n\n");
    printf("Nombres de paires prises par le joueur 1 : %d\n", total[0]);
    printf("Nombres de paires prises par le joueur 2 : %d\n", total[1]);
}



