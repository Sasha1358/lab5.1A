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
    Line();                   // ����������� �� �������������
    Line(double x, double y); // ����������� �����������
    Line(const Line& other);  // ����������� �����������
    ~Line();

    double GetFirst() const { return first; }
    double GetSecond() const { return second; }
    void SetFirst(double value);
    void SetSecond(double value);

    double function(double x) const;

     operator string () const;

    Line& operator=(const Line& other); // �������� ���������

    Line& operator++();                  // ���������� ���������
    Line& operator--();                  // ���������� ���������
    Line operator++(int);                // ����������� ���������                 
    Line operator--(int);                // ����������� ���������

    friend ostream& operator<<(ostream& out, const Line& line);
    friend istream& operator>>(istream& in, Line& line);
};