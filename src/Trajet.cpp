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
    this->depart = GetVille(depart);
    this->destination = GetVille(destination);
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
void Trajet::AfficherTrajet(int index) const
{
    cout << "Trajet n°" << index << " : " << GetNomVille(this->depart) << " -> " << GetNomVille(this->destination);
}

// Getters
Ville Trajet::GetDepart()
{
    return this->depart;
}

Ville Trajet::GetDestination()
{
    return this->destination;
}