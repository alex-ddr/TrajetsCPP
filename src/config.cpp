#include "../include/config.h"
#include <cstring>
#include <iostream>
using namespace std;

// Tableau contenant les noms des villes, dans le même ordre que l'énumération Ville
const char* nomsVille[] = {
  "AixEnProvence", "Amiens", "Angers", "Argenteuil", "Besancon", "Bordeaux",
  "BoulogneBillancourt", "Brest", "Caen", "ClermontFerrand", "Dijon", "Grenoble",
  "Le Havre", "Le Mans", "Lille", "Limoges", "Lyon", "Marseille", "Metz",
  "Montreuil", "Montpellier", "Mulhouse", "Nancy", "Nantes", "Nice", "Nimes",
  "Orleans", "Paris", "Perpignan", "Reims", "Rennes", "Rouen", "SaintDenis",
  "SaintEtienne", "Strasbourg", "Toulon", "Toulouse", "Tours", "Villeurbanne"
};

// Convertit un nom de ville (chaîne de caractères) en énumération Ville
Ville GetVille(const char* nomVille) {
    if (strcasecmp(nomVille, "AixEnProvence") == 0) return AixEnProvence;
    if (strcasecmp(nomVille, "Amiens") == 0) return Amiens;
    if (strcasecmp(nomVille, "Angers") == 0) return Angers;
    if (strcasecmp(nomVille, "Argenteuil") == 0) return Argenteuil;
    if (strcasecmp(nomVille, "Besancon") == 0) return Besancon;
    if (strcasecmp(nomVille, "Bordeaux") == 0) return Bordeaux;
    if (strcasecmp(nomVille, "BoulogneBillancourt") == 0) return BoulogneBillancourt;
    if (strcasecmp(nomVille, "Brest") == 0) return Brest;
    if (strcasecmp(nomVille, "Caen") == 0) return Caen;
    if (strcasecmp(nomVille, "ClermontFerrand") == 0) return ClermontFerrand;
    if (strcasecmp(nomVille, "Dijon") == 0) return Dijon;
    if (strcasecmp(nomVille, "Grenoble") == 0) return Grenoble;
    if (strcasecmp(nomVille, "LeHavre") == 0) return LeHavre;
    if (strcasecmp(nomVille, "LeMans") == 0) return LeMans;
    if (strcasecmp(nomVille, "Lille") == 0) return Lille;
    if (strcasecmp(nomVille, "Limoges") == 0) return Limoges;
    if (strcasecmp(nomVille, "Lyon") == 0) return Lyon;
    if (strcasecmp(nomVille, "Marseille") == 0) return Marseille;
    if (strcasecmp(nomVille, "Metz") == 0) return Metz;
    if (strcasecmp(nomVille, "Montreuil") == 0) return Montreuil;
    if (strcasecmp(nomVille, "Montpellier") == 0) return Montpellier;
    if (strcasecmp(nomVille, "Mulhouse") == 0) return Mulhouse;
    if (strcasecmp(nomVille, "Nancy") == 0) return Nancy;
    if (strcasecmp(nomVille, "Nantes") == 0) return Nantes;
    if (strcasecmp(nomVille, "Nice") == 0) return Nice;
    if (strcasecmp(nomVille, "Nimes") == 0) return Nimes;
    if (strcasecmp(nomVille, "Orleans") == 0) return Orleans;
    if (strcasecmp(nomVille, "Paris") == 0) return Paris;
    if (strcasecmp(nomVille, "Perpignan") == 0) return Perpignan;
    if (strcasecmp(nomVille, "Reims") == 0) return Reims;
    if (strcasecmp(nomVille, "Rennes") == 0) return Rennes;
    if (strcasecmp(nomVille, "Rouen") == 0) return Rouen;
    if (strcasecmp(nomVille, "SaintDenis") == 0) return SaintDenis;
    if (strcasecmp(nomVille, "SaintEtienne") == 0) return SaintEtienne;
    if (strcasecmp(nomVille, "Strasbourg") == 0) return Strasbourg;
    if (strcasecmp(nomVille, "Toulon") == 0) return Toulon;
    if (strcasecmp(nomVille, "Toulouse") == 0) return Toulouse;
    if (strcasecmp(nomVille, "Tours") == 0) return Tours;
    if (strcasecmp(nomVille, "Villeurbanne") == 0) return Villeurbanne;

    return UNKNOWN_VILLE; // Ville inconnue
}

// Retourne le nom (chaîne de caractères) correspondant à une ville (énumération Ville)
const char* GetNomVille(Ville ville) {
    return nomsVille[ville];
}

