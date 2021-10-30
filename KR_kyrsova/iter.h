#pragma once
#include "Occupation.h"
class iter
{
    Occupation* i;
public:
    explicit iter(Occupation* i1 = 0) : i(i1) {};
    iter(const iter& x) : i(x.i) {};
    iter& operator=(const iter& x) { i = x.i; return *this; }
    Occupation& operator*() const { return *i; };
    iter& operator++ () { ++i; return *this; };
    iter& operator-- () { --i; return *this; };
    iter& operator++ (int) { i++; return *this; };
    iter& operator-- (int) { i--; return *this; };
    iter operator-(int n) { return iter(i - n); };
    iter operator+(int n) { return iter(i + n); };
    Occupation get_i() const { return *i; };
    bool operator!=(const iter& x)const { return i != x.i; };
    friend int operator-(const iter& x, const iter& y) { return x.i - y.i; };
};

