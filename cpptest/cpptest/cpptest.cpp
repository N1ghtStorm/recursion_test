// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

void some_1(int a) {
    if (a >= 4500) {
        return;
    }

    a++;
    some_1(std::move(a));
    //some_1(a);
}

void some_2(int* a) {
    if (*a >= 4500) {
        return;
    }

    *a = *a + 1;
    some_2(a);
    //some_1(a);
}

int main()
{
    //std::cout << "Hello World!\n";
    auto t1 = high_resolution_clock::now();
    some_1(0);
    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    std::cout << ms_int.count() << "ms\n";

    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";


    auto a = 0;
    auto t3 = high_resolution_clock::now();
    some_2(&a);
    auto t4 = high_resolution_clock::now();
    auto ms_int_1 = duration_cast<milliseconds>(t4 - t3);
    std::cout << ms_int_1.count() << "ms\n";

    duration<double, std::milli> ms_double_1 = t4 - t3;
    std::cout << ms_double_1.count() << "ms\n";

    return 0;
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
