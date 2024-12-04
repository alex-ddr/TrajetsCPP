#include <iostream>
#include "Catalogue.h"
using namespace std;

int main() {
    Catalogue c = Catalogue();
    c.InitialiserCatalogue();

    int choice = -1;
    while(1)
    {
        switch(choice)
        {
            case 0:
                c.AfficherCatalogue();
                break;
            case 1:
                c.AjouterTrajet();
                break;
            case 2:
                break;
        }
    }

    c.AjouterTrajet();
    c.AfficherCatalogue();
    return 0;
}