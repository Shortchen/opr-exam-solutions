#include "Float.h"
#include "LoggerImpl.h"

int main() {
    LoggerImpl logger;
    Float::logger = &logger;
    Float f1(10), f2(22);
    cout << "f1: " << f1;
    cout << "\nf2: " << f2;
    Float f3 = f2 - f1;
    cout << "\nf3=f2-f1: " << f3;
    Float f4 = -f2;
    cout << "\nf4=-f3: " << f4;
    Float f5;
    f5 = f2 - (-f1);
    cout << "\nf5=f2-(-f1): " << f5;
    f1 -= f2;
    cout << "\nf1-=f2: " << f1;
    cout << endl << logger.text();
}
