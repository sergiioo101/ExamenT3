#include <iostream>
#include <map>
#include <string>
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
            // El símbolo ya existe, mostrar un mensaje de error o manejar la situación según sea necesario
            std::cerr << "Error: El símbolo " << name << " ya existe en la tabla." << std::endl;
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
            // El símbolo no existe, devolver un valor "vacío" usando std::nullopt
            std::cerr << "Advertencia: El símbolo " << name << " no existe en la tabla." << std::endl;
            return std::nullopt;
        }
    }

private:
    // Tabla de símbolos
    std::map<std::string, int> symbolTable;
};

int main() {
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

    auto result2 = myEnvironment.lookupSymbol("variable3");  // Intentar buscar un símbolo que no existe

    return 0;
}



