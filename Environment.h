#pragma once

#include <iostream>
#include <map>
#include <stdexcept>
#include <optional>
#include "Variant.h"

class Environment {
public:
    Environment();
    ~Environment();

    void insertSymbol(const std::string& name, const Variant::ValueType& value);
    [[nodiscard]] std::optional<Variant::ValueType> lookupSymbol(const std::string& name) const;
    void removeSymbol(const std::string& name);
    [[nodiscard]] bool symbolExists(const std::string& name) const;

private:
    std::map<std::string, Variant::ValueType> symbolTable;
};
