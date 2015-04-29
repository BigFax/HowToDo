#ifndef CLASS_FOURMILIERE
#define CLASS_FOURMILIERE

#include <vector>
#include "Plateau.h"
#include "Fourmi.h"

class Fourmiliere
{
    private :
        Plateau *plateau;
        std::vector<Fourmi> popu;
        static int nb;
    public :
        Fourmiliere(Plateau& plat);
        void ajout();
        void affiche();
        void stats();
        void stats(int n, int m);
};

#endif
