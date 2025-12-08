#ifndef OOP_JOCAKINATOR_HPP
#define OOP_JOCAKINATOR_HPP

#include "Arbore.hpp"
#include <istream>
#include <ostream>

class JocAkinator {
public:
    JocAkinator() = default;
    void ruleazaSilentios(std::istream& is, std::ostream& os);
private:
    Arbore arbore_;
};

#endif // OOP_JOCAKINATOR_HPP
