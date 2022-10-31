#include "IntArray.h"

IntArray::IntArray(int length) : m_length{ length }
{
    if(length < 0)
    {
        throw 1;//размер массива отрицательный
    }
    else
    {
        if (length != 0) { m_data = new int[length]{}; }
    }
}

IntArray::IntArray(const IntArray & ob) : IntArray(ob.getLength())
{
    for (size_t i = 0; i < this->m_length; i++)
    {
        this->m_data[i] = ob.m_data[i];
    }
}

IntArray::~IntArray()
{
    delete[] m_data;//обнулять указатель нет смысла т.к. объект все равно будет уничтожен
}

void IntArray::erase()
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка очистить содержимое в не созданном контейнере!");
    }
    delete[] m_data;
    m_data = nullptr;//нужно обнулить указатель т.к. будет указывать на освобожденную память
    m_length = 0;
}

int& IntArray::operator[](int index)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка обратиться к элементу массива в не созданном контейнере!");
    }
    if (index < 0 || index >= m_length)
    {
        throw ExceptionDiv("Выход за границы массива");//выход за границы массива
    }
    else
    {
        return m_data[index];
    }
}

int IntArray::getLength() const { return m_length; }

void IntArray::reallocate(int newLength)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка изменить размеры массива в не созданном контейнере!");
    }
    erase();//удалить данные
    if (newLength <= 0)//если новый размер массива меньше или равен нулю - завершить тут
    {
        return;
    }
    m_data = new int[newLength]{};//выделить память под новый массив размером newLength 
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка изменить размеры массива в не созданном контейнере!");
    }
    if (newLength == m_length)//если новая длина массива равна текущей - завершить тут
    {
        return;
    }
    if (m_length <= 0)//если новый размер массива меньше или равен нулю - завершить тут
    {
        return;
    }
    int* data{ new int[newLength] };//выделить память под новый массив
    int elementsToCopy{ (newLength > m_length) ? m_length : newLength };//определить количество элементов для копирования
    for (int index{ 0 }; index < elementsToCopy; index++)//скопировать элементы старого массива в новый
    {
        data[index] = m_data[index];
    }
    delete[] m_data;//освободить память выделенную под старый массив
    m_data = data; //изменить значение указателя на адрес нового массива, а также количество элементов в массиве 
    m_length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка вставить новый элемент в массив не созданного контейнера!");
    }
    if (index < 0 || index > m_length)
    {
        throw ExceptionDiv("Ошибка! Попытка вставить новый элемент в пустой контейнер!");//выход за границы массива
    }
    int* data{ new int[m_length + 1] };//выделить память под новый массив(размер старого массива + 1)
    for (int before{ 0 }; before < index; before++)//копировать элементы из старого в новый массив до заданного индекса 
    {
        data[before] = m_data[before];
    }
    data[index] = value;//вставить новый элемент
    for (int after{ index }; after < m_length; after++)//копировать элементы из старого в новый массив после заданного индекса
    {
        data[after + 1] = m_data[after];
    }
    delete[] m_data;//освободить память выделенную под старый массив
    m_data = data; //изменить значение указателя на адрес нового массива, а также количество элементов в массиве 
    m_length++;
}

void IntArray::remove(int index)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка удалить элемент по индексу в не созданном контейнере!");
    }
    if (index < 0 || index >= m_length)
    {
        throw ExceptionDiv("Ошибка! Попытка удалить элемент! Выход за пределы массива!");//выход за границы массива
    }
    if (m_length == 1)//если в массиве остался один элемент
    {
        erase();
        return;
    }
    int* data{ new int[m_length - 1] };//выделить память под новый массив(размер старого массива - 1)
    for (int before{ 0 }; before < index; before++)//копировать элементы из старого в новый массив до заданного индекса 
    {
        data[before] = m_data[before];
    }
    for (int after{ index + 1 }; after < m_length; after++)//копировать элементы из старого в новый массив после заданного индекса
    {
        data[after - 1] = m_data[after];
    }
    delete[] m_data;//освободить память выделенную под старый массив
    m_data = data;//изменить значение указателя на адрес нового массива, а также количество элементов в массиве
    m_length--;
}

void IntArray::insertAtBeginning(int value) 
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка вставить новый элемент в начало массива не созданного контейнера!");
    } 
    insertBefore(value, 0); 
}

void IntArray::insertAtEnd(int value) 
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка вставить новый элемент в конец массива не созданного контейнера!");
    } 
    insertBefore(value, m_length); 
}

void IntArray::showContent()
{
    if (m_data == nullptr)
    {
        std::cout << "Пустой" << std::endl;
    }
    else
    {
        std::cout << "{ ";
        for (size_t i = 0; i < m_length; i++)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << "}" << std::endl;
    }
}

void IntArray::operator = (const IntArray & other)
{
    if (this->m_data != nullptr)
    {
        erase();
    }
    if (other.m_data != nullptr)
    {
        this->m_length = other.m_length;
        this->m_data = new int[this->m_length];
        for (size_t i = 0; i < this->m_length; i++)
        {
            this->m_data[i] = other.m_data[i];
        }
    }
}

int IntArray::searchByValue(int value)
{
    if (this == nullptr)
    {
        throw ExceptionDiv("Попытка поиска элемента массива по значению в не созданном контейнере!");
    }
    for (size_t i = 0; i < m_length; i++)
    {
        if (m_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}