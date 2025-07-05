//
// Created by steph on 02.07.2025.
//
#include <string>
class Ausnahme {
private:
    std::string s;
public:
    Ausnahme(const std::string& s)
   : s("Ausnahme: "+s) {}
    const std::string& info() const
    { return s; }
};

