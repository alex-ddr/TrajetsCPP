#include <iostream>
#include "../include/Catalogue.h"
#include <cstring>
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

