#include "Environment.h"

Environment::Environment() {
    // Puedes inicializar cosas si es necesario
}

Environment::~Environment() {
    // Puedes realizar tareas de limpieza si es necesario
}

void Environment::insertSymbol(const std::string& name, const Variant::ValueType& value) {
    auto it = symbolTable.find(name);
    if (it == symbolTable.end()) {
        symbolTable[name] = value;
        std::cout << "Símbolo insertado: " << name << " = " << Variant(value).getValueAsString() << std::endl;
    } else {
        throw std::invalid_argument("Error: El símbolo ya existe en la tabla.");
    }
}

std::optional<Variant::ValueType> Environment::lookupSymbol(const std::string& name) const {
    auto it = symbolTable.find(name);
    if (it != symbolTable.end()) {
        return it->second;
    } else {
        throw std::out_of_range("Error: El símbolo no existe en la tabla.");
    }
}

void Environment::removeSymbol(const std::string& name) {
    auto it = symbolTable.find(name);
    if (it != symbolTable.end()) {
        symbolTable.erase(it);
        std::cout << "Símbolo eliminado: " << name << std::endl;
    } else {
        throw std::out_of_range("Error: No se puede eliminar el símbolo porque no existe en la tabla.");
    }
}

bool Environment::symbolExists(const std::string& name) const {
    return symbolTable.find(name) != symbolTable.end();
}
