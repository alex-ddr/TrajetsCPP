//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

#include "Trajet.h"
#include "../include/TS.h"
#include "ElemTrajet.h"

class Catalogue {
protected:
    // Attributs
    int nb_trajets;
    ElemTrajet* liste_trajets;

    void CreerTrajetCompose();
    void CreerTrajetSimple();
public:
    // Constructeur
    Catalogue();

    // Destructeur
    virtual ~Catalogue();

    // Methodes
    void AjouterTrajet(Trajet t);
    void CreerTrajet();
    void SupprimerTrajet(Trajet t);
    void AfficherCatalogue() const;
    void InitialiserCatalogue();
};

#endif // Catalogue_H