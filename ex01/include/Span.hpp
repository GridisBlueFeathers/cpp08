#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstddef>
#include <vector>

class Span {
	private:
		size_t				_size;
		std::vector<int>	_vec;

	public:
		Span();
		Span(size_t n);
		Span(Span &other);
		~Span();

		Span	&operator=(Span &other);

		void	addNumber(int val);
		void	addRange(
			std::vector<int>::iterator start,
			std::vector<int>::iterator end);
		int		longestSpan() const;
		int		shortestSpan() const;

		class ContainerFullException: public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class NotEnoughNumbersException: public std::exception {
			public:
				virtual const char * what() const throw();
		};
};

#endif
