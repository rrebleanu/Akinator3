// language: cpp
#include "RaspunsFinal.hpp"
#include <utility>

RaspunsFinal::RaspunsFinal(std::string text) : text_(std::move(text)) {}

std::unique_ptr<Nod> RaspunsFinal::clone() const {
    return std::make_unique<RaspunsFinal>(text_);
}

nlohmann::json RaspunsFinal::toJson() const {
    return nlohmann::json{{"entitate", {{"nume", text_}}}};
}
