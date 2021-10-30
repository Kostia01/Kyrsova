#include "Occupation.h"


Occupation::Occupation() :Lector(), Group()
{
    Subject = "No Info";
    Date = "No Info";
    Time = "No Info";
    Type = "No Info";
    Place = "No Info";
}

Occupation::Occupation(int kol_stud, std::string Potok, std::string group, std::string Surname, std::string Name, std::string patronymic, std::string Position, std::string Subject, std::string Date, std::string Time, std::string Type, std::string Place)
{
    this->setSur(Surname);
    this->setName(Name);
    this->setPatron(patronymic);
    this->setPosition(Position);
    this->setStud(kol_stud);
    this->setPotok(Potok);
    this->setGroup(group);
    this->Subject = Subject;
    this->Date = Date;
    this->Time = Time;
    this->Type = Type;
    this->Place = Place;
}

Occupation::~Occupation()
{

}

std::string Occupation::getSubject()
{
    return this->Subject;
}

std::string Occupation::getDate()
{
    return this->Date;
}

std::string Occupation::getTime()
{
    return this->Time;
}
std::string Occupation::getType()
{
    return this->Type;
}
std::string Occupation::getPlace()
{
    return this->Place;
}

std::string Occupation::setSubject(std::string subject)
{
    this->Subject = subject;
    return this->Subject;
}

std::string Occupation::setDate(std::string date)
{
    this->Date = date;
    return this->Date;
}

std::string Occupation::setTime(std::string time)
{
    this->Time = time;
    return this->Time;
}

std::string  Occupation::setType(std::string type)
{
    this->Type = type;
    return this->Type;
}

std::string Occupation::setPlace(std::string place)
{
    this->Place = place;
    return this->Place;
}

void  Occupation::Print()
{
    std::cout << "Subject(name):" << this->Subject << '\n';
    std::cout << "<=============================>\t" << '\n';
    std::cout << "Subject:" << this->Subject << '\n';
    std::cout << "Date of lesson:" << this->Date << '\n';
    std::cout << "Time of lesson:" << this->Time << '\n';
    std::cout << "Type of lesson:" << this->Type << '\n';
    std::cout << "Place of lesson: " << this->Place << '\n';
    std::cout << "<=============================>\t" << '\n';
}


std::ostream& operator<<(std::ostream& os, const Occupation& ocupation)
{
    os << "<=============================>\t" << '\n';
    os << "Subject:" << ocupation.Subject << '\n';
    os << "Date of lesson:" << ocupation.Date << '\n';
    os << "Time of lesson:" << ocupation.Time << '\n';
    os << "Type of lesson:" << ocupation.Type << '\n';
    os << "Place of lesson: " << ocupation.Place << '\n';
    os << "<=============================>\t" << '\n';


    return os;
}

std::istream& operator>>(std::istream& is, Occupation& p)
{
    is >> p.Subject;
    is >> p.Date;
    is >> p.Time;
    is >> p.Type;
    is >> p.Place;
    return is;
}
