#pragma once
#include <iostream>
#include "ExceptionDiv.h"

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;//конструктор по умолчанию
    IntArray(int length);//конструктор с параметрами
    IntArray(const IntArray & ob);//конструктор копирования
    ~IntArray();//деструктор
    void erase();//удалить данные
    int& operator [] (int index);//перегрузка оператора
    void operator = (const IntArray & other);
    int getLength() const;//геттер для размера массива
    void reallocate(int newLength);//изменяет размер массива, удаляя данные
    void resize(int newLength);//изменяет размер массива, сохраняя данные
    void insertBefore(int value, int index);//вставить по индексу
    void remove(int index);//удалить элемент из массива
    void insertAtBeginning(int value);//Вставить элемент в начало
    void insertAtEnd(int value);//вставить элемент в конец
    void showContent();//показать содержимое
    int searchByValue(int value);
};