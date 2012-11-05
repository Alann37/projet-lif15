#include <iostream>
#include <fstream>
#include "automate.h"

using namespace std;

void test();

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
		 else
		 {
			 cerr << "Impossible d'ouvrir le fichier passé en argument.";
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
        automate->read(str,true);
        cout << "L'automate c'est finit dans l'état : " << automate->currentState() << "." << endl;
        cout << "La chaine de caractère : '" << str << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;

        int lenght = 10;
        vector<string>* lastLine = new vector<string>();
        vector<string>* newLine = new vector<string>();
        vector<string>* lemme = new vector<string>();

        for(int i = 0; i < automate->symbolesCount(); i++)
        {
            lastLine->push_back(string(1,(char)(i + 97)));
            lemme->push_back(string(1,(char)(i + 97)));
        }

        for(int i = 0; i < 10; i++)
        {
            for(vector<string>::iterator j = lastLine->begin(); j != lastLine->end(); j++)
            {
                for(int k = 0; k < automate->symbolesCount(); k++)
                {
                    newLine->push_back(*j + (char)(k + 97));
                    lemme->push_back(*j + (char)(k + 97));
                }
            }
            vector<string>* temp = lastLine;
            lastLine = newLine;
            newLine = temp;
            newLine->clear();
        }

        for(vector<string>::iterator i = lemme->begin(); i != lemme->end(); i++)
		{
			automate->initialize();
			*automate << *i;
			if (automate->isFinal())
				cout << *i << endl;
		}
        
        delete lastLine;
        delete newLine;
        delete lemme;
    }
    catch(exception const& e)
    {
        cerr << "Erreur : "<< e.what() << endl;
    }

    test();

    return 0;
}

/*!
 * \brief test test unitaire d'un automate n'acceptant que des chaine de la forme 'a*' avec un alphabet sigma = ('a','b'). Le détails des opérations de chaque chaines testées est affiché sur la sortie standard.
 */
void test()
{
    set<int> finalState = set<int>();
    vector<vector<int>> transMatrix = vector<vector<int>>();
    vector<int> line = vector<int>();
    finalState.insert(0);
    line.push_back(0);
    line.push_back(1);
    transMatrix.push_back(line);
    line.clear();
    line.push_back(1);
    line.push_back(1);
    transMatrix.push_back(line);
    try
    {
        Automate* automate = new Automate(0,finalState,transMatrix);
        cout << "Test d'un automate n'acceptant que des a avec le détails des différentes chaines testées :" << endl;
        automate->read(string("a"),true);
        cout << "La chaine de caractère : '" << "a" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
        automate->read(string("b"),true);
        cout << "La chaine de caractère : '" << "b" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
        automate->read(string("aaaaaab"),true);
        cout << "La chaine de caractère : '" << "aaaaaab" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
        automate->read(string("baaaaaa"),true);
        cout << "La chaine de caractère : '" << "baaaaaa" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
        automate->read(string("aabbaaa"),true);
        cout << "La chaine de caractère : '" << "aabbaaa" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
        automate->read(string("bbbbbbb"),true);
        cout << "La chaine de caractère : '" << "bbbbbbb" << "' est " << (automate->isFinal() ? "acceptée" : "refusée") << "par l'automate." << endl;
    }
    catch(exception const& e)
    {
        cerr << "Erreur : "<< e.what() << endl;
    }
}
