#pragma once
#include "lector.h"
#include "occupation.h"
#include "iter.h"
class Shedule : public Occupation
{
protected:
    Occupation* Occup;
    int size;
public:
    Shedule();
    Shedule(int n);
    Shedule(const Shedule& a);
    ~Shedule();
    Shedule& operator=(const Shedule& a);
    void  Print();
    iter begin() { return iter(Occup); }
    iter end() { return iter(Occup + size); }

};