#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::vector<int>::const_iterator vecRes = vec.end();
	
	try {
		vecRes = easyfind(vec, -1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	if (vecRes != vec.end())
		std::cout << *vecRes << std::endl;

	try {
		vecRes = easyfind(vec, 2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	if (vecRes != vec.end())
		std::cout << *vecRes << std::endl;
}
