#include <iostream>
using namespace std;

struct A {
    int i;
    A(int i) : i(i) { cout << "A" << i << " "; }
};

struct B {
    int i;
    B(const A &a) : i(a.i) { cout << "B" << i << " "; }
};

int main() {
    A a = 1;
    B b(2);
}
