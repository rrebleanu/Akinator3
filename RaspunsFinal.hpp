#ifndef OOP_RASPUNSFINAL_HPP
#define OOP_RASPUNSFINAL_HPP
#include "Nod.hpp"
#include <string>
#include <memory>

class RaspunsFinal : public Nod {
public:
    explicit RaspunsFinal(std::string text) : text_(std::move(text)) {}

    bool esteIntrebare() const override { return false; }
    const std::string& getText() const override { return text_; }
    const std::string& name() const noexcept { return text_; }

    std::unique_ptr<Nod> clone() const override {
        return std::make_unique<RaspunsFinal>(text_);
    }

private:
    std::string text_;
};

#endif // OOP_RASPUNSFINAL_HPP