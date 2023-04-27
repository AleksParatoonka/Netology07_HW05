// N07_HW05_Task03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>

class my_functor {
    int sum;
    int count;
public:
    my_functor() : sum(0), count(0) {}
    void operator()(int x) {
        if (x % 3 == 0) {
            count += 1;
            sum += x;
        }
    }
    int get_sum() const { return sum; }
    int get_count() const { return count; }
};


int main()
{
    std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };

    std::cout << "[IN] : ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    my_functor mf;
    mf = for_each(vec.begin(), vec.end(), mf);
    std::cout << "[OUT] :  get_sum() = " << mf.get_sum() << std::endl;
    std::cout << "[OUT] : get_count() = " << mf.get_count() << std::endl;
}

