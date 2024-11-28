#include "../include/functions.h"
#include <cstring>

Ville GetVille(const char* nomVille) {
  if (strcasecmp(nomVille, "Aix-en-Provence") == 0) return AixEnProvence;
  if (strcasecmp(nomVille, "Amiens") == 0) return Amiens;
  if (strcasecmp(nomVille, "Angers") == 0) return Angers;
  if (strcasecmp(nomVille, "Argenteuil") == 0) return Argenteuil;
  if (strcasecmp(nomVille, "Besancon") == 0) return Besancon;
  if (strcasecmp(nomVille, "Bordeaux") == 0) return Bordeaux;
  if (strcasecmp(nomVille, "Boulogne-Billancourt") == 0) return BoulogneBillancourt;
  if (strcasecmp(nomVille, "Brest") == 0) return Brest;
  if (strcasecmp(nomVille, "Caen") == 0) return Caen;
  if (strcasecmp(nomVille, "Clermont-Ferrand") == 0) return ClermontFerrand;
  if (strcasecmp(nomVille, "Dijon") == 0) return Dijon;
  if (strcasecmp(nomVille, "Grenoble") == 0) return Grenoble;
  if (strcasecmp(nomVille, "Le Havre") == 0) return LeHavre;
  if (strcasecmp(nomVille, "Le Mans") == 0) return LeMans;
  if (strcasecmp(nomVille, "Lille") == 0) return Lille;
  if (strcasecmp(nomVille, "Limoges") == 0) return Limoges;
  if (strcasecmp(nomVille, "Lyon") == 0) return Lyon;
  if (strcasecmp(nomVille, "Marseille") == 0) return Marseille;
  if (strcasecmp(nomVille, "Metz") == 0) return Metz;
  if (strcasecmp(nomVille, "Montpellier") == 0) return Montpellier;
  if (strcasecmp(nomVille, "Montreuil") == 0) return Montreuil;
  if (strcasecmp(nomVille, "Mulhouse") == 0) return Mulhouse;
  if (strcasecmp(nomVille, "Nancy") == 0) return Nancy;
  if (strcasecmp(nomVille, "Nantes") == 0) return Nantes;
  if (strcasecmp(nomVille, "Nice") == 0) return Nice;
  if (strcasecmp(nomVille, "Nimes") == 0) return Nimes;
  if (strcasecmp(nomVille, "Orleans") == 0) return Orleans;
  if (strcasecmp(nomVille, "Paris") == 0) return Paris;
  if (strcasecmp(nomVille, "Perpignan") == 0) return Perpignan;
  if (strcasecmp(nomVille, "Reims") == 0) return Reims;
  if (strcasecmp(nomVille, "Rennes") == 0) return Rennes;
  if (strcasecmp(nomVille, "Rouen") == 0) return Rouen;
  if (strcasecmp(nomVille, "Saint-Denis") == 0) return SaintDenis;
  if (strcasecmp(nomVille, "Saint-Etienne") == 0) return SaintEtienne;
  if (strcasecmp(nomVille, "Strasbourg") == 0) return Strasbourg;
  if (strcasecmp(nomVille, "Toulon") == 0) return Toulon;
  if (strcasecmp(nomVille, "Toulouse") == 0) return Toulouse;
  if (strcasecmp(nomVille, "Tours") == 0) return Tours;
  if (strcasecmp(nomVille, "Villeurbanne") == 0) return Villeurbanne;

  return Paris; // Valeur par défaut
}

