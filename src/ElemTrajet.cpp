#include <iostream>
#include "../include/ElemTrajet.h"
#include "ElemTrajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
ElemTrajet::ElemTrajet()
{
    this->t = nullptr;    // Initialise le trajet à null (aucun trajet associé)
    this->next = nullptr; // Initialise le pointeur suivant à null (pas de prochain élément)
}

ElemTrajet::ElemTrajet(Trajet* t)
{
    this->t = t;          // Associe un trajet donné à cet élément
    this->next = nullptr; // Initialise le pointeur suivant à null (pas encore de lien)
}

// Destructeur
ElemTrajet::~ElemTrajet()
{
#ifdef MAP
    // Affiche un message lorsque le destructeur est appelé (utile en mode debug)
    cout << "Appel au destructeur de <ElemTrajet>" << endl;
#endif
    // Le trajet pointé n'est pas supprimé ici pour éviter des conflits de gestion
    // de mémoire avec d'autres parties du programme.
}

//-------------------------------------------------------------- PROTEGEES

// Methodes

// Getters

ElemTrajet* ElemTrajet::GetNext()
{
    // Retourne le pointeur vers l'élément suivant dans la liste chaînée
    return this->next;
}

Trajet* ElemTrajet::GetTrajet()
{
    // Retourne le trajet associé à cet élément
    return this->t;
}

// Setters

void ElemTrajet::SetNext(ElemTrajet* elem)
{
    // Définit l'élément suivant dans la liste chaînée
    this->next = elem;
}
