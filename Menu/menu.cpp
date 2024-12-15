//
// Created by pablo on 15/12/2024.
//
#include "../T-2/calculartor.h"
#include "../T-4/Variant/Variant.h"
#include "../T-4/prueba/prueba.h"
#include "menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../T-3/labmain.h"

void menu() {
  while (true) {
    int opcion;
    std::cout << "\n========= MENU DE Tiny-Lisp =========" << std::endl;
    std::cout << "1. Realizar una operacion matematica" << std::endl;
    std::cout << "2. Cargar y ejecutar un script de operaciones" << std::endl;
    std::cout << "3. Probar funcionalidades avanzadas (Variant)" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Selecciona una opcion: ";

    std::cin >> opcion;

    if (std::cin.fail()) {
      std::cin.clear(); // clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar el input invalido
      std::cout << "Entrada no valida. Por favor, introduce un numero del 1 al 5." << std::endl;
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar el buffer de entrada

    try {
      switch (opcion) {
        case 1:
          std::cout << "Opcion 1 seleccionada" << std::endl;
          calculadora();
          break;
        case 2:
          std::cout << "Opcion 2 seleccionada" << std::endl;
          load_script_V();
          break;
        case 3:
          std::cout << "Opcion 3 seleccionada" << std::endl;
          prueba_variant();
          break;
        case 4:
          std::cout << "Saliendo..." << std::endl;
          return;
        default:
          std::cout << "Opcion no valida. Por favor, introduce un numero del 1 al 5." << std::endl;
          break;
      }
    } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Error desconocido." << std::endl;
    }
  }
}