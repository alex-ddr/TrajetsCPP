//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

#include "config.h"

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe représente un trajet avec un départ et une destination.
//------------------------------------------------------------------------

class Trajet {
protected:
    // Attributs
    Ville depart;
    Ville destination;

public:
    // Constructeur
    Trajet();
    Trajet(const char* depart, const char* destination);
    Trajet(Ville depart, Ville destination);

    // Destructeur
    virtual ~Trajet();

    // Methodes
    virtual void AfficherTrajet(int index) const = 0;

    // Getters
    Ville GetDepart();
    Ville GetDestination();
};


#endif // TRAJET_H