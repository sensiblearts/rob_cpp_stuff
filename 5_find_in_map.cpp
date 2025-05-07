
#include <cmath>

// #include <eng_format.hpp>
#include "eng_format.cpp" // notice this difference for mine, because
						// you might keep yours like <eng_format.hpp>
#include <iostream>
#include <string>

#include <map>  // for the map<>s
#include <cctype> // std::toupper

const std::map<char, int> myMap = {
    {'A', 1},
    {'B', 2},
    {'C', 3}
};

struct IntResult {
	bool found = false; // default
    int value;
};


IntResult find_int_in_map(std::map<char, int> the_map, char input_char) {
	IntResult result; // has a value and a bool flag (true if found)
	auto it = the_map.find(input_char);
	if (it != the_map.end()) {
        std::cout << "Found map key: " << it->first << std::endl;
		result.value = it->second;
		result.found = true; 
	} else {
        std::cout << "Key NOT FOUND: " << input_char << std::endl;
    }
	return result;
}


int main()
{


    IntResult res; // has a .value field and a .found field

    std::cout << std::endl << "Try lower case..." << std::endl;
    
    res = find_int_in_map(myMap, 'b');
    if (res.found) {
        std::cout << "Map value: " << res.value << std::endl;
    }
    
    std::cout << std::endl << "Try upper case..." << std::endl;
  
    res = find_int_in_map(myMap, 'B');
    if (res.found) {
        std::cout << "Map value: " << res.value << std::endl;
    }

    std::cout << std::endl << "Try std::toupper on lower case..." << std::endl;
  
    char upper = std::toupper('b');
    res = find_int_in_map(myMap, upper);
    if (res.found) {
        std::cout << "Map value: " << res.value << std::endl;
    }


    std::cout << std::endl << "NOW see:    6_Resistor_Calc_Three.cpp" << std::endl << std::endl;

	return 0;
}
