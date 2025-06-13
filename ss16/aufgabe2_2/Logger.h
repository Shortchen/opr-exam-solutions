#pragma once
class Float;
using namespace std;
#include <sstream>
struct Logger
{
    virtual ~Logger() {}
    virtual void log(const Float& f) = 0;
    virtual string text() const = 0 ;
};
