#include <iostream>
#include "Catalogue.h"
#include "functions.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();
    c.InitialiserCatalogue();
    c.AfficherCatalogue();
    return 0;
}