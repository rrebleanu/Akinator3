// language: cpp
#ifndef OOP_NOD_HPP
#define OOP_NOD_HPP

#include <memory>
#include <string>
// Liniile care includeau <nlohmann/json.hpp> au fost ELIMINATE
#include <ostream>

class Nod {
private:
    static int nrTotalNoduri_; // Declarare atribut static

public:
    Nod(); // Declarare constructor
    // Destructorul virtual este esențial pentru dezalocarea corectă a claselor derivate.
    virtual ~Nod(); // Declarare destructor

    // Tema-specific pure virtuals
    virtual bool esteIntrebare() const = 0;

    // Return text by const reference so callers can take its address safely
    virtual const std::string& getText() const = 0;

    // virtual constructor
    virtual std::unique_ptr<Nod> clone() const = 0;

    // Functia virtuala toJson() a fost ELIMINATA COMPLET

    // non-virtual interface that uses virtual functions (affisare via getText)
    void afiseaza(std::ostream& os) const {
        os << getText();
    }

    static int getNrTotalNoduri() { return nrTotalNoduri_; } // Funcție statică
};

#endif // OOP_NOD_HPP