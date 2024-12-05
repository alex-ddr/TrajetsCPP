#include <iostream>
#include <cstdlib>

#include "Catalogue.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();

    char choice;
    int first = 1;
    
    do 
    {
        ClearScreen();
        if (first)
        {
            cout << "~~~~~~~~ Bienvenue dans notre agence de voyages! ~~~~~~~~\n";
            first = 0;
        }


        cout << "\n\t~~~~~~~~~~~ Menu ~~~~~~~~~~~\nEntrez votre choix :\n\t0. Afficher le catalogue\n\t1. Ajouter un trajet au catalogue\n\t2. Supprimer un trajet du catalogue\n\t3. Quitter\n";
        cout << "Votre choix : ";
        cin >> choice;
        // Si l'entrée est invalide
        
        ClearScreen();

        if (!((int)choice >= 48 && (int)choice <= 51)) {
            cout << "\n--------------------/!\\------------------\n";
            cout << "Erreur : vous devez choisir une valeur entre 0 et 3 !\n";
            cin.clear();
            cin.ignore(); 
            cout << "Appuyez sur Entrée pour recommencer...";
            cin.get(); 
            continue;
        }

        switch (choice) {
            case '0': // Afficher
                c.AfficherCatalogue();
                break;
            case '1': // Créer
                c.CreerTrajet();
                break;
            case '2': // Supprimer
                cout << "Fonctionnalité à implémenter." << endl;
                break;
            case '3': // Quitter
                cout << "\n\t~~~~~~~~~~~ A bientôt! ~~~~~~~~~~~\n";
                exit(EXIT_SUCCESS);
                break;
        }

        cout << "\n\nAppuyez sur Entrée pour revenir au menu...";
        cin.ignore();
        cin.get();
    } while(1);
    
    return 0;
}
