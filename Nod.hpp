// language: cpp
#ifndef OOP_NOD_HPP
#define OOP_NOD_HPP

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include <ostream>

class Nod {
public:
    // Destructorul virtual este esențial pentru dezalocarea corectă a claselor derivate.
    virtual ~Nod() = default;

    // Tema-specific pure virtuals
    virtual bool esteIntrebare() const = 0;

    // Return text by const reference so callers can take its address safely
    virtual const std::string& getText() const = 0;

    // virtual constructor
    virtual std::unique_ptr<Nod> clone() const = 0;

    // JSON export
    virtual nlohmann::json toJson() const = 0;

    // non-virtual interface that uses virtual functions (affisare via getText)
    void afiseaza(std::ostream& os) const {
        os << getText();
    }
};

#endif // OOP_NOD_HPP