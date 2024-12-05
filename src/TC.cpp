#include <iostream>
#include "../include/TC.h"
using namespace std;

//---------------------------------------------------------------- PROTEGE

ElemTrajet* TC::CreerListe(Ville depart, Ville destination)
{
    int index = 1;
    ElemTrajet* FirstElem = nullptr;
    ElemTrajet* prev = nullptr;

    char current_depart[100], current_dest[100], current_trans[100];
    Ville villeDep = depart, villeDest;
    Transport trans;

    do
    {
        ClearScreen();
        cout << "Trajet " << GetNomVille(depart) << " -> " << GetNomVille(destination) << " :\n";
        
        cout << "\n\nEscale n°" << index << " :\n";

        // Affichage du premier départ
        if (index == 1)
            cout << "   - Ville de départ : " << GetNomVille(depart) << "\n";
        // Entrée de current_depart
        else
        {
            do
            {
                cout << "   - Ville de départ : ";
                cin >> current_depart;
                villeDep = GetVille(current_depart);

                if (villeDep == UNKNOWN_VILLE)
                {
                    cout << "\nVille inconnue.\n";
                    AfficherVilles(1);
                }
                else if (villeDep != prev->GetTrajet()->GetDestination())
                    cout << "\nLa ville ne correspond pas à la destination précédente. Veuillez réessayer : \n";
            }
            while ((villeDep == UNKNOWN_VILLE) || (villeDep != prev->GetTrajet()->GetDestination()));
        }

        // Entrée de current_dest
        do
        {
            cout << "   - Ville d'arrivée : ";
            cin >> current_dest;
            villeDest = GetVille(current_dest);

            if (villeDest == UNKNOWN_VILLE)
                {
                    cout << "\nVille inconnue.\n";
                    AfficherVilles(1);
                }
        }
        while (villeDest == UNKNOWN_VILLE);

        // Entrée de current_trans
        do
        {
            cout << "   - Moyen de Transport : ";
            cin >> current_trans;
            trans = GetTransport(current_trans);

            if (trans == UNKNOWN_TRANSPORT)
            {
                cout << "\nMoyen de transport inconnu.\n";
                AfficherTransports(1);
            }

        }
        while (trans == UNKNOWN_TRANSPORT);

        // Création du trajet
        ElemTrajet* current = new ElemTrajet(new TS(villeDep, villeDest, trans));

        if (index == 1)
            FirstElem = current;
        else
            prev->SetNext(current);

        prev = current; // Mise à jour du pointeur précédent
        index++;
    } while (villeDest != destination);

    if (prev) prev->SetNext(nullptr); // Dernier élément de la liste
    this->nb_escales = index;
    return FirstElem;
}





//----------------------------------------------------------------- PUBLIC

// Constructeur
TC::TC()
{
}

TC::TC(const char* depart, const char* destination):Trajet(depart, destination)
{
    TS_list = CreerListe(GetVille(depart), GetVille(destination));
}

TC::TC(Ville depart, Ville destination):Trajet(depart, destination)
{
    TS_list = CreerListe(depart, destination);
}


// Destructeur
TC::~TC()
{
    delete TS_list;
}


// Méthodes
void TC::AfficherTrajet(int index) const
{
    cout << "Trajet composé n°" << index << " de " << GetNomVille(depart) << " à " << GetNomVille(destination) << " en " << nb_escales << " escales :\n";
    ElemTrajet* copie = TS_list;
    int i = 1;
    while(copie)
    {
        cout << "\t- ";
        copie->GetTrajet()->AfficherTrajet(i);
        copie= copie->GetNext();
        i++;
    }
}