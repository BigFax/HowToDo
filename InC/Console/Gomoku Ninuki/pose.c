/*
Fichier main.c

Rôle : Contient les fonctions qui testent et effectuent la pose d'un pion.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pose.h"

//i correspond à l'abscisse, j à l'ordonnée.
int possible(int tab[21][21])//On regarde si il y a une case de libre (return 1) ou pas (return0).
{
    int i = 0, j = 0;

    for(i = 0 ; i < 21 ; i++)//Boucle sur les abscisses de 0 à 20.
    {
        for(j = 0 ; j < 21 ; j++)//Boucle sur les ordonnées de 0 à 20.
        {
            if(tab[j][i] == 0)//Si la case est libre (case == 0)
            {
                return 1;//On renvoie 1.
            }
        }
    }

return 0;//Si aucune case ne renvoie 0 alors il n'y a pas de return 1 et plus aucune case n'est libre, on renvoie 0.
}

//x correspond à l'abscisse rentrée par le joueur, y à l'ordonnée rentrée par le joueur.
void pose(int tab[21][21], int n, int *i, int *j)//On demande les coordonnées ou le pion doit être posé et on le pose en mettant le tableau et les coorconnées à jour.
{
    int x = 0, y = 0, verif = 1;

    while(verif)
    {
        printf("\n        abscisse : ");
        scanf("%d", &x);

        if(x > 0 && x < 20)
        {
            printf("        ordonnee : ");
            scanf("%d", &y);

            if(y > 0 && y < 20)
            {
                if(tab[y][x] == 0)
                {
                    tab[y][x] = n;
                    *i = x;
                    *j = y;
                    verif = 0;
                }
                else
                {
                    printf("\nUn pion est deja place !\n");
                }
            }
            else
            {
                printf("\nMauvaises coordonnees !\n");
            }
        }
        else
        {
        printf("\nMauvaises coordonnees !\n");
        }
    }


}

