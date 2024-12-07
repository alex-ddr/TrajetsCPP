//----------- Interface de la classe <TC> (fichier TC.h) -------------------

// Ce fichier définit la classe TC (Trajet Composé), qui hérite de la classe abstraite
// Trajet. Un trajet composé est une suite de trajets simples connectés, formant un
// itinéraire complexe.

// Fonctionnalités :
// - Construction d'un trajet composé à partir d'une liste chaînée de trajets simples.
// - Gestion dynamique des escales avec un suivi du nombre d'étapes.
// - Affichage des détails d'un trajet composé, incluant ses escales.


#if ! defined ( TC_H )
#define TC_H

#include "../include/TS.h"
#include "../include/ElemTrajet.h"

class TC : public Trajet {
protected:
    ElemTrajet* TS_list; // Liste chaînée des trajets simples composant ce trajet composé
    int nb_escales; // Nombre d'escales dans le trajet composé

    // Méthodes internes
    ElemTrajet* CreerListe(Ville depart, Ville destination); 
    // Crée une liste de trajets simples pour former un trajet composé

public:
    // Constructeurs
    TC(); // Constructeur par défaut
    TC(const char* depart, const char* destination); // Initialisation par noms de villes
    TC(Ville depart, Ville destination); // Initialisation par énumérations de villes

    // Destructeur
    virtual ~TC(); // Libère la mémoire de la liste des trajets simples

    // Méthodes
    void AfficherTrajet(int index) const; // Affiche les détails du trajet avec un index
};

#endif // TRAJET_H
