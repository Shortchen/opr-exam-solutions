//
// Created by steph on 02.07.2025.
//
#include <iostream>
using namespace std;

class A {
private:
    int _id;
    static int n;

public:
    A() : _id(n++) { cout << "A::A " << _id << endl; }
    ~A() { cout << "A::~A " << _id << endl; }
    int id() const { return _id; }
    virtual void f() { cout << "A::f\n"; }
    void f() const { cout << "A::f const\n"; }
    void g() { cout << "A::g\n"; }
};

int A::n = 0;

class B : public A {
protected:
    const A *adr;

public:
    B() { cout << "B::B " << id() << endl; }

    B(const A *a) : adr(a) {
        cout << "B::B(const A&) " << id() << " " << adr->id() << endl;
    }

    virtual
    ~B() {
        cout << "B::~B " << id() << endl;
    }

    void f() {
        cout << "B::f\n";
    }

    void g() {
        cout << "B::g\n";
    }
};

struct C : B {
};

int main() {
    A *z1 = new B();
    z1->f();
    z1->g();
    const A *z2 = z1;
    z2->f();
    B *z3 = new B(z2);
    B *z4 = new C;
    delete z1;
    delete z3;
    delete z4;
}
