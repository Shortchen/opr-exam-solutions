#include <iostream>
#include <sstream>
using namespace std;

struct A {
    string s;

    virtual void f(const string &s, int i) = 0;

    void operator%(ostream &os) const { os << s << endl; };
};

struct B : A {
    void f(const string &t, int i) {
        stringstream str;
        str << i << "B" << t;
        s = str.str();
    }
};

struct C : A {
    void f(const string &t, int i) {
        stringstream str;
        str << i << "C" << t;
        s = str.str();
    }
};

template<typename T, const int N>
struct D {
    T t;

    D(string s) {
        t.f(s, N);
        t % cout;
    }
};

struct E : D<B, 7> {
    E(string s) : D(s) {
    }
};

int main() {
    B b;
    b.f("b", 9);
    D<C, 5> d1("d1");
    D<B, 3> d2("d2");
    E e("e");
}

