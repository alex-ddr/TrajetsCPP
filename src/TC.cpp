#include <iostream>
#include "../include/TC.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
TC::TC()
{
}

TC::TC(const char* depart, const char* destination):Trajet(depart, destination)
{
}

TC::TC(Ville depart, Ville destination):Trajet(depart, destination)
{
}


// Destructeur
TC::~TC ( )
{
}


// Méthodes
void TC::AfficherTrajet(int index) const
{
    Trajet::AfficherTrajet(index);
}