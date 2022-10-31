#include <iostream>
#include "IntArray.h"
#include "myFuncs.h"

int main()
{
    IntArray* A = nullptr;
    IntArray* B = nullptr;
    bool flag = true;
    std::string strChoice;
    int intChoice;
    while (flag)
    {
        try
        {
            std::cout << "Контейнеры для тестирования:" << std::endl;
            std::cout << "A = ";
            showСontainer(A);
            std::cout << "B = ";
            showСontainer(B);
            std::cout << std::endl;
            std::cout << "1 - Cоздание контейнера" << std::endl;
            std::cout << "2 - Копирование контейнера" << std::endl;
            std::cout << "3 - Получить доступ к элементу контейнера по индексу" << std::endl;
            std::cout << "4 - Изменить размер массива в контейнере" << std::endl;
            std::cout << "5 - Вставить элемент в контейнер по индексу" << std::endl;
            std::cout << "6 - Вставить элемент в начало" << std::endl;
            std::cout << "7 - Вставить элемент в конец" << std::endl;
            std::cout << "8 - Удалить элемент из контейнера" << std::endl;
            std::cout << "9 - Удалить содержимое контейнера" << std::endl;
            std::cout << "10 - Удалить контейнер" << std::endl;
            std::cout << "11 - Поиск индекса элемента по значению" << std::endl;
            std::cout << "0 - Выйти из программы" << std::endl;
            std::cin >> strChoice;
            intChoice = protectInput(strChoice);
            std::cout << std::endl;
            switch (intChoice)
            {
                case 1:
                {
                    intChoice = choiceContainer();
                    intChoice == 1 ? A = createContainer(A) : B = createContainer(B);
                    break;
                }
                case 2:
                {
                    std::cout << "1 - Копировать А в В" << std::endl;
                    std::cout << "2 - Копировать B в A" << std::endl;
                    std::cin >> strChoice;
                    intChoice = protectInput(strChoice);
                    if  (intChoice != 1 && intChoice != 2)
                    {
                        throw ExceptionDiv("Ошибка копирования! Неверный выбор!");
                    }
                    if (intChoice == 1)
                    {
                        checkContainer(A);
                        if (B == nullptr) { B = new IntArray(*A); }
                        else { *B = *A; }
                    }
                    else
                    {
                        checkContainer(B);
                        if (A == nullptr) { A = new IntArray(*B); }
                        else { *A = *B; }
                    }
                    break;
                }
                case 3:
                {
                    intChoice = choiceContainer();
                    int index, value;
                    std::cout << "Индекс элемента массива: " << std::endl;
                    std::cin >> strChoice;
                    index = protectInput(strChoice);
                    intChoice == 1 ? value = (*A)[index] : value = (*B)[index];
                    strChoice == "1" ? strChoice = "A" : strChoice = "B";
                    std::cout << "Элемент массива контейнера " << strChoice << " с индексом: " << index << " равен " << value << std::endl;
                    break;
                }
                case 4:
                {
                    std::cout << "Введите новый размер массива: ";
                    std::cin >> strChoice;
                    int size = protectInput(strChoice);
                    intChoice = choiceContainer();
                    if (intChoice == 1)
                    {
                        std::cout << "1 - Удалить содержимое контейнера A" << std::endl;
                        std::cout << "2 - Сохранить содержимое контейнера A" << std::endl;
                        std::cin >> strChoice;
                        intChoice = protectInput(strChoice);
                        intChoice == 1 ? A->reallocate(size) : A->resize(size);
                    }
                    else
                    {
                        std::cout << "1 - Удалить содержимое контейнера B" << std::endl;
                        std::cout << "2 - Сохранить содержимое контейнера B" << std::endl;
                        std::cin >> strChoice;
                        intChoice = protectInput(strChoice);
                        intChoice == 1 ? B->reallocate(size) : B->resize(size);
                    }
                    break;
                }
                case 5:
                {
                    std::cout << "Индекс вставки: " << std::endl;
                    std::cin >> strChoice;
                    int index = protectInput(strChoice);
                    std::cout << "Значение: " << std::endl;
                    std::cin >> strChoice;
                    int value = protectInput(strChoice);
                    intChoice = choiceContainer();
                    intChoice == 1 ? A->insertBefore(value, index) : B->insertBefore(value, index);
                    break;
                }
                case 6:
                {
                    std::cout << "Значение: " << std::endl;
                    std::cin >> strChoice;
                    int value = protectInput(strChoice);
                    intChoice = choiceContainer();
                    intChoice == 1 ? A->insertAtBeginning(value) : B->insertAtBeginning(value);
                    break;
                }
                case 7:
                {
                    std::cout << "Значение: " << std::endl;
                    std::cin >> strChoice;
                    int value = protectInput(strChoice);
                    intChoice = choiceContainer();
                    intChoice == 1 ? A->insertAtEnd(value) : B->insertAtEnd(value);
                    break;
                }
                case 8:
                {
                    std::cout << "Индекс удаления: " << std::endl;
                    std::cin >> strChoice;
                    int index = protectInput(strChoice);
                    intChoice = choiceContainer();
                    intChoice == 1 ? A->remove(index) : B->remove(index);
                    break;
                }
                case 9:
                {
                    intChoice = choiceContainer();
                    intChoice == 1 ? A->erase() : B->erase();
                    break;
                }
                case 10:
                {
                    IntArray* ptr;
                    intChoice = choiceContainer();
                    if (intChoice == 1)
                    {
                        ptr = A;
                        A = nullptr;
                    }
                    else
                    {
                        ptr = B;
                        B = nullptr;
                    }
                    if (ptr != nullptr)
                    {
                        delete ptr;
                    }
                    else
                    {
                        throw ExceptionDiv ("Контейнер не создан!");
                    }
                    break;
                }
                case 11:
                {
                    int index;
                    std::cout << "Введите значение: " << std::endl;
                    std::cin >> strChoice;
                    int value = protectInput(strChoice);
                    intChoice = choiceContainer();
                    if (intChoice == 1)
                    {
                        index = A->searchByValue(value);
                        if (index == -1)
                        {
                            std::cout << "В контейнере А нет элемента со значением " << value << std::endl;
                        }
                        else
                        {
                            std::cout << "В контейнере А элемент со значением " << value << " имеет индекс " << index << std::endl;
                        }
                    }
                    else
                    {
                        index = B->searchByValue(value);
                        if (index == -1)
                        {
                            std::cout << "В контейнере B нет элемента со значением " << value << std::endl;
                        }
                        else
                        {
                            std::cout << "В контейнере B элемент со значением " << value << " имеет индекс " << index << std::endl;
                        }
                    }
                    break;
                }
                case 0:
                {
                    flag = false;
                    break;
                }
            }
        }
        catch(const ExceptionDiv & a)
        {
            std::cout << a.what() << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}