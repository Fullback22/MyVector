// MyVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>

#include <iostream>
#include "MyVector.h"

void foo()
{
    MyVector<int> vector1{ 100000000 };
    for (size_t i{}; i < 100000; ++i)
    {
        std::cout << 1;
    }
}
int main()
{
    std::vector<int> trueVector(10,0);
    trueVector.insert(trueVector.begin() + 2, 55);
    //trueVector.assign(100000000, 5);

    //foo();
    MyVector<int> vector1{ 49 };
    MyVector<int> vector2{ vector1 };
    //vector2 = vector1;
    //vector1.assign(100000000, 5);
    //vector2.back() = 100;
    int a{ vector2.back() };
    a = 500;
    //vector1.insert(2, 2,23);
    //vector1.erase(3);
    vector1.pushBack(3);
    vector1.pushBack(3);
    vector1.popBack();
    vector1.resize(20, 5);
    for (size_t i{}; i < vector1.size(); ++i)
    {
        std::cout << vector1[i];
    }
    

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
