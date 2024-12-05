#ifndef CONFIG_H
#define CONFIG_H

#include <cstdlib>
#include <cstring>

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
  UNKNOWN_VILLE
};

extern const char* nomsVille[];
Ville GetVille(const char* nomVille);
const char* GetNomVille(Ville ville);

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
  UNKNOWN_TRANSPORT
};

extern const char* nomsTransport[];
Transport GetTransport(const char* nomTransport);
const char* GetNomTransport(Transport transport);

void ClearScreen();
void AfficherVilles(int ask);
void AfficherTransports(int ask);

#endif // CONFIG_H
