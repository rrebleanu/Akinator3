#ifndef OOP_EROAREDATEINVALIDE_HPP
#define OOP_EROAREDATEINVALIDE_HPP

#include <stdexcept>
#include <string>

class EroareDateInvalide : public std::runtime_error {
public:
    explicit EroareDateInvalide(const std::string &msg)
        : std::runtime_error("Eroare date invalide: " + msg) {}
};

#endif // OOP_EROAREDATEINVALIDE_HPP
