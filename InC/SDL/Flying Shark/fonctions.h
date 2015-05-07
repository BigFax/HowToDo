#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS

void fc_tir(Struct_Tir tir[], Struct_Bombe bombe[], SDL_Rect *positionMainPlane, int *numeroTir, int *numeroBombe, FMOD_SYSTEM **system, FMOD_SOUND **tirSound, int choix, int *music, int *sound, int *mode, int *bonus);
void fc_sens(SDL_Surface **mainPlane , SDL_Rect *positionMainPlane, SDL_Surface **mainPlaneOmbre, SDL_Rect *positionMainPlaneOmbre, int *sens);
void fc_analyse_caractere(Struct_Ennemi ennemi[], char caractere, int *numeroEnnemi, FILE *fichier, int *bonus);
void fc_ennemi_map(Struct_Ennemi ennemi[], int *numeroEnnemi, int *numeroTirEnnemi, Struct_Tir tirEnnemi[], int *music, int *sound, int *mode, FMOD_SYSTEM **system, FMOD_SOUND **tirSound);
void gestion_events_poll(Struct_Event *worker);
void fc_pause();
void fc_texte(SDL_Surface *ecran, char chaine[100], int x, int y, SDL_Color couleurBlanche, int taille);
void fc_gameover();
void sauvegarde(SDL_Surface *ecran, SDL_Color couleurBlanche, char nom[100], int level, int score, int choixMenu);

#endif

