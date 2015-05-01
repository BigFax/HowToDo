/*
Fichier main.c

Rôle : Contient les fonctions qui testent l'éventuelle prise de paires.
*/
#include <stdio.h>
#include <stdlib.h>
#include "paires.h"

//i correspond à l'abscisse, j à l'ordonnée.
void paires(int tab[21][21], int n, int i, int j, int total[2])//Appel les fonctions de vérif de paires.
{
    paires_hg(tab, n, i, j, total);//Vérif paires horizontale (avec pose du pion sur la gauche)
    paires_hd(tab, n, i, j, total);//Vérif paires horizontale (avec pose du pion sur la droite)
    paires_vh(tab, n, i, j, total);//Vérif paires verticale (avec pose du pion en haut)
    paires_vb(tab, n, i, j, total);//Vérif paires verticale (avec pose du pion en bas)
    paires_d1g(tab, n, i, j, total);//Vérif paires diagonale (avec pose du pion en haut à gauche)
    paires_d1d(tab, n, i, j, total);//Vérif paires diagonale (avec pose du pion en bas à droite)
    paires_d2g(tab, n, i, j, total);//Vérif paires diagonale (avec pose du pion en bas à gauche)
    paires_d2d(tab, n, i, j, total);//Vérif paires diagonale (avec pose du pion en haut à droite)
}


void paires_hg(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j][i + 1] == inverse && tab[j][i + 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" sur la droite du pion posé.
    {
        i = i + 3;//On avance de 3 cases en abscisse.

        if(tab[j][i] == n)//Si la case est égale à la valeur du joueur, alors le joueur "n" entoure bien deux pions de l'autre joueur.
        {
            total[n - 1] = total[n - 1] + 1;//On augmente la valeur du total de paires créer.
            tab[j][i - 1] = 0;//On vide la case de son pion.
            tab[j][i - 2] = 0;//On vide la case de son pion.
        }
    }



}


void paires_hd(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j][i - 1] == inverse && tab[j][i - 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" sur la gauche du pion posé.
    {
            i = i - 3;//On recule de 3 cases en abscisse

            if(tab[j][i] == n)
            {
                total[n - 1] = total[n - 1] + 1;//On augmente la valeur du total de paires créer.
                tab[j][i + 1] = 0;//On vide la case de son pion.
                tab[j][i + 2] = 0;//On vide la case de son pion.
            }
    }
}


void paires_vh(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j + 1][i] == inverse && tab[j + 2][i] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en bas du pion posé.
    {

        j = j + 3;//On avance de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j - 1][i] = 0;//On vide la case de son pion.
            tab[j - 2][i] = 0;//On vide la case de son pion.
        }
    }
}


void paires_vb(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j - 1][i] == inverse && tab[j - 2][i] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en haut du pion posé.
    {
        j = j - 3;//On recule de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j + 1][i] = 0;//On vide la case de son pion.
            tab[j + 2][i] = 0;//On vide la case de son pion.
        }
    }
}


void paires_d1g(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j + 1][i + 1] == inverse && tab[j + 2][i + 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en bas à droite du pion posé.
    {
        i = i + 3;//On avance de 3 cases en abscisse
        j = j + 3;//On avance de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j - 1][i - 1] = 0;//On vide la case de son pion.
            tab[j - 2][i - 2] = 0;//On vide la case de son pion.
        }
    }
}


void paires_d1d(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j - 1][i - 1] == inverse && tab[j - 2][i - 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en haut à gauche du pion posé.
    {

        i = i - 3;//On recule de 3 cases en abscisse
        j = j - 3;//On recule de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j + 1][i + 1] = 0;//On vide la case de son pion.
            tab[j + 2][i + 2] = 0;//On vide la case de son pion.
        }
    }
}


void paires_d2g(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j - 1][i + 1] == inverse && tab[j - 2][i + 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en haut à droite du pion posé.
    {

        i = i + 3;//On avance de 3 cases en abscisse
        j = j - 3;//On recule de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j + 1][i - 1] = 0;//On vide la case de son pion.
            tab[j + 2][i - 2] = 0;//On vide la case de son pion.
        }
    }
}


void paires_d2d(int tab[21][21], int n, int i, int j, int total[2])
{
    int compteur = 1, inverse = 0;

    if(n == 1)
    {
        inverse = 2;
    }
    else if(n == 2)
    {
        inverse = 1;
    }

    if(tab[j + 1][i - 1] == inverse && tab[j + 2][i - 2] == inverse)//Si il y a bien deux pions différents du pion du joueur "n" en bas à gauche du pion posé.
    {

        i = i - 3;//On recule de 3 cases en abscisse
        j = j + 3;//On avance de 3 cases en ordonnee

        if(tab[j][i] == n)//On augmente la valeur du total de paires créer.
        {
            total[n - 1] = total[n - 1] + 1;
            tab[j - 1][i + 1] = 0;//On vide la case de son pion.
            tab[j - 2][i + 2] = 0;//On vide la case de son pion.
        }
    }
}

