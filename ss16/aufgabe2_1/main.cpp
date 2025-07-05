//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
struct Eimer
{
    void f()
    {
        cout << "Eimer ausleeren\n";
    }
};
class Traeger
{
private:
    Traeger* naechster;
    Eimer* eimer;
    string name;
public:
    Traeger(const string& name, Traeger* naechster = nullptr)
    : naechster(naechster), eimer(nullptr), name(name) {}
    void ueberreichen(Eimer* eimer)
    {
        cout << name << " erhält Eimer\n";
        this->eimer = eimer;
        }
    Traeger* weitergeben()
    {
        if (eimer == nullptr)
        {
            throw logic_error("Träger " + name + " hat keinen Eimer");
        }
        if(naechster==nullptr)
        {
            eimer->f();
            }
        else
        {
            cout << name << " übergibt Eimer an " << naechster->name <<
           "\n";
            naechster->ueberreichen(eimer);
            }
        eimer = nullptr;
        return naechster;
    }
};
int main()
{
    Eimer eimer;
    Traeger t3("t3"), t2("t2", &t3), t1("t1", &t2);
    t1.ueberreichen(&eimer);
    Traeger* traeger = &t1;
    while(traeger!=nullptr)
    {
        traeger = traeger->weitergeben();
    }
    try
    {
        t1.weitergeben();
    }
    catch(const exception & e)
    {
        cout << "Ausnahme gefangen: " << e.what();
    }
}
