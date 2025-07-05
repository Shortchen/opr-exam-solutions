//
// Created by steph on 02.07.2025.
//
////////////////////////////////
#include "Matrix.h"
////////////////////////////////
#include <iostream>
using namespace std;
int main() {
    M<int> m1("m1",3,2,1);
    M<int> m2("m2",2,3,2);
    M<int> m3("m3");
    M<int> m4("m4",3,2,4);
    M<int> m5(m1);
    cout << m1 << m2 << m3 << m4 <<
    m5;
    try { m1.elem(10,10); }
    catch(const Ausnahme& a) { cout
    << a.info() << endl; }
    try { m3 = m1 + m2; }
    catch(const Ausnahme& a) { cout
    << a.info() << endl; }
    try { m5 = m1 + m4; }
    catch(const Ausnahme& a) { cout
    << a.info() << endl; }
    cout << m5;
}
