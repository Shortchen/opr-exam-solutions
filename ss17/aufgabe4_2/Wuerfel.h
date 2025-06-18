 #pragma once
#include "Koerper3D.h"
class Wuerfel : public Koerper3D
{
    private:
    float a;
    public:
    Wuerfel(float f) : a(f) {}
    float volumen() const { return a*a*a; }
    float oberflaeche() const { return 6*a*a; };
    protected:
    virtual void ausgeben(ostream& os) const {
        os << "W: " <<  "a= " << a;
    }
};
