#include "../include/functions.h"
#include <cstring>

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

    return Pieds; // Valeur par défaut (écologie avant tout :D)
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
        
        default: return "Pieds"; // Valeur par défaut (écologie avant tout :D)
    }
}
