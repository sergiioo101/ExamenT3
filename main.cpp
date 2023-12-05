#include <map>
#include <string>
#include <stdexcept>

class Variant {
    // Define la clase Variant con sus atributos y métodos
    // Puedes implementarla según tus necesidades y con soporte para diferentes tipos de datos.
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    // Constructor y destructor si es necesario

    // Método para insertar símbolos en el entorno
    void insert(const std::string& name, const Variant& value) {
        symbolTable[name] = value;
    }

    // Método para buscar símbolos en el entorno
    Variant lookup(const std::string& name) const {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Symbol not found: " + name);
        }
    }

    // Otras funciones relevantes
};

