#pragma once
#include "Koerper.h"

class Koerper2D : public Koerper {
public:
    int anzahlDimensionen() const { return 2; };

    float virtual flaeche() const = 0;

    float virtual umfang() const = 0;
};
