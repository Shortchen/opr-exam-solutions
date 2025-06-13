#include <iostream>
using namespace std;

struct A {
    void f() {
        cout << "A::f\n";
        g();
        h();
    }

    virtual void g() { cout << "A::g\n"; }
    void h() { cout << "A::h\n"; }
};

struct B : A {
    void g() { cout << "B::g\n"; }
    virtual void h() { cout << "B::h\n"; }
};

struct C : B {
    virtual void g() { cout << "C::g\n"; }
    virtual void h() const { cout << "C::h\n"; }
};

int main() {
    B b;
    C c;
    B &z = c;
    b.f();
    z.g();
    z.h();
    c.f();
}
