// language: cpp
#ifndef OOP_RASPUNSFINAL_HPP
#define OOP_RASPUNSFINAL_HPP

#include "Nod.hpp"
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

class RaspunsFinal : public Nod {
public:
    explicit RaspunsFinal(const std::string& text) : text_(text) {}
    explicit RaspunsFinal(std::string text) : text_(std::move(text)) {}

    bool esteIntrebare() const override { return false; }

    // Return reference so callers can take address
    const std::string& getText() const override { return text_; }

    const std::string& name() const noexcept { return text_; }

    std::unique_ptr<Nod> clone() const override {
        return std::make_unique<RaspunsFinal>(text_);
    }

    nlohmann::json toJson() const override {
        nlohmann::json j;
        j["entitate"] = { {"nume", text_} };
        return j;
    }

private:
    std::string text_;
};

#endif // OOP_RASPUNSFINAL_HPP
