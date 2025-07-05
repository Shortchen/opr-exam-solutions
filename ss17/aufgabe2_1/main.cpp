//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>

struct Klasse {
    std::string name;

    Klasse(std::string name) : name(name) {
    }

    Klasse(const Klasse &k) {
        std::cout << name << "-" << k.name <<
                "\n";
    }

    Klasse &operator=(const Klasse &a) {
        std::cout << name << " = " << a.name << "\n";
        return *this;
    }

    Klasse &operator*(const Klasse &a) {
        std::cout << name << " * " << a.name << "\n";
        return *this;
    }
};

int main() {
    Klasse a("a"), b("b"), c("c");
    a = b = c;
    a * b * c;
    a = b * c;
    a * b = c;
    Klasse d = a;
}
