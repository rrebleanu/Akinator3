//
// Created by Robert on 12/8/2025.
//
#include "JocAkinator.hpp"
#include <iostream>

void JocAkinator::ruleazaSilentios(std::istream& is, std::ostream& os) {
    std::string tema;
    if (!(is >> tema)) {
        os << "Eroare: nu s-a citit tema\n";
        return;
    }
    // tema -> fisier e tema + "_arbore.json"
    std::string fname = tema + "_arbore.json";
    try {
        arbore_.incarcaDinFisier(fname);
    } catch (const std::exception& e) {
        os << "Eroare la incarcare arbore: " << e.what() << "\n";
        return;
    }

    const std::string* rezultat = arbore_.determinaEntitatea(is, os);
    if (rezultat) os << *rezultat << "\n";
    else os << "Negasit\n";
}