// Tableau contenant les noms des moyens de transport
const char* nomsTransport[] = {
  "Voiture", "Train", "Avion", "Bus", "Metro", "Tramway", "Velo", "Scooter",
  "Taxi", "Pieds", "Tmax", "Monocycle", "Velov", "TukTuk", "Planeur", "Quad",
  "F1", "Cheval", "Tank", "Teleporteur", "CampingCar", "Pedalo", "Bateau",
};

// Convertit un nom de transport (chaîne de caractères) en énumération Transport
Transport GetTransport(const char* nomTransport) {
    if (strcasecmp(nomTransport, "Voiture") == 0) return Voiture;
    if (strcasecmp(nomTransport, "Train") == 0) return Train;
    if (strcasecmp(nomTransport, "Avion") == 0) return Avion;
    if (strcasecmp(nomTransport, "Bus") == 0) return Bus;
    if (strcasecmp(nomTransport, "Metro") == 0) return Metro;
    if (strcasecmp(nomTransport, "Tramway") == 0) return Tramway;
    if (strcasecmp(nomTransport, "Velo") == 0) return Velo;
    if (strcasecmp(nomTransport, "Scooter") == 0) return Scooter;
    if (strcasecmp(nomTransport, "Taxi") == 0) return Taxi;
    if (strcasecmp(nomTransport, "Pieds") == 0) return Pieds;
    if (strcasecmp(nomTransport, "Tmax") == 0) return Tmax;
    if (strcasecmp(nomTransport, "Monocycle") == 0) return Monocycle;
    if (strcasecmp(nomTransport, "Velov") == 0) return Velov;
    if (strcasecmp(nomTransport, "TukTuk") == 0) return TukTuk;
    if (strcasecmp(nomTransport, "Planeur") == 0) return Planeur;
    if (strcasecmp(nomTransport, "Quad") == 0) return Quad;
    if (strcasecmp(nomTransport, "F1") == 0) return F1;
    if (strcasecmp(nomTransport, "Cheval") == 0) return Cheval;
    if (strcasecmp(nomTransport, "Tank") == 0) return Tank;
    if (strcasecmp(nomTransport, "Teleporteur") == 0) return Teleporteur;
    if (strcasecmp(nomTransport, "CampingCar") == 0) return CampingCar;
    if (strcasecmp(nomTransport, "Pédalo") == 0) return Pedalo;
    if (strcasecmp(nomTransport, "Bateau") == 0) return Bateau;

    return UNKNOWN_TRANSPORT; // Transport non troouvé
}

// Retourne le nom (chaîne de caractères) correspondant à un transport (énumération Transport)
const char* GetNomTransport(Transport transport) {
    return nomsTransport[transport];
}

// Efface l'écran, en fonction du système d'exploitation
void ClearScreen()
{
    #ifndef MAP
        #ifdef _WIN32
            system("cls"); // Commande pour Windows
        #else
            system("clear"); // Commande pour Unix/Linux
        #endif
    #endif
}

// Affiche toutes les villes disponibles si demandé par l'utilisateur
void AfficherVilles(int ask)
{
    if (ask)
    {
        cout << "Voulez-vous afficher la liste des villes ? (o/n) : ";
        char choice;

        do
        {
            cin >> choice;
            if (choice != 'o' && choice != 'n' && choice != 'O' && choice != 'N')
            {
                ClearScreen(); // Réinitialise l'écran si l'entrée est invalide
                cout << "Voulez-vous afficher la liste des villes ? (o/n) : ";
            }
        }
        while (choice != 'o' && choice != 'n' && choice != 'O' && choice != 'N');

        if (choice == 'n' || choice == 'N') return; // Annule si l'utilisateur refuse
    }

    // Affiche la liste des villes avec leur index
    cout << "Liste des villes :\n" << endl;
    for (int i = 0; i < UNKNOWN_VILLE; i++)
        cout << i + 1 << ". " << GetNomVille((Ville)i) << endl;

    cout << "\n";
}

// Affiche tous les moyens de transport disponibles si demandé par l'utilisateur
void AfficherTransports(int ask)
{
    if (ask)
    {
        cout << "Voulez-vous afficher les modes de transport ? (o/n) : ";
        char choice;

        do
        {
            cin >> choice;
            cin.ignore(); // Ignore les caractères résiduels
            if (choice != 'o' && choice != 'n' && choice != 'O' && choice != 'N')
            {
                ClearScreen();
                cout << "Voulez-vous afficher les modes de transport ? (o/n) : ";
            }
        }
        while (choice != 'o' && choice != 'n' && choice != 'O' && choice != 'N');

        if (choice == 'n' || choice == 'N') return; // Annule si l'utilisateur refuse
    }

    // Affiche la liste des modes de transport avec leur index
    cout << "Liste des modes de transport :\n" << endl;
    for (int i = 0; i < UNKNOWN_TRANSPORT; i++)
        cout << i + 1 << ". " << GetNomTransport((Transport)i) << endl;

    cout << "\n";
}