#include "Line.h"
#include "MyUnexpectedException.h"
#include <iostream>
#include <Windows.h>

#include <stdexcept> 
#include <exception>
#include "MyException.h"

using namespace std;

Line makeLine(double x, double y)
{
    Line z;
    z.SetFirst(x);
    z.SetSecond(y);
    return z;
}

void _unexpected_to_bad()
{
    throw; // �������� bad_exception
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        set_unexpected(_unexpected_to_bad);
        try {
            Line line;
            std::cin >> line;
            std::cout << "�������� ��'��� ��: " << line << std::endl;

            double x;
            std::cout << "������ �������� x: ";
            std::cin >> x;

            std::cout << "�������� ������� ��� x = " << x << " ������� " << line.function(x) << std::endl;


            Line copy = line;
            std::cout << "�������� ����: " << copy << std::endl;

            // �������� ���������

            Line assign;
            assign = line;
            std::cout << "��������� ���������: " << assign << std::endl;

            //  ����������� ���������

            Line post_inc = line++;
            std::cout << "��������� ������������ ����������: " << post_inc << std::endl;

            // ���������� ���������

            Line pre_inc = ++line;
            std::cout << "��������� ����������� ����������: " << pre_inc << std::endl;

            //  ����������� ���������

            Line post_dec = line--;
            std::cout << "��������� ������������ ����������: " << post_dec << std::endl;

            //  ���������� ���������

            Line pre_dec = --line;
            std::cout << "��������� ����������� ����������: " << pre_dec << std::endl;

        }
        catch (const MyException& e) {
            std::cerr << "�������: " << e.what() << std::endl;
        }
        catch (const MyUnexpectedException& e) {
            std::cerr << "����������� �������: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "���������� �������: " << e.what() << std::endl;
        }

        return 0;
    }
};
