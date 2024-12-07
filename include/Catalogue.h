//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------

// Ce fichier définit la classe Catalogue, qui sert de gestionnaire principal pour une 
// collection de trajets, qu'ils soient simples ou composés. Le Catalogue est organisé
// en une liste chaînée dynamique, représentée par des objets de type ElemTrajet.

// Fonctionnalités principales :
// - Ajouter, supprimer, et afficher des trajets.
// - Permettre la recherche de trajets correspondant à un départ et une destination.
// - Créer des trajets via des interactions utilisateur.
// - Gérer l'allocation et la libération des ressources associées aux trajets.


#if ! defined ( Catalogue_H )
#define Catalogue_H

#include "../include/TC.h"
#include "ElemTrajet.h"

class Catalogue {
protected:
    // Attributs
    int nb_trajets; // Nombre total de trajets dans le catalogue
    ElemTrajet* liste_trajets; // Pointeur vers la liste chaînée des trajets

    // Méthodes internes pour la gestion des trajets
    void CreerTrajetCompose(); // Méthode pour créer un trajet composé
    void CreerTrajetSimple(); // Méthode pour créer un trajet simple
    void InitialiserCatalogue(); // Initialise le catalogue au démarrage

    // Méthode de recherche récursive
    int Search(ElemTrajet* current, Ville depart, Ville destination, Trajet** chemin, int profondeur, Ville* visites, int& nbVisites) const;
    // Recherche récursive des trajets d'un point A à un point B, en composant possiblement des trajets.
    // Paramètres : 
    // - current : élément courant de la liste.
    // - chemin : tableau pour stocker le chemin trouvé.
    // - visites : villes déjà visitées pour éviter les boucles.

public:
    // Constructeur
    Catalogue();

    // Destructeur
    virtual ~Catalogue();

    // Méthodes principales pour la gestion des trajets
    void AjouterTrajet(Trajet* t); // Ajoute un trajet dans le catalogue
    void CreerTrajet(); // Interface utilisateur pour créer un trajet
    void SupprimerTrajet(); // Supprime un trajet spécifique
    void AfficherCatalogue() const; // Affiche tous les trajets du catalogue
    void RechercherTrajet() const; // Recherche un trajet spécifique selon les critères
    
};

#endif // Catalogue_H
