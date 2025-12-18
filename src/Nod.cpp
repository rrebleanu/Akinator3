#include "../srh/Nod.hpp"

// Initializare (Definitia) atributului static. Acest lucru se face O SINGURĂ DATĂ în Nod.cpp
int Nod::nrTotalNoduri_ = 0;

// Implementare constructor (pentru contorizare)
Nod::Nod() { nrTotalNoduri_++; }

// Implementare destructor (pentru contorizare)
// Destructorul este deja declarat virtual în Nod.hpp
Nod::~Nod() { nrTotalNoduri_--; }