#pragma once
#include <string>
#include <iostream>

class Group
{
    std::string group;
    std::string Potok;
    int kol_stud;
public:
    std::string getGroup();
    std::string getPotok();
    int getStud();
    void setGroup(std::string group);
    void setPotok(std::string Potok);
    void setStud(int kol_stud);
    Group();
    Group(std::string group, std::string Potok, int kol_stud);
    friend std::ostream& operator<<(std::ostream& os, const Group& ocupation);
    friend std::istream& operator>>(std::istream& is, Group& p);
};

