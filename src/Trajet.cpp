#include <iostream>
#include "../include/Trajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
Trajet::Trajet()
{
}

Trajet::Trajet(Ville depart, Ville destination)
{
    this->depart = depart;
    this->destination = destination;
}

// Destructeur
Trajet::~Trajet ( )
{
}


//-------------------------------------------------------------- PROTEGEES

// Methodes

// Getters
Ville Trajet::getDepart()
{
    return this->depart;
}

Ville Trajet::getDestination()
{
    return this->destination;
}

