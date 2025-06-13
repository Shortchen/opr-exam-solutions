#include <iostream>
using namespace std;

struct A {
    virtual ~A() {}

    void f() { log("A", "f"); }

    virtual void g() = 0;

    static void log(const string &s1, const string &s2) { cout << s1 << "::" << s2 << "\n"; }
};

struct B : A {
    ~B() { log("B", "~B"); }
    void f() { log("B", "f"); }
    void g() { log("B", "g"); }
};

struct C : public B {
    virtual ~C() { log("C", "~C"); }
    virtual void f() { log("C", "f"); }
    virtual void g() { log("C", "g"); }
};

int main() {
    A::log("Log", "Test");
    B b;
    A *ab = &b;
    B *bc = new C();
    cout << "ab->f(): ";
    ab->f();
    cout << "ab->g(): ";
    ab->g();
    cout << "bc->f(): ";
    bc->f();
    cout << "bc->g(): ";
    bc->g();
    delete bc;
    cout << "Ende\n";
}
