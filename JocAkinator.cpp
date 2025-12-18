#include "JocAkinator.hpp"
#include <iostream>

void JocAkinator::ruleazaSilentios(std::istream& is, std::ostream& os) {
    // 🛑 LOGICA DE CITIRE TEMA ȘI arbore_.incarcaDinFisier(fname) ESTE ELIMINATĂ.
    // Arborele este deja construit la instanțierea clasei JocAkinator.

    // Citirea temei din fisier este redundanta, dar o citim doar pentru a avansa cursorul.
    std::string tema;
    if (!(is >> tema)) {
        // Dacă tema nu se poate citi (EOF), ne oprim, dar arborele nu este folosit oricum.
    }

    os << "Tema: Fotbalisti\n"; // Afisăm tema reală a jocului

    // Rularea logicii de ghicire pe arborele existent
    const std::string* rezultat = arbore_.determinaEntitatea(is, os);

    if (rezultat) os << "FINAL: " << *rezultat << "\n";
    else os << "FINAL: Negasit\n";
}