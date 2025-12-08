// language: cpp
#ifndef OOP_INTREBARE_HPP
#define OOP_INTREBARE_HPP

#include "Nod.hpp"
#include <memory>
#include <string>

class Intrebare : public Nod {
public:
    Intrebare(std::string text,
              std::unique_ptr<Nod> da = nullptr,
              std::unique_ptr<Nod> nu = nullptr);

    // rule of five not needed beyond default since we use unique_ptr
    bool esteIntrebare() const override { return true; }
    const std::string& getText() const override { return text_; }

    Nod* getDa() const noexcept { return da_.get(); }
    Nod* getNu() const noexcept { return nu_.get(); }

    void setDa(std::unique_ptr<Nod> d) { da_ = std::move(d); }
    void setNu(std::unique_ptr<Nod> n) { nu_ = std::move(n); }

    std::unique_ptr<Nod> clone() const override;
    nlohmann::json toJson() const override;

private:
    std::string text_;
    std::unique_ptr<Nod> da_;
    std::unique_ptr<Nod> nu_;
};

#endif // OOP_INTREBARE_HPP
