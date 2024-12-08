//------------- Interface de la classe <TS> (fichier TS.h) --------------------

// Ce fichier définit la classe TS (Trajet Simple), qui hérite de la classe abstraite
// Trajet. Un trajet simple est caractérisé par un départ, une destination et un moyen
// de transport unique.

// Rôle principal :
// - Représenter un trajet de base avec des informations minimales (départ, destination,
//   transport).
// - Fournir des méthodes pour afficher les détails d'un trajet simple.


#if ! defined ( TS_H )
#define TS_H

#include "Trajet.h"

class TS : public Trajet {
protected:
    Transport trans; // Moyen de transport utilisé pour ce trajet simple

public:
    // Constructeurs
    TS(); // Constructeur par défaut
    TS(const char* depart, const char* destination, const char* transport); // Initialisation par noms
    TS(Ville depart, Ville destination, Transport transport); // Initialisation par énumérations

    // Destructeur
    virtual ~TS(); // Destructeur virtuel

    // Accesseurs
    Transport GetTrans(); // Retourne le moyen de transport

    // Méthodes
    void AfficherTrajet(int index) const; // Affiche les détails du trajet avec un index
};

#endif // TRAJET_H
