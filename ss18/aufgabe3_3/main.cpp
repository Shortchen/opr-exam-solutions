#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Nachricht {
private:
    const string s;
    public:
    Nachricht(const string& s) : s(s) {}
    string text() const {return s;}
    };
struct Beobachter {
    virtual ~Beobachter() {};
    virtual void benachrichtigen(const Nachricht& nachricht) = 0;
    };
class BeobachterImpl : public Beobachter {
    private:
    string name;
    public:
    BeobachterImpl(const string& name) : name(name) {}
    virtual void benachrichtigen(const Nachricht& nachricht) {
        cout << name << " empfängt Nachricht: " << nachricht.text()<< endl;
    }
};
class Subjekt {
private:
    vector<Beobachter*> beobachter;
    public:
    void beobachterHinzufuegen(Beobachter& b) {
        beobachter.push_back(&b);
        }
    void alleBenachrichtigen(const Nachricht& nachricht) {
        for(auto b : beobachter) {
            b->benachrichtigen(nachricht);
        }
    }
};
int main() {
    Subjekt subjekt;
    BeobachterImpl b1("b1");
    BeobachterImpl b2("b2");
    subjekt.beobachterHinzufuegen(b1);
    subjekt.beobachterHinzufuegen(b2);
    Nachricht nachricht("Hallo Beobachter");
    subjekt.alleBenachrichtigen(nachricht);
}
