
#include <iostream>
#include <vector>
using namespace std;

struct Produkt {
    virtual ~Produkt() {}

    virtual string info() const = 0;
};

struct Fabrik {
    virtual ~Fabrik() {}

    virtual Produkt* erzeuge(string const &sex) = 0;
};

class KonkretesProdukt : public Produkt {
private:
    string const _info;

public:
    KonkretesProdukt(const string &i) : _info(i) {}

    virtual string info() const override {
        // Override ist clean/good practice, aber optional
        return _info;
    }
};

struct KonkreteFabrik : public Fabrik {
private:
    vector<Produkt *> produkte;

public:
    ~KonkreteFabrik() {
        for (auto produkt: produkte) {
            cout << "Lösche Produkte: " << produkt->info() << endl;
            delete produkt;
        }
    }

    Produkt *erzeuge(const string &s) {
        Produkt *p = new KonkretesProdukt(s);
        produkte.push_back(p);
        return p;
    }
};

int main() {
    Fabrik *fabrik = new KonkreteFabrik();
    Produkt *p1 = fabrik->erzeuge("p1");
    cout << "Erzeugtes Produkt: " << p1->info() << endl;
    Produkt *p2 = fabrik->erzeuge("p2");
    cout << "Erzeugtes Produkt: " << p2->info() << endl;
    delete fabrik;
}
