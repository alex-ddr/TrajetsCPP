#include <iostream>
#include <cstdlib>

#include "Catalogue.h"
#include "config.h"
#include "FileHandler.h"
using namespace std;

int main() {
    Catalogue c = Catalogue(); // Création d'une instance de Catalogue pour gérer les trajets

    char choice;
    int first = 1; // Variable pour afficher le message de bienvenue uniquement au premier tour

    do 
    {
        ClearScreen(); // Efface l'écran pour une meilleure lisibilité
        if (first)
        {
            // Affiche un message de bienvenue au démarrage
            cout << "~~~~~~~~ Bienvenue dans notre agence de voyages! ~~~~~~~~\n\n";
            first = 0; // Désactive le message de bienvenue après la première fois
        }

        // Affiche le menu principal avec les options disponibles
        cout << "\t~~~~~~~~~~~ Menu ~~~~~~~~~~~\nEntrez votre choix :\n";
        cout << "\t1. Afficher le catalogue\n";
        cout << "\t2. Afficher les villes disponibles\n";
        cout << "\t3. Ajouter un trajet au catalogue\n";
        cout << "\t4. Rechercher un trajet\n";
        cout << "\t5. Supprimer un trajet du catalogue\n";
        cout << "\t6. Supprimer un trajet du catalogue\n"
        cout << "\t7. Supprimer un trajet du catalogue\n"
        cout << "\t8. Quitter\n";
        cout << "\nVotre choix : ";
        cin >> choice;

        ClearScreen(); // Efface l'écran avant de traiter l'entrée utilisateur

        // Vérifie si l'entrée est valide (entre '1' et '6')
        if (!((int)choice >= '1' && (int)choice <= '6')) {
            cout << "\n--------------------/!\\------------------\n";
            cout << "Erreur : vous devez choisir une valeur entre 1 et 6 !\n";
            cin.clear(); // Réinitialise l'état de cin en cas d'erreur
            cin.ignore(); // Ignore les caractères résiduels
            cout << "Appuyez sur Entrée pour recommencer...";
            cin.get(); // Attend une entrée avant de continuer
            continue;
        }

        // Exécute l'action correspondant au choix de l'utilisateur
        switch (choice) {
            case '1': // Affiche le catalogue
                c.AfficherCatalogue();
                break;
            case '2': // Affiche la liste des villes disponibles
                AfficherVilles(0);
                break;
            case '3': // Permet d'ajouter un trajet (simple ou composé)
                c.CreerTrajet();
                break;
            case '4': // Recherche des trajets disponibles
                c.RechercherTrajet();
                break;
            case '5': // Supprime un trajet du catalogue
                c.SupprimerTrajet();
                break;
            case '6': // Sauvegarder les trajets dans un fichier
                FileHandler.save();
                break;
            case '7': // Charge les trajets dans le catalogue depuis un fichier
                FileHandler.load();
                break;
            case '8': // Quitte le programme
                cout << "\n\t~~~~~~~~~~~ A bientôt! ~~~~~~~~~~~\n";
                return 0;
        }

        // Attend que l'utilisateur appuie sur Entrée avant de revenir au menu
        cout << "\nAppuyez sur Entrée pour revenir au menu...";
        cin.ignore();
        cin.get();
    } while(1); // Boucle infinie pour afficher le menu jusqu'à ce que l'utilisateur quitte
    
    return 0;
}
