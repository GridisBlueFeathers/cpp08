#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	
	std::vector<int> vec = {1, 2, 3, 4};

	std::vector<int>::const_iterator vecRes = vec.end();
	
	try {
		vecRes = easyfind(vec, 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << *vecRes << std::endl;

	try {
		vecRes = easyfind(vec, 2);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << *vecRes << std::endl;
}
