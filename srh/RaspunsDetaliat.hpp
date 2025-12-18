#ifndef OOP_RASPUNSDETAILIAT_HPP
#define OOP_RASPUNSDETAILIAT_HPP

#include "Nod.hpp"
#include <string>
#include <utility>

class RaspunsDetaliat : public Nod {
public:
    RaspunsDetaliat(std::string nume, std::string domeniu, std::string tip_atribute)
        : nume_(std::move(nume)), domeniu_(std::move(domeniu)), tip_atribute_(std::move(tip_atribute)) {}

    // ✅ Clasa este de tip răspuns final
    bool esteIntrebare() const override { return false; }
    const std::string& getText() const override { return nume_; }

    const std::string& domeniu() const noexcept { return domeniu_; }
    const std::string& getAtribute() const noexcept { return tip_atribute_; }

    std::unique_ptr<Nod> clone() const override {
        return std::make_unique<RaspunsDetaliat>(nume_, domeniu_, tip_atribute_);
    }

private:
    std::string nume_;
    std::string domeniu_;
    std::string tip_atribute_;
};

#endif // OOP_RASPUNSDETAILIAT_HPP