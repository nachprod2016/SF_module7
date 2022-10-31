#include "myFuncs.h"

int protectInput(std::string & str)
{
    if (str == "0")
    {
        return 0;
    }
    else if (str.length() > 10)
    {
        throw ExceptionDiv("Ошибка! Введено число превышающее допустимый диапазон int");
    }
    else
    {
        long long k = atoi(&str[0]);
        if (k == 0)
        {
            throw ExceptionDiv("Ошибка ввода! Введите число");
        }
        else if (k > 2147483647 || k < -2147483648)
        {
            throw ExceptionDiv("Ошибка! Введено число превышающее допустимый диапазон int");
        }
        return (int)k;
    }
}

void showСontainer(IntArray* ptr)
{
    if (ptr == nullptr)
    {
        std::cout << "Указатель на контейнер пуст!" << std::endl;
    }
    else
    {
        ptr->showContent();
    }
}

IntArray* createContainer(IntArray* ptr)
{
    if (ptr != nullptr)
    {
        throw ExceptionDiv("Контейнер уже создан!!!");
    }
    std::string str;
    int choice;
    std::cout << "1 - Создать пустой контейнер" << std::endl;
    std::cout << "2 - Создать контейнер c выделением памяти под массив" << std::endl;
    std::cin >> str;
    choice = protectInput(str);
    if (choice != 1 && choice != 2)
    {
        throw ExceptionDiv("Ошибка ввода! Неверный номер контейнера!");
    }
    if (choice == 1)
    {
        ptr = new IntArray();
    }
    else
    {
        std::cout << "Введите размер массива: ";
        std::cin >> str;
        choice = protectInput(str);
        if (choice == 0)
        {
            throw ExceptionDiv("Введен недопустимый размер массива");
        }
        ptr = new IntArray(choice);
    }
    return ptr;
}

int choiceContainer()
{
    std::string str;
    std::cout << "Выбор контейнера " << std::endl;
    std::cout << "1 - Контейнер А" << std::endl;
    std::cout << "2 - Контейнер В" << std::endl;
    std::cin >> str;
    int a = protectInput(str);
    if (a != 1 && a != 2)
    {
        throw ExceptionDiv("Ошибка выбора контейнера!");
    }
    return a;
}

void checkContainer(IntArray* ob)
{
    if (ob == nullptr)
    {
        throw ExceptionDiv("Попытка скопировать не созданный контейнер!!!");
    }
}