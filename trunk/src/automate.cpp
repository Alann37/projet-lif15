#include "automate.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Automate::Automate()
{
    _finalStates = set<int>();
    _initialState = 0;
    _statesCount = 1;
    _finalStatesCount = 1;
    _symbolesCount = 1;
    _transitionMatrix = vector<vector<int>>();
}

Automate::Automate(int myInitialState,const set<int>& myFinalStates,const vector<vector<int>>& myTransitionMaxtrix)
{
    vector<int> z;
    if(myTransitionMaxtrix.empty())
        throw underflow_error(string("L'automate doit contenir au moins un état."));

    vector<int> state = *myTransitionMaxtrix.begin();
    for(vector<vector<int>>::const_iterator i = (myTransitionMaxtrix.begin() + 1); i != myTransitionMaxtrix.end(); i++)
    {
        if(state.size() != (*i).size())
            throw invalid_argument("L'automate n'est pas deterministe. La matrice de transition n'est pas un tableau à deux dimension, des lignes de taille différentes ont été trouvées.");
    }

    if(myTransitionMaxtrix[0].empty())
        throw underflow_error(string("L'automate doit contenir au moins un symbole par état."));

    if((myInitialState < 0) || (myInitialState >= (int)myTransitionMaxtrix.size()))
        throw overflow_error(string("L'état initial ne fait pas partit de l'automate."));

    for(set<int>::iterator i = myFinalStates.begin(); i != myFinalStates.end(); i++)
    {
        if((*i < 0) || (*i >= (int)myTransitionMaxtrix.size()))
            throw overflow_error(string("Un ou plusieurs états finaux ne font pas partit de l'automate."));
    }

    _finalStates = myFinalStates;
    _initialState = myInitialState;
    _transitionMatrix = myTransitionMaxtrix;
    _symbolesCount = myTransitionMaxtrix[0].size();
    _statesCount = myTransitionMaxtrix.size();
    _finalStatesCount = myFinalStates.size();
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
    return this->_transitionMatrix[state][(int)symbole - 97];
}

Automate& Automate::operator<< (const string& value)
{
    cout << "L'automate est dans l'état " << _currentState << ", il va lire la chaine de caractère : '" << value << "'" << endl;
    for( string::const_iterator i = value.begin(); i != value.end(); i++)
    {
        if((((int)*i - 97) < 0) || (((int)*i - 97) > _symbolesCount))
            throw overflow_error(string("Le symbole ") + *i + string(" n'est pas accepté par l'automate"));
        _currentState = delta(currentState(),*i);
        cout << "L'automate lit le caractère " << *i << " et passe dans l'état " << _currentState << endl;
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
            stream << i << " " << j << " " << value._transitionMatrix[i][j] << endl;
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
        line.clear();
        line.assign(value._symbolesCount,0);
        value._transitionMatrix.push_back(line);
    }
    for(int i = 0; i < value._statesCount * value._symbolesCount; i++)
    {
        stream >> state >> blank >> symbole >> blank >> rstate >> blank;
        value._transitionMatrix[state][symbole] = rstate;
    }
    return stream;
}
