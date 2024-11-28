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
    const char* depart;
    const char* destination;

public:
    // Constructeur
    Trajet();
    Trajet(const char* depart, const char* destination);

    // Destructeur
    virtual ~Trajet();

    // Methodes
    void AfficherTrajet(int index) const;

    // Getters
    const char* getDepart();
    const char* getDestination();
};


#endif // TRAJET_H