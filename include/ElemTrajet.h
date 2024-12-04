//---------- Interface de la classe <ElemTrajet> (fichier ElemTrajet.h) ----------------
#if ! defined ( ElemTrajet_H )
#define ElemTrajet_H

#include "Trajet.h"

class ElemTrajet {
protected:
    // Attributs
    Trajet* t;
    ElemTrajet* next;

public:
    // Constructeur
    ElemTrajet(Trajet* t);

    // Destructeur
    virtual ~ElemTrajet();

    // Getters
    ElemTrajet* GetNext();
    Trajet* GetTrajet();

    // Setters
    void setNext(ElemTrajet* next);
};


#endif // ElemTrajet_H