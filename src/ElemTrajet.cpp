#include <iostream>
#include "../include/ElemTrajet.h"
#include "ElemTrajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
ElemTrajet::ElemTrajet()
{
    #ifdef MAP
        cout << "Appel au constructeur de <ElemTrajet>" << endl;
    #endif
    this->t = nullptr;    // Initialise le trajet à null (aucun trajet associé)
    this->next = nullptr; // Initialise le pointeur suivant à null (pas de prochain élément)
}

ElemTrajet::ElemTrajet(Trajet* t)
{
    #ifdef MAP
        cout << "Appel au constructeur de <ElemTrajet>" << endl;
    #endif
    this->t = t;          // Associe un trajet donné à cet élément
    this->next = nullptr; // Initialise le pointeur suivant à null (pas encore de lien)
}

// Destructeur
ElemTrajet::~ElemTrajet()
{
    #ifdef MAP
        cout << "Appel au destructeur de <ElemTrajet>" << endl;
    #endif
    delete t;
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
