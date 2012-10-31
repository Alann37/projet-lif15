#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include <string>

using namespace std;

//TODO: Add a comment
class Automate
{
  // caractristiques
private :
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;

  // tats initial
  int etat_initial;

  // tats finaux
  vector<int> etats_finaux;

  // matrice de transition
  vector<vector<int> > matrice_transition;

public:
  //TODO: Add a comment
  bool readfile(const string filename);
  //TODO: Add a comment
  pair<int,bool> delta(const string str);

};



#endif // AUTOMATE_H
