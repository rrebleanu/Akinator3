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

    // load from JSON file with same structure you provided
    void incarcaDinFisier(const std::string& fname);

    // determines entity by reading answers from input stream and writes prompts to output
    // returns pointer to found entity (lifetime owned by tree) or nullptr
    const std::string* determinaEntitatea(std::istream& is, std::ostream& os) const;

    // convenience: set root manually (used by parsing)
    void setRadacina(std::unique_ptr<Nod> r) { radacina_ = std::move(r); }

private:
    std::unique_ptr<Nod> radacina_;

    // JSON recursive parser
    std::unique_ptr<Nod> parseNod(const nlohmann::json& j) const;
};
#endif // OOP_ARBORE_HPP
