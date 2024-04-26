// Line.cpp
#include "Line.h"
#include "MyUnexpectedException.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept> 
#include <exception> 
#include <Windows.h>
#include "MyException.h"
using namespace std;

// Реалізація конструкторів
Line::Line() : first(0.0), second(0.0) {}
Line::Line(double x, double y) : first(x), second(y) {
    if (x == 0 && y == 0) {
        throw MyUnexpectedException("A and B are both zero.");
    }
}
Line::Line(const Line& other) : first(other.first), second(other.second) {}
Line::~Line() {}

void Line::SetFirst(double value) {
    first = value;
}
void Line::SetSecond(double value) {
    second = value;
}
double Line::function(double x) const {
    if (first == 0 && second == 0) {
        throw MyUnexpectedException("A and B are both zero.");
    }
    return (first * x) + second;
}

Line& Line::operator=(const Line& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}
Line::operator string() const {
    return "A = " + std::to_string(first) + ", B = " + std::to_string(second);
}

Line& Line::operator++() {
    ++first;
    return *this;
}
Line Line::operator++(int) {
    Line temp = *this;
    ++first;
    return temp;
}
Line& Line::operator--() {
    --first;
    return *this;
}
Line Line::operator--(int) {
    Line temp = *this;
    --first;
    return temp;
}

istream& operator>>(istream& in, Line& line) {
    double x, y;
    std::string input_x, input_y;  // Оголошуємо рядки для зберігання введених рядків
    cout << "Введіть значення A: ";
    in >> input_x;
    try {
        x = std::stod(input_x); // Конвертуємо введений рядок в число
    }
    catch (const std::invalid_argument& e) {
        // Виводимо вікно з повідомленням про помилку для неправильного значення A
        const char* errorMsg = "Entered an incorrect value for A.";
        int size = MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, NULL, 0);
        wchar_t* wideMsg = new wchar_t[size];
        MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, wideMsg, size);
        MessageBox(NULL, wideMsg, L"Error", MB_ICONERROR | MB_OK);
        delete[] wideMsg; // Звільняємо пам'ять виділену для wideMsg
        throw MyException("Entered an incorrect value for A");
    }

    cout << "Введіть значення B: ";
    in >> input_y;
    try {
        y = std::stod(input_y); // Конвертуємо введений рядок в число
    }
    catch (const std::invalid_argument& e) {
        // Виводимо вікно з повідомленням про помилку для неправильного значення B
        const char* errorMsg = "Entered an incorrect value for B.";
        int size = MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, NULL, 0);
        wchar_t* wideMsg = new wchar_t[size];
        MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, wideMsg, size);
        MessageBox(NULL, wideMsg, L"Error", MB_ICONERROR | MB_OK);
        delete[] wideMsg; // Звільняємо пам'ять виділену для wideMsg
        throw MyException("Entered an incorrect value for B");
    }

    cout << endl;

    if (x == 0 && y == 0) {
        // Виводимо вікно з повідомленням про помилку для обох нульових значень
        const char* errorMsg = "A and B cannot be both zero.";
        int size = MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, NULL, 0);
        wchar_t* wideMsg = new wchar_t[size];
        MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, wideMsg, size);
        MessageBox(NULL, wideMsg, L"Error", MB_ICONERROR | MB_OK);
        delete[] wideMsg; // Звільняємо пам'ять виділену для wideMsg
        throw MyUnexpectedException("A and B are both zero.");
    }

    line.SetFirst(x);
    line.SetSecond(y);
    return in;
}
ostream& operator<<(ostream& out, const Line& line) {
    out << "A = " << line.GetFirst() << ", B = " << line.GetSecond();
    return out;
}