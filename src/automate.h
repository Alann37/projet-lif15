#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include <set>
#include <iostream>
#include <string>

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
  int _currentState;
public:

  /*!
  * \brief currentState obtient le numéro de l'état actuel.
  */
  int currentState() const;
  /*!
   * \brief isFinal retourne Vrai si l'état actuel de l'automate est final.
   */
  bool isFinal() const;

  /*!
   * \brief statesCount Obtient le nombre d'etat de l'automate.
   */
  int statesCount() const;
  /*!
   * \brief symbolesCount Obtient le nombre de symbole accepté par l'automate. L'automate accepte tous les caractère en partant du caractère ASCII 'a' jusqu'au caractère ASCII ('a' + statesCount()).
   */
  int symbolesCount() const;
  /*!
   * \brief finalState Obtient un tableau non modifiable des états finaux de l'automate.
   */
  const vector<int> &finalState() const;
  /*!
   * \brief initialState Obtient l'état initial de l'automate
   */
  int initialState() const;

  explicit Automate();
  ~Automate();
  /*!
   * \brief initialize définit l'état actuel de l'automate sur l'état de départ.
   */
  void initialize();
  /*!
   * \brief delta fonction de transition de l'automate qui retourne un etat de sortie en fonction d'un etat et d'un symbole donné en entrée.
   * \param state etat courant de l'automate
   * \param symbole symoble à lire par l'automate
   * \return pair<int,bool> representant le numéro de l'état de sortie et un booléen indiquant si celui ci est final ou non
   */
  int delta(const int state, const char symbole) const;

  /*!
   * \brief operator << operateur de lecture de l'automate, l'automate execute l'ensemble des symboles passés en arguments à partir de son état courant
   * \param value chaine de caractère contenant un suite de symboles acceptés par l'automate
   * \exception std::overflow_error le symbole lu n'est pas accepté par l'automate
   * \return l'automate dans son état après lecture de la chaine de caractère
   */
  Automate& operator<< (const string& value);

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
