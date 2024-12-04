#include <iostream>
#include "../include/Catalogue.h"
#include <cstring>
#include "Catalogue.h"

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

        while (current != nullptr && 
            (new_elem->GetTrajet().GetDepart() > current->GetTrajet().GetDepart()))
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

void Catalogue::AjouterTrajet()
{
    // Déclare des buffers pour lire les entrées utilisateur
    char ville1_buffer[100];
    char ville2_buffer[100];

    // Lire les entrées utilisateur dans les buffers
    cout << "Entrez la première ville : ";
    cin >> ville1_buffer;

    cout << "Entrez la deuxième ville : ";
    cin >> ville2_buffer;

    // Déclare des const char* pointant vers les buffers
    const char* ville1 = ville1_buffer;
    const char* ville2 = ville2_buffer;

    Ville v1 = GetVille(ville1);
    Ville v2 = GetVille(ville2);

    if (v1 == UNKNOWN_VILLE)
    {
        printf("Choisir la ville %s n'est pas possible.", ville2);
        return;
    }
    else if (v2 == UNKNOWN_VILLE)
    {
        printf("Choisir la ville %s n'est pas possible.", ville2);
        return;
    }

    Trajet t(v1, v2);

    this->AjouterTrajet(t);
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
    printf("Catalogue de %d trajets :\n\n", nb_trajets);
    int index = 1;
    ElemTrajet* current = liste_trajets;

    while (current)
    {
        current->GetTrajet().AfficherTrajet(index);
        current = current->GetNext();
        index++;
    }
}

