#include <iostream>
#include <stdexcept>
#include "Environment.h"

int main() {
    try {
        Environment myEnvironment;

        myEnvironment.insertSymbol("variable1", 10);
        myEnvironment.insertSymbol("variable2", 3.14);
        myEnvironment.insertSymbol("variable3", "Hola, mundo");

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

        myEnvironment.removeSymbol("variable1");

        if (myEnvironment.symbolExists("variable1")) {
            std::cout << "El símbolo variable1 sigue existiendo." << std::endl;
        } else {
            std::cout << "El símbolo variable1 ha sido eliminado." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}


