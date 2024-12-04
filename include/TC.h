//---------- Interface de la classe <TC> (fichier TC.h) ----------------
#if ! defined ( TC_H )
#define TC_H

//------------------------------------------------------------------------
// Rôle de la classe <TC>
// Cette classe représente un trajet simple.
//------------------------------------------------------------------------

class TC : public Trajet{
protected:
    // Attributs
    Transport transport;

public:
    // Constructeur
    TC();
    TC(const char* depart, const char* destination);
    TC(Ville depart, Ville destination);

    // Destructeur
    virtual ~TC();

    // Methodes
    Transport GetTransport();

    // void AfficherTC(int index) const;
};


#endif // TRAJET_H