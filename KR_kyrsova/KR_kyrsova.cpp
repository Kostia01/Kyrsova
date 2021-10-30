#include <iostream>
#include <Windows.h>
#include "Group.h"
#include "Occupation.h"
#include "Strelka.h"
#include"printer.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывод
    // setlocale(LC_CTYPE, "rus");
    Strelka a;



    while (short check = a.MainMenu())//когда всегда, а именно пока выполняется меню
    {
        switch (check)//в зависимости от пункта выполнять:
        {
        case 1:a.reading();clean;break;
        case 2:a.writtingLK();clean;break; //
        case 3:a.readingLK();clean;break;//обработка
        case 4:a.Info();clean;break;//информация
        case 5:a.MassProverka();clean;break;//полиморф и позне связ
        case 6: return 0; //выход из программы
        default: return check;
        }
        if (check == 0) break;//позиция курсора всегда от 1 до (количество пунктов меню)
    };
}