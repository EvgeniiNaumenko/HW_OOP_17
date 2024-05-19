#pragma once
#include <stdexcept>

class IncorrectValueException : public std::exception {
private:
    const char* message;
public:

    IncorrectValueException(const char* msg) : message(msg) {}

    const char* what() const noexcept override {
        return message;
    }
};