// Line.h
#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
class Line
{
private:
    double first, second;

public:
    Line();                   // Конструктор за замовчуванням
    Line(double x, double y); // Конструктор ініціалізації
    Line(const Line& other);  // Копіювальний конструктор
    ~Line();

    double GetFirst() const { return first; }
    double GetSecond() const { return second; }
    void SetFirst(double value);
    void SetSecond(double value);

    double function(double x) const;

     operator string () const;

    Line& operator=(const Line& other); // Оператор присвоєння

    Line& operator++();                  // Префіксний інкремент
    Line& operator--();                  // Префіксний декремент
    Line operator++(int);                // Постфіксний інкремент                 
    Line operator--(int);                // Постфіксний декремент

    friend ostream& operator<<(ostream& out, const Line& line);
    friend istream& operator>>(istream& in, Line& line);
};