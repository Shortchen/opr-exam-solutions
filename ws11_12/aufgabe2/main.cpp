#include <iostream>
using namespace std;

struct P;

ostream& operator<<(ostream& os, const P& p);

struct A {
    virtual ~A() {};
    virtual void a() const = 0;
};


struct B : public A {
    private:
    const P& p;
    public:
    B(const P& p): p(p) {};
    protected:
    virtual void b() const { cout << p; };
    virtual void a() const override {};
};

struct C : public B {
    C(const P& p) : B(p){};
    void a() const override {
        cout << "B::p=";
        b();
    };
};

struct P : public B {
    int x, y;
    P() : B(*this), x(0), y(0) {};
    P(int x, int y): B(*this), x(x), y(y){};
};


ostream& operator<<(ostream& os, const P& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main()
{
    P p(10,20);
    cout << "p=" << p << endl;
    C c(p);
    cout << "c.a() liefert: ";
    c.a();
}
