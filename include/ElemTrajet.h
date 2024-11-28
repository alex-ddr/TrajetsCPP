//---------- Interface de la classe <ElemTrajet> (fichier ElemTrajet.h) ----------------
#if ! defined ( ElemTrajet_H )
#define ElemTrajet_H

#include "Trajet.h"

class ElemTrajet {
protected:
    // Attributs
    Trajet t;
    ElemTrajet* next;

public:
    // Constructeur
    ElemTrajet(Trajet t);

    // Destructeur
    virtual ~ElemTrajet();

    // Methodes
    void Afficher();
    void Inserer(Trajet t);
    void Supprimer(Trajet t);

    // Getters
    ElemTrajet* getNext();
    Trajet getTrajet();

    // Setters
    void setNext(ElemTrajet* next);
};


#endif // ElemTrajet_H