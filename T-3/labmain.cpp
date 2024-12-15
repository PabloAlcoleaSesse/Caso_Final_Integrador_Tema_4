#include "labmain.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "labmain.h"

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox {
    void new_text() {/*...*/}
    void set_text(const string& text) { cout << text << endl; }
};

ConsoleBox* consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script) {
    string script;
    FILE* f = nullptr;

    try {
        f = fopen(filename, "rb");
        if (!f) {
            cerr << "Error: No se ha podido abrir el archivo. " << filename << endl;
            return;
        }

        char buf[4001];
        size_t c;
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = '\0';
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
            cout << "\033[0m";
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        if (f)
            fclose(f);
    } catch (...) {
        cerr << "Error: Ha ocurrido una excepción leyendo este archivo" << endl;
        if (f)
            fclose(f);
    }
}

void load_script_V() {
    char filename[500];
    std::cout << "Introduce el nombre del archivo: ";
    std::cin.getline(filename, 500);
    load_script(filename, true);
}