const char* GetNomVille(Ville ville) {
  switch (ville) {
    case AixEnProvence: return "Aix-en-Provence";
    case Amiens: return "Amiens";
    case Angers: return "Angers";
    case Argenteuil: return "Argenteuil";
    case Besancon: return "Besancon";
    case Bordeaux: return "Bordeaux";
    case BoulogneBillancourt: return "Boulogne-Billancourt";
    case Brest: return "Brest";
    case Caen: return "Caen";
    case ClermontFerrand: return "Clermont-Ferrand";
    case Dijon: return "Dijon";
    case Grenoble: return "Grenoble";
    case LeHavre: return "Le Havre";
    case LeMans: return "Le Mans";
    case Lille: return "Lille";
    case Limoges: return "Limoges";
    case Lyon: return "Lyon";
    case Marseille: return "Marseille";
    case Metz: return "Metz";
    case Montreuil: return "Montreuil";
    case Montpellier: return "Montpellier";
    case Mulhouse: return "Mulhouse";
    case Nancy: return "Nancy";
    case Nantes: return "Nantes";
    case Nice: return "Nice";
    case Nimes: return "Nimes";
    case Orleans: return "Orleans";
    case Paris: return "Paris";
    case Perpignan: return "Perpignan";
    case Reims: return "Reims";
    case Rennes: return "Rennes";
    case Rouen: return "Rouen";
    case SaintDenis: return "Saint-Denis";
    case SaintEtienne: return "Saint-Etienne";
    case Strasbourg: return "Strasbourg";
    case Toulon: return "Toulon";
    case Toulouse: return "Toulouse";
    case Tours: return "Tours";
    case Villeurbanne: return "Villeurbanne";

    default: return "Paris"; // Valeur par défaut
  }
}

Transport GetTransport(const char* nomTransport) {
    if (strcasecmp(nomTransport, "Voiture") == 0) return Voiture;
    if (strcasecmp(nomTransport, "Train") == 0) return Train;
    if (strcasecmp(nomTransport, "Avion") == 0) return Avion;
    if (strcasecmp(nomTransport, "Bus") == 0) return Bus;
    if (strcasecmp(nomTransport, "Metro") == 0) return Metro;
    if (strcasecmp(nomTransport, "Tramway") == 0) return Tramway;
    if (strcasecmp(nomTransport, "Velo") == 0) return Velo;
    if (strcasecmp(nomTransport, "Scooter") == 0) return Scooter;
    if (strcasecmp(nomTransport, "Taxi") == 0) return Taxi;
    if (strcasecmp(nomTransport, "Pieds") == 0) return Pieds;
    if (strcasecmp(nomTransport, "Tmax") == 0) return Tmax;
    if (strcasecmp(nomTransport, "Monocycle") == 0) return Monocycle;
    if (strcasecmp(nomTransport, "Velov") == 0) return Velov;
    if (strcasecmp(nomTransport, "TukTuk") == 0) return TukTuk;
    if (strcasecmp(nomTransport, "Planeur") == 0) return Planeur;
    if (strcasecmp(nomTransport, "Quad") == 0) return Quad;
    if (strcasecmp(nomTransport, "F1") == 0) return F1;
    if (strcasecmp(nomTransport, "Cheval") == 0) return Cheval;
    if (strcasecmp(nomTransport, "Tank") == 0) return Tank;
    if (strcasecmp(nomTransport, "Teleporteur") == 0) return Teleporteur;
    if (strcasecmp(nomTransport, "CampingCar") == 0) return CampingCar;

    return Voiture; // Valeur par défaut
}

const char* GetNomTransport(Transport transport) {
    switch (transport) {
        case Voiture: return "Voiture";
        case Train: return "Train";
        case Avion: return "Avion";
        case Bus: return "Bus";
        case Metro: return "Metro";
        case Tramway: return "Tramway";
        case Velo: return "Velo";
        case Scooter: return "Scooter";
        case Taxi: return "Taxi";
        case Pieds: return "Pieds";
        case Tmax: return "Tmax";
        case Monocycle: return "Monocycle";
        case Velov: return "Velov";
        case TukTuk: return "TukTuk";
        case Planeur: return "Planeur";
        case Quad: return "Quad";
        case F1: return "F1";
        case Cheval: return "Cheval";
        case Tank: return "Tank";
        case Teleporteur: return "Teleporteur";
        case CampingCar: return "CampingCar";
        
        default: return "Voiture"; // Valeur par défaut
    }
}
