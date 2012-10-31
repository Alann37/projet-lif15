#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include <set>
#include <iostream>

using namespace std;

/*!
 * \brief Contient les attribut et m�thode permetant la d�finition et l'execution d'un automate finit deterministe
 */
class Automate{

  // caract�ristiques
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;
  int etat_initial; // �tats initial
  set<int> etats_finaux; // �tats finaux
  vector<vector<int>> matrice_transition; // matrice de transition

public:

  explicit Automate();
  ~Automate();
  /*!
   * \brief delta fonction de transition de l'automate qui retourne un etat de sortie en fonction d'un etat et d'un symbole donn� en entr�e.
   * \param state etat courant de l'automate
   * \param symbole symoble � lire par l'automate
   * \return pair<int,bool> representant le num�ro de l'�tat de sortie et un bool�en indiquant si celui ci est final ou non
   */
  pair<int,bool> delta(const int state, const char symbole) const;
  /*!
   * \brief operator << operateur de flux de sortie permetant la s�rialition de l'automate pass� en argument dans le flux � gauche de l'op�rande
   */
  friend ostream& operator<< (ostream& stream, const Automate& value);
  /*!
   * \brief operator >> op�rateur de flux d'entr�e permetant la d�s�rialisation dans l'automate pass� en argument � partir du flux � gauche de l'op�rande
   */
  friend istream& operator>> (istream& stream, Automate& value);

};

#endif // AUTOMATE_H
