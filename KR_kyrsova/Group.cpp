#include "Group.h"

std::string Group::getGroup()
{
    return this->group;
}
std::string Group::getPotok()
{
    return this->Potok;
}
int Group::getStud()
{
    return this->kol_stud;
}
void Group::setGroup(std::string group)
{
    this->group = group;
}
void Group::setPotok(std::string Potok)
{
    this->Potok = Potok;
}
void Group::setStud(int kol_stud)
{
    this->kol_stud = kol_stud;
}
Group::Group()
{
    this->setGroup("No info");
    this->setPotok("No info");
    this->setStud(0);
}


Group::Group(std::string group, std::string Potok, int kol_stud)
{
    this->setGroup(group);
    this->setPotok(Potok);
    this->setStud(kol_stud);
}
std::ostream& operator<<(std::ostream& os, const Group& ocupation)
{
    os << "<=============================>\t" << '\n';
    os << "Group:" << ocupation.group;
    os << "Potok" << ocupation.Potok;
    os << "Number of student:" << ocupation.kol_stud;
    os << "<=============================>\t" << '\n';
    return os;
}
std::istream& operator>>(std::istream& is, Group& p)
{
    is >> p.Potok;
    is >> p.group;
    is >> p.kol_stud;
    return is;
}
