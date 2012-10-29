#include "automate.h"

#include <iostream>

bool Automate::readfile(const char* filename)
{
    //TODO: Add a comment
    //TODO: Complete the reading method
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
    //TODO: Add a comment
    //TODO: Test
    int rstate = this->matrice_transition[state][symbole];
    bool final = std::find(nb_etats_finaux.begin(), nb_etats_finaux.end(), rstate) != nb_etats_finaux.end();
    return pair<int, bool>(rstate,final);
}
