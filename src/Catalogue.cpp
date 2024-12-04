#include <iostream>
#include <cstring>

#include "../include/Catalogue.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
Catalogue::Catalogue()
{
    nb_trajets = 0;
    liste_trajets = nullptr;
}


// Destructeur
Catalogue::~Catalogue()
{
    ElemTrajet* current = liste_trajets;
    while (current != nullptr)
    {
        ElemTrajet* next = current->GetNext();
        delete current;
        current = next;
    }
}


//-------------------------------------------------------------- PROTEGEES

// Methodes
void Catalogue::AjouterTrajet(Trajet t)
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
            (new_elem->GetTrajet().GetDepart() > current->GetTrajet().GetDepart()))
        {
            prev = current;
            current = current->GetNext();
        }

        // Si ils ont la même ville de départ
        // On classe par ordre alphabétique de ville d'arrivée
        while (current != nullptr && 
            (new_elem->GetTrajet().GetDepart() == current->GetTrajet().GetDepart()) &&
            (new_elem->GetTrajet().GetDestination() > current->GetTrajet().GetDestination()))
        {
            prev = current;
            current = current->GetNext();
        }

        if (prev == nullptr) // Insérer en tête
        {
            new_elem->setNext(liste_trajets);
            liste_trajets = new_elem;
        }
        else // Insérer entre prev et current
        {
            prev->setNext(new_elem);
            new_elem->setNext(current);
        }
    }

    nb_trajets++;
}

void Catalogue::CreerTrajet()
{
    cout << "------------------------------------\n";
    cout << "Voulez vous ajouter un trajet simple ou composé ?\n\t1. Trajet simple\n\t2. Trajet composé\n";

    int choice;
    cin >> choice;
    if (choice == 0)
    {
        CreerTrajetSimple();
    }
    else
    {
        CreerTrajetCompose();
    }
}

void Catalogue::CreerTrajetSimple()
{
    // Déclare des buffers pour lire les entrées utilisateur
    char ville1_buffer[100];
    char ville2_buffer[100];
    char transport_buffer[100];

    // Lire les entrées utilisateur dans les buffers
    cout << "Entrez la première ville : ";
    cin >> ville1_buffer;
    const char* ville1 = ville1_buffer;

    cout << "Entrez la deuxième ville : ";
    cin >> ville2_buffer;
    const char* ville2 = ville2_buffer;

    cout << "Entrez le moyen de transport : ";
    cin >> transport_buffer;
    const char* transport = transport_buffer;

    Ville v1 = GetVille(ville1);
    Ville v2 = GetVille(ville2);
    Transport t = GetTransport(transport);

    if (v1 == UNKNOWN_VILLE)
    {
        cout << "Choisir la ville " << ville2 << " n'est pas possible."; 
        return;
    }
    else if (v2 == UNKNOWN_VILLE)
    {
        cout << "Choisir la ville " << ville2 << " n'est pas possible.";      
        return;
    }
    
    if (t ==  UNKNOWN_TRANSPORT)
    {
        cout << "Choisir le transport "<< transport << " n'est pas possible.";
        return;
    }

    TS traj(v1, v2, t);

    this->AjouterTrajet(traj);
}

void Catalogue::CreerTrajetCompose()
{
    // à implémenter
}


void Catalogue::InitialiserCatalogue()
{
    AjouterTrajet(Trajet("Paris", "Marseille"));
    AjouterTrajet(Trajet("Lyon", "Nice"));
    AjouterTrajet(Trajet("Strasbourg", "Metz")); 
    AjouterTrajet(Trajet("Lille", "Toulon"));
}


// void Catalogue::SupprimerTrajet(Trajet t)
// {   
//     ElemTrajet* prev = nullptr;
//     ElemTrajet* next = nullptr;
//     if (liste_trajets == nullptr)
//     {
//         return;
//     }

//     ElemTrajet* copy = liste_trajets;
//     while(copy != nullptr && copy->getTrajet())
//     {
//         prev = copy;
//         copy = copy->getNext();
//         next = copy->getNext();
//     }
// }

void Catalogue::AfficherCatalogue() const
{
    cout << "Catalogue de " << nb_trajets << " trajets :\n\n";
    int index = 1;
    ElemTrajet* current = liste_trajets;

    while (current)
    {
        current->GetTrajet().AfficherTrajet(index);
        current = current->GetNext();
        index++;
    }
}

