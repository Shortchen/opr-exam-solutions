 #pragma once
#include "Koerper2D.h"
class Rechteck : public Koerper2D
{
private:
    float a, b;

public:
    Rechteck(float a, float b) : a(a), b(b) {}
    float flaeche() const { return a*b; }
    float umfang() const { return 2*(a+b); }

protected:
    virtual void ausgeben(ostream& os) const {
        os << "R: a= " << a <<" b= " << b;
    }
};
