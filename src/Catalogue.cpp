#include <iostream>
#include <cstring>
#include <cstdlib>

#include "../include/Catalogue.h"

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
    cout << "-------------------------------------------------\n";
    cout << "Voulez vous ajouter un trajet simple ou composé ?\n\t1. Trajet simple\n\t2. Trajet composé\n";

    int choice;
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2))
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        cout << "--------------------------------------------\n";
        cout << "Vous devez choisir une valeur entre 1 et 2 !\n\t1. Trajet simple\n\t2. Trajet composé\n";

        cin >> choice; 
    }

    if (choice == 1) {
        CreerTrajetSimple();
    } else {
        CreerTrajetCompose();
    }
}


void Catalogue::CreerTrajetSimple()
{
    char ville1_buffer[100];
    char ville2_buffer[100];
    char transport_buffer[100];

    cout << "Entrez la première ville : ";
    cin >> ville1_buffer;
    const char* ville1 = ville1_buffer;
    Ville v1 = GetVille(ville1);
     if (v1 == UNKNOWN_VILLE)
    {
        cout << "Choisir la ville " << ville1 << " n'est pas possible."; 
        return;
    }

    cout << "Entrez la deuxième ville : ";
    cin >> ville2_buffer;
    const char* ville2 = ville2_buffer;
    Ville v2 = GetVille(ville2);
    if (v2 == UNKNOWN_VILLE)
    {
        cout << "Choisir la ville " << ville2 << " n'est pas possible.";      
        return;
    }

    cout << "Entrez le moyen de transport : ";
    cin >> transport_buffer;
    const char* transport = transport_buffer;
    Transport t = GetTransport(transport);

    if (t ==  UNKNOWN_TRANSPORT)
    {
        cout << "Choisir le transport "<< transport << " n'est pas possible.";
        return;
    }

    TS* tr = new TS(v1, v2, t);
    this->AjouterTrajet(tr);
}


void Catalogue::CreerTrajetCompose()
{
    // à implémenter
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
        (*current->GetTrajet()).AfficherTrajet(index);
        current = current->GetNext();
        index++;
    }
}

