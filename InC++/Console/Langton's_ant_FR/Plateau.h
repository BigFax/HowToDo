#ifndef CLASS_PLATEAU
#define CLASS_PLATEAU

#include "Etat.h"

class Plateau
{
    private :
        Etat** tab;
        int hauteur, largeur;
    public :
        Plateau();
        Plateau(int h, int l);
        Plateau(const Plateau &plateauSource);
        Plateau& operator=(const Plateau &plateauSource);
        Plateau& operator++();
        ~Plateau();
        void affiche();
        Etat& get_case(int i, int j);
        int get_h() const;
        int get_l() const;
};

#endif
