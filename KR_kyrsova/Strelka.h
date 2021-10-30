#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include "Shedule.h"
#include "printer.h"
#include <fstream>
#include <iostream>
#include <vector>
#define clean system("CLS") //������� ������
//

using namespace std;
class Strelka
{
public:



    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<string>TextMenu{ "     |���������� �������� (� �����)                  |", "     |���������� ���������� ��� �������(����� � ����)|", "     |���������� ���������� ��� �������(� �����)     |", "     |��������� ��� ������                          |","     |������ ������������ �� �����������,����������|", "     |�����|" };//����� ����
    //������� ��� ���������� ���������, ����� �� ��������� � �� ������������ ���� ���� �� ������� � �������
    //��� ��� ����� �����: ������ (������������ ������) �����, ����� ��� ������, ���������� ����� � ������
    std::vector<string> Str;
    string buffer = "";
    unsigned int strsize;
    //������� ��� ������ ����, ������ ������
    void CoutTextMenu() //������� ���������� � ������ ����� ����
    {
        //������� ��������, ����� ���� ���� �� ���� ������
        std::cout << endl << endl;
        //���������� ���������� � �������� ������ ���������� ����� �� ����������
        for (auto par : TextMenu)
        {
            cout << par << endl;
        }
    }
    void SelectMenu(short posY)
    { // ������� ��� ��������� ��������� � ����, ��� ������ ��������� ���������� ���� short � ������� �������� ������� ��������� ��������� �� �*

        for (short i = 1; i <= TextMenu.size(); i++) //����������� ���, ��� ���������� ����
        {
            SetConsoleCursorPosition(hStdOut, { short(TextMenu[i - 1].length() + 1), short(i + 1) });//������� ��������� ���, ��� �� ���
            cout << "  ";//�������, ��������� ���� ���������
        }
        SetConsoleCursorPosition(hStdOut, { short(TextMenu[posY - 1].length() + 1) , short(posY + 1) });//������ ��������� ���, ��� ��� ����
        cout << "<-";//� ��� � ���� ���������
    }
    short MainMenu()
    { // ������� ����
        CoutTextMenu();//������� �����
        short posY = 1;//�������� ������ - 1� ����� ���� (����� ��� �� �������� ������ � �������� �� ����)
        SelectMenu(posY);//��������� ������� ������� � �������, �������� ���������
        while (true)
        {
            int check = _getch();//�������� ������� (� ����� � ���� ���)
            if (check == 72)
            { // �����
                if (posY > 1)
                    posY--;
                else
                    posY = TextMenu.size();
            }
            if (check == 80)
            { // ����
                if (posY < TextMenu.size())
                    posY++;
                else
                    posY = 1;
            }
            if (check == 13)
            { // ����� (Enter)
                if (posY == TextMenu.size())
                    return 0;
                else
                    return posY;
            }
            SelectMenu(posY);//��������� ������� ������� � �������, �������� ���������, ��� ���
        }
    }
    void MassProverka()
    {
        printer b;
        clean;
        Shedule a;

        b.Print(&a);//�����������

        _getch();
    }

    void Info()
    {
        clean;
        cout << "�� �������� ���� ������ ���������� � ����� �� ���������� �� � ���� " << endl;
        cout << "�� ����� ������ �������� ����" << endl;
        cout << "�������� ����-��� ������, ��� ����������� �� ����" << endl;
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
            cout << "���� �� ��������!" << '\n';
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
    void writtingLK()//���� ���������� � ������ � ���� ��� �������
    {
        clean;
        std::string NameFile = "Lector.txt";
        fstream fs;
        fs.open(NameFile, fstream::in | fstream::out | fstream::app);//��������� ���� ��� �������, ������ � �����
        if (!fs.is_open())
        {
            cout << "���� �� ��������!" << '\n';
        }
        else
        {
            cout << "���� ��������!" << endl;
            int lectors;
            Lector a;
            std::cout << "������ ������� ������� (�������� 3):";
            try {
                std::cin >> lectors;
                if (lectors > 3)
                    throw lectors;
                std::cout << '\n';
                Lector* arr = new Lector[lectors];
                a.Fill_info(arr, lectors);
                for (int i = 0;i < lectors;i++)//�����
                {
                
                    fs << arr[i];
                }
            }
            catch (int lectors)
            {
                std::cerr << "����������� ������ ������� 3!!!!!";
            }
        }

        _getch();
    }
    void readingLK()//���� ���������� � ������ � ���� ��� �������
    {
       
        clean;
        std::string NameFile = "Lector.txt";
        fstream fs;
        fs.open(NameFile, fstream::in | fstream::out | fstream::app);
        if (!fs.is_open())
        {
            cout << "���� �� ��������" << '\n';
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
