
#include <cmath>

// #include <eng_format.hpp>
#include "eng_format.cpp" // notice this difference for mine, because
						// you might keep yours like <eng_format.hpp>
#include <iostream>
#include <string>

#include <map>  // for the map<>s
#include <cctype> // std::toupper

static const std::map<char, int> d1_d2_Map = {
    { 'K', 0},
    { 'N', 1},
    { 'R', 2},
    { 'O', 3},
	{ 'Y', 4},
	{ 'G', 5},
	{ 'L', 6},
	{ 'V', 7},
	{ 'E', 8},
	{ 'W', 9}	
};

static const std::map<char, int> m_Map = {
    { 'K', 0},
    { 'N', 1},
    { 'R', 2},
    { 'O', 3},
	{ 'Y', 4},
	{ 'G', 5},
	{ 'L', 6},
	{ 'V', 7},
	{ 'E', 8},
	{ 'W', 9},	
	{ 'D', -1},	
	{ 'S', -2}
};

static const std::map<char, double> t_Map = {
    { 'N', 0.01},
    { 'R', 0.02},
    { 'O', 0.03},
	{ 'Y', 0.04},
	{ 'G', 0.005},
	{ 'L', 0.0025},
	{ 'V', 0.001},
	{ 'E', 0.0005},
	{ 'D', 0.05},	
	{ 'S', 0.1}
};

struct IntResult {
	bool found = false; // default
    int value;
};

struct DoubleResult {
	bool found = false; 
    double value;
};


IntResult find_int_in_map(std::map<char, int> the_map, char input_char) {
	IntResult result;
	auto it = the_map.find(std::toupper(input_char));
	if (it != the_map.end()) {
		result.value = it->second;
		result.found = true;
	}
	return result;
}

DoubleResult find_double_in_map(std::map<char, double> the_map, char input_char) {
	DoubleResult result;
	auto it = the_map.find(std::toupper(input_char));
	if (it != the_map.end()) {
		result.value = it->second;
		result.found = true;
	}
	return result;
}

void say_not_supported(std::string band_str) {
	std::cout << "ERROR: Band " << band_str << " input not supported" << std::endl;
}

int main()
{

	std::cout << "blac[K] brow[N] [R]ed [O]range [Y]ellow [G]reen b[L]ue [V]iolet gr[E]y [W]hite gol[D] [S]ilver\n" << std::endl;

	std::cout << "Color Code:" << std::endl;
	while (true) {
		std::string input;

		bool check = true;
		int d1 = 0;
		int d2 = 0;
		int m = 0;
		double t = 0;
		double result = 0;

		while (check == true) {
			std::cin >> input;
			int size = input.size();

			if (size < 4 || size > 4) {
				std::cout << "ERROR: Only four band input is accepted\n" << std::endl;
				check = false;
				break;
			}
			else;
			
			IntResult res;
			
			res = find_int_in_map(d1_d2_Map, input[0]);
			if (res.found)
				d1 = res.value;
			else {
				say_not_supported("one");
				check = false;
			}

			res = find_int_in_map(d1_d2_Map, input[1]);
			if (res.found)
				d2 = res.value;
			else {
				say_not_supported("two");
				check = false;
			}

			res = find_int_in_map(m_Map, input[2]);
			if (res.found)
				m = res.value;
			else {
				say_not_supported("three");
				check = false;
			}

			DoubleResult res_d = find_double_in_map(t_Map, input[3]);
			if (res_d.found)
				t = res_d.value;
			else {
				say_not_supported("four");
				check = false;
			}
			
			if (check == false)
				break;
			else;

			result = (d1 * 10 + d2) * pow(10, m);

			std::wcout.imbue(std::locale(""));
			std::cout << to_engineering_string(result, 4, false, "\xEA \xF1 ");
			std::cout << to_engineering_string(t * result, 4, false, "\xEA") + "\n" << std::endl;

		}
	}
	return 0;
}
