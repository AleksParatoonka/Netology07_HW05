// N07_HW05_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

template <class T>
T my_square(T a) {
    return a * a;
}
template<>
std::vector<int> my_square(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] *= a[i];
    }
    return a;
}

void print_vector(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i];
        if (i != a.size() - 1) {
            std::cout << ", ";
        }
    }
}

int main()
{
    int in_int = 4;
    std::vector<int> in_vector = { -1, 4, 8 };
    my_square<int>(4);
    std::cout << "[IN]: "<<in_int<<"\n";
    std::cout << "[OUT]: " << my_square<int>(in_int) << std::endl;
    std::cout << "[IN]: ";
    print_vector(in_vector);
    std::cout << std::endl;
    std::cout << "[OUT]: ";
    print_vector(my_square<std::vector<int>>(in_vector));
    std::cout << std::endl;
}
