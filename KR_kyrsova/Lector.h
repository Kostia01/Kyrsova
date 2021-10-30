#pragma once
#include <string>
#include <iostream>

class Lector
{
    std::string Surname;
    std::string Name;
    std::string patronymic;
    std::string Position;
public:
    std::string getSurname();
    std::string getName();
    std::string getPatronymic();
    std::string getPosition();
    void setSur(std::string Surname);
    void setName(std::string name);
    void setPatron(std::string patron);
    void setPosition(std::string pos);
    Lector(std::string Surname, std::string Name, std::string patronymic, std::string Position);
    Lector();
    virtual ~Lector();
    void Fill_info(Lector* arr, int size);
    virtual void Print();
    friend std::ostream& operator<<(std::ostream& os, const Lector& ocupation);
    friend std::istream& operator>>(std::istream& is, Lector& p);
};


