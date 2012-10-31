#include "automate.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Automate::Automate()
{
    this->etats_finaux = set<int>();
    this->etat_initial = 0;
    this->nb_etats = 0;
    this->nb_etats_finaux = 0;
    this->nb_symboles = 0;
    this->matrice_transition = vector<vector<int>>();
}

Automate::~Automate()
{
    delete etats_finaux;
    delete matrice_transition;
}

pair<int, bool> Automate::delta(const int state, const char symbole) const
{
    //TODO: Test
    int rstate = this->matrice_transition[state][symbole];
    set<int>::iterator i;
    for(i = etats_finaux.begin();i != etats_finaux.end();i++)
    {
        if(*i == rstate)
            return pair<int, bool>(rstate,true);
    }
    return pair<int, bool>(rstate,false);
}

ostream& operator<<(ostream& stream, const Automate& value)
{
    stream << value.nb_etats << " " << value.nb_symboles << " " << value.etats_finaux.size() << endl;
    stream << value.etat_initial << endl;
    for(set<int>::iterator i = value.etats_finaux.begin(); i != value.etats_finaux.end(); i++)
        stream << *i << endl;
    for(int i = 0; i < value.nb_etats; i++)
    {
        for(int j = 0; j < value.nb_symboles; j++)
        {
            stream << i << " " << j << " " << value.matrice_transition[i][j] << endl;
        }
    }
    return stream;
}

istream& operator>> (istream& stream, Automate& value)
{
    string blank;
    stream >> value.nb_etats >> blank >> value.nb_symboles >> blank >> value.nb_etats_finaux >> blank;
    stream >> value.etat_initial >> blank;
    int state, symbole, rstate;
    for(int i = 0; i < value.nb_etats_finaux; i++)
    {
        stream >> state >> blank;
        value.etats_finaux.insert(state);
    }
    vector<int> line = vector<int>();
    for(int i = 0; i < value.nb_etats; i++)
    {
        line = vector<int>();
        line.assign(value.nb_symboles,0);
    }
    for(int i = 0; i < value.nb_etats * value.nb_symboles; i++)
    {
        stream >> state >> blank >> symbole >> blank >> rstate >> blank;
        value.matrice_transition[state][symbole] = rstate;
    }
    return stream;
}
