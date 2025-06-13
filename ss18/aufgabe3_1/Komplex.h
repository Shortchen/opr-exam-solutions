#include <iostream>

template<typename T>
struct Komplex {
    T re, im;

    Komplex(const T &re, const T &im) : re(re), im(im) {}

    template<typename S>
    Komplex(const Komplex<S> &k) {
        re = k.re;
        im = k.im;
    }
};


template<typename T>
std::ostream &operator<<(std::ostream &s, const Komplex<T> &k) {
    s << k.re << " " << k.im;
    return s;
}
