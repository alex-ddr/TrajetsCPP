#include <iostream>
#include "Catalogue.h"
#include "functions.h"
using namespace std;

int main() {
    // Déclare des buffers pour lire les entrées utilisateur
    char ville1_buffer[100];
    char ville2_buffer[100];

    // Lire les entrées utilisateur dans les buffers
    cout << "Entrez la première ville : ";
    cin >> ville1_buffer;

    cout << "Entrez la deuxième ville : ";
    cin >> ville2_buffer;

    // Déclare des const char* pointant vers les buffers
    const char* ville1 = ville1_buffer;
    const char* ville2 = ville2_buffer;

    // Crée un trajet et ajoute des trajets au catalogue
    Trajet t1(ville1, ville2);

    Catalogue c = Catalogue();
    c.AjouterTrajet(Trajet("Paris", "Marseille"));
    c.AjouterTrajet(Trajet("qzd", "b"));
    c.AjouterTrajet(Trajet("btfb", "uoo"));
    c.AjouterTrajet(t1);
    c.AjouterTrajet(Trajet("eevb", "Marseille"));
    c.AfficherCatalogue();
    return 0;
}