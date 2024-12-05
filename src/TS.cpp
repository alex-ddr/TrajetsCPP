#include <iostream>
#include "../include/TS.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
TS::TS()
{
}

TS::TS(const char* depart, const char* destination, const char* trans):Trajet(depart, destination)
{
    this->trans = GetTransport(trans);
}

TS::TS(Ville depart, Ville destination, Transport trans):Trajet(depart, destination)
{
    this->trans = trans;
}


// Destructeur
TS::~TS ( )
{
}


// Méthodes
Transport TS::GetTrans()
{
    return this->trans;
}

void TS::AfficherTrajet(int index) const
{
    Trajet::AfficherTrajet(index);

    if (trans == Velo || trans == Velov || trans == Cheval || trans == Pieds)
        cout << " -> ";
    else
        cout << " || ";

    cout << GetNomTransport(trans) << endl;
}