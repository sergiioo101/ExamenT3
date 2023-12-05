#include <iostream>
#include <map>
#include <string>

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
    myEnvironment.insertSymbol("variable1", 30);  // Intentar insertar un símbolo existente

    return 0;
}



