#include <iostream>
#include "Plateau.h"
#include "Fourmi.h"
#include "Fourmiliere.h"

using namespace std;

int Fourmiliere::nb = 0;

Fourmiliere::Fourmiliere(Plateau &plat)
{
    plateau = new Plateau;
    *this->plateau = plat;

    Fourmi fourmi(*this->plateau);
    this->popu.push_back(fourmi);
}

void Fourmiliere::ajout()
{
    Fourmi fourmi(*this->plateau);
    this->popu.push_back(fourmi);
    this->nb++;
}

void Fourmiliere::affiche()
{
    cout << endl << "Fourmi numero " << this->nb << endl << endl;
    this->plateau->affiche();
    cout << endl << "Distance parcourue par cette fourmie : " << this->popu[this->nb - 1].get_d() << endl << endl;
}

void Fourmiliere::stats()
{
    int min = this->popu[0].get_d(), max = this->popu[0].get_d(), moyenne = 0, fourmiMin = 1, fourmiMax = 1;

    for(int i = 0 ; i < this->nb ; i++)
    {
        moyenne += this->popu[i].get_d();

        if(this->popu[i].get_d() < min)
        {
            min = this->popu[i].get_d();
            fourmiMin = i + 1;
        }

        if(this->popu[i].get_d() > max)
        {
            max = this->popu[i].get_d();
            fourmiMax = i + 1;
        }
    }

    moyenne /= this->nb;

    cout << endl;
    cout << "Rapport de la colonie : " << endl;
    cout << "Pas minimum : " << min << " Numero de la fourmie : " << fourmiMin << endl;
    cout << "Pas moyen : " << moyenne << endl;
    cout << "Pas maximum : " << max << " Numero de la fourmie : " << fourmiMax << endl;
}

void Fourmiliere::stats(int n, int m)
{
    int min = this->popu[n].get_d(), max = this->popu[n].get_d(), moyenne = 0, fourmiMin = n, fourmiMax = n;
    int i = n - 1;

    if(i <= this->nb && m <= this->nb && i <= m)
    {
        for(i ; i < m ; i++)
        {
            moyenne += this->popu[i].get_d();

            if(this->popu[i].get_d() < min)
            {
                min = this->popu[i].get_d();
                fourmiMin = i + 1;
            }

            if(this->popu[i].get_d() > max)
            {
                max = this->popu[i].get_d();
                fourmiMax = i + 1;
            }
        }

    moyenne /= m - n + 1;

    cout << endl;
    cout << "Rapport de la colonie : " << endl;
    cout << "Pas minimum : " << min << " Numero de la fourmie : " << fourmiMin << endl;
    cout << "Pas moyen : " << moyenne << endl;
    cout << "Pas maximum : " << max << " Numero de la fourmie : " << fourmiMax << endl;
    }
}
