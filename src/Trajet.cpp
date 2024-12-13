#include <iostream>
#include "../include/Trajet.h"
using namespace std;

//----------------------------------------------------------------- PUBLIC

// Constructeur par défaut
Trajet::Trajet()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    // Aucun code spécifique ici, utilisé pour initialiser des instances sans paramètres
}

// Constructeur prenant des noms de villes (chaînes de caractères)
Trajet::Trajet(const char* depart, const char* destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif

    // Convertit les noms de villes en énumérations Ville
    this->depart = GetVille(depart);
    this->destination = GetVille(destination);
}

// Constructeur prenant des énumérations Ville
Trajet::Trajet(Ville depart, Ville destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
    this->depart = depart;           // Initialise la ville de départ
    this->destination = destination; // Initialise la destination
}

// Destructeur
Trajet::~Trajet()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
    // Pas d'allocation dynamique ici, donc pas de mémoire à libérer
}

//-------------------------------------------------------------- PROTEGEES

// Méthodes

// Affiche les informations du trajet
void Trajet::AfficherTrajet(int index) const
{
    // Affiche le numéro du trajet suivi de sa ville de départ et de sa destination
    cout << "Trajet n°" << index << " : " << GetNomVille(this->depart) << " -> " << GetNomVille(this->destination);
}

// Getters

// Retourne la ville de départ
Ville Trajet::GetDepart()
{
    return this->depart;
}

// Retourne la destination
Ville Trajet::GetDestination()
{
    return this->destination;
}
