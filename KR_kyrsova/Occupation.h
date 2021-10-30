#pragma once
#include <string>
#include <iostream>
#include "group.h"
#include"lector.h"

class Occupation :public Lector, public Group
{
    std::string Subject;
    std::string Date;
    std::string Time;
    std::string Type;
    std::string Place;
public:
    Occupation(int kol_stud, std::string Potok, std::string group, std::string Surname, std::string Name, std::string patronymic, std::string Position, std::string Subject, std::string Date, std::string Time, std::string Type, std::string Place);
    Occupation();
    ~Occupation();
    std::string getSubject();
    std::string getDate();
    std::string getTime();
    std::string getType();
    std::string getPlace();
    std::string setSubject(std::string subject);
    std::string setDate(std::string date);
    std::string setTime(std::string time);
    std::string setType(std::string type);
    std::string setPlace(std::string place);
    void Print();
    friend std::ostream& operator<<(std::ostream& os, const Occupation& ocupation);
    friend std::istream& operator>>(std::istream& is, Occupation& p);
};

