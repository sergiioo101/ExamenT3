#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <optional>

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
    void insertSymbol(const std::string& name, int value) {
        // Verificar si el símbolo ya existe en la tabla
        auto it = symbolTable.find(name);
        if (it == symbolTable.end()) {
            // El símbolo no existe, se puede insertar
            symbolTable[name] = value;
            std::cout << "Símbolo insertado: " << name << " = " << value << std::endl;
        } else {
            // El símbolo ya existe, lanzar una excepción
            throw std::invalid_argument("Error: El símbolo ya existe en la tabla.");
        }
    }

    // Método para buscar un símbolo en la tabla
    std::optional<int> lookupSymbol(const std::string& name) const {
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

private:
    // Tabla de símbolos
    std::map<std::string, int> symbolTable;
};

int main() {
    try {
        // Ejemplo de uso de la clase Environment
        Environment myEnvironment;

        // Insertar símbolos de prueba
        myEnvironment.insertSymbol("variable1", 10);
        myEnvironment.insertSymbol("variable2", 20);

        // Buscar símbolos
        auto result1 = myEnvironment.lookupSymbol("variable1");
        if (result1) {
            std::cout << "Valor de variable1: " << *result1 << std::endl;
        }

        // Intentar insertar un símbolo ya existente
        myEnvironment.insertSymbol("variable1", 30);  // Esto debería lanzar una excepción

    } catch (const std::exception& e) {
        // Capturar y manejar la excepción
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}



