//
// Created by Pablo Alcolea Sesse on 7/12/24.
//

#ifndef VARIANT_H
#define VARIANT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <variant>
#include <type_traits>
#include "../json11/json11.hpp"
#include <stdexcept>

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno {}; // Minimal definition of Entorno

class Variant {
public:
    typedef Variant(*proc_type)(const std::vector<Variant>&);
    typedef std::vector<Variant>::const_iterator iter;
    typedef std::map<std::string, Variant> map;

    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    // Add a variant type to hold different types of values
    using Simbolo = std::string;
    using Numero = double;
    using Lista = std::vector<Variant>;
    using Procedimiento = Variant(*)(const std::vector<Variant>&);

    std::variant<Simbolo, Numero, Lista, Procedimiento> value;

    Variant(variant_type type = Symbol) : type(type), env(nullptr), proc(nullptr) {}
    Variant(variant_type type, const std::string& val) : type(type), val(val), env(nullptr), proc(nullptr) {}
    Variant(proc_type proc) : type(Proc), proc(proc), env(nullptr) {}

    // Imprime el valor de la instancia
    void imprimir() const;
    // Convierte la instancia a una cadena legible
    std::string to_string();

    // Convierte la instancia a una cadena JSON
    std::string to_json_string();

    // Crea una instancia de Variant desde una cadena JSON
    static Variant from_json_string(std::string sjson);

    // Parsea un objeto json11::Json a un Variant
    static Variant parse_json(const json11::Json &job);

};

#endif //VARIANT_H