//
// Created by steph on 02.07.2025.
//
#include <iostream>
using namespace std;

struct A {
    virtual A &f() {
        cout << "A::f\n";
        return *this;
    }

    const A &f() const {
        cout << "A::fc\n";
        return *this;
    }

    A &g() {
        cout << "A::g\n";
        return *this;
    }
};

struct B : A {
    virtual A &f() {
        cout << "B::f\n";
        return *this;
    }

    virtual const A &f() const {
        cout << "B::fc\n";
        return *this;
    }

    A &g() {
        cout << "B::g\n";
        return *this;
    }
};

struct C : B {
    virtual A &f() {
        cout << "C::f\n";
        return *this;
    }

    virtual const A &f() const {
        cout << "C::fc\n";
        return *this;
    }

    virtual A &g() {
        cout << "C::g\n";
        return *this;
    }
};

int main() {
    B b;
    A &ab = b;
    C c;
    B &bc = c;
    ab.f();
    ab.g();
    ab.g().f();
    bc.g();
    bc.f();
    bc.f().g();
}
