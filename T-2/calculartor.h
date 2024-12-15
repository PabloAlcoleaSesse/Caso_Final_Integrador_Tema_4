//
// Created by pablo on 15/12/2024.
//

#ifndef CALCULARTOR_H
#define CALCULARTOR_H

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

// Define tokens as a vector of strings
typedef std::vector<std::string> Tokens;

// Declare the functions
Tokens tokenize(const std::string& input);
double evaluate(Tokens& tokens);
void calculadora();

#endif //CALCULARTOR_H
