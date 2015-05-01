/*
Fichier alignement.h

Rôle : Contient les prototypes des fonctions du fichier alignement.c
*/

#ifndef DEF_ALIGNEMENT
#define DEF_ALIGNEMENT

int alignement(int tab[21][21], int n, int i, int j);
int alignement_v(int tab[21][21], int n, int i, int j);
int alignement_h(int tab[21][21], int n, int i, int j);
int alignement_d1(int tab[21][21], int n, int i, int j);
int alignement_d2(int tab[21][21], int n, int i, int j);

#endif
