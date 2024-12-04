#include <iostream>
#include "Catalogue.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();
    c.InitialiserCatalogue();
    int choice = -1;

    cout << "~~~~~~~~~~~ Bienvenue dans notre agence de voyages ~~~~~~~~~~~\n\n";
    while(1)
    {
        cout << "\n\t~~~~~~~~~~~ Menu ~~~~~~~~~~~\nEntrez votre choix :\n\t0. Afficher le catalogue\n\t1. Ajouter un trajet au catalogue\n\t2. Supprimer un trajet du catalogue\n\t3. Quitter\n";
        cin >> choice;
        switch(choice)
        {
            case 0: // Afficher
                c.AfficherCatalogue();
                break;
            case 1: // Creer
                c.CreerTrajet();
                break;
            case 2: // Supprimer
                break;
            case 3: // Sortir du main
                cout << "\n~~~~~~~~~~~ A bientot! ~~~~~~~~~~~\n";
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}