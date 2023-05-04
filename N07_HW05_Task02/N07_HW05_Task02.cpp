// N07_HW05_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class T>
class table
{
public:
    table(int rows, int cols){
        this->rows=rows;
        elements = new int* [rows];
        for (int i = 0; i < rows; i++) {
            elements[i] = new T[cols]();
        }
    }
    /*T getElement(int inIndex_r, int inIndex_c) const
    {
        //return elements[inIndex_r, inIndex_c];
        return elements[inIndex_r][inIndex_c];
    }
    void setElement(int inIndex_r, int inIndex_c, T inValue)
    {
        elements[inIndex_r][inIndex_c] = inValue;
    }*/

    T* operator[](int inIndex_r){
        return elements[inIndex_r];
    }

    table(const table& t) = delete;
    //Person(const Person& p) = delete;
    table& operator=(const table&) = delete;

    ~table()
    {
        for (int i = 0; i < rows; i++) {
            delete[] elements[i];
        }
        delete[] elements;
    }
private:
    T** elements = nullptr;
    int rows;
};

int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 8;  
    std::cout << test[0][0] << std::endl;
}


