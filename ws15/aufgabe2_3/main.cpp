//
// Created by steph on 02.07.2025.
//
#include <iostream>

class H {
private:
    int id;

public:
    H(int id) : id(id) {
    }

    virtual ~H() {
    }

    virtual H &h() = 0;

    virtual const H &h() const = 0;

    void log(const char *s) const {
        std::cout << id << " " << s << std::endl;
    }
};

class A : public H {
private:
    int _id;
    static int n;

public:
    A() : H(n++) { log("A::A"); }
    ~A() { log("A::~A"); }
    void f() { log("A::f"); }

    H &h() {
        log("A::h");
        return *this;
    }

    const H &h() const {
        log("A::h const");
        return *this;
    }
};

class B : public H {
private:
    static int n;

protected:
    int _id;

public:
    B() : H(--n) { log("B::B"); }
    virtual ~B() { log("B::~B"); }
    void f() { log("B::f"); }
    virtual void b() { log("B::b"); }

    H &h() {
        log("B::h");
        return *this;
    }

    const H &h() const {
        log("B::h const");
        return *this;
    }
};

class C : public B {
public:
    C() { log("C::C"); }
    ~C() { log("C::~B"); }
    void f() { log("C::f"); }
    void b() { log("C::b"); }

    H &h() {
        log("C::h");
        A *a = new A();
        return *a;
    }
};

int A::n = 10;
int B::n = 100;

int main() {
    const A a1;
    C c1;
    const H *h[] = {
        &a1, &c1
    };
    for (const H *e: h) {
        e->h();
    }
    B *b = new C();
    H &a2 = b->h();
    b->b();
    b->f();
    h[0] = b;
    h[1] = &a2;
    for (const H *e: h) {
        delete e;
    }
}
