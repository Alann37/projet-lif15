#include "automate.h"

#include <iostream>

bool Automate::readfile(const char* filename)
{
    FILE** file;
    if(fopen_s(file, filename,"R"))
    {
        return true;
    }
    else
        return false;
}

pair<int, bool> Automate::delta(const int state, const char symbole)
{
    int rstate = this->matrice_transition[state][symbole];
    bool final = std::find(nb_etats_finaux.begin(), nb_etats_finaux.end(), rstate) != nb_etats_finaux.end();
    return pair<int, bool>(rstate,final);
}
