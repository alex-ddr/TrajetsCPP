#include <iostream>
#include "Catalogue.h"
#include "functions.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();
    char ville1[100];
    char ville2[100];
    scanf("%s", &ville1);
    scanf("%s", &ville2);

    Trajet t1 = Trajet(GetVille(ville1), GetVille(ville2));
    c.AjouterTrajet(Trajet(Paris, Marseille));
    return 0;
}