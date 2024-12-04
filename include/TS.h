//---------- Interface de la classe <TS> (fichier TS.h) ----------------
#if ! defined ( TS_H )
#define TS_H
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TS>
// Cette classe représente un trajet simple.
//------------------------------------------------------------------------

class TS : public Trajet{
protected:
    // Attributs
    Transport trans;

public:
    // Constructeur
    TS();
    TS(const char* depart, const char* destination, char* transport);
    TS(Ville depart, Ville destination, Transport transport);

    // Destructeur
    virtual ~TS();

    // Methodes
    Transport GetTrans();

    void AfficherTrajet(int index) const;
};


#endif // TRAJET_H