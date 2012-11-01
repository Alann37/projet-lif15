#include "automate.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Automate::Automate()
{
    _finalStates = set<int>();
    _initialState = 0;
    _statesCount = 0;
    _finalStatesCount = 0;
    _symbolesCount = 0;
    matrice_transition = vector<vector<int>>();
}

Automate::~Automate()
{
}

int Automate::statesCount() const
{
    return _statesCount;
}

int Automate::symbolesCount() const
{
    return _symbolesCount;
}

const set<int>& Automate::finalState() const
{
    return _finalStates;
}

int Automate::initialState() const
{
    return _initialState;
}

void Automate::initialize()
{
    _currentState = _initialState;
}

int Automate::currentState() const
{
    return _currentState;
}

bool Automate::isFinal() const
{
    for(set<int>::iterator i = _finalStates.begin(); i != _finalStates.end(); i++)
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
        if((((int)*i - 97) < 0) || (((int)*i - 97) > _symbolesCount))
            throw overflow_error(string("Le symbole ") + *i + string(" n'est pas accepté par l'automate"));
        _currentState = delta(currentState(),*i);
    }
    return *this;
}

ostream& operator<<(ostream& stream, const Automate& value)
{
    stream << value._statesCount << " " << value._symbolesCount << " " << value._finalStates.size() << endl;
    stream << value._initialState << endl;
    for(set<int>::iterator i = value._finalStates.begin(); i != value._finalStates.end(); i++)
        stream << *i << endl;
    for(int i = 0; i < value._statesCount; i++)
    {
        for(int j = 0; j < value._symbolesCount; j++)
        {
            stream << i << " " << j << " " << value.matrice_transition[i][j] << endl;
        }
    }
    return stream;
}

istream& operator>> (istream& stream, Automate& value)
{
    string blank;
    stream >> value._statesCount >> blank >> value._symbolesCount >> blank >> value._finalStatesCount >> blank;
    stream >> value._initialState >> blank;
    int state, symbole, rstate;
    for(int i = 0; i < value._finalStatesCount; i++)
    {
        stream >> state >> blank;
        value._finalStates.insert(state);
    }
    vector<int> line = vector<int>();
    for(int i = 0; i < value._statesCount; i++)
    {
        line = vector<int>();
        line.assign(value._symbolesCount,0);
    }
    for(int i = 0; i < value._statesCount * value._symbolesCount; i++)
    {
        stream >> state >> blank >> symbole >> blank >> rstate >> blank;
        value.matrice_transition[state][symbole] = rstate;
    }
    return stream;
}
