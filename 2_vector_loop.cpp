#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {10, 20, 30, 40, 50};

    std::cout << std::endl << "4 different ways of doing the same thing:" << std::endl << std::endl;


    // 1. Range-based for loop (C++11 and later) - Simplest and often preferred
    std::cout << "Range-based for loop: ";
    for (int element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 2. Traditional for loop with index
    std::cout << "Traditional for loop: ";
    for (size_t i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    // 3. Iterator-based loop
    std::cout << "Iterator-based loop: ";
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 4. Using auto and iterators (more concise)
    std::cout << "STUDY THIS ONE:  Auto and iterator loop: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "The IMPORTANT thing to notice is how iterators are like indexes in loops but also work like pointers";
    std::cout << std::endl << std::endl;
   
    std::cout << "NOW, see:   3_map_loop.cpp" << std::endl;

    return 0;
}