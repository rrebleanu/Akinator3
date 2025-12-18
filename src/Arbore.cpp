// Arbore.cpp
// language: cpp
#include "../srh/Arbore.hpp"
#include "../srh/Intrebare.hpp"
#include "../srh/RaspunsFinal.hpp"
#include "../srh/RaspunsDetaliat.hpp"
#include "../srh/EroareFisier.hpp"
#include "../srh/EroareFormat.hpp"
#include <fstream>
#include <stdexcept>
// 🛑 LINIE ȘTEARSĂ: #include <nlohmann/json.hpp>

// 🛑 FUNCȚII ELIMINATE COMPLET (NU SE MAI CITESC DIN JSON)

/*
void Arbore::incarcaDinFisier(const std::string& fname) { ... }
std::unique_ptr<Nod> Arbore::parseNod(const nlohmann::json& j) const { ... }
*/

// ----------------------------------------------------------------
// IMPLEMENTAREA CRITICĂ A LOGICII JOCULUI (Parcurgerea Arborelui)
// ----------------------------------------------------------------

const std::string* Arbore::determinaEntitatea(std::istream& is, std::ostream& os) const {
    Nod* curent = radacina_.get();
    std::string raspuns;

    while (curent && curent->esteIntrebare()) {
        const auto* intrebareCurenta = dynamic_cast<const Intrebare*>(curent);

        if (!intrebareCurenta) return nullptr;

        // Afișează prompt-ul de întrebare în stream-ul de output
        os << intrebareCurenta->getText() << " (yes/no): ";

        if (!(is >> raspuns)) {
            // S-a terminat input-ul
            return nullptr;
        }

        if (raspuns == "yes" || raspuns == "da") {
            curent = intrebareCurenta->getDa();
        } else if (raspuns == "no" || raspuns == "nu") {
            curent = intrebareCurenta->getNu();
        } else {
            // Răspuns invalid citit
            return nullptr;
        }
    }

    // Dacă am ieșit din buclă, nodul curent este o entitate
    if (curent) {
        os << "M-am gandit la: " << curent->getText() << ". E corect? (yes/no): ";
        if (!(is >> raspuns)) return nullptr;

        if (raspuns == "yes" || raspuns == "da") {
            return &curent->getText();
        }
    }

    // Nu s-a găsit nimic (ramură goală sau răspuns final "no")
    return nullptr;
}