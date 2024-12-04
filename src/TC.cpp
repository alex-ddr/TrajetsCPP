#include <iostream>
#include "../include/TC.h"
using namespace std;

//--------------------------------------------------------------- PROTEGEE

ElemTrajet* TC::CreerListe(Ville depart, Ville destination)
{
    // Création du premier trajet de ville de départ : depart
    cout << "Trajet n°1 :\n   - Ville de départ : " << GetNomVille(depart) << "\n   - Ville d'arrivée : ";
    char* first_dest = new char[100];
    cin >> first_dest;

    char* first_trans = new char[100];
    cout << "   - Moyen de transport : ";
    cin >> first_trans;
    ElemTrajet* FirstElem = new ElemTrajet(new TS(depart, GetVille(first_dest), GetTransport(first_trans)));
    
    
    // Création du reste des trajets
    int index = 2;
    ElemTrajet* prev = FirstElem;
    ElemTrajet* current;
    char* current_depart = new char[100];
    char* current_dest = new char[100];
    char* current_trans = new char[100];

    do
    {
        cout << "\n\nTrajet n°" << index++ << " :\n   - Ville de départ : ";
        do cin >> current_depart;
        while (GetVille(current_depart) == UNKNOWN_VILLE);

        cout << "   - Ville d'arrivée : ";
        do cin >> current_dest;
        while (GetVille(current_dest) == UNKNOWN_VILLE);

        cout << "   - Moyen de Transport : ";
        do cin >> current_trans;
        while (GetTransport(current_trans) == UNKNOWN_TRANSPORT);

        current = new ElemTrajet(new TS(GetVille(current_depart), GetVille(current_dest), GetTransport(current_trans)));
        prev->SetNext(current);
        prev = current;
    }
    while (GetVille(current_dest) != destination);

    current->SetNext(nullptr);

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
    Trajet::AfficherTrajet(index);
}