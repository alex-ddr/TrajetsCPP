#include <iostream>
#include "../include/ElemTrajet.h"
#include "ElemTrajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs
ElemTrajet::ElemTrajet(Trajet t)
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
ElemTrajet* ElemTrajet::getNext()
{
    return this->next;
}

Trajet ElemTrajet::getTrajet()
{
    return this->t;
}

// Setters
void ElemTrajet::setNext(ElemTrajet* next)
{
    this->next = next;
}