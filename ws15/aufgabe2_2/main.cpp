//
// Created by steph on 02.07.2025.
//
#include <iostream>
#include <string>

struct S {
    S() { std::cout << "S"; }
    virtual std::string typ() const { return "S"; }
};

struct T : S {
    T() { std::cout << "T"; }
    virtual std::string typ() const { return "T"; }
};

void log(const char *s1, const std::string &s2) {
    std::cout << s1 << s2 << std::endl;
}

int main() {
    try { throw S(); } catch (const S &e) { log("-S", e.typ()); }
    catch (const T &e) { log("-T", e.typ()); }
    try { throw T(); } catch (const S &e) { log("-S", e.typ()); }
    catch (const T &e) { log("-T", e.typ()); }
    try { throw T(); } catch (const T &e) { log("-T", e.typ()); }
    catch (const S &e) { log("-S", e.typ()); }
    try { throw S(); } catch (S e) { log("-S", e.typ()); }
    catch (T e) { log("-T", e.typ()); }
    try { throw T(); } catch (T e) { log("-T", e.typ()); }
    catch (S e) { log("-S", e.typ()); }
    try { throw T(); } catch (S e) { log("-S", e.typ()); }
    catch (T e) { log("-T", e.typ()); }
}
