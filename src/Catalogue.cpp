#include <iostream>
#include <cstring>
#include <cstdlib>

#include "../include/Catalogue.h"
#include "Catalogue.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
Catalogue::Catalogue()
{
    nb_trajets = 0; // Initialise le nombre de trajets dans le catalogue
    liste_trajets = nullptr; // Initialise la liste de trajets comme vide
    InitialiserCatalogue(); // Ajoute des trajets d'exemple pour démarrer
}

void Catalogue::InitialiserCatalogue()
{
    AjouterTrajet(new TS("Paris", "Marseille", "Avion"));
    AjouterTrajet(new TS("Lyon", "Nice", "TukTuk"));
    AjouterTrajet(new TS("Lille", "Toulon", "Tmax"));
    AjouterTrajet(new TS("Strasbourg", "Metz", "Tank")); 
    AjouterTrajet(new TS("Lille", "Nice", "Velo"));
    AjouterTrajet(new TS("Metz", "Paris", "Avion"));
    AjouterTrajet(new TS("Paris", "Rouen", "Train")); 
    AjouterTrajet(new TS("Strasbourg", "Paris", "Train")); 
    AjouterTrajet(new TS("Lyon", "Bordeaux", "Train")); 
    AjouterTrajet(new TS("Lyon", "Paris", "Voiture")); 

    TS** trajetsCompo1 = new TS*[2];
    trajetsCompo1[0] = new TS("Lyon", "Marseille", "Pédalo");
    trajetsCompo1[1] = new TS("Marseille", "Paris", "Avion");
    AjouterTrajet(new TC(trajetsCompo1, 2));
    
    TS** trajetsCompo2 = new TS*[3];
    trajetsCompo2[0] = new TS("Metz", "Strasbourg", "Voiture");
    trajetsCompo2[1] = new TS("Strasbourg", "Lyon", "Train");
    trajetsCompo2[2] = new TS("Lyon", "Toulouse", "Tmax");
    AjouterTrajet(new TC(trajetsCompo2, 3));

    TS** trajetsCompo3 = new TS*[2];
    trajetsCompo3[0] = new TS("Strasbourg", "Metz", "TukTuk");
    trajetsCompo3[1] = new TS("Metz", "Paris", "Train");
    AjouterTrajet(new TC(trajetsCompo3, 2));

    delete[] trajetsCompo1;
    delete[] trajetsCompo2;
    delete[] trajetsCompo3;
}

// Destructeur
Catalogue::~Catalogue()
{
    // Libère la mémoire de tous les trajets du catalogue
    ElemTrajet* current = liste_trajets;
    while (current != nullptr) {
        ElemTrajet* next = current->GetNext(); // Sauvegarde l'élément suivant
        delete current->GetTrajet(); // Supprime le trajet associé
        delete current;             // Supprime l'élément lui-même
        current = next;             // Passe à l'élément suivant
    }
}

//-------------------------------------------------------------- PROTEGEES

// Methodes
void Catalogue::AjouterTrajet(Trajet *t)
{
    // Crée un nouvel élément de la liste pour le trajet
    ElemTrajet* new_elem = new ElemTrajet(t);

    if (liste_trajets == nullptr) // Si la liste est vide, insérer directement
    {
        liste_trajets = new_elem;
    }
    else
    {
        // Insère le trajet dans la liste en conservant un ordre alphabétique
        ElemTrajet* prev = nullptr;
        ElemTrajet* current = liste_trajets;

        // Tri par ville de départ
        while (current != nullptr && 
            ((*new_elem->GetTrajet()).GetDepart() > (*current->GetTrajet()).GetDepart()))
        {
            prev = current;
            current = current->GetNext();
        }

        // Tri secondaire par ville d'arrivée si les départs sont identiques
        while (current != nullptr && 
            ((*new_elem->GetTrajet()).GetDepart() == (*current->GetTrajet()).GetDepart()) &&
            ((*new_elem->GetTrajet()).GetDestination() > (*current->GetTrajet()).GetDestination()))
        {
            prev = current;
            current = current->GetNext();
        }

        if (prev == nullptr) // Cas particulier : insérer en tête de liste
        {
            new_elem->SetNext(liste_trajets);
            liste_trajets = new_elem;
        }
        else // Insertion classique entre prev et current
        {
            prev->SetNext(new_elem);
            new_elem->SetNext(current);
        }
    }

    nb_trajets++; // Met à jour le nombre de trajets
}

