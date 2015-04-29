#include <iostream>
#include "Etat.h"

using namespace std;

Etat::Etat()
{
    this->occupe = false;
    this->direction = 1;
}

Etat::Etat(bool o, int d)
{
    this->occupe = o;
    if(d > 0 && d < 5)
        this->direction = d;
    else
        this->direction = 1;
}

bool Etat::get_o()
{
    return this->occupe;
}

int Etat::get_d()
{
    return this->direction;
}

void Etat::set_o(bool o)
{
    this->occupe = o;
}

void Etat::set_d(int d)
{
    this->direction = d;
}

void Etat::modif_d()
{
    if(this->direction == 1)
        this->direction = 2;
    else if(this->direction == 2)
        this->direction = 3;
    else if(this->direction == 3)
        this->direction = 4;
    else
        this->direction = 1;
}
