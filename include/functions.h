#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../include/config.h"

Ville GetVille(const char* nomVille);
const char* GetNomVille(Ville ville);

Transport GetTransport(const char* nomTransport);
const char* GetNomTransport(Transport transport);

#endif // FUNCTIONS_H