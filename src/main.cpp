#include <iostream>
#include <fstream>
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
         ifstream file;
         file.open(argv[1]);
         if (file.is_open())
         {
             try
             {
                 file >> *automate;
             }
             catch(exception const& e)
             {
                 cerr << "Erreur : "<< e.what() << endl;
             }
             file.close();
         }
    }
    else
    {
        int nb_state, nb_symbole, nb_final_state, initial_state;
        set<int> final_state = set<int>();
        vector<vector<int>> transitionMatrix = vector<vector<int>>();
        cout << "Quel est le nombre d'états de l'automate ?";
        cin >> nb_state;
        cout << endl << "Quel est le nombre de symbole composant l'alphabet accepté par l'automate ?";
        cin >> nb_symbole;
        cout << endl << "Quel est le nombre d'états finaux de l'automate' ?";
        cin >> nb_final_state;
        cout << endl << "Quel est le numéro de l'état de départ de l'automate ?";
        cin >> initial_state;
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
            transitionMatrix.push_back(vector<int>());
            for(int j = 0; j < nb_symbole; j++)
            {
                int state;
                cout << endl << "Veillez saisir l'état de sortie pour la fonction de transition de l'état " << i << " symbole " << (char)(j+97) << ":";
                cin >> state;
                transitionMatrix[i].push_back(state);
            }
        }
        try
        {
            automate = new Automate(initial_state,final_state,transitionMatrix);
            cout << endl << "Automate sérialisé :";
            cout << endl << *automate;
        }
        catch(exception const& e)
        {
            cerr << "Erreur : "<< e.what() << endl;
        }
    }

    try
    {
        string str;
        cout << endl << "Veuillez saisir une chaine de caractère à lire par l'automate :";
        cin >> str;
        *automate << str;
        cout << "L'automate c'est finit dans l'état : " << automate->currentState() << "." << endl;
        cout << "La chaine de caractère : '" << str << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
    }
    catch(exception const& e)
    {
        cerr << "ERREUR : "<< e.what() << endl;
    }

    return 0;
}

    //TODO:Write a test method
