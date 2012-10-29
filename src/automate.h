#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>

using namespace std;

struct sAutomate{
  // caractéristiques
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;

  // états initial
  int etat_initial;

  // états finaux
  // (stockés dans un tableau dynamique, un vector...)
  vector<int> etats_finaux;

  // matrice de transition
  // (stockée dans un tableau dynamique 2D, un vector de vectors...)
  vector<vector<int>> matrice_transition;


} typedef Automate;

#endif // AUTOMATE_H
