#include <iostream>
using namespace std;
struct A {
    int i;
    A(int i) : i(i) {}
    A(const A &a) : i(a.i) {}
    A &operator=(int i) {
        this->i = i;
        return *this;
    }
    A &operator-() {
        i = -i;
        return *this;
    }
    A operator-() const { return A{-i}; }
    A &operator-(const A &a) {
        i -= a.i;
        return *this;
    }
    A operator-(const A &a) const { return A{i - a.i}; }
};
ostream &operator<<(ostream &os, const A &a) {
    os << a.i;
    return os;
}
int main() {
    A a1{1};
    const A a2{2};
    A a3{-a1};
    cout << a1 << " " << a3 << endl;
    A a4{-a2};
    cout << a2 << " " << a4 << endl;
    a4 = 4;
    a1 = -a4;
    cout << a1 << " " << a4 << endl;
    A a5 = a1 - a4;
    cout << a1 << " " << a4 << " " << a5 << endl;
    const A a6{11};
    cout << -(a2 - a6);
}
