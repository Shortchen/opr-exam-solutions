#include <iostream>
#include "A.h"
#pragma once

class B : public A <float>
{
    private:
    B(const B& b);
    float f;
    //.............................................. ;
    protected:
    B(float f);
    A<float>* g(const B* const b);
    public:
    static B* erstellen(float f);
    virtual ~B() ;
    B& operator=(const B& b);
    float f(float t) const override;
    B& operator*(const B& b) ;
    friend std::istream& operator>>(std::istream& is, const B& b) ;
};
std::ostream& operator<<(std::ostream& os, const B& b) ;
