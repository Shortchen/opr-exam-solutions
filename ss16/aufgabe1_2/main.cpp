//
// Created by steph on 02.07.2025.
//
#include <iostream>

template<typename T, int N = 5, int zaehler = 1, int nenner = 2>
struct A {
    T x[N];

    A() {
        for (auto i = 0; i < N; i++) {
            x[i] = ((T) i * zaehler) / nenner;
        }
    }

    void log() {
        for (auto i: x) {
            std::cout << i << "\t";
        }
        std::cout << std::endl;
    }
};

template<typename T=int>
struct B : A<T, 6> {
};

int main() {
    A<int> a1;
    a1.log();
    A<float, 4> a2;
    a2.log();
    A<double, 3, 4> a3;
    a3.log();
    B<float> b1;
    b1.log();
    B<> b2;
    b2.log();
}
