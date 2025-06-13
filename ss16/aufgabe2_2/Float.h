#pragma once
#include "Logger.h"
#include <iostream>
using namespace std;

class Float {
private:
    float _wert;
    int _id;
    static int objektZaehler;

public:
    static Logger *logger;

    Float(float wert = 0) : _wert(wert), _id(++objektZaehler) {
        logger->log(*this);
    }

    Float operator-(const Float &f) const {
        return _wert - f._wert;
    }

    Float operator-() const {
        return -_wert;
    }

    void operator-=(const Float &f) {
        _wert -= f._wert;
        logger->log(*this);
    }

    int id() const { return _id; }

    float wert() const {
        return _wert;
    }
};

ostream &operator<<(ostream &os, const Float &f); // hier war ehemalig: int Float::objektZaehler = 0;
