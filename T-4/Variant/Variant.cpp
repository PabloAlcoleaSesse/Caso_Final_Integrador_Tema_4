//
// Created by Pablo Alcolea Sesse on 7/12/24.
//
//
// Created by Pablo Alcolea Sesse on 7/12/24.
//

#include "Variant.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <variant>
#include <type_traits>
#include "../json11/json11.hpp"






void Variant::imprimir() const {
    std::visit([](const auto& val) {
        using T = std::decay_t<decltype(val)>;
        if constexpr (std::is_same_v<T, Simbolo>) {
            std::cout << "Simbolo: " << val << std::endl;
        } else if constexpr (std::is_same_v<T, Numero>) {
            std::cout << "Numero: " << val << std::endl;
        } else if constexpr (std::is_same_v<T, Lista>) {
            std::cout << "Lista: [ ";
            for (const auto& item : val) {
                item.imprimir();
            }
            std::cout << "]" << std::endl;
        } else if constexpr (std::is_same_v<T, Procedimiento>) {
            std::cout << "Procedimiento: (puntero a funcion)" << std::endl;
        }
    }, value);
}

std::string Variant::to_string() {
    switch (type) {
        case Symbol:
            return "Symbol: " + val;
        case Number:
            return "Number: " + val;
        case Cadena:
            return "Cadena: " + val;
        case List: {
            std::string result = "List: (";
            for (size_t i = 0; i < list.size(); ++i) {
                result += list[i].to_string();
                if (i < list.size() - 1) result += ", ";
            }
            result += ")";
            return result;
        }
        case Proc:
            return "Proc: <procedure>";
        case Lambda:
            return "Lambda: <lambda>";
        default:
            return "Unknown";
    }
}

std::string Variant::to_json_string() {
    using namespace json11;
    Json::object obj;
    // Definimos la clave "type" según el tipo
    switch (type) {
        case Symbol:
            obj["type"] = "Symbol";
            obj["value"] = val;
            break;
        case Number:
            obj["type"] = "Number";
            obj["value"] = val;
            break;
        case Cadena:
            obj["type"] = "Cadena";
            obj["value"] = val;
            break;
        case List: {
            obj["type"] = "List";
            std::vector<Json> arr;
            for (auto &item : list) {
                // Parsear cada elemento a JSON
                std::string err;
                arr.push_back(json11::Json::parse(item.to_json_string(), err));
            }
            obj["value"] = arr;
            break;
        }
        case Proc:
            obj["type"] = "Proc";
            obj["value"] = "null";
            break;
        case Lambda:
            obj["type"] = "Lambda";
            obj["value"] = "null";
            break;
        default:
            obj["type"] = "Unknown";
            obj["value"] = "null";
            break;
    }
    Json j(obj);
    return j.dump();
}

Variant Variant::from_json_string(std::string sjson) {
    std::string err;
    auto json_obj = json11::Json::parse(sjson, err);
    if (!err.empty()) {
        // Error al parsear JSON, retornar un Symbol vacío como fallback
        return Variant(Symbol, "");
    }
    return parse_json(json_obj);
}

Variant Variant::parse_json(const json11::Json &job) {
    // Esperamos un objeto con "type"
    std::string type_str = job["type"].is_string() ? job["type"].string_value() : "Unknown";
    Variant v;

    if (type_str == "Symbol") {
        v.type = Symbol;
        v.val = job["value"].string_value();
    } else if (type_str == "Number") {
        v.type = Number;
        v.val = job["value"].string_value();
    } else if (type_str == "Cadena") {
        v.type = Cadena;
        v.val = job["value"].string_value();
    } else if (type_str == "List") {
        v.type = List;
        // value debe ser un array
        if (job["value"].is_array()) {
            for (auto &elem : job["value"].array_items()) {
                v.list.push_back(parse_json(elem));
            }
        }
    } else if (type_str == "Proc") {
        v.type = Proc;
        // Proc no almacena valor directo
    } else if (type_str == "Lambda") {
        v.type = Lambda;
        // Lambda no almacena valor directo
    } else {
        // Caso desconocido
        v.type = Symbol;
        v.val = "";
    }

    return v;
}


