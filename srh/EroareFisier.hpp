#ifndef OOP_EROAREFISIER_HPP
#define OOP_EROAREFISIER_HPP

#include "EroareDateInvalide.hpp"
#include <string>

class EroareFisier : public EroareDateInvalide {
public:
    explicit EroareFisier(const std::string& nume_fisier)
        : EroareDateInvalide("Eroare la deschiderea sau citirea fisierului: " + nume_fisier) {}
};

#endif // OOP_EROAREFISIER_HPP