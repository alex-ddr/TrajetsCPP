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
    nb_trajets = 0;
    liste_trajets = nullptr;
    InitialiserCatalogue();
}

void Catalogue::InitialiserCatalogue()
{
    AjouterTrajet(new TS("Paris", "Marseille", "Avion"));
    AjouterTrajet(new TS("Lyon", "Nice", "TukTuk"));
    AjouterTrajet(new TS("Lille", "Toulon", "Tmax"));
    AjouterTrajet(new TS("Strasbourg", "Metz", "Tank")); 
}


// Destructeur
Catalogue::~Catalogue()
{
    ElemTrajet* current = liste_trajets;
    while (current != nullptr) {
        ElemTrajet* next = current->GetNext();
        delete current->GetTrajet(); // Libère le trajet
        delete current;             // Libère l'élément
        current = next;
    }
}



//-------------------------------------------------------------- PROTEGEES

// Methodes
void Catalogue::AjouterTrajet(Trajet *t)
{
    ElemTrajet* new_elem = new ElemTrajet(t);

    if (liste_trajets == nullptr) // Liste vide
        liste_trajets = new_elem;
    
    else
    {
        // Recherche de la bonne position
        ElemTrajet* prev = nullptr;
        ElemTrajet* current = liste_trajets;

        // On classe par ordre alphabétique de ville de départ
        while (current != nullptr && 
            ((*new_elem->GetTrajet()).GetDepart() > (*current->GetTrajet()).GetDepart()))
        {
            prev = current;
            current = current->GetNext();
        }

        // Si ils ont la même ville de départ
        // On classe par ordre alphabétique de ville d'arrivée
        while (current != nullptr && 
            ((*new_elem->GetTrajet()).GetDepart() == (*current->GetTrajet()).GetDepart()) &&
            ((*new_elem->GetTrajet()).GetDestination() > (*current->GetTrajet()).GetDestination()))
        {
            prev = current;
            current = current->GetNext();
        }

        if (prev == nullptr) // Insérer en tête
        {
            new_elem->SetNext(liste_trajets);
            liste_trajets = new_elem;
        }
        else // Insérer entre prev et current
        {
            prev->SetNext(new_elem);
            new_elem->SetNext(current);
        }
    }

    nb_trajets++;
}

void Catalogue::CreerTrajet()
{
    cout << "-------------------------------------------------\n";
    cout << "Voulez vous ajouter un trajet simple ou composé ?\n\t1. Trajet simple\n\t2. Trajet composé\n";

    char choice;
    cin >> choice;
    ClearScreen();

    while (cin.fail() || (choice != '1' && choice != '2'))
    {
        cout << "--------------------------------------------\n";
        cout << "Vous devez choisir une valeur entre 1 et 2 !\n\t1. Trajet simple\n\t2. Trajet composé\n";

        cin >> choice;
        ClearScreen();
    }

    if (choice == 1) {
        CreerTrajetSimple();
    } else {
        CreerTrajetCompose();
    }
}

void Catalogue::SupprimerTrajet()
{
    // si la liste est vide
    if (liste_trajets == NULL)
    {
        cout << "Le catalogue est vide, il n'y a rien à supprimer." << endl;
        return;
    }


    AfficherCatalogue();

    int index, i = 1;
    do
    {
        cout << "Veuillez indiquer le numéro du trajet que vous souhaitez supprimer (sinon entrez -1 pour annuler) : ";
        cin >> index;

        if (cin.fail() || ((index < 1 || index > nb_trajets) && index != -1))
        {
            cin.clear();          
            cin.ignore(100, '\n');
            cout << "\nVeuillez saisir un numéro de trajet correct.\n";
            continue;
        }

        if (index == -1)
        {
            cout << "Suppression annulée." << endl;
            return;
        }

    } while (index < 1 || index > nb_trajets);

    ElemTrajet* current = liste_trajets;
    ElemTrajet* prev = NULL;

    // Suppression en tête
    if (index == 1)
    {
        liste_trajets = current->GetNext();
        delete current;
        cout << "Trajet supprimé avec succès." << endl;
        return;
    }

    while (current->GetNext() && i != index)
    {
        prev = current;
        current = current->GetNext();
        i++;
    }

    prev->SetNext(current->GetNext());
    delete current;
    cout << "Trajet supprimé avec succès." << endl;
}

void Catalogue::CreerTrajetSimple()
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;
    char transport_buffer[100];
    Transport trans;


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

    do
    {
        cout << "   - Moyen de transport : ";
        cin >> transport_buffer;
        trans = GetTransport(transport_buffer);

        if (trans == UNKNOWN_TRANSPORT)
            {
                cout << "\n Moyen de transport inconnu.\n";
                AfficherTransports(1);
            }
    }
    while (trans == UNKNOWN_TRANSPORT);

    TS* tr = new TS(ville1, ville2, trans);
    this->AjouterTrajet(tr);
}

void Catalogue::CreerTrajetCompose()
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;

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

    TC* tr = new TC(ville1, ville2);
    this->AjouterTrajet(tr);
}

void Catalogue::AfficherCatalogue() const
{
    cout << "Catalogue de " << nb_trajets << " trajets :\n\n";
    int index = 1;
    ElemTrajet* current = liste_trajets;

    while (current)
    {
        (*current->GetTrajet()).AfficherTrajet(index);
        cout << "-----------------------------------------------------\n";
        current = current->GetNext();
        index++;
    }
    cout << endl;
}

int Backtrack(Ville v1, Ville v2, Ville v3)
{
    
}

void Catalogue::RechercherTrajet() const
{
    char ville1_buffer[100], ville2_buffer[100];
    Ville ville1, ville2;

    // Saisie des villes
    do
    {
        cout << "Quelle est la ville de départ ? : ";
        cin >> ville1_buffer;
        ville1 = GetVille(ville1_buffer);

        if (ville1 == UNKNOWN_VILLE)
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        }
    } while (ville1 == UNKNOWN_VILLE);

    do
    {
        cout << "Quelle est la destination ? : ";
        cin >> ville2_buffer;
        ville2 = GetVille(ville2_buffer);

        if (ville2 == UNKNOWN_VILLE)
        {
            cout << "\nVille inconnue.\n";
            AfficherVilles(1);
        }
        else if (ville2 == ville1)
            cout << "\nLa destination doit être différente de la ville de départ, Veuillez réessayer : \n";
    } while ((ville2 == UNKNOWN_VILLE) || (ville2 == ville1));

    // Recherche et affichage des trajets
    ClearScreen();
    Backtrack(ville1, ville2, ville1);
}
