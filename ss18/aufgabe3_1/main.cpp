#include "Komplex.h"
using namespace std;

int main() {
    Komplex<double> k1(1.1, 2.2);
    const Komplex<int> k2(3, 4);
    Komplex<int> k3(k1);
    Komplex<double> k4(k2);
    Komplex<double> k5 = k2;
    cout << "k1: " << k1 << endl;
    cout << "k2: " << k2 << endl;
    cout << "k3: " << k3 << endl;
    cout << "k4: " << k4 << endl;
    cout << "k5: " << k5 << endl;
}
