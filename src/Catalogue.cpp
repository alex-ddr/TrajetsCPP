#include <iostream>
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
Catalogue::~Catalogue ( )
{
}


//-------------------------------------------------------------- PROTEGEES

// Methodes
void Catalogue::AjouterTrajet(Trajet t)
{
    ElemTrajet* new_elem = new ElemTrajet(t);

    if (liste_trajets == nullptr)
        liste_trajets = new_elem;

    else
    {
        // Déclaration des pointeurs de recherche
        ElemTrajet* prev = liste_trajets;
        ElemTrajet* current = liste_trajets;

        // Chercher la bonne place dans l'ordre alphabétique
        while ((new_elem->getTrajet().getDepart() > current->getTrajet().getDepart()) || current->getNext() != nullptr)
        {
            prev = current;
            current = current->getNext();
        }

        // Insérer le nouveau trajet à la place trouvée
        prev->setNext(new_elem);
        new_elem->setNext(current);
    }

    nb_trajets++;
}

