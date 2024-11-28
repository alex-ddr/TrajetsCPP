#include <iostream>
#include "../include/Trajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
Trajet::Trajet()
{
}

Trajet::Trajet(const char* depart, const char* destination)
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
void Trajet::AfficherTrajet(int index) const
{
    cout << "Trajet n°" << index << " de " << this->depart << " à " << this->destination << endl;
}

// Getters
const char* Trajet::getDepart()
{
    return this->depart;
}

const char* Trajet::getDestination()
{
    return this->destination;
}

