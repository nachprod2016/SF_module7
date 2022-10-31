#include "ExceptionDiv.h"

ExceptionDiv::ExceptionDiv(const std::string & str) : error(str) {}

ExceptionDiv::~ExceptionDiv() {};

const char* ExceptionDiv::what() const noexcept
{
    return &(error.at(0));
}