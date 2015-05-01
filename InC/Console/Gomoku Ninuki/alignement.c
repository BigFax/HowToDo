/*
Fichier main.c

Rôle : Contient les fonctions qui testent l'alignement de 5 pions.
*/
#include <stdio.h>
#include <stdlib.h>
#include "alignement.h"

//i correspond à l'abscisse, j à l'ordonnée.
int alignement(int tab[21][21], int n, int i, int j)//Appel les fonctions de vérif d'alignement.
{
    int retour_alignement_v = 0, retour_alignement_h = 0, retour_alignement_d1 = 0, retour_alignement_d2 = 0;

    retour_alignement_v = alignement_v(tab, n, i, j);//Vérif alignement verticale.
    retour_alignement_h = alignement_h(tab, n, i, j);//Vérif alignement horizontale.
    retour_alignement_d1 = alignement_d1(tab, n, i, j);//Vérif alignement diagonale 1.
    retour_alignement_d2 = alignement_d2(tab, n, i, j);//Vérif alignement diagonale 2.

    if(retour_alignement_v == 1 || retour_alignement_h == 1 || retour_alignement_d1 == 1 || retour_alignement_d2 == 1)//Si il y a un alignement de 5 pions, on renvoie 1.
    {
        return 1;//On renvoie 1.
    }

return 0;//Pas d'alignement on renvoie.
}


int alignement_v(int tab[21][21], int n, int i, int j)//On veut vérifier l'alignement vertical.
{
    int compteur = 1;

    j++;//On avance d'une case en ordonnee. On descend donc (si on se réfère au plateau). On est une case en dessous de la case ou le pion a été posé.

    while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
    {
        compteur += 1;//On augmente le compteur d'1.
        j++;//On avance d'une case en ordonnee (pour descendre).
    }

    if(compteur != 5)//Si après avoir était vers le bas, il n'a pas trouver 5 case (compteur != 5) appartenant au joueur "n". Il va vers le haut avec le code ci-dessous.
    {
        j = j - (compteur + 1);//On met l'ordonnée une case au dessus de la case ou le pion a été posé.
        while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
        {
            compteur += 1;//On augmente le compteur d'1.
            j--;//On recule d'une case en ordonnee (pour monter).
        }
    }

    if(compteur == 5)//Au final si le compteur est égale à 5 alors il y a bien un alignement de 5 cases sur la valeur du joueur "n" et donc 5 pions alignés.
    {
        return 1;//On renvoie 1.
    }


return 0;//Pas d'alignement, alors on renvoie 0.
}


int alignement_h(int tab[21][21], int n, int i, int j)
{
    int compteur = 1;

    i++;//On avance d'une case en abscisse. On va vers la droite (si on se réfère au plateau). On est une case à droite de la case ou le pion a été posé.

    while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
    {
        compteur += 1;//On augmente le compteur d'1.
        i++;//On avance d'une case en abscisse.
    }

    if(compteur != 5)//Si après avoir était vers la droite, il n'a pas trouver 5 case (compteur != 5) appartenant au joueur "n". Il va vers la gauche avec le code ci-dessous.
    {
        i = i - (compteur + 1);//On met l'abscisse une case à gauches de la case ou le pion a été posé.
        while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
        {
            compteur += 1;//On augmente le compteur d'1.
            i--;//On recule d'une case en abscisse.
        }
    }

    if(compteur == 5)//Au final si le compteur est égale à 5 alors il y a bien un alignement de 5 cases sur la valeur du joueur "n" et donc 5 pions alignés.
    {
        return 1;//On renvoie 1.
    }

return 0;//Pas d'alignement, alors on renvoie 0.
}


int alignement_d1(int tab[21][21], int n, int i, int j)
{
    int compteur = 1;

    i++;//On avance d'une case en abscisse.
    j++;//On avance d'une case en ordonnee.

    while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
    {
        compteur += 1;//On augmente le compteur d'1.
        i++;//On avance d'une case en abscisse.
        j++;//On avance d'une case en ordonnee.
    }

    if(compteur != 5)//Si il n'a pas trouver 5 case (compteur != 5) appartenant au joueur "n".
    {
        i = i - (compteur + 1);//On met l'abscisse une case au à gauche de la case ou le pion a été posé.
        j = j - (compteur + 1);//On met l'ordonnée une case au dessus de la case ou le pion a été posé.
        while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
        {
            compteur += 1;//On augmente le compteur d'1.
            i--;//On recule d'une case en abscisse.
            j--;//On recule d'une case en ordonnee.
        }
    }

    if(compteur == 5)//Au final si le compteur est égale à 5 alors il y a bien un alignement de 5 cases sur la valeur du joueur "n" et donc 5 pions alignés.
    {
        return 1;//On renvoie 1.
    }

return 0;//Pas d'alignement, alors on renvoie 0.
}


int alignement_d2(int tab[21][21], int n, int i, int j)
{
    int compteur = 1;

    i++;//On avance d'une case en abscisse.
    j--;//On recule d'une case en ordonnee.

    while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
    {
        compteur += 1;//On augmente le compteur d'1.
        i++;//On avance d'une case en abscisse.
        j--;//On recule d'une case en ordonnee.
    }

    if(compteur != 5)//Si il n'a pas trouver 5 case (compteur != 5) appartenant au joueur "n".
    {
        i = i - (compteur + 1);//On met l'abscisse une case à gauche de la case ou le pion a été posé.
        j = j + (compteur + 1);//On met l'ordonnée une case au dessous de la case ou le pion a été posé.
        while(tab[j][i] == n && compteur < 5)//Tant que la case est égale au n° de joueur ET que le compteur est inférieur à 4. Le compteur parcourera ainsi 5 case au maximum.
        {
            compteur += 1;//On augmente le compteur d'1.
            i--;//On recule d'une case en abscisse.
            j++;//On avance d'une case en ordonnée.
        }
    }

    if(compteur == 5)//Au final si le compteur est égale à 5 alors il y a bien un alignement de 5 cases sur la valeur du joueur "n" et donc 5 pions alignés.
    {
        return 1;//On renvoie 1.
    }

return 0;//Pas d'alignement, alors on renvoie 0.
}

