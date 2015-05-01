/*
Fichier main.c

Rôle : Fonction principale du programme
*/
#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "pose.h"
#include "alignement.h"
#include "paires.h"
#include "gagne.h"
#include "fichier.h"
#include "fonctions.h"

//Main qui gère l'ajout de la règle additionnelle.
int main(int argc, char *argv[])
{
    //Déclaration des variables du programme.
    int tab[21][21], total[2] = {0, 0};
    int n = 1, i = 0, j = 0, victoire = 0, verif_possible = 0, verif_alignement = 0, partie = 1, choix = 0;
    int i2 = 0, j2 = 0, verif_alignement_precedent = 0, verif_alignement_actuel = 0, regleAjouter = 0, totalAjouter = 0;
    FILE *fichier = NULL;
    char chaine[50];

    /*
    L'ouverture de fichier ci-dessous permet de créer un fichier vierge à chaque début de programme.
    */
    fichier = fopen("score.txt" , "w+"); //Ouverture du fichier "score.txt" en ouverture w+.
    if (fichier == NULL) //Si problème d'ouverture.
    {
        printf("\nProbleme d'ouverture de fichier\n");
        exit(1);
    }
    fclose(fichier);

    while(partie != 0) //Tant que variable "partie" n'est pas égale à 0, le jeu n'est pas fini.
    {
        //Initialisation des variables en début de partie.
        int total[2] = {0, 0};
        n = 1, i = 0, j = 0, victoire = 0, verif_possible = 1, verif_alignement = 0;
        i2= 0, j2 = 0, verif_alignement_actuel = 0, verif_alignement_precedent = 0, regleAjouter = 0, totalAjouter = 0; //Variable ajouté pour la règle additionnelle.

        initialise(tab); //Initialisation du tableau.

        while(victoire == 0) //Tant que la variable "victoire" est égale à 0 personne gagne. Si valeur 1, joueur 1 gagne. Si valeur 2, joueur 2 gagne.
        {
            verif_possible = possible(tab); //On vérifie si il y a encore de la place sur le plateau.
            if(verif_possible == 1) //Si il reste de la place.
            {
                if(regleAjouter == 1) //Règle additionnelle.
                {
                    totalAjouter = total[n - 1] + 1 ;
                    affiche(tab, total); //Affiche le plateau de jeu.
                    printf("Attention !\nJoueur %d : saisissez les coordonnees de la case ou vous voulez jouer :\n", n);
                    pose(tab, n, &i2, &j2); //Pose le pion du joueur "n" aux coordonnées "i2" (abscisse) et "j2" ordonnées. Les coordonnées sont demandées au joueur.
                    verif_alignement_actuel = alignement(tab, n, i2, j2); //Vérifie si la pose du pion aux coordonnées "i2" et "j2" créer un alignement de 5 pions.
                    paires(tab, n, i2, j2, total); //Vérifie si le pion posé du joueur "n" capture une paire ou plus.
                    n = changeJoueur(n); //Changement de joueur.
                    verif_alignement_precedent = alignement(tab, n, i, j); //On vérifie si l'alignement de 5 pions du tour précédent est toujours valable après vérification de la prise d'une paire.
                    n = changeJoueur(n); //Changement de joueur.

                    if(verif_alignement_precedent == 1) //Si l'alignement n'est pas cassé (donc pas de paire prise sur l'alignement).
                    {
                        regleAjouter = 0; //On sort de la règle additionnelle
                        n = changeJoueur(n); //Changement de joueur.
                        victoire = n; //Victoire au joueur "n". Car l'alignement n'a pas été cassé.
                        affiche(tab, total); //Affiche le plateau de jeu.
                    }
                    else if(verif_alignement_precedent == 0) //Si l'alignement est cassé (paire prise par l'autre joueur enlevant un des pions qui formaient l'alignement).
                    {
                        if(total[n - 1] >= 5) //En plus d'avoir cassé l'alignement, le joueur peut former avoir 5 paires ou plus. Si c'est le cas.
                        {
                            regleAjouter = 0; //On sort de la règle additionnelle
                            verif_alignement = 0; //Le gain ne se fait plus par alignement mais pas prise de 5 pions.
                            victoire = n; //Victoire au joueur "n". Car l'alignement n'a pas été cassé.
                            affiche(tab, total); //Affiche le plateau de jeu.
                        }
                        else if(verif_alignement_actuel == 1) //En plus d'avoir cassé l'alignement, le joueur peut former un alignement de 5 pions. Si c'est le cas.
                        {
                            i = i2; //On va rentrer une nouvelle fois dans la règle additionnelle, il faut donc que i soit égale à la coordonnée précèdente (qui est i2).
                            j = j2; //On va rentrer une nouvelle fois dans la règle additionnelle, il faut donc que j soit égale à la coordonnée précèdente (qui est j2).
                            n = changeJoueur(n); //Changement de joueur. La règle n'est pas désactivé pour revenir dedans au tour de jeu suivant.
                        }
                        else //L'alignement est cassé mais pas de nouvel alignement de 5 pions ni de prise de 5 paires ou plus.
                        {
                            regleAjouter = 0; //Désactive la règle additionnelle. Le jeu va reprendre normalement.
                            verif_alignement = 0; //Le gain ne se fait plus par alignement.
                            n = changeJoueur(n); //Changement de joueur.
                        }
                    }
                }
                else //Jeu sans la règle additionnelle.
                {
                    affiche(tab, total); //Affiche le plateau de jeu.
                    printf("\nJoueur %d : saisissez les coordonnees de la case ou vous voulez jouer :\n", n);
                    pose(tab, n, &i, &j); //Pose le pion du joueur "n" aux coordonnées "i" (abscisse) et "j" ordonnées. Les coordonnées sont demandées au joueur.
                    verif_alignement = alignement(tab, n, i, j); //Vérifie si le pion posé du joueur "n" créer un alignement.
                    paires(tab, n, i, j, total); //Vérifie si le pion posé du joueur "n" capture une paire ou plus.

                    if(total[n - 1] > 4)
                    {
                        victoire = n; //Victoire au joueur "n".
                        affiche(tab, total); //Affiche le plateau de jeu.
                    }
                    else if(verif_alignement == 1)
                    {
                        regleAjouter = 1; //Active la règle additionnelle.
                    }

                    n = changeJoueur(n); //Changement de joueur.
                }
            }
            else
            {
                victoire = 3; //Valeur de match nul.
                affiche(tab, total); //Affiche le plateau de jeu.
            }
        }

        gagne(victoire, verif_alignement, total); //Affiche le joueur qui a gagné.
        ecrireFichier(fichier, partie, victoire); //Ecrit le vainqueur et le mode de victoire dans le fichier.
        partie = rejouer(partie); //Demande si le joueur veut refaire une partie (valeur != 0) ou quitter le jeu (valeur == 0).

    }

    lireFichier(fichier, chaine); //Lecture du contenu du fichier et affichage de celui-ci.
    printf("\n"); //Espace pour un affichage plus propre.
    remove("score.txt"); //Suppression du fichier "score.txt"

    return 0;
}




