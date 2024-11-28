//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

#include "Trajet.h"
#include "ElemTrajet.h"

class Catalogue {
protected:
    // Attributs
    int nb_trajets;
    ElemTrajet* liste_trajets;

public:
    // Constructeur
    Catalogue();

    // Destructeur
    virtual ~Catalogue();

    // Methodes
    void AjouterTrajet(Trajet t);
};


#endif // Catalogue_H