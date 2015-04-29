#include <iostream>
#include <windows.h>
#include "Plateau.h"
#include "Fourmi.h"
#include "Fourmiliere.h"

using namespace std;

bool operator<(const Fourmi &a, const Fourmi &b)
{
    if(a.d < b.d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char* argv[])
{
    Plateau plateau001;
    Fourmiliere fourmiliere(plateau001);

    for(int compteur = 1; compteur <= 5000; compteur++)
    {
        system("cls");
        fourmiliere.ajout();
        fourmiliere.affiche();
        Sleep(10);
    }

    fourmiliere.stats();
    cout << endl;
    fourmiliere.stats(32, 39);

    return 0;
}
