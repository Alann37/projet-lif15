#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>

using namespace std;

//TODO: Add a comment
struct s_Automate{
  // caract�ristiques
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;

  // �tats initial
  int etat_initial;

  // �tats finaux
  vector<int> etats_finaux;

  // matrice de transition
  vector<vector<int>> matrice_transition;

  //TODO: Add a comment
  bool readfile(const char* filename);
  //TODO: Add a comment
  pair<int,bool> delta(const int state, const char symbole);


} typedef Automate;

#endif // AUTOMATE_H
