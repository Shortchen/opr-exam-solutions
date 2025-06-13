 #include <iostream>
using namespace std;
void log(const string& s) {
    cout << s << " ";
}
struct A {};
struct B : A {};
void a() {
    log("a1"); throw A(); log("a2");
}
void b() {
    log("b1"); throw B(); log("b2");
}
void f() {
    try { log("f1"); a(); log("f2"); }
    catch(const A& e) { log("f3"); }
}
void g() {
    try { log("g1"); a(); log("g2"); }
    catch(const B& e) { log("g3"); }
}
void h() {
    try { log("h1"); b(); log("h2"); }
    catch(const A& e) { log("h3"); }
}
void k() {
    try { log("k1"); b(); log("k2"); }
    catch(const B& e) { log("k3"); }
}
int main() {
    try { log("m11"); f(); log("m12"); }

    catch(const B& e) { log("\nm13"); }
    catch(const A& e) { log("\nm14"); }
    log("\nm15");

    try { log("\nm21"); g(); log("m22"); }

    catch(const B& e) { log("\nm23"); }
    catch(const A& e) { log("\nm24"); }
    log("\nm25");

    try { log("\nm31"); h(); log("m32"); }

    catch(const B& e) { log("\nm33"); }
    catch(const A& e) { log("\nm34"); }
    log("\nm35");

    try { log("\nm41"); k(); log("m42"); }

    catch(const B& e) { log("\nm43"); }
    catch(const A& e) { log("\nm44"); }
    log("\nm45");
}
