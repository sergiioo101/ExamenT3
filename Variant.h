#pragma once

#include <variant>
#include <string>

class Variant {
public:
    using ValueType = std::variant<int, double, std::string>;

    Variant() : value(0) {}
    explicit Variant(ValueType initialValue) : value(std::move(initialValue)) {}

    [[maybe_unused]] [[nodiscard]] ValueType getValue() const;
    [[nodiscard]] std::string getValueAsString() const;

private:
    ValueType value;
};
