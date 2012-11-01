#include <iostream>
#include <fstream>
#include "automate.h"

using namespace std;

/*!
 * \brief main Point d'entrée du programme
 */
int main(int argc, char** argv)
{
    Automate automate = Automate();
    if(argc > 1)
    {
         ifstream file;
         file.open(argv[1]);
         if (file.is_open())
         {
             try
             {
                 file >> automate;
             }
             catch(exception const& e)
             {
                 cerr << "ERREUR : "<< e.what() << endl;
             }
         }
    }
    else
    {
        int nb_state, nb_symbole, nb_final_state, start_state;
        set<int> final_state = set<int>();
        cout << "Quel est le nombre d'états de l'automate ?";
        cin >> nb_state;
        cout << endl << "Quel est le nombre de symbole composant l'alphabet accepté par l'automate ?";
        cin >> nb_symbole;
        cout << endl << "Quel est le nombre d'états finaux de l'automate' ?";
        cin >> nb_final_state;
        cout << endl << "Quel est le numéro de l'état de départ de l'automate ?";
        cin >> start_state;
        int temp;
        cout << endl << "Quel est le numéro du 1er état final de l'automate ?";
        cin >> temp;
        final_state.insert(temp);
        for (int i = 1; i < nb_final_state; i++)
        {
            cout << endl << "Quel est le numéro du " << (i+1) << "ème état final de l'automate ?";
            cin >> temp;
            final_state.insert(temp);
        }
        for(int i = 0; i < nb_state; i++)
        {
            for(int j = 0; j < nb_symbole; j++)
            {
                char c;
                cout << endl << "Veillez saisir l'état de sortie pour la fonction de transition de l'état " << i << " symbole " << (char)(j+97) << ":";
                cin >> c;
            }
        }

    }

    //TODO:Ask for a string to the user to execute with the current loaded automate.

    return 0;
}

    //TODO:Write a test method
