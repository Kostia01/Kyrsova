#include "Lector.h"
void Lector::Print()
{
    std::cout << "ФІО:" << this->Surname << this->Name << this->patronymic << '\n';
    std::cout << "Посада:" << this->Position << '\n';
}
std::string Lector::getSurname()
{
    return this->Surname;
}
std::string Lector::getName()
{
    return this->Name;
}
std::string Lector::getPatronymic()
{
    return this->patronymic;
}
std::string Lector::getPosition()
{
    return this->Position;
}
Lector::Lector()
{
    Surname = "No Surname";
    Name = "No Name";
    patronymic = "No patronymic";
    Position = "No position";

}
Lector::Lector(std::string Surname, std::string Name, std::string patronymic, std::string Position)
{
    this->Surname = Surname;
    this->Name = Name;
    this->patronymic = patronymic;
    this->Position = Position;

}
void Lector::Fill_info(Lector* arr, int size)
{

    {
        for (int i = 0; i < size; i++)
        {
            std::string Surname;
            std::string Name;
            std::string patronymic;
            std::string Position;

            std::cout << "Заповніть ФІО:" << '\n';
            std::cin >> Surname;
            std::cin >> Name;
            std::cin >> patronymic;
            std::cout << "Заповніть посаду:" << '\n';
            std::cin >> Position;

            arr[i] = Lector(Surname, Name, patronymic, Position);
            std::cout << '\n';

        }
    }
}
void  Lector::setSur(std::string Surname)
{
    this->Surname = Surname;
}
void  Lector::setName(std::string name)
{
    this->Name = name;
}
void Lector::setPatron(std::string patron)
{
    this->patronymic = patron;
}
void Lector::setPosition(std::string pos)
{
    this->Position = pos;
}
Lector::~Lector()
{

}
std::ostream& operator<<(std::ostream& os, const Lector& ocupation)
{
    os << "<=============================>\t" << '\n';
    os << "Прізвище:" << ocupation.Surname << '\n';
    os << "Ім'я:" << ocupation.Name << '\n';
    os << "Побатькові:" << ocupation.patronymic << '\n';
    os << "Посада:" << ocupation.Position << '\n';

    return os;
}

std::istream& operator>>(std::istream& is, Lector& p)
{
    is >> p.Surname;
    is >> p.Name;
    is >> p.patronymic;
    is >> p.Position;

    return is;
}