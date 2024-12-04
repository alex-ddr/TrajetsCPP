#include <iostream>
#include "../include/TC.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur
TC::TC()
{
}

TC::TC(const char* depart, const char* destination):TC(depart, destination)
{
}

TC::TC(Ville depart, Ville destination):TC(depart, destination)
{
}


// Destructeur
TC::~TC ( )
{
}


// Méthodes
TC::GetTransport()
{
    return this->transport;
}

TC::AfficherTrajet(int index) const
{
    TC::AfficherTrajet(index);
    
    if (transport == Velo || transprt = Velov || transport == Cheval || transport == Pieds)
        cout << "à ";
    else
        cout << "en ";

    cout << transport;
}