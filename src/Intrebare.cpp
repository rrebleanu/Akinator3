#include "../srh/Intrebare.hpp"
#include <utility>

Intrebare::Intrebare(std::string text, std::unique_ptr<Nod> da, std::unique_ptr<Nod> nu)
    : text_(std::move(text)), da_(std::move(da)), nu_(std::move(nu)) {}

std::unique_ptr<Nod> Intrebare::clone() const {
    std::unique_ptr<Nod> da_clone = da_ ? da_->clone() : nullptr;
    std::unique_ptr<Nod> nu_clone = nu_ ? nu_->clone() : nullptr;
    return std::make_unique<Intrebare>(text_, std::move(da_clone), std::move(nu_clone));
}