void Catalogue::CreerTrajet()
{
    // Affiche les options pour créer un trajet
    cout << "-------------------------------------------------\n";
    cout << "Voulez vous ajouter un trajet simple ou composé ?\n\t1. Trajet simple\n\t2. Trajet composé\n";

    char choice;
    cin >> choice;
    ClearScreen();

    while (cin.fail() || (choice != '1' && choice != '2')) // Validation de l'entrée
    {
        cout << "--------------------------------------------\n";
        cout << "Vous devez choisir une valeur entre 1 et 2 !\n\t1. Trajet simple\n\t2. Trajet composé\n";
        cin >> choice;
        ClearScreen();
    }

    // Appelle la méthode correspondante selon le choix de l'utilisateur
    if (choice == '1')
        CreerTrajetSimple();
    else if (choice == '2')
        CreerTrajetCompose();
}

void Catalogue::SupprimerTrajet()
{
    if (liste_trajets == NULL) // Vérifie si la liste est vide
    {
        cout << "Le catalogue est vide, il n'y a rien à supprimer." << endl;
        return;
    }

    AfficherCatalogue(); // Affiche tous les trajets pour faciliter la sélection

    int index, i = 1;
    do
    {
        cout << "Veuillez indiquer le numéro du trajet que vous souhaitez supprimer (sinon entrez -1 pour annuler) : ";
        cin >> index;

        if (cin.fail() || ((index < 1 || index > nb_trajets) && index != -1)) // Validation de l'entrée
        {
            cin.clear();          
            cin.ignore(100, '\n');
            cout << "\nVeuillez saisir un numéro de trajet correct.\n";
            continue;
        }

        if (index == -1) // Cas d'annulation
        {
            cout << "Suppression annulée." << endl;
            return;
        }

    } while (index < 1 || index > nb_trajets);

    ElemTrajet* current = liste_trajets;
    ElemTrajet* prev = NULL;

    if (index == 1) // Suppression en tête de liste
    {
        liste_trajets = current->GetNext();
        delete current;
        cout << "Trajet supprimé avec succès." << endl;
        return;
    }

    while (current->GetNext() && i != index) // Parcourt la liste jusqu'à trouver l'élément
    {
        prev = current;
        current = current->GetNext();
        i++;
    }

    prev->SetNext(current->GetNext()); // Relie l'élément précédent au suivant
    delete current; // Supprime l'élément
    cout << "Trajet supprimé avec succès." << endl;
}

void Catalogue::AfficherCatalogue() const
{
    cout << "Catalogue de " << nb_trajets << " trajets :\n\n";
    int index = 1;
    ElemTrajet* current = liste_trajets;

    while (current)
    {
        (*current->GetTrajet()).AfficherTrajet(index); // Affiche chaque trajet avec son index
        cout << "-----------------------------------------------------\n";
        current = current->GetNext();
        index++;
    }
    cout << endl;
}

void Catalogue::CreerTrajetSimple()
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;
    char transport_buffer[100];
    Transport trans;

    // Saisie de la ville de départ avec validation
    do
    {
        cout << "   - Ville de départ : ";
        cin >> ville1_buffer;
        ville1 = GetVille(ville1_buffer);

        if (ville1 == UNKNOWN_VILLE) // Vérifie si la ville est valide
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1); // Affiche la liste des villes pour aider l'utilisateur
        }
    }
    while (ville1 == UNKNOWN_VILLE);

    // Saisie de la destination avec validation
    do
    {
        cout << "   - Destination : ";
        cin >> ville2_buffer;
        ville2 = GetVille(ville2_buffer);

        if (ville2 == UNKNOWN_VILLE)
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        }
        else if (ville2 == ville1) // Empêche que la destination soit identique à la ville de départ
            cout << "\nLa destination doit être différente de la ville de départ, Veuillez réessayer : \n";
    }
    while ((ville2 == UNKNOWN_VILLE) || (ville2 == ville1));

    // Saisie du moyen de transport avec validation
    do
    {
        cout << "   - Moyen de transport : ";
        cin >> transport_buffer;
        trans = GetTransport(transport_buffer);

        if (trans == UNKNOWN_TRANSPORT) // Vérifie si le transport est valide
        {
            cout << "\n Moyen de transport inconnu.\n";
            AfficherTransports(1); // Affiche la liste des transports disponibles
        }
    }
    while (trans == UNKNOWN_TRANSPORT);

    // Création d'un trajet simple et ajout au catalogue
    TS* tr = new TS(ville1, ville2, trans);
    this->AjouterTrajet(tr);
}

