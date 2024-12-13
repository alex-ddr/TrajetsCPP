#include <iostream>
#include "../include/TS.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeurs

// Constructeur par défaut
TS::TS()
{
    #ifdef MAP
        cout << "Appel au constructeur de <TS>" << endl;
    #endif
    // Pas de logique spécifique ici
}

// Constructeur prenant des chaînes de caractères pour le départ, la destination, et le transport
TS::TS(const char* depart, const char* destination, const char* trans) : Trajet(depart, destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TS>" << endl;
    #endif
    // Convertit le nom du transport en énumération Transport
    this->trans = GetTransport(trans);
}

// Constructeur prenant directement des énumérations Ville et Transport
TS::TS(Ville depart, Ville destination, Transport trans) : Trajet(depart, destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TS>" << endl;
    #endif
    this->trans = trans; // Initialise directement l'attribut `trans`
}

// Destructeur
TS::~TS()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TS>" << endl;
    #endif
    // Pas de ressources dynamiques à libérer
}

// Méthodes

// Getter pour récupérer le moyen de transport
Transport TS::GetTrans()
{
    return this->trans; // Retourne l'attribut `trans`
}

// Affiche les détails du trajet
void TS::AfficherTrajet(int index) const
{
    // Appelle la méthode `AfficherTrajet` de la classe de base pour afficher le départ et la destination
    Trajet::AfficherTrajet(index);

    // Ajoute le moyen de transport au format de sortie
    cout << " || " << GetNomTransport(trans) << endl;
}