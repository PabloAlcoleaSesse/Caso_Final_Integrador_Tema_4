//
// Created by pablo on 15/12/2024.
//

#include "calculartor.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath> // Para operaciones matemáticas avanzadas como pow
#include <algorithm>
#include <unordered_map>
#include <functional>

//Definir tokens como un vector de strings, en ellos se almacenaran los tokens de la entrada
typedef std::vector<std::string> Tokens;
//Definir variables como un mapa no ordenado de strings y doubles, en ellos se almacenaran las variables y sus valores
std::unordered_map<std::string, double> variables;
//Definir funciones como un mapa no ordenado de strings y pares de enteros y funciones, en ellos se almacenaran las funciones y sus argumentos
std::unordered_map<std::string, std::pair<double, std::function<double(const std::vector<double>&)>>>functions;


//Tokenizar la entrada, convirtiendo el string de entrada en un vector de tokens
Tokens tokenize(const std::string& input) {
    Tokens tokens;
    std::istringstream stream(input);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

//Evaluar la expresión dada en notación postfija
//Utiliza una pila para manejar los operandos y operadores
double evaluate(Tokens& tokens) {
    std::stack<double> stack;

    while (!tokens.empty()) {
        std::string token = tokens.front();
        tokens.erase(tokens.begin());


        //Operadores aritmeticos
        /* Esta condicion nos permite verificar si hay suficientes valores en la pila para realizar la operacion, si no los hay se lanza un mensaje de error:
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar la (operacion en cuestion)");
            }
        */
        //Suma
        if (token == "+") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la suma");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a + b);
        }
            //Resta
        else if (token == "-") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la resta");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a - b);
        }
            //Multiplicacion
        else if (token == "*") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la multiplicacion");
            }
            double a = stack.top();
            stack.pop();
            double b = stack.top();
            stack.pop();
            stack.push(a * b);
        }
            //Division
            //Si b = 0, se lanza un mensaje de error informando que no se puede dividir por cero
        else if (token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para realizar la division");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (b == 0) {
                throw std::runtime_error("Division por cero");
            }
            stack.push(a / b);
        }
        else if (token == "%") {
            if (stack.size() < 2) {
                throw std::runtime_error("Valores insuficientes para devorlver el resto de la divison");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            if (b == 0) {
                throw std::runtime_error("Division por cero");
            }
            stack.push(fmod(a, b));
        }
        else if (token == "^") { // Potencia
            if (stack.size() < 2){
                throw std::runtime_error("Valores insuficientes para realizar la potencia");
            }
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            stack.push(pow(a, b));
        }
        //Valor absoluto
        else if (token == "abs") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar el valor absoluto");
            }
            double a = stack.top(); stack.pop();
            stack.push(abs(a));
        }
        //Operadores trigonometricos
        //Seno
        else if (token == "sin") {
            if (stack.size() < 1) {
                throw std::runtime_error("Operandos insuficientes para el seno");
            }
            double a = stack.top(); stack.pop();
            stack.push(std::sin(a));
        }
            //Coseno
        else if (token == "cos") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar el coseno");
            }
            double a = stack.top(); stack.pop();
            stack.push(cos(a));
        }
            //Tangente
        else if (token == "tan") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar la tangente");
            }
            double a = stack.top(); stack.pop();
            stack.push(tan(a));
        }
            //Cotangente
        else if (token == "cot") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar la cotangente");
            }
            double a = stack.top(); stack.pop();
            stack.push(1/tan(a));
        }
            //Secante
        else if (token == "sec") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar la secante");
            }
            double a = stack.top(); stack.pop();
            stack.push(1/cos(a));
        }
            //Cosecante
        else if (token == "csc") {
            if (stack.size() < 1){
                throw std::runtime_error("Valores insuficientes para realizar la cosecante");
            }
            double a = stack.top(); stack.pop();
            stack.push(1/sin(a));
        }

        //Operadores logicos
        else if (token == "min") {
            if (stack.size() < 2) {
                throw std::runtime_error("Operandos insuficientes para la funcion min");
            }
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            stack.push(std::min(a, b));
        }
        else if (token == "max") {
            if (stack.size() < 2) {
                throw std::runtime_error("Operandos insuficientes para la funcion max");
            }
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            stack.push(std::max(a, b));
        } else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

void calculadora() {
    std::cout << "Bienvenido a TinyLisp!" << std::endl;
    std::cout << "Operaciones matematicas basicas: Suma(+), Resta(-), Multiplicacion(*) y Division(/)"<< std::endl;
    std::cout << "Operaciones matematicas avanzadas: Modulo(%), Potencia(^) y Valor absoluto(abs)" << std::endl;
    std::cout << "Operaciones trigonometricas: Seno(sin), Coseno(cos), Tangente(tan), Cotangente(cot), Secante(sec) y Cosecante(csc)" << std::endl;
    std::cout << "Operaciones logicas: Minimo(min) y Maximo(max)" << std::endl;
    std::cout << "Para salir, escriba 'exit'" << std::endl;

    std::string input;
    while (true) {
        std::cout << "->";
        std::getline(std::cin, input);
        if (input == "exit") break;
        try {
            Tokens tokens = tokenize(input);
            std::cout << evaluate(tokens) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}