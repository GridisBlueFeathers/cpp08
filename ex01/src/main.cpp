#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main() {
	srand(time(NULL));
	Span	small(5);

	try {
		small.shortestSpan();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::vector<int>	smallVec = {1 ,2, 3, 4, 5};

	small.addRange(smallVec.begin(), smallVec.end());

	try {
		small.addNumber(1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		small.addRange(smallVec.begin(), smallVec.end());
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << small.shortestSpan() << std::endl;
	std::cout << small.longestSpan() << std::endl;

	Span	big(10000);
	for (int i = 0; i < 10000; i++) {
		big.addNumber(rand());
	}

	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
}
