// language: cpp
#include "Arbore.hpp"
#include "Intrebare.hpp"
#include "RaspunsFinal.hpp"
#include "RaspunsDetaliat.hpp"
#include "EroareFisier.hpp"
#include "EroareFormat.hpp"
#include <fstream>
#include <stdexcept>
#include <nlohmann/json.hpp>

void Arbore::incarcaDinFisier(const std::string& fname) {
    std::ifstream ifs(fname);
    if (!ifs) throw EroareFisier(fname);

    nlohmann::json j;
    try {
        ifs >> j;
    } catch (const std::exception& e) {
        // Eroare de parsing JSON
        throw EroareFormat(e.what());
    }

    if (j.contains("radacina")) {
        radacina_ = parseNod(j.at("radacina"));
    } else {
        radacina_.reset();
    }
}

std::unique_ptr<Nod> Arbore::parseNod(const nlohmann::json& j) const {
    if (j.is_null()) return nullptr;

    if (j.contains("entitate")) {
        const auto& ent = j.at("entitate");
        std::string nume = ent.at("nume").get<std::string>();

        // Dacă există metadate suplimentare, se creează RaspunsDetaliat
        if (ent.contains("tip") || ent.contains("domeniu")) {
            std::string domeniu = ent.contains("domeniu") ? ent.at("domeniu").get<std::string>() : "";
            std::string tip = ent.contains("tip") ? ent.at("tip").get<std::string>() : "";
            return std::make_unique<RaspunsDetaliat>(nume, domeniu, tip);
        }
        // Altfel, se creează RaspunsFinal
        return std::make_unique<RaspunsFinal>(nume);
    }
    else if (j.contains("intrebare")) {
        std::string q = j.at("intrebare").get<std::string>();
        std::unique_ptr<Nod> yes = nullptr;
        std::unique_ptr<Nod> no = nullptr;

        // Parsarea nodurilor Da și Nu recursiv
        if (j.contains("da")) yes = parseNod(j.at("da"));
        if (j.contains("nu")) no = parseNod(j.at("nu"));

        return std::make_unique<Intrebare>(q, std::move(yes), std::move(no));
    }

    // Nod JSON invalid (nu e nici "entitate", nici "intrebare")
    return nullptr;
}

// ----------------------------------------------------------------
// IMPLEMENTAREA CRITICĂ A LOGICII JOCULUI (Parcurgerea Arborelui)
// ----------------------------------------------------------------

const std::string* Arbore::determinaEntitatea(std::istream& is, std::ostream& os) const {
    Nod* curent = radacina_.get();
    std::string raspuns;

    while (curent && curent->esteIntrebare()) {
        const auto* intrebareCurenta = dynamic_cast<const Intrebare*>(curent);

        // Ar trebui să fie mereu adevărat dacă esteIntrebare() e true
        if (!intrebareCurenta) return nullptr;

        // Afișează prompt-ul de întrebare
        os << intrebareCurenta->getText() << " (yes/no): ";

        // Citește răspunsul din stream-ul de input (e.g., tastatura.txt)
        if (!(is >> raspuns)) {
            // S-a terminat input-ul înainte de a ghici
            return nullptr;
        }

        if (raspuns == "yes") {
            curent = intrebareCurenta->getDa();
        } else if (raspuns == "no") {
            curent = intrebareCurenta->getNu();
        } else {
            return nullptr;
        }
    }

    // Dacă am ieșit din buclă, nodul curent este o entitate (RaspunsFinal sau RaspunsDetaliat)
    if (curent) {
        return &curent->getText();
    }

    // Nu s-a găsit nimic (ramură goală)
    return nullptr;
}