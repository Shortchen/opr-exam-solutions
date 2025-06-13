 #include <iostream>
using namespace std;
struct A {
    static int n;
    const int id;
    char* x;
    A(int i) : id(++n) {
        cout << "A(int) " << id << "\n";
        x = new char(i);
    }
    A(const A& a) : id(++n) {
        cout << "A(const A&) " << id << "\n";
        x = new char(*(a.x));
    }
    A(A&& a) : id(++n) {
        cout << "A(A&&) " << id << "\n";
        x = a.x;
        a.x = nullptr;
    }
    virtual ~A() {
        cout << "~A() " << id << "\n";
        if(x!=nullptr) { delete x; }
    }
    A& operator=(const A& a) {
        cout << "operator=(constA&) " << id << " " << a.id << endl;
        if(&a!=this) {
            if(x==nullptr) { x = new char(*(a.x)); }
            else { *x = *(a.x); }
        }
        return *this;
    }
    A& operator=(A&& a) {
        cout << "operator=(constA&&) " << id << " " << a.id << endl;
        if(&a!=this) {
            if(x!=nullptr) { delete x; }
            x = a.x;
            a.x = nullptr;
        }
        return *this;
    }
};
int A::n = 0;
ostream& operator<<(ostream& os, const A& a) {
    os << a.id << " ";
    if(a.x!=nullptr) { os << *(a.x); }
    return os;
}
int main() {
    A a1 = {'X'};
    cout << a1 << endl;
    A a2 = {a1};
    cout << a2 << endl;
    A a3 = {move(a1)};
    cout << a1 << endl;
    cout << a3 << endl;
    a1 = move(a3);
    cout << a1 << endl;
    cout << a3 << endl;
    a3 = a1;
    cout << a1 << endl;
    cout << a3 << endl;
}
