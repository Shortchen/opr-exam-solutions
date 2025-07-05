//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>

struct S {
    std::string name;
    std::string text;

    S(std::string name) : name(name) {
    }

    S &operator=(const S &a) {
        text += "=";
        std::cout << name << "=" << a.name << ": " << text + "\n";
        return *this;
    }

    S &operator-(const S &a) {
        text += "-";
        std::cout << name << "-" << a.name << ": " + text + "\n";
        return *this;
    }
};

int main() {
    S a1("a"), b1("b"), c1("c");
    S a2("a"), b2("b"), c2("c");
    S a3("a"), b3("b"), c3("c");
    S a4("a"), b4("b"), c4("c");
    a1 - b1 - c1;
    a2 = b2 = c2;
    a3 - b3 = c3;
    a4 = b4 - c4;
}
