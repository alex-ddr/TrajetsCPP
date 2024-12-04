#include <iostream>
#include "Catalogue.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();
    c.InitialiserCatalogue();
    c.AjouterTrajet();
    c.AfficherCatalogue();
    return 0;
}