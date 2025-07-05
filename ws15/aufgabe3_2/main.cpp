//
// Created by steph on 02.07.2025.
//
#include <iostream>

struct Feld {
    // Destruktor:
    virtual ~Feld() {
    }

    // Liefert die Länge des Felds zurück:
    virtual int laenge() const = 0;

    // Klammeroperator für nicht-konstante Objekte:
    virtual double &operator[](int i) = 0;

    // Klammeroperator für konstante Objekte:
    virtual double &operator[](int i) const = 0;
};

// Feld auf den Ausgabestrom ausgeben:
std::ostream &operator<<(std::ostream &os, const Feld &feld) {
    os << "[ ";
    for (int i = 0; i < feld.laenge(); i++) {
        os << feld[i]<<" ";
    }
    os << "]";
    return os;
}

class FeldImpl : public Feld {
private:
    double *werte;
    int _laenge;

public:
    // Konstruktor:
    FeldImpl(int laenge) : _laenge(laenge) {
        werte = new double[_laenge];
        for (int i = 0; i < laenge; i++) {
            werte[i] = 0;
        }
    }

    // Destruktor:
    ~FeldImpl() {
        if (werte != nullptr) {
            delete[] werte;
        }
    }

    // Liefert die Länge des Felds zurück:
    int laenge() const {
        return _laenge;
    }

    // Klammeroperator für nicht-konstante Objekte:
    virtual double &operator[](int i) {
        return werte[i];
    }

    // Klammeroperator für konstante Objekte:
    virtual double &operator[](int i) const {
        return werte[i];
    }

    // Zuweisungsoperator mit Verschiebesemantik
    FeldImpl &operator=(FeldImpl &&f) {
        if (this != &f)
            if (werte != nullptr) {
                {
                    delete[] werte;
                }
                _laenge = f._laenge;
                werte = f.werte;
                f.werte = nullptr;
                f._laenge = 0;
            }
        return *this;
    }
};

int main() {
    Feld *feld1 = new FeldImpl(3);
    std::cout << "1: " << *feld1 << std::endl;
    for (int i = 0; i < feld1->laenge(); i++) {
        (*feld1)[i] = 10 * (i + 1);
    }
    std::cout << "2: " << *feld1 << std::endl;
    delete feld1;
    FeldImpl feld2(2), feld3(3);
    for (int i = 0; i < feld2.laenge(); i++) {
        feld2[i] = 100 * (i + 1);
    }
    for (int i = 0; i < feld3.laenge(); i++) {
        feld3[i] = 1000 * (i + 1);
    }
    std::cout << "3: " << feld2 << " " << feld3 << std::endl;
    feld2 = std::move(feld3);
    std::cout << "4: " << feld2 << " " << feld3 << std::endl;
    feld2 = std::move(feld2);
    std::cout << "5: " << feld2 << std::endl;
}
