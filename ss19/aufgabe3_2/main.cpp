#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct A {
    const T x;
    A(const T &y) : x(y) {}
};

template<typename T>
ostream &operator<<(ostream &cout, const A<T> &a) {
    cout << a.x;
    return cout;
};

template<typename T, typename S>
struct B : public A<T> {
    S const y;
    const A<S> a;
    B(const T &t, const S &s1, const S &s2) : A<T>(t), y(s1), a(s2) {
    };
};

template<typename T, typename S>
ostream &operator<<(ostream &os, const B<T, S> &Q) {
    os << Q.x << " " << Q.y << " " << Q.a;
    return os;
};

int main() {
    A<int> a = 1;
    cout << a << endl;
    B<string, float> b = {"xyz", 2.6, 1.8};
    cout << b << endl;
}
