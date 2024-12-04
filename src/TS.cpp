#include <iostream>
#include "../include/TS.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
TS::TS()
{
}

TS::TS(const char* depart, const char* destination, char* transport):TS(depart, destination)
{
    this->transport = getDestination(transport);
}

TS::TS(Ville depart, Ville destination, Destination destination):TS(depart, destination)
{
    this->transport = transport;
}


// Destructeur
TS::~TS ( )
{
}


// Méthodes
TS::GetTransport()
{
    return this->transport;
}

TS::AfficherTrajet(int index) const
{
    TS::AfficherTrajet(index);
    
    if (transport == Velo || transprt = Velov || transport == Cheval || transport == Pieds)
        cout << "à ";
    else
        cout << "en ";

    cout << transport;
}