void Catalogue::CreerTrajetCompose()
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;

    // Saisie de la ville de départ avec validation
    do
    {
        cout << "   - Ville de départ : ";
        cin >> ville1_buffer;
        ville1 = GetVille(ville1_buffer);

        if (ville1 == UNKNOWN_VILLE)
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        }
    }
    while (ville1 == UNKNOWN_VILLE);

    // Saisie de la destination avec validation
    do
    {
        cout << "   - Destination : ";
        cin >> ville2_buffer;
        ville2 = GetVille(ville2_buffer);

        if (ville2 == UNKNOWN_VILLE)
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        }
        else if (ville2 == ville1)
            cout << "\nLa destination doit être différente de la ville de départ, Veuillez réessayer : \n";
    }
    while ((ville2 == UNKNOWN_VILLE) || (ville2 == ville1));

    // Création d'un trajet composé et ajout au catalogue
    TC* tr = new TC(ville1, ville2);
    this->AjouterTrajet(tr);
}

int Catalogue::Search(ElemTrajet* current, Ville depart, Ville destination, Trajet** chemin, int profondeur, Ville* visites, int& nbVisites) const
{
    // Si applicable, ajoute le trajet courant au chemin parcouru
    if (profondeur > 0 && current != nullptr) {
        chemin[profondeur - 1] = current->GetTrajet();
    }

    // Si la destination est atteinte, affiche tout le chemin parcouru
    if (depart == destination)
    {
        for (int i = 0; i < profondeur; ++i) {
            chemin[i]->AfficherTrajet(i + 1);
        }
        cout << endl;
        return 1; // Indique qu'un chemin a été trouvé
    }

    // Marque la ville actuelle comme visitée pour éviter les boucles
    visites[nbVisites++] = depart;

    int foundPaths = 0;

    // Parcourt tous les trajets disponibles dans le catalogue
    ElemTrajet* trajetCourant = liste_trajets;
    while (trajetCourant)
    {
        Trajet* trajet = trajetCourant->GetTrajet();

        // Vérifie si ce trajet commence par la ville actuelle
        if (trajet->GetDepart() == depart)
        {
            Ville prochaineVille = trajet->GetDestination();
            bool dejaVisitee = false;

            // Vérifie si la prochaine ville a déjà été visitée
            for (int i = 0; i < nbVisites; ++i) {
                if (visites[i] == prochaineVille) {
                    dejaVisitee = true;
                    break;
                }
            }

            // Continue la recherche si la ville n'a pas encore été visitée
            if (!dejaVisitee) {
                foundPaths += Search(trajetCourant, prochaineVille, destination, chemin, profondeur + 1, visites, nbVisites);
            }
        }

        trajetCourant = trajetCourant->GetNext(); // Passe au trajet suivant
    }

    // Retire la ville actuelle de la liste des visites après exploration
    --nbVisites;

    return foundPaths;
}

void Catalogue::RechercherTrajet() const
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;

    // Saisie de la ville de départ avec validation
    do
    {
        cout << "Quelle est la ville de départ ? : ";
        cin >> ville1_buffer;
        ville1 = GetVille(ville1_buffer);

        if (ville1 == UNKNOWN_VILLE) {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1); // Affiche les villes disponibles pour aider
        }
    } while (ville1 == UNKNOWN_VILLE);

    // Saisie de la destination avec validation
    do
    {
        cout << "Quelle est la destination ? : ";
        cin >> ville2_buffer;
        ville2 = GetVille(ville2_buffer);

        if (ville2 == UNKNOWN_VILLE) {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        } else if (ville2 == ville1) {
            cout << "\nLa destination doit être différente de la ville de départ, Veuillez réessayer : \n";
        }
    } while ((ville2 == UNKNOWN_VILLE) || (ville2 == ville1));

    // Recherche des trajets et affichage des résultats
    ClearScreen();

    Trajet* chemin[50]; // Tableau temporaire pour stocker les trajets du chemin
    Ville visites[50];  // Liste des villes visitées pour éviter les boucles
    int nbVisites = 0;

    int cheminsTrouves = Search(liste_trajets, ville1, ville2, chemin, 0, visites, nbVisites);

    if (cheminsTrouves == 0) {
        cout << "Aucun trajet trouvé de " << GetNomVille(ville1) << " à " << GetNomVille(ville2) << endl;
    }
}
