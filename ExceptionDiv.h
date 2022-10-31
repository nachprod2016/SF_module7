#pragma once
#include <iostream>

class ExceptionDiv : public std::exception
{
    private:
    std::string error;

    public:
    ExceptionDiv(const std::string & str);
    ~ExceptionDiv();
    const char* what() const noexcept override;
};
