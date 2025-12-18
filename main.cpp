#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// CORECȚIE: S-a schimbat extensia din .h în .hpp pentru toate headerele
#include "srh/JocAkinator.hpp"
#include "srh/Intrebare.hpp"
// Presupunând că ai o clasă comună (EroareAkinator) sau include-le specifice:
#include "srh/EroareFisier.hpp"
#include "srh/EroareFormat.hpp"
#include "srh/EroareDateInvalide.hpp"

// Folosim constantele pentru I/O
const std::string FISIER_INTRARE = "tastatura.txt";
const std::string FISIER_IESIRE = "raspuns.txt";

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream is(FISIER_INTRARE);
    std::ofstream os(FISIER_IESIRE);

    if (is.fail() || os.fail()) {
        std::cerr << "Eroare critica: Fisierele de I/O (" << FISIER_INTRARE << ", " << FISIER_IESIRE << ") nu sunt deschise corect." << std::endl;
        return 1;
    }

    std::stringstream buffer;

    try {
        JocAkinator joc();

        joc.ruleazaSilentios(is, buffer);
    }
    // T2: Aceste catch-uri depind de headerele de eroare incluse mai sus
    catch (const EroareFisier& e) { // Exemplu de prindere, adaptat la numele fisierului tau
        buffer << "Eroare Fatala (Fisier): " << e.what() << "\n";
    }
    catch (const EroareFormat& e) {
        buffer << "Eroare Format: " << e.what() << "\n";
    }
    catch (const EroareDateInvalide& e) {
        buffer << "Eroare Date Invalide: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        buffer << "Eroare Necunoscuta (std::exception): " << e.what() << "\n";
    }

    os << buffer.str();

    // T2: Verificare static
    os << "\n--- Verificari Structura T2 ---\n";
    os << "Numar total de intrebari generate: " << Intrebare::getNumarIntrebariTotale() << "\n";

    return 0;
}