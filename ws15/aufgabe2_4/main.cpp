//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <memory>
using namespace std;

struct Z {
    int n;
    Z(int n) : n(n) { cout << "Z::Z " << n << endl; }
    ~Z() { cout << "Z::~Z " << n << endl; }
    void f() { cout << "Z::f " << n << endl; }
};

int main() {
    int n = 0; {
        shared_ptr<Z> z1(new Z(++n));
        shared_ptr<Z> z2(z1);
        z1->f();
        z2->f();
    }
    Z *z3 = new Z(++n);
    unique_ptr<Z> z4(z3);
    z3->n = 99;
    z4->f();
}
