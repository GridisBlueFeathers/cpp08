#include "Span.hpp"
#include <algorithm>
#include <iterator>

Span::Span() {
#if DEBUG
	std::cerr << "Span was constructed (default)" << std::endl;
#endif
}

Span::Span(size_t n): _size(n) {
#if DEBUG
	std::cerr << "Span was constructed (size)" << std::endl;
#endif
}

Span::Span(Span &other): _size(other._size), _vec(other._vec) {
#if DEBUG
	std::cerr << "Span was constructed (copy)" << std::endl;
#endif
}

Span::~Span() {
#if DEBUG
	std::cerr << "Span was deconstructed" << std::endl;
#endif
}

Span	&Span::operator=(Span &other) {
	if (this != &other) {
		_size = other._size;
		_vec = other._vec;
	}
	return (*this);
}

void	Span::addNumber(int val) {
	if (_vec.size() == _size)
		throw ContainerFullException();
	_vec.push_back(val);
}

void	Span::addRange(
	std::vector<int>::iterator start,
	std::vector<int>::iterator end
) {
	if (std::distance(start, end) + _vec.size() > _size)
		throw ContainerFullException();
	_vec.insert(_vec.end(), start, end);
}

int		Span::longestSpan() const {
	std::vector<int>	tmp = _vec;

	if (_vec.size() < 2)
		throw NotEnoughNumbersException();

	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

int		Span::shortestSpan() const {
	std::vector<int>	tmp = _vec;
	int					res;

	if (_vec.size() < 2)
		throw NotEnoughNumbersException();

	std::sort(tmp.begin(), tmp.end());
	res = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < res)
			res = tmp[i] = tmp[i - 1];
	}
	return (res);
}

const char	*Span::ContainerFullException::what() const throw() {
	return ("Container is full");
}

const char	*Span::NotEnoughNumbersException::what() const throw() {
	return ("Not enough numbers in container to perform operation");
}
