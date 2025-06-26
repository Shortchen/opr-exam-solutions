#include <iostream>
using namespace std;
struct A;
struct B;
struct C;
struct A {
    int i;
    void log() const { cout << i << endl; }
    explicit operator int() const { return i; }
};
struct B : A {
    B(int j = 1);
    B(const C &);
    explicit operator int() const { return -i; }
};
struct C : A {
    C(const B &);
    C(const A &, const A &);
};
B::B(int j) { i = 2 * j; }
B::B(const C &c) { i = 3 * c.i; }
C::C(const B &b) { i = 4 * b.i; }
C::C(const A &a1, const A &a2) { i = int(a1) - int(a2); }
int main() {
    B b1{};
    b1.log();
    C c1{b1};
    c1.log();
    C c2{b1, c1};
    c2.log();
    int i = int(c2);
    B b2{i};
    b2.log();
    B b3{c2};
    b3.log();
    cout << int(b3);
}
