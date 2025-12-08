// language: cpp
#ifndef OOP_RASPUNSDETAILIAT_HPP
#define OOP_RASPUNSDETAILIAT_HPP

#include "Nod.hpp"
#include <string>
#include <nlohmann/json.hpp>

class RaspunsDetaliat : public Nod {
public:
    RaspunsDetaliat(std::string nume, std::string domeniu = {}, std::string tip = {})
        : nume_(std::move(nume)), domeniu_(std::move(domeniu)), tip_(std::move(tip)) {}

    bool esteIntrebare() const override { return false; }
    const std::string& getText() const override { return nume_; }

    const std::string& domeniu() const noexcept { return domeniu_; }
    const std::string& tip() const noexcept { return tip_; }

    std::unique_ptr<Nod> clone() const override {
        return std::make_unique<RaspunsDetaliat>(nume_, domeniu_, tip_);
    }

    nlohmann::json toJson() const override {
        nlohmann::json j;
        j["entitate"] = { {"nume", nume_} };
        if (!domeniu_.empty()) j["entitate"]["domeniu"] = domeniu_;
        if (!tip_.empty()) j["entitate"]["tip"] = tip_;
        return j;
    }

private:
    std::string nume_;
    std::string domeniu_;
    std::string tip_;
};

#endif // OOP_RASPUNSDETAILIAT_HPP
