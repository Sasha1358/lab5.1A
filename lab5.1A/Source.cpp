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
    throw; // генеруємо bad_exception
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
            std::cout << "Створено об'єкт лінії: " << line << std::endl;

            double x;
            std::cout << "Введіть значення x: ";
            std::cin >> x;

            std::cout << "Значення функції для x = " << x << " дорівнює " << line.function(x) << std::endl;


            Line copy = line;
            std::cout << "Створено копію: " << copy << std::endl;

            // оператор присвоєння

            Line assign;
            assign = line;
            std::cout << "Присвоєння завершено: " << assign << std::endl;

            //  постфіксний інкремент

            Line post_inc = line++;
            std::cout << "Результат постфіксного інкремента: " << post_inc << std::endl;

            // префіксний інкремент

            Line pre_inc = ++line;
            std::cout << "Результат префіксного інкремента: " << pre_inc << std::endl;

            //  постфіксний декремент

            Line post_dec = line--;
            std::cout << "Результат постфіксного декремента: " << post_dec << std::endl;

            //  префіксний декремент

            Line pre_dec = --line;
            std::cout << "Результат префіксного декремента: " << pre_dec << std::endl;

        }
        catch (const MyException& e) {
            std::cerr << "Помилка: " << e.what() << std::endl;
        }
        catch (const MyUnexpectedException& e) {
            std::cerr << "Неочікувана помилка: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Стандартна помилка: " << e.what() << std::endl;
        }

        return 0;
    }
};
