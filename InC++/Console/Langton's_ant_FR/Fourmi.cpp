#include <iostream>
#include <windows.h>
#include "Plateau.h"
#include "Fourmi.h"

using namespace std;

Fourmi::Fourmi(Plateau &plat)
{
    this->i = (plat.get_h() / 2);
    this->j = (plat.get_l() / 2);

    for(this->d = 0 ; plat.get_case(this->i, this->j).get_o() == true ; this->d++)
    {
        plat.get_case(this->i, this->j).modif_d();
        if(plat.get_case(this->i, this->j).get_d() == 1)
        {
            this->j--;
        }
        else if(plat.get_case(this->i, this->j).get_d() == 2)
        {
            this->i--;
        }
        else if(plat.get_case(this->i, this->j).get_d() == 3)
        {
            this->j++;
        }
        else if(plat.get_case(this->i, this->j).get_d() == 4)
        {
            this->i++;
        }
    }

    plat.get_case(this->i, this->j).set_o(true);

    if(this->i < 2 || this->i > plat.get_h() - 2 || this->j < 2 || this->j > plat.get_l() - 2)
    {
        plat.operator++();
    }
}


int Fourmi::get_d()
{
    return this->d;
}





