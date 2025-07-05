//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>
using namespace std;

struct A {
    string name;
    A *a1;
    static A *a2;

    A(string name) : name(name) {
        a1 = nullptr;
        a2 = this;
    }

    A *f() {
        a1 = this;
        return a1;
    }

    A *f() const {
        return a2;
    }

    void log() const {
        if (a1 == nullptr) {
            cout << name << " 0 " << a2->name << endl;
        } else {
            cout << name << " " << a1->name << " " << a2->name << endl;
        }
    }
};

A *A::a2 = nullptr;

int main() {
    const A a1("1");
    A a2("2");

    a1.log();
    a1.f()->log();
    a1.log();
    a2.log();
    a2.f()->log();
    a2.log();
}
