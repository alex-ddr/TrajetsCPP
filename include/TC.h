//---------- Interface de la classe <TC> (fichier TC.h) ----------------
#if ! defined ( TC_H )
#define TC_H

#include "../include/TS.h"
#include "../include/ElemTrajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TC>
// Cette classe représente un trajet simple.
//------------------------------------------------------------------------

class TC : public Trajet{
protected:
    // Attributs
    ElemTrajet* TS_list;

    // Methodes
    ElemTrajet* CreerListe(Ville depart, Ville destination);

public:
    // Constructeur
    TC();
    TC(const char* depart, const char* destination);
    TC(Ville depart, Ville destination);

    // Destructeur
    virtual ~TC();

    // Methodes
    void AfficherTrajet(int index) const;
};


#endif // TRAJET_H