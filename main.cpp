//
// Created by pablo on 14/12/2024.
//
#include <iostream>
#include "Variant/Variant.h"

int main() {
    // Ejemplo de uso
    Variant sym(Symbol, "x");
    Variant num(Number, "42");
    Variant str(Cadena, "Hola");
    Variant lst;
    lst.type = List;
    lst.list.push_back(sym);
    lst.list.push_back(num);
    lst.list.push_back(str);

    std::cout << "to_string(): " << lst.to_string() << std::endl;

    std::string json_repr = lst.to_json_string();
    std::cout << "to_json_string(): " << json_repr << std::endl;

    Variant parsed = Variant::from_json_string(json_repr);
    std::cout << "Parsed from JSON: " << parsed.to_string() << std::endl;

    return 0;
}