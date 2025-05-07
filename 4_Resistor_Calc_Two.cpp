
#include <cmath>

// #include <eng_format.hpp>
#include "eng_format.cpp" // notice this difference for mine, because
						// you might keep yours like <eng_format.hpp>
#include <iostream>
#include <string>

#include <map>  

#include <cctype> // std::toupper, to convert all input to upper case
					// because our map keys are upper case.

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
    // { 'K', 0},
    { 'N', 0.01},
    { 'R', 0.02},
    { 'O', 0.03},
	{ 'Y', 0.04},
	{ 'G', 0.005},
	{ 'L', 0.0025},
	{ 'V', 0.001},
	{ 'E', 0.0005},
	// { 'W', 9},	
	{ 'D', 0.05},	
	{ 'S', 0.1}
};

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
			
			auto it = d1_d2_Map.find(std::toupper(input[0]));
			if (it != d1_d2_Map.end())
				d1 = it->second;
			else {
				std::cout << "ERROR: Band one input not supported" << std::endl;
				check = false;
			}
			it = d1_d2_Map.find(std::toupper(input[1]));
			if (it != d1_d2_Map.end())
				d2 = it->second;
			else {
				std::cout << "ERROR: Band two input not supported" << std::endl;
				check = false;
			}

			auto it_m = m_Map.find(std::toupper(input[2]));
			if (it_m != m_Map.end())
				m = it_m->second;
			else {
				std::cout << "ERROR: Band three input not supported" << std::endl;
				check = false;
			}

			auto it_t = t_Map.find(std::toupper(input[3]));
			if (it_t != t_Map.end())
				t = it_t->second;
			else {
				std::cout << "ERROR: Band four input not supported" << std::endl;
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
