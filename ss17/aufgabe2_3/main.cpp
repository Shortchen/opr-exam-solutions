//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>
using namespace std;
struct K;

struct Ausnahme {
    K const *const obj1;
    K const *const obj2;
    const string text;

    Ausnahme(K const *const obj1 = nullptr, K const *const obj2 =
                     nullptr, const string &text = "Undefiniert") : obj1(obj1), obj2(obj2), text(text) {
    }
};

struct K {
    string name;
    int i;

    K(const string &name, int i = 0) : name(name), i(i) {
    }

    void operator=(const K &a) {
        cout << name << " " << i << endl;
        if (this == &a) {
            throw Ausnahme(this, &a, "Selbstzuweisung");
        }
        cout << name << " " << i << " -> " << a.i << endl;
        i = a.i;
    }
};

ostream &operator<<(ostream &os, const Ausnahme &a) {
    os << a.text << " " << a.obj1->name << " " << a.obj2->name <<
            endl;
    return os;
}

int main() {
    try {
        K *d;
        K a("a", 1);
        K b("b", 2);

        K &c = a;
        try { a = c; } catch (Ausnahme &e) {
            cout << e;
        }
        try { a = b; } catch (Ausnahme e) {
            cout << e;
        }
        try { d = &b; } catch (Ausnahme &e) {
            cout << e;
        }
        try { *d = c; } catch (Ausnahme e) {
            cout << e;
        }
        try { b = *d; } catch (Ausnahme &e) {
            cout << e;
        }
        throw Ausnahme();
    } catch (Ausnahme e) {
        cout << e.text;
    }
}
