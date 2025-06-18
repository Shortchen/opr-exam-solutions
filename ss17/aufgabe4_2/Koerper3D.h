#pragma once
#include "Koerper.h"

class Koerper3D : public Koerper {
public:
    int anzahlDimensionen() const { return 3; };

    float virtual volumen() const = 0;

    float virtual oberflaeche() const = 0;
};
