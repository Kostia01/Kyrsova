#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Shedule.h"
#include "printer.h"
#include <fstream>
#include <iostream>
#include <vector>
#define clean system("CLS") //очистка экрана
//

using namespace std;
class Strelka
{
public:



    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<string>TextMenu{ "     |Зчитування розкладу (з файлу)                  |", "     |Заповнення інформації про лектора(запис у файл)|", "     |Зчитування інформації про лектора(з файлу)     |", "     |Інформіція про роботу                          |","     |Робота конструкторів та деструкторів,поліморфізм|", "     |Вихід|" };//текст меню
    //объявим эти переменные глобально, чтобы не таскаться с их передаванием туда сюда из функции в функцию
    //Вот они снизу вверх: вектор (динамический массив) строк, буфер для хаписи, количество строк в тексте
    std::vector<string> Str;
    string buffer = "";
    unsigned int strsize;
    //функции для работы меню, ничего нового
    void CoutTextMenu() //выводит написанный в начале текст меню
    {
        //сначала отступим, чтобы меню было не прям сверху
        std::cout << endl << endl;
        //используем интересний и короткий способ извлечения строк из контейнера
        for (auto par : TextMenu)
        {
            cout << par << endl;
        }
    }
    void SelectMenu(short posY)
    { // функция для рисование стрелочки в меню, для вызова требуется переменная типа short в которой записана позиция рисования стрелочки по У*

        for (short i = 1; i <= TextMenu.size(); i++) //выполняется там, где существует меню
        {
            SetConsoleCursorPosition(hStdOut, { short(TextMenu[i - 1].length() + 1), short(i + 1) });//стирает стрелочку там, где ее нет
            cout << "  ";//пустота, убивающая нашу стрелочку
        }
        SetConsoleCursorPosition(hStdOut, { short(TextMenu[posY - 1].length() + 1) , short(posY + 1) });//рисует стрелочку там, где она есть
        cout << "<-";//а вот и сама стрелочка
    }
    short MainMenu()
    { // Функция меню
        CoutTextMenu();//выведем текст
        short posY = 1;//выставим начало - 1й пункт меню (здесь уже не работает прикол с отсчетом от нуля)
        SelectMenu(posY);//передадим позицию курсора в функцию, рисующую стрелочку
        while (true)
        {
            int check = _getch();//захватим клавишу (а потом и весь мир)
            if (check == 72)
            { // вверх
                if (posY > 1)
                    posY--;
                else
                    posY = TextMenu.size();
            }
            if (check == 80)
            { // вниз
                if (posY < TextMenu.size())
                    posY++;
                else
                    posY = 1;
            }
            if (check == 13)
            { // выбор (Enter)
                if (posY == TextMenu.size())
                    return 0;
                else
                    return posY;
            }
            SelectMenu(posY);//передадим позицию курсора в функцию, рисующую стрелочку, еще раз
        }
    }
    void MassProverka()
    {
        printer b;
        clean;
        Shedule a;

        b.Print(&a);//полиморфизм

        _getch();
    }

    void Info()
    {
        clean;
        cout << "Ця програма може читати інформацію з файлу та записувати її у файл " << endl;
        cout << "Ви також можете побачити опис" << endl;
        cout << "Натисніть будь-яку клавішу, щоб повернутися до меню" << endl;
        _getch();
    }
    void reading()
    {
        clean;
        std::string NameFile = "Occupation.txt";
        fstream fs;
        fs.open(NameFile, fstream::in | fstream::out | fstream::app);
        if (!fs.is_open())
        {
            cout << "Файл не відкритий!" << '\n';
        }
        else
        {
            string a;
            ifstream creat;
            creat.open("Occupation.txt");
            while (true)
            {
                getline(creat, a, '\n');
                if (!creat.eof())
                    cout << a << "\n";
                else
                    break;
            }




        }
        _getch();
    }
    void writtingLK()//Ввод информации и запись в файл про лектора
    {
        clean;
        std::string NameFile = "Lector.txt";
        fstream fs;
        fs.open(NameFile, fstream::in | fstream::out | fstream::app);//відкриваємо файл для читання, запису у кінець
        if (!fs.is_open())
        {
            cout << "Файл не відкритий!" << '\n';
        }
        else
        {
            cout << "Файл відкритий!" << endl;
            int lectors;
            Lector a;
            std::cout << "Введіть кількість лекторів (максимум 3):";
            try {
                std::cin >> lectors;
                if (lectors > 3)
                    throw lectors;
                std::cout << '\n';
                Lector* arr = new Lector[lectors];
                a.Fill_info(arr, lectors);
                for (int i = 0;i < lectors;i++)//вывод
                {
                
                    fs << arr[i];
                }
            }
            catch (int lectors)
            {
                std::cerr << "Максимальна кількіть лекторів 3!!!!!";
            }
        }

        _getch();
    }
    void readingLK()//Ввод информации и запись в файл про лектора
    {
       
        clean;
        std::string NameFile = "Lector.txt";
        fstream fs;
        fs.open(NameFile, fstream::in | fstream::out | fstream::app);
        if (!fs.is_open())
        {
            cout << "Файл не відкритий" << '\n';
        }
        else
        {
            string a;
            ifstream creat;
            creat.open("Lector.txt");
            while (true)
            {
                getline(creat, a, '\n');
                if (!creat.eof())
                    cout << a << "\n";
                else
                    break;
            }

        }
        _getch();
    }
};
