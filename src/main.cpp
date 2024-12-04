#include <iostream>
#include <cstdlib>

#include "Catalogue.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();

    int choice = -1;

    while (1) {
        #ifdef _WIN32
        cout << choice;
            system("cls");
        #else
            system("clear");
        #endif
        
        if (choice == -1)
        {
            cout << "~~~~~~~~~~~ Bienvenue dans notre agence de voyages! ~~~~~~~~~~~\n";
        }


        cout << "\n\t~~~~~~~~~~~ Menu ~~~~~~~~~~~\nEntrez votre choix :\n\t0. Afficher le catalogue\n\t1. Ajouter un trajet au catalogue\n\t2. Supprimer un trajet du catalogue\n\t3. Quitter\n";
        cin >> choice;

        while (cin.fail() || (choice != 0 && choice != 1 && choice != 2 && choice != 3))
        {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            cout <<     "--------------------/!\\------------------\n";
            cout << "Vous devez choisir une valeur entre 0 et 3!\nEntrez votre choix :\n\t0. Afficher le catalogue\n\t1. Ajouter un trajet au catalogue\n\t2. Supprimer un trajet du catalogue\n\t3. Quitter\n";

            cin >> choice; 
        }

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (choice) {
            case 0: // Afficher
                c.AfficherCatalogue();
                break;
            case 1: // Créer
                c.CreerTrajet();
                break;
            case 2: // Supprimer
                cout << "Fonctionnalité à implémenter." << endl;
                break;
            case 3: // Quitter
                cout << "\n\t~~~~~~~~~~~ A bientôt! ~~~~~~~~~~~\n";
                exit(EXIT_SUCCESS);
        }

        // Pause avant de revenir au menu
        cout << "\n\nAppuyez sur Entrée pour revenir au menu...";
        cin.ignore();
        cin.get();
    }
    return 0;
}
