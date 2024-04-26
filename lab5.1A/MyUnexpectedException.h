#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>

class MyUnexpectedException  {
private:
    std::string message;
public:
    MyUnexpectedException(const std::string& msg) : message(msg) {}
    const std::string& what() const {
        return message;
    }
};