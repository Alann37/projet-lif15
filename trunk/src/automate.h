#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include <set>
#include <iostream>

using namespace std;

/*!
 * \brief Contient les attribut et méthode permetant la définition et l'execution d'un automate finit deterministe
 */
class Automate{

  // caractéristiques
  int nb_etats;
  int nb_symboles;
  int nb_etats_finaux;
  int etat_initial; // états initial
  set<int> etats_finaux; // états finaux
  vector<vector<int>> matrice_transition; // matrice de transition

public:

  explicit Automate();
  ~Automate();
  /*!
   * \brief delta fonction de transition de l'automate qui retourne un etat de sortie en fonction d'un etat et d'un symbole donné en entrée.
   * \param state etat courant de l'automate
   * \param symbole symoble à lire par l'automate
   * \return pair<int,bool> representant le numéro de l'état de sortie et un booléen indiquant si celui ci est final ou non
   */
  pair<int,bool> delta(const int state, const char symbole) const;
  /*!
   * \brief operator << operateur de flux de sortie permetant la sérialition de l'automate passé en argument dans le flux à gauche de l'opérande
   */
  friend ostream& operator<< (ostream& stream, const Automate& value);
  /*!
   * \brief operator >> opérateur de flux d'entrée permetant la désérialisation dans l'automate passé en argument à partir du flux à gauche de l'opérande
   */
  friend istream& operator>> (istream& stream, Automate& value);

};

#endif // AUTOMATE_H
