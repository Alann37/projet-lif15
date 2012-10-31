#include <iostream>
#include "automate.h"

using namespace std;

/*!
 * \brief main Point d'entrée du programme
 */
int main(int argc, char** argv)
{
    Automate* automate = new Automate();
    if(argc > 1)
    {
         ofstream  file(argv[1],ios::out);
         if (file.is_open())
            file >> automate;
    }
    else
    {
        int nb_state, nb_symbole, nb_final_state, start_state;
        set<int> final_state();
        cout << "Quel est le nombre d'états de l'automate ?" << endl;
        cin >> nb_state;
        cout << "Quel est le nombre de symbole composant l'alphabet accepté par l'automate ?" << endl;
        cin >> nb_symbole;
        cout << "Quel est le nombre d'états finaux de l'automate' ?" << endl;
        cin >> nb_final_state;
        cout << "Quel est le numéro de l'état de départ de l'automate ?" << endl;
        cin >> start_state;
        int temp;
        cout << "Quel est le numéro du 1rt état final de l'automate ?" << endl;
        cin >> temp;
        final_state.insert(temp);
        for (int i = 1; i < automate->nb_etats_finaux; i++)
        {
            cout << "Quel est le numéro du " << i << "ème état final de l'automate ?" << endl;
            cin >> temp;
            final_state.insert(temp);
        }
        cout << "Veillez " << endl;
    }
    //TODO:Load a file if argc > 1 or ask for automate parameter to the user before start the execution of the programm.
    //TODO:Ask for a string to the user to execute with the current loaded automate.
    return 0;
}
