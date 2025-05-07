#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap = {
        {"A", 1},
        {"B", 2},
        {"C", 3}
    };

    std::cout << "\nLoop using map iterators:" << std::endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
    // Note that the iterator, "it", is declared "auto" -- it figures out its type
    // at compile time because. Because it is an iterator (~pointer) into a map,
    // it knows that each map has a key and a value (e.g., A and 1, B and 2), and the
    // map key in value in std::map<char,int>::iterator is called "first" and "second".
    // Thus, you get the key with it->first and the value with it->second.

    std::cout << std::endl << "NOW see:    4_Resistor_Calc_Two.cpp" << std::endl << std::endl;


    return 0;
}