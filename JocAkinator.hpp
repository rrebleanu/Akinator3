#ifndef OOP_JOCAKINATOR_HPP
#define OOP_JOCAKINATOR_HPP

#include "Arbore.hpp"
#include <istream>
#include <ostream>
#include <utility>

class JocAkinator {
public:
    // ✅ NOU: Constructor care primește arborele (deja construit în main)
    explicit JocAkinator(Arbore arbore) : arbore_(std::move(arbore)) {}

    void ruleazaSilentios(std::istream& is, std::ostream& os);

private:
    Arbore arbore_;
};

#endif // OOP_JOCAKINATOR_HPP

















