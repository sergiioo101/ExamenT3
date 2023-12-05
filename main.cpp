#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <utility>
#include <variant>
#include <optional>

class Variant {
public:
    // Definir los posibles tipos que puede almacenar Variant
    using ValueType = std::variant<int, double, std::string>;

    // Constructor
    Variant() : value(0) {}

    // Constructor con un valor inicial
    explicit Variant(ValueType  initialValue) : value(std::move(initialValue)) {}

    // Obtener el valor almacenado
    [[maybe_unused]] [[nodiscard]] ValueType getValue() const {
        return value;
    }

    // Función para obtener una representación de cadena del valor almacenado en Variant
    [[nodiscard]] std::string getValueAsString() const {
        if (std::holds_alternative<int>(value)) {
            return std::to_string(std::get<int>(value));
        } else if (std::holds_alternative<double>(value)) {
            return std::to_string(std::get<double>(value));
        } else if (std::holds_alternative<std::string>(value)) {
            return std::get<std::string>(value);
        } else {
            return "Tipo desconocido";
        }
    }

private:
    ValueType value;
};

class Environment {
public:
    // Constructor
    Environment() {
        // Puedes inicializar cosas si es necesario
    }

    // Destructor
    ~Environment() {
        // Puedes realizar tareas de limpieza si es necesario
    }

    // Método para insertar un símbolo en la tabla
    void insertSymbol(const std::string& name, const Variant::ValueType& value) {
        // Verificar si el símbolo ya existe en la tabla
        auto it = symbolTable.find(name);
        if (it == symbolTable.end()) {
            // El símbolo no existe, se puede insertar
            symbolTable[name] = value;
            std::cout << "Símbolo insertado: " << name << " = " << Variant(value).getValueAsString() << std::endl;
        } else {
            // El símbolo ya existe, lanzar una excepción
            throw std::invalid_argument("Error: El símbolo ya existe en la tabla.");
        }
    }

    // Método para buscar un símbolo en la tabla
    [[nodiscard]] std::optional<Variant::ValueType> lookupSymbol(const std::string& name) const {
        // Buscar el símbolo en la tabla
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            // El símbolo existe, devolver su valor
            return it->second;
        } else {
            // El símbolo no existe, lanzar una excepción
            throw std::out_of_range("Error: El símbolo no existe en la tabla.");
        }
    }

    // Método para eliminar un símbolo de la tabla
    void removeSymbol(const std::string& name) {
        // Buscar el símbolo en la tabla
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            // El símbolo existe, eliminarlo
            symbolTable.erase(it);
            std::cout << "Símbolo eliminado: " << name << std::endl;
        } else {
            // El símbolo no existe, lanzar una excepción
            throw std::out_of_range("Error: No se puede eliminar el símbolo porque no existe en la tabla.");
        }
    }

    // Método para verificar si un símbolo existe en la tabla
    [[nodiscard]] bool symbolExists(const std::string& name) const {
        return symbolTable.find(name) != symbolTable.end();
    }

private:
    // Tabla de símbolos
    std::map<std::string, Variant::ValueType> symbolTable;
};

int main() {
    try {
        // Ejemplo de uso de la clase Environment con Variant
        Environment myEnvironment;

        // Insertar símbolos de prueba con valores de diferentes tipos
        myEnvironment.insertSymbol("variable1", 10);
        myEnvironment.insertSymbol("variable2", 3.14);
        myEnvironment.insertSymbol("variable3", "Hola, mundo");

        // Buscar y mostrar los valores de los símbolos
        auto result1 = myEnvironment.lookupSymbol("variable1");
        if (result1) {
            std::cout << "Valor de variable1: " << Variant(*result1).getValueAsString() << std::endl;
        }

        auto result2 = myEnvironment.lookupSymbol("variable2");
        if (result2) {
            std::cout << "Valor de variable2: " << Variant(*result2).getValueAsString() << std::endl;
        }

        auto result3 = myEnvironment.lookupSymbol("variable3");
        if (result3) {
            std::cout << "Valor de variable3: " << Variant(*result3).getValueAsString() << std::endl;
        }

        // Eliminar un símbolo
        myEnvironment.removeSymbol("variable1");

        // Verificar si un símbolo existe
        if (myEnvironment.symbolExists("variable1")) {
            std::cout << "El símbolo variable1 sigue existiendo." << std::endl;
        } else {
            std::cout << "El símbolo variable1 ha sido eliminado." << std::endl;
        }

    } catch (const std::exception& e) {
        // Capturar y manejar la excepción
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}

