#include <iostream>
#include "Plateau.h"
#include "Etat.h"

using namespace std;

Plateau::Plateau()
{
    this->hauteur = 9;
    this->largeur = 15;
    this->tab = new Etat*[this->hauteur];

    for(int i = 0; i < this->hauteur; i++)
    {
        this->tab[i] = new Etat[this->largeur];
        for(int j = 0; j < this->largeur; j++)
        {
            this->tab[i][j].set_o(false);
            this->tab[i][j].set_d(1);
        }
    }
}

Plateau::Plateau(int h, int l)
{
    if(h%2 == 1 && l%2 == 1)
    {
        this->hauteur = h;
        this->largeur = l;
    }
    else
    {
        this->hauteur = 9;
        this->largeur = 15;
    }

    this->tab = new Etat*[this->hauteur];

    for(int i = 0; i < this->hauteur; i++)
    {
        this->tab[i] = new Etat[this->largeur];
        for(int j = 0; j < this->largeur; j++)
        {
            this->tab[i][j].set_o(false);
            this->tab[i][j].set_d(1);
        }
    }
}

Plateau::Plateau(const Plateau &plateauSource)
{
    (*this) = plateauSource;
}

Plateau& Plateau::operator=(const Plateau &plateauSource)
{
	this->hauteur = plateauSource.get_h();
	this->largeur = plateauSource.get_l();
    this->tab = new Etat*[this->hauteur];

    for(int i = 0; i < this->hauteur; i++)
    {
        this->tab[i] = new Etat[this->largeur];
        for(int j = 0; j < this->largeur; j++)
        {
            this->tab[i][j] = plateauSource.tab[i][j];
        }
    }
	return *this;
}

Plateau& Plateau::operator++()
{
    Plateau plateauSource(*this);
    delete[] this->tab;
    this->hauteur = this->hauteur + 2;
    this->largeur = this->largeur + 2;
    this->tab = new Etat*[this->hauteur + 2];
    for(int i = 0; i < this->hauteur; i++)
    {
        this->tab[i] = new Etat[this->largeur + 2];
        for(int j = 0; j < this->largeur; j++)
        {
            if(i == 0 || i == this->hauteur - 1 || j == 0 || j == this->largeur - 1)
            {
                this->tab[i][j].set_o(false);
                this->tab[i][j].set_d(1);
            }
            else
            {
                this->tab[i][j] = plateauSource.tab[i - 1][j - 1];
                this->tab[i][j] = plateauSource.tab[i - 1][j - 1];
            }
        }
    }

    return *this;
}

Plateau::~Plateau()
{
    for(int i = 0; i < this->hauteur; i++)
    {
        delete[] this->tab[i];
    }
    delete[] this->tab;
}

void Plateau::affiche()
{
    for(int i = 0; i < this->hauteur; i++)
    {
        for(int j = 0; j < this->largeur; j++)
        {
            if(this->tab[i][j].get_o() == false)
            {
                if(this->tab[i][j].get_d() == 1)
                    cout << "o";
                if(this->tab[i][j].get_d() == 2)
                    cout << "n";
                if(this->tab[i][j].get_d() == 3)
                    cout << "e";
                if(this->tab[i][j].get_d() == 4)
                    cout << "s";
            }
            else
            {
                if(this->tab[i][j].get_d() == 1)
                    cout << "O";
                if(this->tab[i][j].get_d() == 2)
                    cout << "N";
                if(this->tab[i][j].get_d() == 3)
                    cout << "E";
                if(this->tab[i][j].get_d() == 4)
                    cout << "S";
            }
        }
        cout << endl;
    }
}

Etat& Plateau::get_case(int i, int j)
{
    return this->tab[i][j];
}

int Plateau::get_h() const
{
    return this->hauteur;
}

int Plateau::get_l() const
{
    return this->largeur;
}
