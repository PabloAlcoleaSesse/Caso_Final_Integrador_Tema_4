https://github.com/PabloAlcoleaSesse/Caso_Final_Integrador_Tema_4.git

## Introducción

El proyecto VariantProject es una aplicación modular en C++ que combina múltiples componentes para realizar tareas como evaluación de expresiones matemáticas, manejo de estructuras de datos mediante variantes, procesamiento de archivos, y demostraciones de conversión JSON. Este documento describe cómo funciona el programa, las opciones del menú, el manejo de errores y las especificaciones técnicas de cada módulo.

Estructura del Proyecto

El proyecto está organizado en múltiples archivos:

CMakeLists.txt: Configuración del proyecto para CMake.

main.cpp: Punto de entrada principal del programa.

T-2/calculartor.cpp y calculartor.h: Implementa una calculadora con soporte para notación postfija y operaciones matemáticas avanzadas.

T-3/labmain.cpp y labmain.h: Maneja operaciones relacionadas con la carga y visualización de archivos.

T-4/Variant/variant.cpp y variant.h: Implementa una estructura de datos genérica para manejar diferentes tipos de datos (simbolos, números, listas, etc.) con soporte para conversión JSON.

T-4/prueba/prueba.cpp y prueba.h: Proporciona ejemplos y demostraciones del funcionamiento del módulo Variant.

## Dependencias

json11: Biblioteca para manejo de JSON.

Compilador C++ compatible con el estándar C++17 o superior.

Compilación

Para compilar el proyecto, utiliza el archivo CMakeLists.txt proporcionado:

Navega al directorio del proyecto.

Ejecuta los siguientes comandos:
```cpp
mkdir build
cd build
cmake ..
make
```
Esto generará un ejecutable llamado VariantProject en el directorio build.

Uso del Programa

## Inicio

El programa comienza ejecutando la función principal en main.cpp, que invoca al menú principal definido en Menu/menu.cpp.

### Menú Principal

El menú principal permite al usuario acceder a diferentes funcionalidades del programa:

### Calculadora (TinyLisp):

Ofrece una calculadora basada en notación postfija.

Admite operaciones básicas (+, -, *, /), avanzadas (potencias, módulo) y funciones trigonométricas (sin, cos, tan, etc.).

Entrada: Expresiones matemáticas.

Salida: Resultado de la evaluación.

Manejo de errores: Si hay valores insuficientes para una operación, se lanza una excepción con un mensaje adecuado.
```cpp
Ejemplo:

-> 5 3 +
8
-> 10 2 /
5
-> exit
```
### Carga de Archivos:

Permite cargar y mostrar el contenido de archivos de texto.

Utiliza colores en la consola para mejorar la experiencia visual.

Entrada: Ruta del archivo.

Salida: Contenido del archivo en pantalla.

Manejo de errores: Si no se puede abrir el archivo, se muestra un mensaje de error.
```cpp
Ejemplo:

Introduce el nombre del archivo: ejemplo.txt
Contenido del archivo:
(Mostrado en colores)
```
### Demostración de Variant:

Crea diferentes variantes (átomos, listas, etc.).

Convierte las variantes a JSON y de JSON de vuelta a objeto.

Demuestra las capacidades de imprimir, to_string y to_json_string.

Manejo de errores: Controla excepciones durante la conversión JSON.

Ejemplo:
```cpp
Demostración de imprimir():
Simbolo: MiSimbolo
Numero: 42
Cadena: Hola Mundo
Lista: [Simbolo: MiSimbolo, Numero: 42, Cadena: Hola Mundo]
```
## Módulos

### Módulo calculartor

Función tokenize: Convierte una cadena de entrada en un vector de tokens.

Función evaluate: Evalúa expresiones en notación postfija utilizando una pila.

Función calculadora: Punto de entrada para la calculadora interactiva.

Control de errores: Maneja condiciones como divisiones por cero, valores insuficientes y operadores no válidos.

### Módulo labmain

Función load_script: Carga el contenido de un archivo y lo muestra por consola.

Función load_script_V: Solicita al usuario la ruta del archivo e invoca load_script.

Control de errores: Detecta excepciones al abrir o leer archivos.

### Módulo Variant

Clase Variant: Maneja diferentes tipos de datos utilizando std::variant.

Tipos soportados: Simbolos, Números, Listas, Procedimientos.

### Métodos destacados:

imprimir: Muestra el contenido de la variante.

to_string: Convierte el contenido a una cadena legible.

to_json_string: Convierte la variante a una representación JSON.

from_json_string: Reconstruye una variante desde un JSON.

Control de errores: Maneja excepciones durante la conversión JSON.

### Módulo prueba

Proporciona ejemplos para probar las capacidades del módulo Variant.

Demuestra todas las funcionalidades mediante llamadas a las funciones de la clase Variant.

## Manejo de Errores

El programa utiliza excepciones para manejar errores comunes:

Errores de expresión: Operadores inválidos, valores insuficientes, divisiones por cero.

Errores de archivo: Archivos no encontrados, problemas al leer contenido.

Errores JSON: Fallos durante el parseo o construcción de JSON.

En cada caso, se muestra un mensaje claro para ayudar al usuario a identificar y resolver el problema.
