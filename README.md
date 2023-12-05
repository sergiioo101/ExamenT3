# ExamenT3
https://github.com/sergiioo101/ExamenT3.git

Parte 1: Preguntas de elección múltiple
1. b) Representar cualquier tipo de dato Lisp
2. a) Una cadena de texto que representa una instancia de Variant
3. b) Convierte un objeto Variant a una cadena JSON
4. a) Convierte una cadena JSON en un objeto Variant

DESCRIPCION BREVE DE CADA EJERCICIO:
Ejercicio 1: Estructura Básica
Este ejercicio define la estructura fundamental de la clase Environment para establecer la base de la implementación. La clase debe incluir un std::map para administrar la tabla de símbolos. Los símbolos y sus correspondientes valores se almacenarán en esta tabla, que funcionará como un diccionario.

Ejercicio 2: Insertar Símbolos
El método insert se implementa y prueba en la clase Environment. Con este método, es posible agregar nuevos símbolos al entorno y evitar conflictos si se intenta insertar un símbolo que ya existe en la tabla.

Ejercicio 3: Búsqueda de Símbolos
Este ejercicio implementa y prueba el método de búsqueda. Con esta técnica, es posible encontrar un símbolo en el entorno. Se toman en cuenta los casos en los que el símbolo puede no estar presente en la tabla y se manejan correctamente para evitar errores.

Ejercicio 4: Gestión de Errores
Para manejar situaciones de error, como intentar acceder an un símbolo que no existe o insertar un símbolo ya existente con un valor diferente, se introduce la gestión de excepciones. Esto hace que el código sea más fuerte y facilita la detección y corrección de problem

Ejercicio 5: Integración con Variant
Se explica y demuestra cómo la clase Environment y Variant interactúan. Se explica cómo la tabla de símbolos puede almacenar valores de varios tipos y interactuar con ellos. Se presentan ejemplos prácticos de esta integración

Ejercicio 6: Expandiendo Funcionalidades
Se diseñan y añaden al menos dos funciones adicionales que se consideran relevantes para la clase Environment. Estas funciones podrían incluir la eliminación de un símbolo o verificar si un símbolo existe en la tabla, entre otras posibilidades.

Ejercicio 7: Casos de Uso
Se proporcionan ejemplos de cómo un diseñador o desarrollador de videojuegos podría utilizar la clase Environment en conjunto con Variant para personalizar el comportamiento de un juego. Esto podría incluir la configuración dinámica de parámetros o la definición de reglas específicas.

Ejercicio 8: Reflexión y Mejoras
Se realiza una reflexión sobre la implementación actual y se discuten posibles mejoras o extensiones para el sistema de scripting en el futuro. Se consideran aspectos como la optimización del rendimiento, la expansión de la tabla de símbolos para soportar más tipos de datos, o la introducción de funciones más avanzadas que mejoren la flexibilidad del sistema.
