#include <iostream>
using namespace std;
void log(const char *const s) { cout << "LOG " << s << endl; }

struct A {
    int n;
    static int z;
    const char *s;

    A(const char *s) : s(s) {
        n = z++;
        log("A");
    }

    virtual ~A() {
        log("~A");
    }

    void log(const char *const t) const {
        cout << n << s << t << endl;
    }
};

int A::z = 1;

struct B : A {
    B(const char *s) : A(s) { log("B"); }
    ~B() { log("~B"); }

    void log(const char *const t) const {
        std::cout << "#";
        A::log(t);
    }
};

struct C : B {
    C(const char *s) : B(s) {
        log("C");
    }

    ~C() {
        log("~C");
    }
};

int main() {
    A a("a");
    B b("b");
    C c("c");
    log("ENDE");
}
