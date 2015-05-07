#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define LARGEUR_FENETRE          640
#define HAUTEUR_FENETRE          480
#define NBRE_TIR_MAX             100
#define NBRE_TIR_ENNEMI_MAX      100
#define NBRE_ENNEMI_MAX          100
#define NBRE_EXPLOSION_MAX       100
#define NBRE_BOMBE_MAX           10
#define SCROLL                   0.5

    //Déclaration de constantes (variables globales) remplacées à la compilation dans l'ordre par 0, 1, 2, 3 et 4.
    enum{STATIC, GAUCHE, DROITE, HAUT, BAS};
    enum{TIR, BOMBE};

    typedef struct Struct_Event Struct_Event;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Event".
    struct Struct_Event
    {
        int key[SDLK_LAST];//Tableau de int (dont le nom est key) et dont la taille SDLK_LAST est une constante SDL qui contient la plus haute valeur de la touche SDL, +1.
        int quit;//Variable de type int.
    };

    typedef struct Struct_Tir Struct_Tir;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Tir".
    struct Struct_Tir
    {
        SDL_Surface *surfaceTir;
        SDL_Rect positionTir;
    };

    typedef struct Struct_Ennemi Struct_Ennemi;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Ennemi".
    struct Struct_Ennemi
    {
        SDL_Surface *surfaceEnnemi;
        SDL_Rect positionEnnemi;
        int sensEnnemi;
        int type;
    };

    typedef struct Struct_Explosion Struct_Explosion;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Explosion".
    struct Struct_Explosion
    {
        SDL_Surface *surfaceExplosion;
        SDL_Rect positionExplosion;
        int compteurAnimation;
    };

    typedef struct Struct_Bombe Struct_Bombe;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Tir".
    struct Struct_Bombe
    {
        SDL_Surface *surfaceBombe;
        SDL_Rect positionBombe;
    };

    typedef struct Struct_Partie Struct_Partie;//Evite de réécrire struct dans le reste du programme devant le type "Struct_Tir".
    struct Struct_Partie
    {
        char partie[100];
    };

#endif
