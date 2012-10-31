#include "automate.h"

#include <iostream>
#include <fstream>

using namespace std;

bool Automate::readfile(const string filename)
{
    //TODO: Add a comment
    //TODO: Complete the reading method
    ifstream file(filename.c_str(), ios::in);
    if(file)
    {
        file >> nb_etats >> nb_symboles >> nb_etats_finaux;
        file >> etat_initial;
        for (int i = 0; i< nb_etats_finaux; i++)
        {
            int var;
            file >> var;
            etats_finaux.insert(etats_finaux.end(), var);
        }
        //initialisation de la matrice
        matrice_transition.resize(nb_etats);
        for(int i = 0; i<nb_etats; i++ )
            matrice_transition[i].resize(nb_symboles);
        int etat,etat_arrive;
        char symbole;
        for(int i = 0; i<nb_etats*nb_symboles; i++)
        {
              file >> etat >> symbole >> etat_arrive;
         matrice_transition[etat][symbole - 97] = etat_arrive;
        }
         file.close();
        return true;
    }
    else  // sinon
                    cerr << "Impossible d'ouvrir le fichier !" << endl;

    return false;
}

pair<int, bool> Automate::delta(const string str)
{

    //TODO: Add a comment
    //TODO: Test
}
