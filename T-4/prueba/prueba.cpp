#include "prueba.h"
#include <iostream>
#include "../Variant/Variant.h"

int prueba_variant() {
    try {
        // Crear variantes con diferentes tipos
        Variant simbolo(Symbol, "MiSimbolo");
        Variant numero(Number, "42");
        Variant cadena(Cadena, "Hola Mundo");

        // Crear una lista de variantes
        Variant lista(List);
        lista.list.push_back(simbolo);
        lista.list.push_back(numero);
        lista.list.push_back(cadena);

        // Mostrar el contenido usando imprimir()
        std::cout << "Demostración de imprimir():\n";
        simbolo.imprimir();
        numero.imprimir();
        cadena.imprimir();
        lista.imprimir();

        // Convertir a string
        std::cout << "\nDemostración de to_string():\n";
        std::cout << simbolo.to_string() << "\n";
        std::cout << numero.to_string() << "\n";
        std::cout << cadena.to_string() << "\n";
        std::cout << lista.to_string() << "\n";

        // Convertir a JSON
        std::cout << "\nDemostración de to_json_string():\n";
        std::string jsonSimbolo = simbolo.to_json_string();
        std::string jsonNumero = numero.to_json_string();
        std::string jsonCadena = cadena.to_json_string();
        std::string jsonLista = lista.to_json_string();
        std::cout << jsonSimbolo << "\n";
        std::cout << jsonNumero << "\n";
        std::cout << jsonCadena << "\n";
        std::cout << jsonLista << "\n";

        // Reconstruir desde JSON
        std::cout << "\nDemostración de from_json_string():\n";
        Variant newSimbolo = Variant::from_json_string(jsonSimbolo);
        Variant newNumero = Variant::from_json_string(jsonNumero);
        Variant newCadena = Variant::from_json_string(jsonCadena);
        Variant newLista = Variant::from_json_string(jsonLista);

        // Mostrar las variantes reconstruidas
        newSimbolo.imprimir();
        newNumero.imprimir();
        newCadena.imprimir();
        newLista.imprimir();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Error desconocido." << std::endl;
    }

    return 0; // Ensure the function returns an integer
}