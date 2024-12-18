//------------------ Configuration et outils du projet (fichier config.h) ------------------

// Ce fichier regroupe les énumérations, constantes, et fonctions utilitaires utilisées
// pour la gestion des trajets. Il joue un rôle clé dans la manipulation des villes et
// des moyens de transport, en facilitant leur conversion et leur affichage.

// Contenu principal :
// - Énumération Ville : liste des villes disponibles dans le projet.
// - Énumération Transport : liste des moyens de transport disponibles.
// - Fonctions de conversion entre noms et énumérations (`GetVille`, `GetNomVille`).
// - Fonctions pour afficher les options de villes et de transports.
// - Outils utilitaires comme `ClearScreen` pour le confort utilisateur.


#ifndef CONFIG_H
#define CONFIG_H

#include <cstdlib>
#include <cstring>

// Enumération des villes disponibles
enum Ville {
  AixEnProvence,
  Amiens,
  Angers,
  Argenteuil,
  Besancon,
  Bordeaux,
  BoulogneBillancourt,
  Brest,
  Caen,
  ClermontFerrand,
  Dijon,
  Grenoble,
  LeHavre,
  LeMans,
  Lille,
  Limoges,
  Lyon,
  Marseille,
  Metz,
  Montreuil,
  Montpellier,
  Mulhouse,
  Nancy,
  Nantes,
  Nice,
  Nimes,
  Orleans,
  Paris,
  Perpignan,
  Reims,
  Rennes,
  Rouen,
  SaintDenis,
  SaintEtienne,
  Strasbourg,
  Toulon,
  Toulouse,
  Tours,
  Villeurbanne,
  UNKNOWN_VILLE // Valeur par défaut pour les villes non reconnues
};

// Tableau des noms de villes pour les conversions
extern const char* nomsVille[];
Ville GetVille(const char* nomVille); // Retourne l'énumération associée à un nom
const char* GetNomVille(Ville ville); // Retourne le nom associé à une énumération


// Enumération des moyens de transport
enum Transport {
  Voiture,
  Train,
  Avion,
  Bus,
  Metro,
  Tramway,
  Velo,
  Scooter,
  Taxi,
  Pieds,
  Tmax,
  Monocycle,
  Velov,
  TukTuk,
  Planeur,
  Quad,
  F1,
  Cheval,
  Tank,
  Teleporteur,
  CampingCar,
  Pedalo,
  Bateau,
  UNKNOWN_TRANSPORT  // Valeur par défaut pour les transports non reconnus
};

extern const char* nomsTransport[];
Transport GetTransport(const char* nomTransport);  // Retourne l'énumération associée à un nom
const char* GetNomTransport(Transport transport);  // Retourne le nom associé à une énumération

// Fonctions utilitaires
void ClearScreen(); // Efface l'écran (dépendant du système)
void AfficherVilles(int ask); // Affiche la liste des villes disponibles
void AfficherTransports(int ask); // Affiche la liste des moyens de transport
// Paramètre 'ask' : Si égal à 0, alors affiche seulement, sinon demande si on affiche

#endif // CONFIG_H
