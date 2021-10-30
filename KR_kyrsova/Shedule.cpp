#include "Shedule.h"
#include <conio.h>
Shedule::Shedule(int n) {
    size = n;
    Occup = new Occupation[size];
    for (iter i = begin(); i != end(); ++i) {
        *i = Occup[i - begin()];
    };
}
Shedule::Shedule(const Shedule& a) {
    Occup = new Occupation[size = a.size];///////////////////
    for (iter i = begin(); i != end(); ++i)
        *i = a.Occup[i - begin()];
}
Shedule::Shedule() {
    std::cout << "Введіть кількіть елементів\n";
    std::cin >> size;
    Occup = new Occupation[size];
    for (iter i = begin(); i != end(); ++i)  *i = Occup[i - begin()];
}


Shedule::~Shedule()
{
    delete[]Occup;
    std::cout << std::endl << "Масив видалено!";
    _getch();
}

Shedule& Shedule::operator=(const Shedule& a) {
    if (this != &a) {
        delete[]Occup; Occup = new Occupation[size = a.size];
        for (iter i = begin(); i != end(); ++i) *i = a.Occup[i - begin()];
    }
    return *this;
}
void Shedule::Print() {

    for (iter i = begin(); i != end(); i++)
    {
        std::cout << Occup[i - begin()].getSubject() << " " << Occup[i - begin()].getDate() << " " << Occup[i - begin()].getPlace() << " " << Occup[i - begin()].getType() << " " << Occup[i - begin()].getTime() << std::endl;
    };
    _getch();
}
#include "Shedule.h"
