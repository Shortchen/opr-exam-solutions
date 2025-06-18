#include <iostream>
#include <vector>
#include "Rechteck.h"
#include "Wuerfel.h"
using namespace std;

int main() {
    vector<Koerper2D *> koerper2D;
    koerper2D.push_back(new Rechteck(5, 4));
    koerper2D.push_back(new Rechteck(2, 3));
    vector<Koerper3D *> koerper3D;
    koerper3D.push_back(new Wuerfel(2));
    vector<Koerper *> koerper;
    for (Koerper *k: koerper2D) {
        koerper.push_back(k);
    }
    for (Koerper *k: koerper3D) {
        koerper.push_back(k);
    }
    for (Koerper2D *k: koerper2D) {
        cout << *k << ", F=" << k->flaeche() << ", U=" << k->umfang() << endl;
    }
    for (Koerper3D *k: koerper3D) {
        cout << *k << ", V=" << k->volumen() << ", O=" << k->oberflaeche() << endl;
    }
    for (Koerper *k: koerper) {
        cout << "delete " << k->anzahlDimensionen() << "-d " << *k << endl;
        delete k;
    }
}
