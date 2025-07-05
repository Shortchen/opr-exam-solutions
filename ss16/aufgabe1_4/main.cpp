//
// Created by steph on 02.07.2025.
//
#include <iostream>
using namespace std;

class A {
private:
    int x, y, z;

public:
    A(int x, int y) : x(x), y(y), z(0) {
    }

    A(int x, int y, int z) : x(y), y(z), z(x) {
        cout << "A(int,int,int)\n";
    }

    A(int xx, int yy, int zz, int ww) : z(y), y(2 * x), x(2 * ww) {
    }

    void log() {
        cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
    }
};

int main() {
    A a1(1, 2);
    a1.log();
    A a2 = {3, 4};
    a2.log();
    A a3 = {5, 6, 7};
    a3.log();
    A a4 = {8, 9, 10, 11};
    a4.log();
}
