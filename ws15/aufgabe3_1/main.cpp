//
// Created by steph on 02.07.2025.
//
#include <iostream>
using namespace std;

template<typename T>
class Zahl {
private:
    T zahl;

public:
    Zahl(const T &z = T()) : zahl(z) {
    }

    inline T wert() const;

    template<typename S>
    friend Zahl<S> operator+(const Zahl<S> &z1, const Zahl<S> &z2);
};

template<typename T>
T Zahl<T>::wert() const {
    return zahl;
}

template<typename T>
Zahl<T> operator +(const Zahl<T> &z1, const Zahl<T> &z2) {
    Zahl<T> summe;
    summe.zahl = z1.zahl + z2.zahl;
    return summe;
}

class Integer : public Zahl<int> {
public:
    Integer(int z) : Zahl<int>(z) {
    }
};

int main() {
    Zahl<int> a, b(1);
    Zahl<int> c = a + b;
    cout << c.wert() << endl;
    Integer d(2), e(3);
    cout << operator+(d, e).wert() << endl;
}
