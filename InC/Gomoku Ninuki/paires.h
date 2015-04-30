/*
Fichier paires.h

Rôle : Contient les prototypes des fonctions du fichier paires.c
*/

#ifndef DEF_PAIRES
#define DEF_PAIRES

void paires(int tab[21][21], int n, int i, int j, int total[2]);
void paires_hg(int tab[21][21], int n, int i, int j, int total[2]);
void paires_hd(int tab[21][21], int n, int i, int j, int total[2]);
void paires_vh(int tab[21][21], int n, int i, int j, int total[2]);
void paires_vb(int tab[21][21], int n, int i, int j, int total[2]);
void paires_d1g(int tab[21][21], int n, int i, int j, int total[2]);
void paires_d1d(int tab[21][21], int n, int i, int j, int total[2]);
void paires_d2g(int tab[21][21], int n, int i, int j, int total[2]);
void paires_d2d(int tab[21][21], int n, int i, int j, int total[2]);

#endif
