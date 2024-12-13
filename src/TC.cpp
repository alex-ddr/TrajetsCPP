#include <iostream>
#include "../include/TC.h"
using namespace std;

//---------------------------------------------------------------- PROTEGE

// Méthode pour créer une liste chaînée de trajets simples pour un trajet composé
ElemTrajet* TC::CreerListe(Ville depart, Ville destination)
{
    int index = 1; // Compteur pour les escales
    ElemTrajet* FirstElem = nullptr; // Premier élément de la liste
    ElemTrajet* prev = nullptr; // Pointeur vers l'élément précédent

    char current_depart[100], current_dest[100], current_trans[100];
    Ville villeDep = depart, villeDest;
    Transport trans;

    do
    {
        ClearScreen(); // Efface l'écran pour une meilleure lisibilité
        cout << "Trajet " << GetNomVille(depart) << " -> " << GetNomVille(destination) << " :\n";
        cout << "\n\nEscale n°" << index << " :\n";

        // Gestion de la ville de départ
        if (index == 1) // Pour la première escale
            cout << "   - Ville de départ : " << GetNomVille(depart) << "\n";
        else
        {
            do
            {
                cout << "   - Ville de départ : ";
                cin >> current_depart;
                villeDep = GetVille(current_depart);

                if (villeDep == UNKNOWN_VILLE) // Ville non valide
                {
                    cout << "\nVille inconnue.\n";
                    AfficherVilles(1); // Affiche la liste des villes pour aider l'utilisateur
                }
                else if (villeDep != prev->GetTrajet()->GetDestination()) // Vérifie la continuité des escales
                    cout << "\nLa ville ne correspond pas à la destination précédente. Veuillez réessayer : \n";
            }
            while ((villeDep == UNKNOWN_VILLE) || (villeDep != prev->GetTrajet()->GetDestination()));
        }

        // Gestion de la ville d'arrivée
        do
        {
            cout << "   - Ville d'arrivée : ";
            cin >> current_dest;
            villeDest = GetVille(current_dest);

            if (villeDest == UNKNOWN_VILLE) // Ville non valide
            {
                cout << "\nVille inconnue.\n";
                AfficherVilles(1);
            }
        }
        while (villeDest == UNKNOWN_VILLE);

        // Gestion du moyen de transport
        do
        {
            cout << "   - Moyen de Transport : ";
            cin >> current_trans;
            trans = GetTransport(current_trans);

            if (trans == UNKNOWN_TRANSPORT) // Transport non valide
            {
                cout << "\nMoyen de transport inconnu.\n";
                AfficherTransports(1); // Affiche la liste des moyens de transport pour aider l'utilisateur
            }
        }
        while (trans == UNKNOWN_TRANSPORT);

        // Création d'un nouvel élément de la liste pour l'escale actuelle
        ElemTrajet* current = new ElemTrajet(new TS(villeDep, villeDest, trans));

        if (index == 1) // Premier élément de la liste
            FirstElem = current;
        else
            prev->SetNext(current); // Relie l'élément précédent au nouvel élément

        prev = current; // Met à jour le pointeur précédent
        index++; // Passe à l'escale suivante
    } while (villeDest != destination); // Continue jusqu'à atteindre la destination finale

    if (prev) prev->SetNext(nullptr); // Marque la fin de la liste
    this->nb_escales = index; // Met à jour le nombre total d'escales
    return FirstElem; // Retourne le premier élément de la liste
}

//----------------------------------------------------------------- PUBLIC

// Constructeurs

TC::TC()
{
    #ifdef MAP
        cout << "Appel au constructeur de <TC>" << endl;
    #endif
}

TC::TC(const char* depart, const char* destination) : Trajet(depart, destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TC>" << endl;
    #endif
    // Initialise le trajet composé en créant une liste de trajets simples
    TS_list = CreerListe(GetVille(depart), GetVille(destination));
}

TC::TC(Ville depart, Ville destination) : Trajet(depart, destination)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TC>" << endl;
    #endif
    // Initialise le trajet composé en créant une liste de trajets simples
    TS_list = CreerListe(depart, destination);
}

TC::TC(TS** trajets, int nbTrajets) : Trajet(trajets[0]->GetDepart(), trajets[nbTrajets - 1]->GetDestination())
{
    #ifdef MAP
        cout << "Appel au constructeur de <TC>" << endl;
    #endif

    if (trajets == nullptr || nbTrajets <= 0) {
        TS_list = nullptr;
        nb_escales = 0;
        return;
    }

    nb_escales = nbTrajets;
    TS_list = new ElemTrajet(trajets[0]);
    ElemTrajet* prev = TS_list;

    // Pour chaque trajet passé en paramètre, on l'ajoute à la liste chaînée de trajets simples
    for(int i = 1; i < nbTrajets; ++i)
    {
        ElemTrajet* current = new ElemTrajet(trajets[i]);
        prev->SetNext(current);
        prev = current;
    }
}

// Destructeur
TC::~TC()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TC>" << endl;
    #endif
    ElemTrajet* current = TS_list;
    while (current != nullptr) {
        ElemTrajet* next = current->GetNext();
        Trajet* trajet = current->GetTrajet();
        if (trajet != nullptr) {
            delete trajet; // Libère le trajet
        }
        delete current; // Libère l'élément
        current = next;
    }
}

// Méthodes

void TC::AfficherTrajet(int index) const
{
    // Affiche les détails du trajet composé avec toutes ses escales
    cout << "Trajet composé n°" << index << " de " << GetNomVille(depart) << " à " << GetNomVille(destination) << " en " << nb_escales << " escales :\n";
    ElemTrajet* copie = TS_list; // Copie pour parcourir la liste sans la modifier
    int i = 1;
    while (copie) // Parcourt chaque escale
    {
        cout << "\t- ";
        copie->GetTrajet()->AfficherTrajet(i); // Affiche les détails de chaque trajet simple
        copie = copie->GetNext(); // Passe à l'élément suivant
        i++;
    }
}
