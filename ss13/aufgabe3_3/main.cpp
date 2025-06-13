#include <iostream>

struct A {
    void f(const int &i) { log("A::f(const int&)"); }
    void f(int &i) { log("A::f(int&)"); }
    void f(const int &i) const { log("A::f(const int&) const"); }
    void f(int &i) const { log("A::f(int&) const"); }

    void log(const char *const s) const {
        std::cout << s << std::endl;
    }
};

int main() {
    A a1;
    const A a2;
    int i1 = 0;
    const int i2 = 0;
    a1.f(i1);
    a2.f(i1);
    a1.f(i2);
    a2.f(i2);
}
