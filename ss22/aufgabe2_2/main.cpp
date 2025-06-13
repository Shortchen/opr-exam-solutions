#include <iostream>
using namespace std;

template<typename T, int N = 2, int m = 1>
struct A {
    T x[N];

    A(const T &start = 0) {
        for (auto i = 0; i < N; i++) { x[i] = start + i * m; }
    }

    A(const A &a) {
        cout << "A ";
        for (auto i = 0; i < N; i++) { x[i] = a.x[i]; }
    }
};

template<typename S, int Q, int R>
ostream &operator<<(ostream &os, const A<S, Q, R> &a) {
    for (auto i: a.x) { os << i << " "; }
    return os;
}

template<typename T=int>
struct B : A<T, 3> {
    B(const T &start) : A<T, 3>(start) {}

    B(const B &b) : A<T, 3>(b) {
        cout << "B ";
    }
};

int main() {
    A<int> a1;
    cout << a1 << endl;
    A<float, 2> a2(1.1);
    cout << a2 << endl;
    A<double, 3, 4> a3;
    cout << a3 << endl;
    B<float> b1(1.2);
    cout << b1 << endl;
    B<> b2(2.3);
    cout << b2 << endl;
    B<> b3 = b2;
    cout << b3 << endl;
}
