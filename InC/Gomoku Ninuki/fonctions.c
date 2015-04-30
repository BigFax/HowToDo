/*
Fichier fonctions.c

Rôle : Contient des fonctions supplémentaires du programme afin d'avoir une programmation plus modulaire.
*/
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int changeJoueur(int n)//On change le joueur !
{
    if(n == 1)
    {
        n = 2;
    }
    else if(n == 2)
    {
        n = 1;
    }

    return n;
}
