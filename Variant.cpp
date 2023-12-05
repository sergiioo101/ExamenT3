// Variant.cpp
#include "Variant.h"
#include <sstream>
#include <iostream>


// Implementa la conversión a cadena según sea necesario
std::string Variant::getValueAsString() const {
    // Usa std::visit para manejar los diferentes tipos almacenados en la variante
    std::visit([](const auto &value) {
        // Usa std::to_string para convertir el valor a cadena
        std::ostringstream oss;
        oss << value;
        // Puedes devolver o imprimir la cadena según tus necesidades
        // En este ejemplo, estoy imprimiendo en la consola
        std::cout << "Value as String: " << oss.str() << std::endl;
    }, value);

    // Si prefieres devolver la cadena en lugar de imprimir en la consola, haz lo siguiente:
    // std::ostringstream oss;
    // std::visit([&oss](const auto &v) { oss << v; }, value);
    // return oss.str();

    // Por ahora, devolver una cadena vacía
    return "";
}
