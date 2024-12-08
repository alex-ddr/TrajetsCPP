//--------- Interface de la classe <ElemTrajet> (fichier ElemTrajet.h) -----------------

// Ce fichier définit la classe ElemTrajet, qui est une structure de base pour les listes
// chaînées utilisées dans le Catalogue. Chaque élément de la liste contient un trajet
// et un pointeur vers l'élément suivant, permettant une organisation dynamique.

// Rôle principal :
// - Fournir une encapsulation pour chaque trajet dans le Catalogue.
// - Permettre la navigation dans la liste chaînée via les pointeurs `next`.
// - Faciliter la manipulation des trajets sans exposer directement leur implémentation.


#if ! defined ( ElemTrajet_H )
#define ElemTrajet_H

#include "Trajet.h"

class ElemTrajet {
protected:
    // Attributs
    Trajet* t; // Pointeur vers le trajet contenu dans cet élément
    ElemTrajet* next; // Pointeur vers l'élément suivant dans la liste chaînée

public:
    // Constructeurs
    ElemTrajet(); // Initialise un élément vide
    ElemTrajet(Trajet* t); // Initialise un élément avec un trajet donné

    // Destructeur
    virtual ~ElemTrajet(); // Libère la mémoire du trajet si nécessaire

    // Accesseurs
    ElemTrajet* GetNext(); // Retourne l'élément suivant
    Trajet* GetTrajet(); // Retourne le trajet contenu

    // Modificateurs
    void SetNext(ElemTrajet* elem); // Définit le prochain élément de la liste
};

#endif // ElemTrajet_H
