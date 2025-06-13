#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

struct A {
    int i;
    A(int i) : i(i) { cout << "A()\n"; }
    A(A &&a) : i(a.i) { cout << "A(A&&)\n"; }
    ~A() { cout << "~A()\n"; }
};

ostream &operator<<(ostream &os, const unique_ptr<A> &z) {
    if (z == nullptr) { os << "nullptr"; }
    else { os << z->i; }
    return os;
}

void e(int i) {
    if (i == 0) { throw exception(); }
    else { throw invalid_argument(""); }
}

void f1() {
    A *z = new A(1);
    e(0);
    delete z;
    cout << "Ende f1()\n";
}

void f2() {
    unique_ptr<A> z(new A(2));
    e(1);
    cout << "Ende f2()\n";
}

int main() {
 try { f1(); } catch (const exception &e) { cout << "S\n"; }
 catch (const invalid_argument &e) { cout << "T\n"; }

 try { f2(); } catch (const invalid_argument &e) { cout << "T\n"; }
 catch (const exception &e) { cout << "S\n"; }
 unique_ptr<A> z1(new A{9});
 cout << z1 << endl;

 unique_ptr<A> z2(move(z1));

 cout << z1 << endl;

 cout << z2 << endl;
}
