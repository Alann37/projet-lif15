#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>

using namespace std;

struct s_Automate{
  // caract�ristiques
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;

  // �tats initial
  int etat_initial;

  // �tats finaux
  // (stock�s dans un tableau dynamique, un vector...)
  vector<int> etats_finaux;

  // matrice de transition
  // (stock�e dans un tableau dynamique 2D, un vector de vectors...)
  //vector<int,int> matrice_transition;

  bool readfile(const char* filename);
} typedef Automate;

#endif // AUTOMATE_H
