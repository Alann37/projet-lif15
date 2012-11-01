#include "automate.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Automate::Automate()
{
    etats_finaux = set<int>();
    etat_initial = 0;
    nb_etats = 0;
    nb_etats_finaux = 0;
    nb_symboles = 0;
    matrice_transition = vector<vector<int>>();
}

Automate::~Automate()
{
}

int Automate::statesCount() const
{
    return nb_etats;
}

int Automate::symbolesCount() const
{
    return nb_symboles;
}

const vector<int>& Automate::finalState() const
{
    return etats_finaux;
}

int Automate::initialState() const
{
    return etat_initial;
}

void Automate::initialize()
{
    _currentState = etat_initial;
}

int Automate::currentState() const
{
    return _currentState;
}

bool Automate::isFinal() const
{
    for(set<int>::iterator i = etats_finaux.begin(); i != etats_finaux.end(); i++)
        if(*i == currentState()) return true;
    return false;
}

int Automate::delta(const int state, const char symbole) const
{
    return this->matrice_transition[state][(int)symbole - 97];
}

Automate& Automate::operator<< (const string& value)
{
    for( string::const_iterator i = value.begin(); i != value.end(); i++)
    {
        if((((int)*i - 97) < 0) || (((int)*i - 97) > nb_symboles))
            throw overflow_error(string("Le symbole ") + *i + string(" n'est pas accepté par l'automate"));
        _currentState = delta(currentState(),*i);
    }
    return *this;
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
