#ifndef OOP_ARBORE_HPP
#define OOP_ARBORE_HPP

#include "Nod.hpp"
#include <memory>
#include <string>
#include <istream>
#include <ostream>

class Arbore {
public:
    Arbore() = default;

    // ✅ R5: Constructor de mutare (preia ownership-ul rădăcinii)
    explicit Arbore(std::unique_ptr<Nod> r) : radacina_(std::move(r)) {}

    // ✅ R5: Regula Zero (destructor default, move semantics)
    Arbore(Arbore&&) noexcept = default;
    Arbore& operator=(Arbore&&) noexcept = default;
    ~Arbore() = default;

    // Suprascrierea cc/op= este omisa pentru ca unique_ptr nu permite copierea.

    const std::string *determinaEntitatea(std::istream &is, std::ostream &os) const; // Logică de joc
    void setRadacina(std::unique_ptr<Nod> r) { radacina_ = std::move(r); } // move to cpp

private:
    std::unique_ptr<Nod> radacina_;
};

#endif // OOP_ARBORE_HPP