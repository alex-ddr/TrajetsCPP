//------------ Interface de la classe <Trajet> (fichier Trajet.h) -----------------

// Ce fichier contient la déclaration de la classe abstraite Trajet, qui définit 
// les bases communes pour toutes les formes de trajets. Elle est conçue pour être
// héritée par des classes plus spécifiques comme TS (Trajet Simple) ou TC (Trajet Composé).

// Rôle principal :
// - Définir une interface standard avec des méthodes communes (`AfficherTrajet`).
// - Encapsuler les attributs de départ et de destination pour tous les trajets.
// - Assurer une extensibilité pour ajouter de nouvelles formes de trajets.


#if ! defined ( TRAJET_H )
#define TRAJET_H

#include "config.h"

class Trajet {
protected:
    Ville depart; // Ville de départ
    Ville destination; // Ville de destination

public:
    // Constructeurs
    Trajet(); // Constructeur par défaut
    Trajet(const char* depart, const char* destination); // Initialisation par noms
    Trajet(Ville depart, Ville destination); // Initialisation par énumérations

    // Destructeur
    virtual ~Trajet(); // Destructeur virtuel pour permettre une destruction correcte des sous-classes

    // Méthodes virtuelles
    virtual void AfficherTrajet(int index) const = 0; // Méthode pure pour afficher le trajet

    // Getters
    Ville GetDepart(); // Retourne la ville de départ
    Ville GetDestination(); // Retourne la ville de destination
};

#endif // TRAJET_H
