#pragma once
#include "Logger.h"
#include "Float.h"
#include <sstream>
using namespace std;

class LoggerImpl : public Logger {
private:
 stringstream ss;
 int zaehler = 0;

public:
 void log(const Float &f) {
  zaehler++;
  ss << zaehler << ": " << f << endl;
 }

 virtual string text() const {
  return ss.str();
 }
};
