#include "Float.h"
#include "Logger.h"

int Float::objektZaehler = 0;
Logger *Float::logger = NULL;

ostream &operator<<(ostream &os, const Float &f) {
    os << "{#" << f.id() << "->" << f.wert() << "}";
    return os;
}
