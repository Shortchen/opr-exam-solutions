//
// Created by steph on 02.07.2025.
//
#pragma once
#include "Ausnahme.h"
#include <iostream>
using namespace std;

template<typename T>
class M {
private:
    string s; // Name
    T **e; // Matrixelemente
    ////////////////////////////////
    T wert, nx, ny;
    ////////////////////////////////
public:
    M(const string &s = "", int nx = 0, int ny = 0, T wert = 0)
    ////////////////////////////////
    : s(s), nx(nx), ny(ny), wert(wert) {
        ////////////////////////////////
        e = new T*[nx];
        ////////////////////////////////
        for (int x = 0; x < nx; x++) {
            ////////////////////////////////
            e[x] = new T[ny];
            ////////////////////////////////
            for (int y = 0; y < ny; y++) {
                ////////////////////////////////
                e[x][y] = wert;
                ////////////////////////////////
            }
        }
    }

    M(const M &m) : s(m.s), e(nullptr), nx(0), ny(0) {
        kopieren(m);
    }

    virtual ~M() {
        loeschen();
    }

    M &operator=(const M &m) {
        if (this != &m) {
            ////////////////////////////////
            kopieren(m);
            ////////////////////////////////
        }
        ////////////////////////////////
        return *this;
        ////////////////////////////////
    }

    T elem(int x, int y) const {
        if (x >= nx || y >= ny) {
            ////////////////////////////////
            throw Ausnahme("M: Ausserhalb des Bereichs");
            ////////////////////////////////
        }
        ////////////////////////////////
        return e[x][y];
        ////////////////////////////////
    }

    string name() const {
        return s;
    }

    int dimX() const { return nx; }
    int dimY() const { return ny; }

    virtual M operator+(const M &m) {
        if (nx != m.nx || ny != m.ny) {
            ////////////////////////////////
            throw Ausnahme("M-Addition: falsche Dimension");
            ////////////////////////////////
        }
        M summe("summe", nx, ny);
        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                ////////////////////////////////
                summe.e[x][y] = this->e[x][y] + m.e[x][y];
                ////////////////////////////////
            }
        }
        ////////////////////////////////
        return summe;
        ////////////////////////////////
    }

private:
    void loeschen() {
        for (int i = 0; i < nx; i++) {
            ////////////////////////////////
            delete[] e[i];
            ////////////////////////////////
        }
        ////////////////////////////////
        delete[] e;
        ////////////////////////////////
        e = nullptr;
    }
    ////////////////////////////////
    void kopieren(const M &m);
    ////////////////////////////////
};

template<typename T>
void M<T>::kopieren(const M &m) {
    if (nx == m.nx && ny == m.ny) {
        for (int x = 0; x < nx; x++) {
            for (int y = 0; y < ny; y++) {
                ////////////////////////////////
                this->e[x][y] = m.e[x][y];
                ////////////////////////////////
            }
        }
    } else {
        loeschen();
        nx = m.nx;
        ny = m.ny;
        ////////////////////////////////
        e = new T *[nx];
        ////////////////////////////////
        for (int x = 0; x < nx; x++) {
            ////////////////////////////////
            e[x] = new T[ny];
            ////////////////////////////////
            for (int y = 0; y < ny; y++) {
                ////////////////////////////////
                this->e[x][y] = m.e[x][y];
                ////////////////////////////////
            }
        }
    }
}

template<typename T>
////////////////////////////////
ostream &operator<<(ostream &os, const M<T> &m) {
    ////////////////////////////////
    os << m.name() << " = [";
    for (int y = 0; y < m.dimY(); y++) {
        os << "( ";
        for (int x = 0; x < m.dimX(); x++) {
            ////////////////////////////////
            os << m.elem(x, y)
                    << " ";
            ////////////////////////////////
        }
        os << ")";
    }
    os << "]\n";
    return os;
}
