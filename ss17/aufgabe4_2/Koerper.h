 #pragma once
#include <ostream>
using namespace std;
class Koerper {
public:
    virtual ~Koerper() {}
    int virtual anzahlDimensionen() const = 0;
    protected:
    void virtual ausgeben(std::ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Koerper& k);
};
ostream& operator<<(ostream& os,const Koerper& k) {
    k.ausgeben(os);
    return os;
}
