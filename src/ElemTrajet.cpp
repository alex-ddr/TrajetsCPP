#include <iostream>
#include "../include/ElemTrajet.h"
#include "ElemTrajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
ElemTrajet::ElemTrajet()
{
    this->t = nullptr;
    this->next = nullptr;
}

ElemTrajet::ElemTrajet(Trajet* t)
{
    this->t = t;
    this->next = nullptr;
}


// Destructeur
ElemTrajet::~ElemTrajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <ElemTrajet>" << endl;
#endif
}


//-------------------------------------------------------------- PROTEGEES

// Methodes

// Getters
ElemTrajet* ElemTrajet::GetNext()
{
    return this->next;
}

Trajet* ElemTrajet::GetTrajet()
{
    return this->t;
}

// Setters
void ElemTrajet::SetNext(ElemTrajet* elem)
{
    this->next = elem;
}