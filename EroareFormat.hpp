// language: cpp
#ifndef OOP_EROAREFORMAT_HPP
#define OOP_EROAREFORMAT_HPP

#include "EroareDateInvalide.hpp"
#include <string>

class EroareFormat : public EroareDateInvalide {
public:
    explicit EroareFormat(const std::string& msg)
        : EroareDateInvalide("format json invalid: " + msg) {}
};

#endif // OOP_EROAREFORMAT_HPP
