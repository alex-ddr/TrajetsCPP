//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

#include "../include/TC.h"
#include "ElemTrajet.h"

class Catalogue {
protected:
    // Attributs
    int nb_trajets;
    ElemTrajet* liste_trajets;

    void CreerTrajetCompose();
    void CreerTrajetSimple();
    void InitialiserCatalogue();
public:
    // Constructeur
    Catalogue();

    // Destructeur
    virtual ~Catalogue();

    // Methodes
    void AjouterTrajet(Trajet* t);
    void CreerTrajet();
    void SupprimerTrajet(Trajet* t);
    void AfficherCatalogue() const;
};

#endif // Catalogue_H