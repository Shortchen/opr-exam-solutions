//
// Created by steph on 02.07.2025.
//
#include <vector>
#pragma once
#include <sstream>

class A;

class B{
  private:
    string s;
  protected:
    A* a;
    std::vector<B*> Kinder;
  public:
    B(A*a = nullptr);
    A& f(const A&a) const;
    A& f(A&& a);
    B& operator +(const B* b);
    inline string t() const;
};